// MT MK2 NES v0.4
// Copyleft 2016 by The Mojon Twins

// Game loop & shit

void game_init (void) {
	gp_gen = scr_attr + 192; gpit = 16; while (gpit --) *gp_gen = 0;

	c_ts_pals = l_ts_pals [level];
	c_ts_tmaps = l_ts_tmaps [level];
	c_behs = l_behs [level];
	n_pant = l_n_pant [level];
		
	c_map = l_map [level];
	c_enems = l_enems [level];
	c_hotspots = l_hotspots [level];
	c_locks = map_napia_locks;

	spr_enems = l_spr_enems [level];
	spr_player = l_spr_player [level];
	spr_items = l_spr_items [level];

	// Fake constants for this cart...
	MAP_W = l_MAP_W [level];
	MAP_H = l_MAP_H [level];
	max_pant = l_max_pant [level];
	
	CELL_FACING_LEFT = l_CELL_FACING_LEFT [level];

	PLAYER_VX_MAX = l_PLAYER_VX_MAX [level]; 
	PLAYER_AX = l_PLAYER_AX [level];
	PLAYER_RX = l_PLAYER_RX [level];
	
	PLAYER_VY_JUMP_INITIAL = l_PLAYER_VY_JUMP_INITIAL [level];
	PLAYER_AY_JUMP = l_PLAYER_AY_JUMP [level];
	PLAYER_VY_JUMP_MAX = l_PLAYER_VY_JUMP_MAX [level];

	plife = game_napia ? 5 : 0;

	max_hotspots_type_1 = l_max_hotspots_type_1 [level];

	if (game_rendezvous) {
		if (restart_girl) {
			if (very_first_time) {
				very_first_time = 0;
				ini_px [0] = ini_py [0] = ini_py [1] = 80 << FIX_BITS;	// 5 * 16 << FIX_BITS
				ini_px [1] = 128 << FIX_BITS;							// 8 * 16 << FIX_BITS
				ini_n_pant [0] = 40; ini_n_pant [1] = 44;
				active_girl = 0;
			} else {
				// Make first placement of characters in the game.
				rda = rand8 () & 7;
				ini_px [0] = init_x [rda] << (4 + FIX_BITS);
				ini_py [0] = (1+init_y [rda]) << (4 + FIX_BITS);
				ini_n_pant [0] = init_screens [rda];
				rda += 8;
				ini_px [1] = init_x [rda] << (4 + FIX_BITS);
				ini_py [1] = (1+init_y [rda]) << (4 + FIX_BITS);
				ini_n_pant [1] = init_screens [rda];
				if (wins < 3) active_girl = rand8 () & 1;
			}
			restart_girl = 0;
		}
		n_pant = ini_n_pant [active_girl];
	}

#if defined(ENEMIES_CAN_DIE) && defined(PERSISTENT_DEATHS)
	enems_persistent_deaths_init ();
#endif	
#ifdef PERSISTENT_ENEMIES
	persistent_enems_load ();
#endif		

#ifdef HOTSPOT_TYPE_KEY
	bolts_load ();
#endif
	player_init ();
	hotspots_ini ();

	oplife = 0xff;
	pobjs = 0; opobjs = 0xff;
#ifdef HOTSPOT_TYPE_KEY
	pkeys = 0; opkeys = 0xff;
#endif

// CUSTOM {
	if (game_rendezvous) { altuniverse = (wins > 2); rda = altuniverse; altuniverse_set (); }
// } CUSTOM
}

void game_prepare_screen (void) {
	if (first_time) first_time = 0; else fade_out ();
	ppu_off ();

	if (game_rendezvous) rendezvous_backdrop ();
	draw_scr ();

	if (game_napia) fumettos_init ();

	// Update bolts
#ifdef HOTSPOT_TYPE_KEY
	bolts_update_screen ();
#endif
	
#ifdef PLAYER_CAN_FIRE	
	bullets_ini ();
#endif
#ifdef SHOOTING_DRAINS	
	flower_ini ();
#endif
#ifdef PERSISTENT_ENEMIES
	persistent_update ();
#endif	
	enems_load ();
	hotspots_load ();
// CUSTOM {
	if (game_rendezvous) {
		girl_init ();
		scrtctr = 0;
		rda = altuniverse; altuniverse_set ();
	}
// } END_OF_CUSTOM
#ifdef SHOOTING_DRAINS		
	pgauge = 30; bullets_draw_gauge_offline ();
#endif
#ifdef ENABLE_COCOS	
	simplecoco_init ();
#endif

	ppu_on_all ();

	oam_index = 28;
	prx = px >> FIX_BITS; pry = py >> FIX_BITS;
	player_render ();
	hotspots_do ();
	enems_do ();

	oam_hide_rest (oam_index);
	ul = update_list; hud_update (); *ul = NT_UPD_EOF;
	ppu_wait_frame ();

	fade_in ();
}

void game_loop (void) {
	girlact = 0;
	half_life = 0;
	first_time = 1;
	on_pant = 99;
	game_res = GS_GAME_OVER;

	reset_attributes ();

	if (game_rendezvous) pal_bg (girl_palette [active_girl]);
			
	ppu_on_all ();

#ifdef PLAYER_FLICKERS
	pflickering = PLAYER_FLICKERS;
#endif	

	if (game_potipoti) music_play (MUSIC_INGAME_POTIPOTI);
	if (game_napia) music_play (MUSIC_INGAME_NAPIA);

	set_vram_update (update_list);

	if (game_rendezvous) {
		ul = update_list; p_t2 (0x14, 2, retries); p_t2 (0x1d, 2, wins); *ul = NT_UPD_EOF; ppu_wait_frame ();
	}

	do_game = 1; // ticker = ticks;
	pwashit = 0;

	while (do_game) {		
		half_life = 1 - half_life;		// Main flip-flop
		frame_counter ++;				// Increase frame counter
		//if (ticker) ticker --; else ticker = ticks;
	
		ul = update_list;				// Reset pointer to update list
		oam_index = 28;					// Reset OAM index; skip sprite #0 & player
		pad0 = pad_poll (0);			// Read pads here.

#ifdef PLAYER_CAN_FIRE
		bullets_do ();
#endif
		hotspots_do ();
// CUSTOM {
		girl_do ();
// } END_OF_CUSTOM		
		enems_do ();
#ifdef ENABLE_COCOS		
		simplecoco_do ();
#endif		
#ifdef SHOOTING_DRAINS			
		flower_do ();
#endif

		player_move ();	
		if (n_pant == on_pant) player_render ();
		if (pwashit) player_hit ();

		if (game_napia) {
			if (hrt && half_life) oam_index = oam_meta_spr (hrx, hry + SPRITE_ADJUST, oam_index, ssit_napia_03);
			player_border ();
			fumettos_do ();
		}

		oam_hide_rest (oam_index);

		hud_update ();

		*ul = NT_UPD_EOF;
		ppu_wait_frame ();

		if (game_rendezvous) altuniverse_do ();
		if (pkilled || 
			pobjs == max_hotspots_type_1 ||
			(pad0 & (PAD_B|PAD_SELECT)) == (PAD_B|PAD_SELECT)
		) do_game = 0;

		#include "engine/mainloop/flick_screen.h"
	}
	
	if (game_rendezvous && wins < 3) {
		rda = 0;
		altuniverse_set ();
	}

	set_vram_update (0);
	exit_cleanly ();
}

void game_title (void) {
	if (game_rendezvous) if (wins > 2) { rda = 1; altuniverse_set (); }

	enter_screen (mypal_game_bg_title, screen_title);
	
	if (game_potipoti) music_play (MUSIC_TITLE);
	gpit = 0; while (!gpit) {
		if (pad_poll (0) & PAD_START) {
			if (pad_poll (0) & PAD_SELECT) wins = 3;
			gpit = 1;
		}
		rda = rand8 ();	// This helps the game be more random.
		ppu_wait_frame ();
	}
	while (pad_poll (0));
	if (!game_rendezvous) music_stop ();
	sfx_play (SFX_START, SC_LEVEL);
	delay (50);

	exit_cleanly ();
}

void game_over (void) {
	enter_screen (mypal_game_bg_title, screen_game_over);
	if (!game_rendezvous) music_play (MUSIC_GAME_OVER);
	do_screen (10);
}

void game_ending (void) {
	if (wins >= 3) pal_spr (palss_rendezvous_ending_alt);
	enter_screen (mypal_game_bg_title, screen_game_ending);
	if (!game_rendezvous) music_play (MUSIC_TITLE);
	do_screen (255);
	if (game_rendezvous) pal_spr (palss_rendezvous);
}
