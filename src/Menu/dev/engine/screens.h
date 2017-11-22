// MT MK2 NES v0.6
// Copyleft 2016 by The Mojon Twins

// Code for fixed screens

void enter_screen (const unsigned char *pal, void (*func) (void)) {
	scroll (0, 0);
	
	cls ();
	reset_attributes ();
	
	rda = 0;
	(*func) ();
	if (rda) show_attributes ();
	
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
	switch (gs) {
		case GM_TRABAJO_BASURA:
			p_s (10, 20, "PRESS START!");
			p_s (5, 24, "@ 2016 THE MOJON TWINS");
			break;
		case GM_VESTA_VAAL:
			p_s (2, 4, "THIS GAME IS AN UNFINISHED,%%EXPERIMENTAL GAME JAM ENTRY%%%     DO NOT DISTRIBUTE.%%%GRAPHICS ARE A PLACE HOLDER%%GAMEPLAY IS AN EXPERIMENT!!%%PRESS A-B-DOWN TO CHANGE.%%      A JUMP, B HIT.%%%       PRESS START!");
			p_s (5, 25, "@ 2016 THE MOJON TWINS");
			break;
	}
}

void screen_game_over (void) {
	p_s (11, 14, "GAME OVER!");
	rda = 1;
}

void screen_game_ending (void) {
	vram_adr (NAMETABLE_A);
	switch (gs) {
		case GM_TRABAJO_BASURA:
			vram_unrle (tb_ending_rle);

			p_s (7, 19, "   AND AT LAST,%%JUSTICE WAS SERVED%% CONGRATULATIONS!");
			break;
		case GM_VESTA_VAAL:
			vram_unrle (vv_qr_rle);
			break;
	}
}

void screen_qr_tb (void) {
	vram_adr (NAMETABLE_A);
	vram_unrle (tb_qr_rle);
}
