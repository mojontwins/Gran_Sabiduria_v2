// MT MK2 NES v0.6
// Copyleft 2016 by The Mojon Twins

// Infested screens!
// QUE FEO! Embonitecer, please.

	if (infested && !generators_active) {
		// Check player position, then close exits!
		if (prx > 16 && prx < 240-16 && pry > 16 && pry < 176-16) {
			// tint
			pal_bg (mypal_game_reds);

			// Fullery
			gpit = 0; rdt = 36; rdx = 0; rdy = TOP_ADJUST;
			for (infsy = 0; infsy < 12; infsy ++) {
				for (infsx = 0; infsx < 16; infsx ++) {
					if (infsy == 0 || infsx == 0 || infsy == 11 || infsx == 15) {
						if (!scr_attr [gpit]) {
							ul = update_list;
							update_list_tile ();
							*ul = NT_UPD_EOF;
							ppu_wait_frame (); delay (4);
							scr_attr [gpit] = 8+16;
						}
					}
					gpit ++; rdx += 2;
				}
				rdy += 2; rdx = 0;
			}

			// palette back
			pal_bg (mypal_game_bg0);

			// Activate generators
			generators_active = 1;
		}
	}

	if (!infested && generators_active) {
		// tint
		pal_bg (mypal_game_reds);

		// New fullery
		gpit = 0; rdx = 0; rdy = TOP_ADJUST;
		for (infsy = 0; infsy < 12; infsy ++) {
			for (infsx = 0; infsx < 16; infsx ++) {
				if (infsy == 0 || infsx == 0 || infsy == 11 || infsx == 15) {
					if (scr_attr [gpit] == 8 + 16) {
						ul = update_list;
						rdt = scr_buff [gpit];
						update_list_tile ();
						*ul = NT_UPD_EOF;
						ppu_wait_frame (); delay (4);
						scr_attr [gpit] = 0;
					}
				}
				gpit ++; rdx += 2;
			}
			rdy += 2; rdx = 0;
		}

		// palette back
		pal_bg (mypal_game_bg0);

		generators_active = 0;
	}
