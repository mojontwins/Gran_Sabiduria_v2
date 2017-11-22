// Pantanow Engine rev2b 201703
// Copyleft 2016 by The Mojon Twins

// Code for fixed screens

void enter_screen (void (*func) (void)) {
	scroll (0, 0);
	
	cls ();
	reset_attributes ();
	rda = 0;
	(*func) ();
	if (rda) show_attributes ();
	
	ppu_on_all ();
	fade_in ();
}

void exit_cleanly (void) {
	//set_vram_update (0);
	oam_hide_rest (0);
	music_stop ();
	fade_out ();
	ppu_off ();	
}

void wait_time_or_input (void) {
	rda = (pad_poll (0) != 0);
	while (game_time) {
		ticker ++; if (ticker == ticks) {
			ticker = 0;
			game_time --;
		}

		if (pad_poll (0)) {
			if (!rda) break;
		} else {
			rda = 0;
		}

		ppu_wait_frame ();
	}
}

void do_screen (unsigned char seconds) {
	game_time = seconds; ticker = 0;
	wait_time_or_input ();
	exit_cleanly ();
}

void screen_title (void) {
	vram_adr (NAMETABLE_A);
	vram_unrle (full_game ? title_comandow_rle : level_title_rle [level]);
	if (full_game) {
		p_s (10, 21, strs_texts [0x0b]);
	} else {
		p_s (6, 7, strs_texts [0x00]);
		p_s (12, 21, strs_texts [0x01]);
		p_s (12, 22, strs_texts [0x02]);
	}
	p_s (5, 25, strs_texts [0x03]);
}

void screen_2p (void) {
	vram_adr (NAMETABLE_A);
	vram_unrle (level_title_rle [level]);
	p_s (9, 15, strs_texts [0x06]);
	p_s (7, 17, strs_texts [0x04]);
	p_s (7, 18, strs_texts [0x05]);
}

void screen_game_over (void) {
	p_s (11, 14, strs_texts [0x0a]); rda = 1;
}

void screen_game_ending (void) {
	vram_adr (NAMETABLE_A);
	vram_unrle (full_game ? level_ending_comandow_rle : level_ending_rle);
	p_s (10, 18, strs_texts [0x07]);
	p_s (6, 20, strs_texts [0x08]);
	p_s (7 + full_game, 22, full_game ? strs_texts [0x0c] : strs_texts [0x09]);;
}

void screen_level (void) {
	p_s (12, 14, strs_texts [0x0d + level]);
	p_s (11, 16, strs_texts [0x10]);
}
