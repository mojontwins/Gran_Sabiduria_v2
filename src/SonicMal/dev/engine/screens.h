// MT MK2 NES v0.86 - Sonic Bad is bad
// Copyleft 2017 by The Mojon Twins

// Code for fixed screens

void enter_screen (const unsigned char *pal, void (*func) (void)) {
	//scroll (0, 472);
	cls ();
	
	pal_bg (pal);
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

	if (game_somari) {
		vram_unrle (title_somari_rle);
		if (level == 2) {
			p_s (5, 12, "    MEMORY SOMARI!//REMEMBER THE ROUTE AND/REACH THE BOTTOM SAFE!");
		} else {
			p_s (9, 13, "S O M A R I  1");
			p_s (10, 8, "COJON TWINS'");
		}
	} else {
		vram_unrle (title_rle);

		if (game_espinete) {
			gp_gen = (unsigned char *) espinete_pegatina;
			for (rdy = 13; rdy < 17; rdy ++) {
				vram_adr (NAMETABLE_A + 13 + (rdy << 5));
				gpit = 6; while (gpit --) vram_put (*gp_gen ++);
			}
		}

		p_s (10, 8, "MOJON TWINS'");
	}

	p_s (10, 18, "PRESS START!");

	vram_adr (NAMETABLE_A + 607); vram_put (63);
}

void screen_game_over (void) {
	// Game over
	p_s (11, 15, "GAME OVER!");
}

void screen_ending (void) {
	if (pemmeralds || game_somari) {
		vram_adr (NAMETABLE_A);
		switch (gs) {
			case 0:
				vram_unrle (ending_rle);

				p_s (4, 19, "SE HA TERMINADO EL FANTA// JO, PERO QUE MAL . . .// MOJON TWINS WISH SONIC//A HAPPY 26TH ANNIVERSARY");

				// Sonic mal
				oam_meta_spr (100, 67, 4, sspla0_01_a);

				// Alex Kidd Mal
				oam_meta_spr (143, 99, 28, ssending_00);

				// Mario Bros Mal
				oam_meta_spr (209, 99, 52, ssending_01);

				// Kirby Mal
				oam_meta_spr (167, 99, 76, ssending_02);

				// Link Mal
				oam_hide_rest (oam_meta_spr (68, 99, 100, ssending_03));
				break;

			case 1:
				vram_unrle (ending_espinete_rle);

				oam_meta_spr (100, 14*8-1, 4, sspla1_01_a);
				oam_hide_rest (oam_meta_spr (148, 14*8-1+4, 28, ssending_04));

				p_s (4, 19, "ESPINETE Y ANA ES MEJOR//   QUE ENRIQUE Y ANA");
				break;

			case 2:
				oam_hide_rest (oam_meta_spr (12*8, 8*8-1, 4, ssendingsomari_00));

				if (level == 1)
					p_s (7, 19, "   SORRY SOMARI//BUT YOUR MSX IS IN//  ANOTHER CASTLE");
				else
					p_s (6, 19, "  A SOMARI LE GUSTA/SER BAJITO PORQUE LOS/ OJOS LE QUEDAN A LA/ ALTURA DE LOS TOTOS");

				break;
		}
	} else {
		p_s (4, 8, "IT SEEMS THAT YOU DIDN'T/  BOTHER TO COLLECT THE/  EMMERALD, SO YOU ARE/  GETTING THE INFAMOUS//    BAD ENDING SCREEN//  DON'T EXPECT ANYTHING/   FLASHIER THAN THIS./   SO NICE TRY, BUT NO/ BANANA, MY DEAR FRIEND.");
	}	
}

void screen_game_level (void) {
	p_s (8, 13, str_levels [level]);
	p_s (11, 16, "GET READY!");
	if (game_espinete) p_s (8, 20, "PRESS B TO SHOOT");
}
