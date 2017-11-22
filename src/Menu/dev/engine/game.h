// MT MK2 NES v0.6
// Copyleft 2016 by The Mojon Twins

// Game loop & shit

void game_init (void) {
	gp_gen = scr_attr + 192; gpit = 16; while (gpit --) *gp_gen = 0;

	// Multiple level support
	c_ts_pals = l_ts_pals [level];
	c_ts_tmaps = l_ts_tmaps [level];
	c_behs = l_behs [level];
	n_pant = l_scr_ini [level];
	c_map = l_map [level];
	c_enems = l_enems [level];
	c_hotspots = l_hotspots [level];
	c_locks = l_locks [level];
	max_hotspots_type_1 = l_max_hotspots_type_1 [level];
	map_w = l_map_w [level];

	pal_bg (l_pal_bgs [level]);
	pal_spr (l_pal_fgs [level]);

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
#ifdef COUNT_KILLED_ON_FLAG
	flags [COUNT_KILLED_ON_FLAG] = 0;
#endif
#ifdef ONLY_ONE_OBJECT_FLAG
	flags [ONLY_ONE_OBJECT_FLAG] = 0;
#endif

	plife = l_plife [level]; oplife = 0xff;
	pobjs = 0; opobjs = 0xff;
	pkeys = 0; opkeys = 0xff;

	// CUSTOM {
	okilled = opgauge = 0xff;
	pstatespradder = 0;

	pal_c [0] = 0x12;
	pal_c [1] = pal_c [3] = 0x2C;
	pal_c [2] = 0x30;
	// }
}

void game_prepare_screen (void) {
	if (first_time) first_time = 0; else fade_out ();
	ppu_off ();

	draw_scr ();

#ifdef ENABLE_FUMETTOS
	fumettos_init ();
#endif
#ifdef HOTSPOT_TYPE_KEY
	bolts_update_screen ();
#endif
#ifdef ENABLE_PUAS
	puas_init ();
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

	max_stars = 8;
	menu_stars_init ();
	menu_stars_frame ();

	oam_hide_rest (oam_index);
	ul = update_list; hud_update (); *ul = NT_UPD_EOF;
	ppu_wait_frame ();

	fade_in ();
}

// CUSTOM {
void game_qr_tb () {
	update_list [0] = NT_UPD_EOF;
	fade_out ();
	m113_safe_change_chr_bank (0xe);
	ppu_off ();
	enter_screen (palts1, screen_qr_tb);
	do_screen (255);
	m113_safe_change_chr_bank (0x0);
	hud_draw ();
	okilled = opkeys = opobjs = oplife = 0xff;
	first_time = 1;
}
// } END_OF_CUSTOM

void game_loop (void) {
	half_life = 0;
	first_time = 1;
	on_pant = 99;
	game_res = GS_GAME_OVER;

	reset_attributes ();
	ppu_on_all ();

#ifdef PLAYER_FLICKERS
	pflickering = PLAYER_FLICKERS;
#endif	

	music_play (MUSIC_INGAME);

	set_vram_update (update_list);
	do_game = 1; ticker = ticks;
	pwashit = 0;

	while (do_game) {		
		half_life = 1 - half_life;		// Main flip-flop
		frame_counter ++;				// Increase frame counter
		// CUSTOM {
		//if (ticker) ticker --; else ticker = ticks;
		if (ticker) ticker --; else {
			ticker = ticks; 
			if (pgauge < PGAUGE_MAX) pgauge ++; 
		}
		// } END_OF_CUSTOM
	
		ul = update_list;				// Reset pointer to update list
		oam_index = 28;					// Reset OAM index; skip sprite #0 & player

		// Read pads here.
		pad_this_frame = pad0; 
		pad0 = pad_poll (0);
		pad_this_frame = (pad_this_frame ^ pad0) & pad0;

#ifdef ENABLE_PUAS
		puas_do ();
#endif
#ifdef PLAYER_CAN_FIRE
		bullets_do ();
#endif
		hotspots_do ();
	
		if (game_vesta_vaal) {
			hitter_do ();
			if (!(frame_counter & 7)) pal_cycle ();
			menu_stars_frame ();
			pal_col (pstatespradder ? 0x17 : 0x1f, (pgauge == PGAUGE_MAX && half_life) ? 0x16 : 0x28);
		}

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

#ifdef ENABLE_FUMETTOS
		fumettos_do ();
#endif

		// Custom
		if (game_trabajo_basura) {
			if ((n_pant == 2 || n_pant == 7 || n_pant == 12 || n_pant == 17) && flags [ONLY_ONE_OBJECT_FLAG]) {
				if ((pad0 & PAD_B) && prx >= 124 && prx <= 140 && pry > 168 && pry <= 176) {
					flags [ONLY_ONE_OBJECT_FLAG] = 0;
					pobjs ++;
					sfx_play (0, SC_LEVEL);
					pobject = 45;
				}
				if (half_life) oam_index = oam_meta_spr (128, 175, oam_index, ssit_tb_04);
			} else if (n_pant == 0) {
				if (half_life) oam_index = oam_meta_spr (32, 175, oam_index, ssit_tb_05);
			}
		}
		
		hud_update ();

		oam_hide_rest (oam_index);
		*ul = NT_UPD_EOF;
		//ppu_wait_frame ();
		ppu_wait_frame ();

		if (pkilled 
			|| (pobjs == max_hotspots_type_1 && (flags [COUNT_KILLED_ON_FLAG] == 25 || game_vesta_vaal))
			|| ((pad0 & (PAD_SELECT | PAD_B | PAD_UP)) == (PAD_SELECT | PAD_B | PAD_UP))
		) do_game = 0;

		// Detect hidden terminal and show QR in Trabajo Basura
		if (game_trabajo_basura) {
			if (n_pant == 0) {
				if (pry >= 160 && pry <= 176 && prx >= 25 && prx <= 47) {
					if (!pobject && (pad0 & PAD_B)) {
						pobject = ticks;		// Begin animation
					}
					if (pobject == halfticks) {
						oam_hide_rest (0);
						game_qr_tb ();
						on_pant = 99;			// Reenter
					}
				}
			}
		}

		#include "engine/mainloop/flick_screen.h"
	}
	music_stop ();

	set_vram_update (0);
	exit_cleanly ();
}

void game_title (void) {
	enter_screen (t_pal_bgs [level], screen_title);
	pal_spr (palss1);
	//music_play (MUSIC_TITLE);
	
	logoy1 = logoy2 = 56;
	logox1 = 64; logox2 = 128;
	half_life = 0;

	gpit = 0; while (!gpit) {
		half_life = 1 - half_life;

		if (pad_poll (0) & PAD_START) {
			gpit = 1;
		}

		if (game_trabajo_basura) {
			rda = (rand8 () & 1) << 1;
			rdb = (rand8 () & 1) << 1;
			if (half_life) {
				logox1 += rda - 1; logoy1 += rdb - 1;
				oam_hide_rest (oam_meta_spr (logox1, logoy1, 0, ssti_tb_00));
			} else {
				logox2 += rda - 1; logoy2 += rdb - 1;
				oam_hide_rest (oam_meta_spr (logox2, logoy2, 0, ssti_tb_01));
			}
		}
		
		ppu_wait_frame ();
	}
	while (pad_poll (0));
	music_stop ();
	sfx_play (SFX_START, SC_LEVEL);
	delay (ticks);

	exit_cleanly ();
}

void game_over (void) {
	enter_screen (t_pal_bgs [level], screen_game_over);
	//music_play (MUSIC_GAME_OVER);
	do_screen (10);
}

void game_ending (void) {
	enter_screen (t_pal_bgs [level], screen_game_ending);
	//music_play (MUSIC_TITLE);
	do_screen (255);
}
