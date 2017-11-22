// Pantanow Engine rev2b 201703
// Copyleft 2016 by The Mojon Twins

// Game states

void game_init (void) {
	scroll_init ();
	player_init ();
	bullets_init ();
	enems_init ();

	map_ptr = level_map [level];
	behs = level_behs [level];
	strip_pointer = level_strips [level];

	rda = level + (full_game ? 3 : 0);

	c_ts_tmaps_0 = level_ts_tmaps_0 [rda];
	c_ts_tmaps_1 = level_ts_tmaps_0 [rda] + 16;
	c_ts_tmaps_2 = level_ts_tmaps_0 [rda] + 32;
	c_ts_tmaps_3 = level_ts_tmaps_0 [rda] + 48;

	c_ts_pals = level_ts_pals [rda];
}

void get_pad_once (void) {
	// Thanks for this, Nicole & nesdev!
	// https://forums.nesdev.com/viewtopic.php?p=179315#p179315
	pad_once = pad0; 
	pad0 = pad_poll (0);
	pad_once = (pad_once ^ pad0) & pad0;
}

void game_loop (void) {
	pal_bright (0);
	ppu_on_all ();

	set_vram_update (update_list);
	ul = update_list;
	*ul = NT_UPD_EOF;
		
	gpjt = 64; while (gpjt --) {
		scroll_advance (4);
		ppu_wait_frame ();
	}
	
	oam_spr (8, 16, 3, 3, 4);
	hud_life ();

	fade_in (); half_life = scroll_lock = 0;
	cheat_on = pkilled = pwins = paused = 0;
	pad0 = 0xff;

	music_play (MUSIC_INGAME);

	while (!pkilled && !pwins) {
		//*((unsigned char*)0x2001) = 0x1f;
		
		get_pad_once ();

		if (pad_once & PAD_START) {
			paused = 1 - paused;
			pal_bright (4 - paused);
			music_pause (paused);
			sfx_play (0, SC_LEVEL);
		}

		/*
		if ((pad_once & (PAD_SELECT|PAD_B)) == (PAD_SELECT|PAD_B)) {
			cheat_on = 1 - cheat_on;
		}
		*/

		if (0 == paused) {
			half_life = 1 - half_life; hl_proc = half_life;
			frame_counter ++;
			ul = update_list;
			oam_index = 12;
			
			if (cheat_on) { scroll_lock=0; pry -=4; } else {
				player_move ();
				bullets_do ();
				enems_do ();
			}

			gpijt = camera_position + 120;
			if (pry < gpijt && camera_position && !scroll_lock) {
				scroll_advance (cheat_on?4:1);
				enems_spawn (); 
			} else delta = 0;
			
			//player_render ();
			oam_hide_rest (oam_index);
			
			*ul = NT_UPD_EOF;
		}

		//*((unsigned char*)0x2001) = 0x1e;
		ppu_wait_frame ();

		pwins = pry < 8 || ((pad0 & (PAD_B|PAD_UP|PAD_SELECT))==(PAD_B|PAD_UP|PAD_SELECT));
	}

	music_stop ();

	fade_out ();
	oam_hide_rest (0);
	set_vram_update (0);
	ppu_off ();

	set_scroll_write (0);
}

void game_over (void) {
	enter_screen (screen_game_over);
	do_screen (10);
}

void game_title (void) {
	enter_screen (screen_title);

	music_play (MUSIC_TITLE);

	gpit = 0; rda = 0; pad0 = 0xff;
	while (!gpit) {
		get_pad_once ();

		if (pad_once & PAD_START) {
			gpit = 1;
			sfx_play (SFX_START, SC_LEVEL);
		}

		if (!full_game) {
			if (pad_once & (PAD_SELECT | PAD_UP | PAD_DOWN)) {
				rda = 8 - rda;
				sfx_play (SFX_SHOOT, SC_LEVEL); 
			}

			rdb = !( (pad0 & (PAD_B | PAD_A)) == (PAD_B | PAD_A) );

			oam_hide_rest (
				oam_meta_spr (
					96, 88,
					oam_meta_spr (
						80, 21*8+1 + rda,
						0,
						ssenb_06
					), 
					spr_title [rdb]
				)
			);
		}
		
		ppu_wait_frame ();
	}

	if (rda) {
		exit_cleanly ();
		enter_screen (screen_2p);

		pad_once = gpit = 0; while (!gpit) {
			get_pad_once ();

			if (pad_once & (PAD_SELECT | PAD_START | PAD_A | PAD_B)) {
				gpit = 1;
				sfx_play (SFX_SHOOT, SC_LEVEL);
			}
		}
	}

	exit_cleanly ();
}

void game_ending (void) {
	enter_screen (screen_game_ending);
	do_screen (10);
}

void game_level (void) {
	enter_screen (screen_level);
	do_screen (5);
}
