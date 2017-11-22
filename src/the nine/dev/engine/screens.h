// MT MK2 NES v0.2
// Copyleft 2016 by The Mojon Twins

// Code for fixed screens

void enter_screen (const unsigned char *pal, void (*func) (void)) {
	scroll (0, 0);
	
	cls ();
	(*func) ();
	
	pal_bg (pal);
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
	cls ();
	vram_adr (NAMETABLE_A);
	
	switch (level) {
		case 0:
		case 1:
			vram_unrle (the_nine_title_rle);
			break;
		case 2:
			vram_unrle (meghan_title_rle);
			p_s (4, 19, "COLLECT THE LIGHT BULBS");
			p_s (3, 20, "AND GET BACK TO THE TARDIS");
			break;
	}
	
	p_s (10, 22, "PRESS START!");
	p_s (5, 24, "@ 2016 THE MOJON TWINS");
}

void screen_game_over (void) {
	p_s (11, 14, "GAME OVER!");
	reset_attributes ();
	show_attributes ();
}

void screen_game_ending (void) {
	vram_adr (NAMETABLE_A);
	
	switch (level) {
		case 0:
		case 1:
			vram_unrle (the_nine_ending_rle);

			p_s (5, 21, "THIS IS THE DREAM TEAM");
			p_s (4, 23, "WHO SHALL WIN THE GAMES!");
			p_s (9, 25, "JUANA Y SERGIO");
			p_s (3, 27, "DOS DEPORTISTAS Y UN AMOWR");
			break;
		case 2:
			vram_unrle (meghan_ending_rle);
			oam_hide_rest (oam_meta_spr (96, 90, 0, spr_ending_meghan_00));
			break;
	}
}
