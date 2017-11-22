// MT MK2 NES v0.2
// Copyleft 2016 by The Mojon Twins

// Code for fixed screens

void enter_screen (const unsigned char *pal, void (*func) (void)) {
	scroll (0, 0);
	
	cls ();
	reset_attributes ();
	(*func) ();
	//show_attributes ();
	
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
	// Logos. Monono: 16x4, Jet Puri: 16x5 metatiles.
	rdy = 24;
	switch (level) {
		case GAME_MONONO:
			vram_adr (NAMETABLE_A);
			vram_unrle (monono_title_rle);
			break;
		case GAME_MONONA:
			vram_adr (NAMETABLE_A);
			vram_unrle (monona_title_rle);
			p_s (16, 19, "[START]  BEGIN");
			if (already_played) p_s (16, 20, "[SELECT] CONT.");
			rdy = 25;
			break;
		case GAME_JET_PURI:
			vram_adr (NAMETABLE_A);
			vram_unrle (jetpuri_title_rle);
			break;
		case GAME_LAH:
			vram_adr (NAMETABLE_A);
			vram_unrle (lah_title_rle);
			break;
		case GAME_PPPP:
			vram_adr (NAMETABLE_A);
			vram_unrle (pppp_title_rle);
			/*p_s (7, 13, "PETULANT PUGSLAY\"S");
			p_s (8, 14, "POWERFUL PARADES");
			*/
			p_s (7, 14, "PETULANT PUGSLAY\"S/ POWERFUL PARADES");
			break;
	}

	if (level != GAME_MONONA) {
		if (already_played && level < GAME_LAH) {
			/*
			p_s (7, 19, "[START]   NEW GAME");
			p_s (7, 20, "[SELECT]  CONTINUE");
			*/
			p_s (7, 19, "[START]   NEW GAME/[SELECT]  CONTINUE");
		} else {
			p_s (10, 19, "PRESS START!");
		}
	}

	/*p_s (5, rdy, "@ 2016 THE MOJON TWINS");
	p_s (6, rdy+1, "PUBLISHED BY XIN XIN");*/
	p_s (5, rdy, "@ 2016 THE MOJON TWINS/ PUBLISHED BY XIN XIN");
}

void screen_game_over (void) {
	p_s (11, 14, "GAME OVER!");
	show_attributes ();
}

void screen_game_ending (void) {
	vram_adr (NAMETABLE_A);
	switch (level) {
		case GAME_MONONO:
			// Small platform
			c_ts_pals = ts0_pals;
			c_ts_tmaps = ts0_tmaps;
			rdx = 8; rdy = 16; rdt = 10; gpjt = 8; while (gpjt --) draw_tile_advance ();
			p_s (13, 8, "MONONO");
			p_s (7, 10, "PLATANONGA NGA NGAS");
			/*
			p_s (6, 20, "NGA DNA DONGO BONGO!");
			p_s (8, 22, "GANGA MOJINGANGA");
			p_s (6, 24, "DEN CAGALERA CHUNGA!");
			*/
			p_s (6, 20, "NGA DNA DONGO BONGO!//  GANGA MOJINGANGA//DEN CAGALERA CHUNGA!");
			oam_meta_spr (124, 111, 4, sspl0_00_a);
			oam_meta_spr (96, 111, 28, ssit0_00);
			oam_meta_spr (144, 111, 44, ssit0_00);
			oam_meta_spr (156, 111, 60, ssit0_00);
			oam_meta_spr (150, 96, 76, ssit0_00);	
			show_attributes ();		
			break;
		case GAME_MONONA:
			/*
			p_s (8, 14, "GOOD JOB, YOU'RE");
			p_s (8, 15, "THE STRONGEST!!!");
			*/
			vram_unrle (monona_ending_rle);
			p_s (13, 14, "GOOD JOB, YOU ARE//THE STRONGEST!!!");
			break;
		case GAME_JET_PURI:
			vram_unrle (jetpuri_ending_rle);
			/*
			p_s (14, 8, "JET PURI!!");
			p_s (14, 10, "YOU MADE IT!");
			p_s (14, 12, "NOW SOMEBODY");
			p_s (14, 14, "SHOULD BUG THE");
			p_s (14, 16, "MOJON TWINS");
			p_s (14, 18, "SO THEY GIVE YA");
			p_s (14, 20, "A PROPER GAME!");
			*/
			p_s (14, 8, "JET PURI!!//YOU MADE IT!//NOW SOMEBODY//SHOULD BUG THE//MOJON TWINS//SO THEY GIVE YA//A PROPER GAME!");
			break;
		case GAME_LAH:
			vram_unrle (lah_ending_rle);
			oam_meta_spr (120, 112, 4, sspl_lah_ending_00);
			oam_meta_spr (120, 112, 28, sspl_lah_ending_01);
			oam_meta_spr (140, 112, 52, sspl_lah_ending_02);
			p_s (14, 10, "CACA");
			break;
		case GAME_PPPP:
			vram_unrle (pppp_ending_rle);
			/*
			p_s (2, 7, "GOSH, YOU MADE IT...");
			p_s (2, 8, "I MEAN IT, WTF?");
			p_s (2, 9, "I NEVER THOUGHT SOMEBODY");
			p_s (2, 10, "WOULD ENDURE THIS GAME");
			p_s (2, 11, "CONGRATULATIONS");
			p_s (2, 12, "THE NEXT COPA DEL MEAO");
			p_s (2, 13, "WILL BE FOR YOU.");
			p_s (2, 14, "TAKE A SCREENSHOT");
			p_s (2, 15, "AND TELL US!");
			*/
			p_s (2, 7, "GOSH, YOU MADE IT.../I MEAN IT, WTF?/I NEVER THOUGHT SOMEBODY/WOULD ENDURE THIS GAME/CONGRATULATIONS/THE NEXT COPA DEL MEAO/WILL BE FOR YOU./TAKE A SCREENSHOT/AND TELL US!");
			oam_meta_spr (142, 120, 4, ssending_pppp_00);
			break;
	}
}
