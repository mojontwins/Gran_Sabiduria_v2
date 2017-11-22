// Cheril: the Nine
// Copyleft 2016 by The Mojon Twins

// Game loop & shit

void game_init (void) {
	c_ts_pals = l_ts_pals [level];
	c_ts_tmaps = l_ts_tmaps [level];
	c_map = l_map [level];
	c_enems = l_enems [level];
	c_behs = l_behs [level];
	c_hotspots = l_hotspots [level];
	c_locks = l_locks [level];

	n_pant = l_scr_ini [level]; 

	enems_persistent_deaths_init ();
	player_init ();
	hotspots_ini ();
	flower_ini ();
	bolts_load ();

	pkeys = 0; opkeys = 0xff;
	plife = l_plife [level]; oplife = 0xff;
	pobjs = 0; opobjs = 0xff;
}

void game_prepare_screen (void) {
	if (first_time) first_time = 0; else fade_out ();
	ppu_off ();

	draw_scr ();

	if (c_locks) bolts_update_screen ();

	bullets_ini ();
	flower_ini ();
	enems_load ();
	hotspots_load ();
	pgauge = 30; bullets_draw_gauge_offline ();

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
	first_time = 1;
	on_pant = 99;
	game_res = GS_GAME_OVER;
	
	scroll (0, 472);
	ppu_on_all ();

	music_play (MUSIC_INGAME);

	set_vram_update (update_list);
	do_game = 1;
	while (do_game) {
		half_life = 1 - half_life;		// Main flip-flop
		frame_counter ++;				// Increase frame counter
	
		ul = update_list;				// Reset pointer to update list
		oam_index = 28;					// Reset OAM index; skip sprite #0 & player
		pad0 = pad_poll (0);			// Read pads here.

		bullets_do ();
		hotspots_do ();
		flower_do ();
		enems_do ();
		
		player_move ();
		
		player_render ();
		oam_hide_rest (oam_index);

		hud_update ();

		*ul = NT_UPD_EOF;
		//ppu_wait_frame ();
		ppu_wait_frame ();

		if (game_cheril) {
			#include "engine/mainloop/infested.h"
		} 

		#include "engine/mainloop/flick_screen.h"

		if (pkilled || 
			(pobjs == l_max_objs [level] && (game_cheril || (n_pant == 45 && prx >= 208 && prx < 224 && pry >= 128 && pry < 138))) ||
			((pad0 & (PAD_SELECT | PAD_B | PAD_UP)) == (PAD_SELECT | PAD_B | PAD_UP))
		) do_game = 0;

#ifdef DEBUG
		if (pad0 & PAD_SELECT) fill_scr_data ();
#else
		//if ((pad0 & PAD_SELECT) && pobjs < l_max_objs [level]) pobjs ++;		
#endif		
	}

	music_stop ();

	set_vram_update (0);
	fade_out ();
	oam_hide_rest (4);
	ppu_off ();
}

void game_title (void) {
	enter_screen (c_pal_bg, screen_title);

	music_play (MUSIC_TITLE);
	gpit = 0; while (!gpit) {
		if (pad_poll (0) & PAD_START) {
			gpit = 1;
		}
		// Do something?
		ppu_wait_frame ();
	}
	while (pad_poll (0));
	music_stop ();
	sfx_play (SFX_START, SC_LEVEL);
	delay (ticks);

	exit_cleanly ();
}

void game_over (void) {
	enter_screen (c_pal_bg, screen_game_over);
	music_play (MUSIC_EVENT);
	do_screen (10);
}

void game_ending (void) {
	enter_screen (c_pal_bg, screen_game_ending);
	music_play (MUSIC_EVENT);

	gpit = 9; while (gpit --) ending_sprid [gpit] = rand8 () & 3;
	
	gpit = 0; while (!gpit) {
		if (pad_poll (0)) {
			gpit = 1;
		}
		
		if (game_cheril) {
			// Place muses
			gpjt = 9; while (gpjt --) oam_index = oam_meta_spr (
				ending_x [gpjt], ending_y [gpjt],
				oam_index,
				spr_ending [ending_sprid [gpjt]]
			);
			gpjt = rand8 () & 15; if (gpjt < 9) ending_sprid [gpjt] = rand8 () & 3;
			
			// Place cheril 181, 107
			oam_index = oam_meta_spr (
				181, 107,
				oam_index,
				spr_pl_0C);
		}

		ppu_wait_frame ();
	}
	while (pad_poll (0));

	exit_cleanly ();	
}
