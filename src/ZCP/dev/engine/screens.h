// MT MK2 NES v0.87ZCP - Peyejo pendejo!
// Copyleft 2017 by The Mojon Twins

// Code for fixed screens

void enter_screen (void (*func) (void)) {
	cls ();
	
	(*func) ();
	
	ppu_on_all ();
	fade_in ();
}

void exit_cleanly (void) {
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

		if (pad0 = pad_poll (0)) {
			if (!rda) break;
		} else {
			rda = 0;
		}

		ppu_wait_nmi ();
	}
}

void do_screen (unsigned char seconds) {
	game_time = seconds; ticker = 0;
	wait_time_or_input ();
	exit_cleanly ();
}

void screen_title (void) {
	vram_adr (NAMETABLE_A);
	if (game_zcp) {
		vram_unrle (zcp_title_rle);
		p_s (11, 20, str_texts_02);
		p_s (11, 21, str_texts_03);
		p_s (5, 25, str_texts_01);
	} else {
		vram_unrle (yun_title_rle);
	}
}

void screen_game_over (void) {
	p_s (12, 14, str_texts_04);
	show_attributes ();
}

void screen_game_ending (void) {
	if (game_zcp) {
		vram_adr (NAMETABLE_A);
		vram_unrle (zcp_ending_rle);
	} else {
		pal_spr (palssend);
		oam_meta_spr (108, 76, 0, ssending_00);
	}
}
