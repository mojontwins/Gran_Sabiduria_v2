// MT MK2 NES v0.3
// Copyleft 2016 by The Mojon Twins

// Game loop & shit

void game_init (void) {
	gp_gen = scr_attr + 192; gpit = 16; while (gpit --) *gp_gen = 0;

	/*
	c_ts_pals = level_ts_pals [level];
	c_ts_tmaps = level_ts_maps [level];
	c_behs = level_behs [level];
	n_pant = level_n_pant_ini [level];
		
	c_map = level_map [level];
	c_enems = level_enems [level];
	c_hotspots = level_hotspots [level];
	c_locks = level_locks [level];
	*/
	if (level == GAME_OTRO_BOSQUE) {
		c_ts_pals = ts1_pals;
		c_ts_tmaps = ts1_tmaps;
		c_behs = behs1;
		n_pant = 15;
			
		c_map = map_1_tiles;
		c_enems = enems_1;
		c_hotspots = hotspots_1;
		c_locks = map_1_locks;

		max_hotspots_type_1 = MAX_HOTSPOTS_1_TYPE_1;
	} else {
		c_ts_pals = ts0_pals;
		c_ts_tmaps = ts0_tmaps;
		c_behs = behs0;
		n_pant = 12;
			
		c_map = map_0_tiles;
		c_enems = enems_0;
		c_hotspots = hotspots_0;
		c_locks = map_0_locks;		

		max_hotspots_type_1 = MAX_HOTSPOTS_0_TYPE_1;
	}

#if defined(ENEMIES_CAN_DIE) && defined(PERSISTENT_DEATHS)
	enems_persistent_deaths_init ();
#endif	
#ifdef PERSISTENT_ENEMIES
	persistent_enems_load ();
#endif		

	// CUSTOM {
	gpit = MAP_W * MAP_H * N_ENEMS; while (gpit --) ep_flags [gpit] &= 0xfe;
	muacs_count = 0; omuacs_count = 0xff;
	// }

	bolts_load ();
	player_init ();
	hotspots_ini ();
	ob_init_char_array ();

	plife = level == 2 ? 50 : LIFE_INI; oplife = 0xff;
	pobjs = 0; opobjs = 0xff;
	pkeys = 0; opkeys = 0xff;

	n_bolts = BOLTS_MAX;
}

void game_prepare_screen (void) {
	if (first_time) first_time = 0; else fade_out ();
	ppu_off ();

	draw_scr ();

	// Update bolts
	bolts_update_screen ();
	
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
#ifdef SHOOTING_DRAINS		
	pgauge = 30; bullets_draw_gauge_offline ();
#endif
#ifdef ENABLE_COCOS	
	simplecoco_init ();
#endif

	// Custom
	ob_char_load ();

	ppu_on_all ();

	oam_index = 28;
	prx = px >> FIX_BITS; pry = py >> FIX_BITS;
	player_render ();
	enems_do ();
	hotspots_do ();

	// Custom
	ob_char_do ();
	hearts_init ();

	oam_hide_rest (oam_index);
	ul = update_list; hud_update (); *ul = NT_UPD_EOF;
	ppu_wait_frame ();

	fade_in ();
}

void game_loop (void) {
	half_life = 0;
	first_time = 1;
	on_pant = 99;
	//game_res = GS_GAME_OVER;

	reset_attributes ();
	pal_bg (pal_game_ts [level]);
	pal_spr (pal_game_ss [level]);
			
	ppu_on_all ();

#ifdef PLAYER_FLICKERS
	pflickering = PLAYER_FLICKERS;
#endif	

	music_play (MUSIC_INGAME);

	// TODO :: Level intro

	set_vram_update (update_list);
	do_game = 1; ticker = 50;

	while (do_game) {		
		half_life = 1 - half_life;		// Main flip-flop
		frame_counter ++;				// Increase frame counter
		if (ticker) ticker --; else ticker = 50;
	
		ul = update_list;				// Reset pointer to update list
		oam_index = 28;					// Reset OAM index; skip sprite #0 & player
		pad0 = pad_poll (0);			// Read pads here.

#ifdef PLAYER_CAN_FIRE
		bullets_do ();
#endif
		hotspots_do ();
		enems_do ();
#ifdef ENABLE_COCOS		
		simplecoco_do ();
#endif		
#ifdef SHOOTING_DRAINS			
		flower_do ();
#endif 

		// Custom
		if (level == GAME_OTRO_BOSQUE) ob_char_do ();	
		hearts_move ();	

		player_move ();		
		player_render ();

		oam_hide_rest (oam_index);

		hud_update ();

		*ul = NT_UPD_EOF;
		//ppu_wait_frame ();
		ppu_wait_frame ();

		//if (level == GAME_OTRO_BOSQUE) if (pad0 & PAD_SELECT) text_split ();

		#include "engine/mainloop/flick_screen.h"
		#include "engine/mainloop/cheat.h"

		if (
			pkilled || (
				pobjs == max_hotspots_type_1 && 
				(character_order_idx == 5 || level != GAME_OTRO_BOSQUE) && 
				(muacs_count == 75 || level != GAME_BEGINS)
			) || ((pad0 & (PAD_SELECT | PAD_B | PAD_UP)) == (PAD_SELECT | PAD_B | PAD_UP))
		) do_game = 0;
	}
	music_stop ();

	set_vram_update (0);
	fade_out ();
	oam_hide_rest (4);
	ppu_off ();
}

void game_title (void) {
	enter_screen (pal_title [level], screen_title);
	
	music_play (MUSIC_TITLE);
	gpit = 0; while (!gpit) {
		if (pad_poll (0) & PAD_START) {
			gpit = 1;
		}
		// Do something?
		rda = rand8 (); // randomize the randomized random
		ppu_wait_frame ();
	}
	while (pad_poll (0));
	music_stop ();
	sfx_play (SFX_START, SC_LEVEL);
	delay (50);

	exit_cleanly ();
}

void game_over (void) {
	enter_screen (pal_game_ts [level], screen_game_over);
	music_play (MUSIC_GAME_OVER);
	do_screen (30);
}

void game_ending (void) {
	enter_screen (pal_ending [level], screen_game_ending);
	pal_spr (mypal_game_fg0);
	music_play (MUSIC_EVENT);
	do_screen (255);
}
