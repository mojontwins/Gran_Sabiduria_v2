// MT MK2 NES v0.1
// Copyleft 2016 by The Mojon Twins

// Game loop & shit

void game_init (void) {
	gp_gen = scr_attr + 192; gpit = 16; while (gpit --) *gp_gen = 0;

	c_ts_pals = l_ts_pals [level];
	c_ts_tmaps = l_ts_tmaps [level];
	c_behs = l_behs [level];
	n_pant = l_n_pant [level];

	if (level < GAME_LAH) {
		c_map = map_0_tiles;
		c_decos = 0;
		c_enems = enems_0;
		c_hotspots = hotspots_0;
		c_locks = map_0_locks;
		max_hotspots_type_1 = MAX_HOTSPOTS_0_TYPE_1;
	} else {
		c_map = map_1_tiles;
		c_decos = map_1_decos;
		c_enems = enems_1;
		c_hotspots = hotspots_1;
		c_locks = map_1_locks;
		max_hotspots_type_1 = MAX_HOTSPOTS_1_TYPE_1;
	}

#if defined(ENEMIES_CAN_DIE) && defined(PERSISTENT_DEATHS)
	enems_persistent_deaths_init ();
#endif	
#ifdef PERSISTENT_ENEMIES
	persistent_enems_load ();
#endif		

	// CUSTOM {
	/*
	bolts_load ();
	player_init ();
	hotspots_ini ();

	plife = 9; oplife = 0xff;
	pobjs = 0; opobjs = 0xff;
	pkeys = 0; opkeys = 0xff;

	n_bolts = BOLTS_MAX;
	*/	
	
	if (!please_continue) {
		bolts_load ();
		hotspots_ini ();
		pobjs = 0; 
		pkeys = 0; 
	}
	player_init ();
	plife = 9; 
	oplife = 0xff;
	opobjs = 0xff;
	opkeys = 0xff;

	// } CUSTOM

}

void game_prepare_screen (void) {
	if (first_time) first_time = 0; else fade_out ();
	ppu_off ();

	draw_scr ();

	// Update bolts
	bolts_update_screen ();

	show_attributes ();	
#ifdef PLAYER_CAN_FIRE	
	bullets_ini ();
#endif
#ifdef SHOOTING_DRAINS	
	flower_ini ();
#endif
#ifdef ENABLE_COCOS
	simplecoco_init ();
#endif
#ifdef PERSISTENT_ENEMIES
	persistent_update ();
#endif	
	enems_load ();
	hotspots_load ();
#ifdef SHOOTING_DRAINS		
	pgauge = 30; bullets_draw_gauge_offline ();
#endif	
// CUSTOM {
	fumettos_init ();
// } END_OF_CUSTOM

	ppu_on_all ();

	oam_index = 28;
	prx = px >> FIX_BITS; pry = py >> FIX_BITS;
	player_render ();
	enems_do ();

	oam_hide_rest (oam_index);
	ul = update_list; hud_update (); *ul = NT_UPD_EOF;
	ppu_wait_frame ();

	fade_in ();

	generators_active = 0;
}

void game_loop (void) {
	half_life = 0;
	first_time = 1;
	on_pant = 99;
	game_res = GS_GAME_OVER;
	reset_attributes ();
	
	if (level < GAME_LAH) scroll (0, 472);
	pal_bg (mypal_game_bg [level]);
	
	ppu_on_all ();
	music_play (music_track_ingame [level]);

#ifdef PLAYER_FLICKERS
	pflickering = PLAYER_FLICKERS;
#endif	

	set_vram_update (update_list);
	do_game = 1; ticker = ticks;
	while (do_game) {		
		half_life = 1 - half_life;		// Main flip-flop
		frame_counter ++;				// Increase frame counter
		if (ticker) ticker --; else ticker = ticks;
	
		ul = update_list;				// Reset pointer to update list
		oam_index = 28;					// Reset OAM index; skip sprite #0 & player
		pad0 = pad_poll (0);			// Read pads here.

#ifdef PLAYER_CAN_FIRE
		bullets_do ();
#endif
		hotspots_do ();
		enems_do ();
		simplecoco_do ();
#ifdef SHOOTING_DRAINS			
		flower_do ();
#endif
		player_move ();
	
// CUSTOM {
		fumettos_do ();
// } END_OF_CUSTOM

		player_render ();
		oam_hide_rest (oam_index);

		hud_update ();

		*ul = NT_UPD_EOF;
		ppu_wait_frame ();

		#include "engine/mainloop/flick_screen.h"

		if (pkilled || 
			pobjs == max_hotspots_type_1 ||
			((pad0 & (PAD_SELECT | PAD_B | PAD_UP)) == (PAD_SELECT | PAD_B | PAD_UP))
		) do_game = 0;
	}

	music_stop ();

	set_vram_update (0);
	fade_out ();
	oam_hide_rest (4);
	ppu_off ();
}


void game_title (void) {
	if (game_monona) {
		m113_safe_change_chr_bank (CHR_BANK_ENDING); bank_bg (1);
	}
	enter_screen (mypal_game_bg_title [level], screen_title);

	//music_play (MUSIC_TITLE);
	gpit = 0; while (!gpit) {
		if (pad_poll (0) & PAD_START) {
			gpit = 1; please_continue = 0;
		}
		if (already_played && (pad_poll (0) & PAD_SELECT) && level < GAME_LAH) {
			gpit = please_continue = 1;
		}
		// Do something?
		ppu_wait_frame ();
	}
	while (pad_poll (0));
	music_stop ();
	sfx_play (SFX_START, SC_LEVEL);
	delay (ticks);

	exit_cleanly ();
	if (game_monona) m113_safe_change_chr_bank (CHR_BANK_MAIN);
	bank_bg (0);
}

void game_over (void) {
	enter_screen (mypal_game_bg [level], screen_game_over);
	//music_play (MUSIC_EVENT);
	do_screen (10);
}

void game_ending (void) {
	if (game_jet_puri || game_monona) m113_safe_change_chr_bank (CHR_BANK_ENDING);
	if (game_pppp) pal_spr (mypal_game_fg5);
	enter_screen (mypal_game_bg_ending [level], screen_game_ending);
	//music_play (MUSIC_EVENT);
	do_screen (60);
	if (game_jet_puri || game_monona) m113_safe_change_chr_bank (CHR_BANK_MAIN);
	if (game_pppp) pal_spr (mypal_game_fg4);
}
