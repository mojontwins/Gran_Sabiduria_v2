// MT MK2 NES v0.4
// Copyleft 2016 by The Mojon Twins

// Code for fixed screens

void enter_screen (const unsigned char *pal, void (*func) (void)) {
	scroll (0, 0);
	
	cls ();
	reset_attributes ();
	
	pal_bg (pal);
	rdd = 1; (*func) ();
	if (rdd) show_attributes ();
	
	ppu_on_all ();
	fade_in ();
}

void exit_cleanly (void) {
	//set_vram_update (0);
	if (!game_rendezvous) music_stop ();
	oam_hide_rest (0);
	fade_out ();
	ppu_off ();	
}

void wait_time_or_input (void) {
	rda = (pad_poll (0) != 0);
	while (game_time) {
		ticker ++; if (ticker == 50) {
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

void twospr (unsigned char x, unsigned char y, const unsigned char *s1, const unsigned char *s2) {
	oam_hide_rest (oam_meta_spr (x, y, oam_meta_spr (x, y, 0, s1), s2));
}

void screen_title (void) {
	switch (level) {
		case GM_POTIPOTI:
			c_ts_pals = ts_potipoti_pals;
			c_ts_tmaps = ts_potipoti_tmaps;
		
			c_map = map_potipoti;
			n_pant = 0; draw_scr ();
		
			// hack: -1, -4, and rdt = 1 so tile 0 is not used (as it is skipped by the routines)
			c_ts_pals = ts_potipoti_logo_pals;
			c_ts_tmaps = ts_potipoti_logo_tmaps;
			
			rdy = 6; rdt = 0;
			gpit = 2; while (gpit --) {
				rdx = 8; 
				gpjt = 8; while (gpjt --) {
					draw_tile_advance (); rdt ++; if (gpjt == 4) rdt -= 4;
				}
				rdy += 2;
			}

			p_s (13, 10, "GRUFAS");
			p_s (10, 20, "PRESS START!");

			break;
		
		case GM_RENDEZVOUS:
			c_ts_pals = ts_rendezvous_pals;
			c_ts_tmaps = ts_rendezvous_tmaps;

			un_rle_screen (scr_title_rendezvous);

			/*
			p_s (10, 21, "PRESS START!");
			p_s (9, 22, "@ 2016 XIN XIN");
			*/
			p_s (9, 21, " PRESS START!%@ 2016 XIN XIN");

			rda = rand8 () & 15; gp_gen = (unsigned char *) texts_rendezvous + (rda << 4) + (rda << 3);
			vram_adr (NAMETABLE_A + 0x84); gpit = 24; while (gpit --) vram_put (*gp_gen ++ - 32);

			break;

		case GM_NAPIA:
			if (egg) {
				p_s (12, 12, " DESTROY THE EGGS%%IN THIS ALIEN CAVE%%%%   PRESS START!");
			} else {
				vram_adr (NAMETABLE_A);
				vram_unrle (napia_title_rle);
				rdd = 0;
			}
			twospr (36, 68, ssti_napia_01, ssti_napia_00);
			/*
			oam_index = 0;
			oam_index = oam_meta_spr (36, 68, oam_index, ssti_napia_01);
			oam_index = oam_meta_spr (36, 68, oam_index, ssti_napia_00);
			oam_hide_rest (oam_index);
			*/
			
			break;
	}
}

void screen_game_over (void) {
	if (game_potipoti) {
		/*
		p_s (10, 14, "POTIPOTI MAL");
		p_s (11, 16, "TRY HARDER");
		*/
		p_s (10, 14, "POTIPOTI MAL%% TRY HARDER");
	} else {
		p_s (11, 14, "GAME OVER!");
	}
}

void screen_game_ending (void) {
	switch (level) {
		case GM_POTIPOTI:
			/*
			p_s (10, 14, "POTIPOTI BIEN!");
			p_s (10, 16, "POTIPOTI LISTO");
			*/
			p_s (10, 14, "POTIPOTI BIEN!%%POTIPOTI LISTO");
			break;
		case GM_RENDEZVOUS:
			if (wins >= 3) {
				pal_bg (palss_rendezvous_ending_alt);
				//un_rle_screen (scr_ending_rendezvous_alt);
				/*
				oam_index = oam_meta_spr (
					112, 63,
					4,
					spr_ending_alt_00);
				oam_index = oam_meta_spr (
					112, 63,
					oam_index,
					spr_ending_alt_01);
				*/
				twospr (112, 63, spr_ending_alt_00, spr_ending_alt_01);
				/*
				p_s (8, 20, "HIC VENIT DIABOLUS");
				p_s (9, 21, "DEFLECTO MACHINA");
				*/
				p_s (8, 20, "HIC VENIT DIABOLUS% DEFLECTO MACHINA");
			} else {
				un_rle_screen (scr_ending_rendezvous);
				/*
				oam_index = oam_meta_spr (
					48, 63,
					4,
					spr_ending_00);
				oam_index = oam_meta_spr (
					48, 63,
					oam_index,
					spr_ending_01);
				*/
				twospr (48, 63, spr_ending_00, spr_ending_01);
			}
			break;
		case GM_NAPIA:
			vram_adr (NAMETABLE_A);
			vram_unrle (napia_ending_rle);
			twospr (64, 84, sste_napia_01, sste_napia_00);
			rdd = 0;
			break;
	}
}
