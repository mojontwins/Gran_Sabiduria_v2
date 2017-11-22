// MT MK2 NES v0.86 - Sonic Bad is bad
// Copyleft 2017 by The Mojon Twins

// Game loop & shit

#ifdef SCRIPTING_ON
void game_run_fire_script (void) {
	run_script (2 * MAX_PANTS + 2);		// Press fire in any room.
	run_script (n_pant + n_pant + 1);		// Press fire in current room.
}
#endif

void game_init (void) {
	// This makes my life easier
	// gp_gen = scr_attr + 192; gpit = 16; while (gpit --) *gp_gen = 0;
	// Deprecating this...

	// Multiple level support (pseudo custom)
	// Some things are hardcoded for some games.

	c_ts_pals = l_ts_pals [level];
	c_ts_tmaps = l_ts_tmaps [level];
	c_behs = l_behs [level];
	c_map = l_map [level];
	//c_decos = l_decos [level];
	c_enems = l_enems [level];
	c_hotspots = l_hotspots [level];
	c_locks = l_locks [level];
	max_hotspots_type_1 = l_max_hotspots_type_1 [level];
	spr_enems = spr_enems_0; // l_spr_enems [level];
	
	// Scalar types dealt with together
	// This produces better code.
	map_w = l_map_w [level];
	n_pant = game_somari ? 0 : l_scr_ini [level];

	//pal_bg (l_pal_bgs [gs + gs + gs + level]);
	// CUSTOM {
	//pal_spr (l_pal_fgs [level]);
	// }

	// c_pal_bg = l_pal_bgs [level];

	// Sonic, Espinete or Somari ?
	spr_player = l_spr_player [gs];
	PLAYER_VX_MAX = l_PLAYER_VX_MAX [gs];
	PLAYER_AX = l_PLAYER_AX [gs];
	PLAYER_RX = l_PLAYER_RX [gs];

#if defined(ENEMIES_CAN_DIE) && defined(PERSISTENT_DEATHS)
	enems_persistent_deaths_init ();
#endif	

#ifdef PERSISTENT_ENEMIES
	persistent_enems_load ();
#endif

#ifdef PERSISTENT_TILE_GET
	gpint = MAX_PANTS*12; while (gpint --) tile_got [gpint] = game_sonic ? 0 : 0xff;
#endif

#ifdef HOTSPOT_TYPE_KEY
	bolts_load ();
#endif

	player_init ();

#ifndef DISABLE_HOTSPOTS		
	// CUSTOM {}
	//hotspots_ini ();
#endif	

	// Scripting / flags stuff

#ifdef COUNT_KILLED_ON_FLAG
	flags [COUNT_KILLED_ON_FLAG] = 0;
#endif

#ifdef ONLY_ONE_OBJECT_FLAG
	flags [ONLY_ONE_OBJECT_FLAG] = 0;
#endif

#ifdef PLAYER_INV_FLAG
	flags [PLAYER_INV_FLAG] = 0;
#endif

#ifdef SCRIPTING_ON
	// Script init
	script_pool = level_scripts [level];
#endif

	// CUSTOM {
	custom_on_off = l_custom_on_off [level];
	// } END_OF_CUSTOM

	// Game values (lifes, etc)

	oplife = 0xff;
	pobjs = 0; opobjs = 0xff;
	pbodycount = 0; opbodycount = 0xff;
	pkeys = 0; opkeys = 0xff;
	//pammo = AMMO_MAX; opammo = 0x0ff;

	// The almighty debug line!
	//n_pant = 7; pobjs = 4; pkeys = 5;
}

void game_prepare_screen (void) {
	no_ct = 0;
	update_list [0] = NT_UPD_EOF;
	ppu_wait_nmi ();

	if (first_time) first_time = 0; else fade_out ();
	ppu_off ();

#ifdef ENABLE_SPRINGS
	springs_idx = 0;
#endif

#ifdef ENABLE_PROPELLERS
	propellers_idx = 0;
#endif

#if defined (ENABLE_ESTRUJATORS) || defined (ENABLE_CATARACTS)
	est_ini_delay = est_idx = 0;
#endif	

#ifdef ENABLE_CATARACTS
	cataracts_on = 0;
#endif

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

#ifdef BREAKABLE_WALLS
	breakable_init ();
#endif

	enems_load ();

#ifndef DISABLE_HOTSPOTS	
	hotspots_load ();
#endif

#ifdef SHOOTING_DRAINS		
	pgauge = 30; bullets_draw_gauge_offline ();
#endif

#ifdef ENABLE_COCOS	
	simplecoco_init ();
#endif

#ifdef ENABLE_FABOLEES
	fabolee_init ();
#endif

	show_attributes ();

	ppu_on_all ();

	oam_index = 44;
	prx = px >> FIX_BITS; pry = py >> FIX_BITS;
	player_render ();

#ifndef DISABLE_HOTSPOTS	
	hotspots_do ();
#endif	

	enems_do ();

	oam_hide_rest (oam_index);
	ul = update_list; 
	hud_update (); 
	close_update_cycle ();

#ifdef ENABLE_CONTAINERS
	c_idx = 0;
#endif

#ifdef SCRIPTING_ON
	run_script (2 * MAX_PANTS + 1);		// Entering any script
	run_script (n_pant + n_pant);			// Entering this room script
#endif

#ifdef ENABLE_HOLES
	player_register_safe_spot ();
#endif

	// CUSTOM {
	// Custom rings for Sonic Mal
	ring_on = 0;
	// }

	fade_in ();
}

void game_loop (void) {
	half_life = 0;
	first_time = 1;
	on_pant = 99;

	// scroll (0, SCROLL_Y);
	// reset_attributes ();
	// gpit = 8; while (gpit --) attr_table [gpit] = 0x55;
	
	// CUSTOM {
	// ppu_on_all ();
	// } END_OF_CUSTOM

	// CUSTOM {
	rda = gs + (gs << 1) + level;
	music_play (level_musics [rda]);
	if (!game_somari) {
		enter_screen (l_pal_bgs [rda], screen_game_level);
		game_time = game_somari ? 10 : 2; ticker = 30; wait_time_or_input ();
		fade_out ();
		ppu_off ();
	} else pal_bg (l_pal_bgs [rda]);
	cls ();
	hud_draw ();	// Moved this here.
	ppu_on_all ();
	if (custom_on_off & FLAG_BOTTOM_SPLIT) {
		oam_spr (1, 211, 2, 0, 0);
	}
	fskip_ctr = 1;
	// } END_OF_CUSTOM

	set_vram_update (update_list);
	do_game = 1;
	pwashit = 0; 
	pcharacter = 0;

	// Entering Game
#ifdef SCRIPTING_ON
#ifdef CLEAR_FLAGS
	msc_clear_flags ();
#endif
	script_result = 0;
	// Entering game script
	run_script (2 * MAX_PANTS);
#endif

	paused = 0; update_list [0] = NT_UPD_EOF;

	while (do_game) {

		//*((unsigned char*)0x2001) = 0x1e;
		//ppu_wait_frame ();
		ppu_wait_nmi ();
		//*((unsigned char*)0x2001) = 0x1f;

		
		pad_read ();		

		if (pwashit) player_hit ();		

		if (pad_this_frame & PAD_START) {
			paused = !paused;
			if (paused) pal_bright (3); else pal_bright (4);
			music_pause (paused);
			sfx_play (0, SC_LEVEL);
		}

		if (pkilled 
			|| (pobjs == max_hotspots_type_1)
			|| ((pad0 & (PAD_SELECT | PAD_B | PAD_UP)) == (PAD_SELECT | PAD_B | PAD_UP))
		) do_game = 0;

		if (ntsc == 0 || fskip_ctr) {				
			half_life = 1 - half_life;		// Main flip-flop
			frame_counter ++;				// Increase frame counter

			// Press Fire At
#ifdef SCRIPTING_ON
			if (f_zone_ac) {
				if (pry >= fzy1 && pry <= fzy2)
					if (prx >= fzx1 && prx <= fzx2)
						game_run_fire_script ();
			}
#endif

			#include "engine/mainloop/flick_screen.h"

			if (!paused) {
				ul = update_list;				// Reset pointer to update list
				oam_index = 44;					// Reset OAM index; skip sprite #0 & player
			
				pgotten = pgtmx = pgtmy = 0;

#ifdef ENABLE_PUAS
				puas_do ();
#endif
#ifdef PLAYER_CAN_FIRE
				bullets_do ();
#endif
#ifndef DISABLE_HOTSPOTS		
				hotspots_do ();
#endif		
#ifdef ENABLE_FABOLEES
				fabolee_do ();
#endif

				enems_do ();
			
#ifdef ENABLE_COCOS		
				simplecoco_do ();
#endif		
#ifdef SHOOTING_DRAINS			
				flower_do ();
#endif
#ifdef BREAKABLE_WALLS
				breakable_do ();
#endif		

				// If both active, cataracts and estrujators are exclusive
#ifdef ENABLE_CATARACTS
				if (cataracts_on) cataracts_do ();
#ifdef ENABLE_ESTRUJATORS
				else
#endif
#endif
#ifdef ENABLE_ESTRUJATORS
				estrujators_do ();
#endif

				player_move ();	
				if (n_pant == on_pant) player_render ();
				//if (pwashit) player_hit ();

#ifdef ENABLE_FUMETTOS
				fumettos_do ();
#endif
#ifdef ENABLE_CONTAINERS
				containers_draw ();
#endif
#ifdef ENABLE_SPRINGS
				if (springs_idx) springs_do ();
#endif
#ifdef ENABLE_PROPELLERS
				if (propellers_idx) propellers_do ();
#endif

				// CUSTOM {
				// Custom rings for Sonic Mal
				ring_do ();

				hud_update ();
			
				oam_hide_rest (oam_index);
			}
		}

		fskip_ctr ++; if (fskip_ctr == 6) fskip_ctr = 0;

		if (custom_on_off & FLAG_PAL_CYCLE) {
				#include "engine/mainloop/palcycle.h"
		}
		if (custom_on_off & FLAG_BOTTOM_SPLIT) {
			split (frame_counter, 0);
		}

		*ul = NT_UPD_EOF;
	}
	
	if (pkilled && game_somari && level == 2) {
		music_stop ();
		game_time = 10;
		pal_col (0, 0xf);
		wait_time_or_input ();
	}

	set_vram_update (0);
	exit_cleanly ();
}

void game_title (void) {
	// Custom title screen :-)

	enter_screen (pal_ts_title [gs], screen_title);
	if (game_somari == 0) music_play (MUSIC_TITLE);
	oam_spr (254, 154, 2, 0, 0);
	ppu_wait_nmi ();
	
	rda = rdb = rdc = rdx = rdct = 0;
	rdd = game_sonic ? 0 : 3;
	rdt = 1; ticker = ticks;

	while (1) {
		pad_read (); if (pad_this_frame & PAD_START) break;

		if (game_somari == 0) {
			oam_meta_spr (120, 108, 4, spr_title [rdd]);
			oam_meta_spr (120 + rdx, 112 - rdb, 28, spr_title [rdd + rdt]);

			if (ticker) ticker --; else {
				rdc = (rdc + 1) & 3; if (!rdc) {
					if (rdb < 17) rdb ++; else {
						rdx = game_sonic && ((rand8 () & 15) == 1);
						if ((rand8 () & 7) == 3) { rdct = 16; rdt = 2; }
					}
				}
				if (rdct) rdct --; else rdt = 1;
			}
		}

		rda ++; split (rda, 0);
		
		ppu_wait_nmi ();
	}

	music_stop ();
	sfx_play (SFX_START, SC_LEVEL);
	delay (ticks);

	exit_cleanly ();
}

void game_over (void) {
	enter_screen (palts0, screen_game_over);
	//music_play (MUSIC_EVENT);
	do_screen (10);
}

void game_ending (void) {
	rdb = 0xff;

	enter_screen ((pemmeralds && game_sonic) ? palts0 : palts3, screen_ending);
	//music_play (MUSIC_EVENT);
	
	while (!pad_poll (0)) {	
		ppu_wait_nmi ();
	}

	exit_cleanly ();
}
