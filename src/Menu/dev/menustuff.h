// Menu related stuff goes here and doesn't pollute my beautiful MK2 engine.

#define MENU_TOP_Y 8
#define MENU_TOP_X 5

void trainer_run (void) {
	cls ();
	p_s (4, 10, "[A] SELECT PRG ROM");
	p_s (4, 11, "[B] SELECT CHR ROM");
	p_s (4, 12, "[UP/DOWN] CHANGE GS");
	p_s (4, 13, "[START] TO RUN!");
	p_s (4, 15, "PRG [00] CHR [00] GS [00]");

	prg_rom_sel = chr_rom_sel = gs_sel = 0;

	oam_hide_rest (0);
	ppu_on_all ();
	fade_in ();

	set_vram_update (update_list);
	while (1) {
		ul = update_list;

		// Thanks for this, Nicole & nesdev!
		// https://forums.nesdev.com/viewtopic.php?p=179315#p179315
		pad_this_frame = pad0; 
		pad0 = pad_poll (0);
		pad_this_frame = (pad_this_frame ^ pad0) & pad0;

		// What do
		if (pad_this_frame & PAD_UP) {
			gs_sel ++; if (gs_sel == 100) gs_sel = 0;
			p_t2 (26, 15, gs_sel);
		} else if (pad_this_frame & PAD_DOWN) {
			if (gs_sel) gs_sel --;
			p_t2 (26, 15, gs_sel);
		}

		if (pad_this_frame & PAD_A) {
			prg_rom_sel = (prg_rom_sel + 1) & 7;
			p_t2 (9, 15, prg_rom_sel);
		}

		if (pad_this_frame & PAD_B) {
			chr_rom_sel = (chr_rom_sel + 1) & 15;
			p_t2 (18, 15, chr_rom_sel);
		}

		if (pad_this_frame & PAD_START) {
			COMM_GAME_SELECT = gs_sel;
			m113_comm_pool_checksum_write ();
			m113_rom_pair_jump (prg_rom_sel, chr_rom_sel);
		}

		*ul = NT_UPD_EOF;
		ppu_wait_frame ();
	}
	set_vram_update (0);
}

void show_menu_page () {
	// Show text lines from menu_page * 8 to menu_page * 8 + 7
	// That means rendering text from menu_page * 8 * 24 to (menu_page + 1) * 8 * 24 - 1

	// Or drawing 192 characters from menu_page * 192
	// 192 = 128 + 64.

	gp_gen = (unsigned char *) menu_mandanga + (menu_page << 7) + (menu_page << 6);

	rdy = MENU_TOP_Y; rdx = 0; gpit = 192; while (gpit --) {
		if (!rdx) vram_adr (NAMETABLE_A + (rdy << 5) + MENU_TOP_X);
		vram_put (*gp_gen ++ - 32);
		rdx ++; if (rdx == 24) { rdx = 0; rdy += 2; }
	}

	p_s (24, 24, "PAGE ");
	vram_put (menu_page + 17);	
}

void show_menu_frame () {
	// Draws logo & Bottom
	c_ts_tmaps = tslogo_tmaps; c_ts_pals = tslogo_pals;
	rdx = 4; rdy = 2; rdt = 0; gpit = 24; while (gpit --) {
		draw_tile_advance (); rdt ++; if (rdx == 28) { rdx = 4; rdy += 2; }
	}

	/*p_s (9, 26, "#$#$");
	p_s (2, 27, "@ 2016 '&'& AND MOJON TWINS!");
	p_s (8, 28, "VERSION RADASTAN");*/
	p_s (5, 27, "@ 2016 THE MOJON TWINS");
	p_s (5, 28, "@ 2017 1985 ALTERNATIVO");
}

void menu_stars_init () {
	gpit = max_stars; while (gpit --) {
		str_x [gpit] = rand8 () << FIX_BITS;
		str_mx [gpit] = rand8 () & 63;
		str_id [gpit] = 3 + (str_mx [gpit] >> 4);
		do { str_y [gpit] = rand8 (); } while (str_y [gpit] > 232);
	}
}

void menu_stars_frame () {
	gpit = max_stars; while (gpit --) {
		str_x [gpit] -= str_mx [gpit];
		if (str_x [gpit] < 0) str_x [gpit] += (256<<FIX_BITS);

		//oam_spr (str_x [gpit] >> FIX_BITS, str_y [gpit], str_id [gpit], 0x20 + 1, 20 + (gpit << 2));
		oam_index = oam_spr (str_x [gpit] >> FIX_BITS, str_y [gpit], str_id [gpit], 0x20 + 1, oam_index);
	}
}

void menu_do () {
	pal_bg (palts0);
	pal_spr (palss0);

	menu_page = 0;
	pointer_opt = 0;

	cls ();
	reset_attributes ();
	show_menu_frame ();
	show_attributes ();

	max_stars = 32;
	menu_stars_init ();
	oam_index = 20;
	menu_stars_frame ();

	music_play (0);

	while (1) {
		show_menu_page ();
		ppu_on_all ();
		fade_in ();

		launch = 0;

		rdc = pointer_opt;

		while (1) {
			oam_meta_spr (16, (pointer_opt << 4) + 60, 4, hand); 
			oam_index = 20;
			menu_stars_frame ();
			oam_hide_rest (oam_index);

			ppu_wait_frame ();

			pad_this_frame = pad0; 
			pad0 = pad_poll (0);
			pad_this_frame = (pad_this_frame ^ pad0) & pad0;

			if (pad_this_frame & PAD_UP) {
				if (pointer_opt) pointer_opt --; else {
					pointer_opt = 7; menu_page = (menu_page - 1) & 3; break; 
				}
			}

			if (pad_this_frame & PAD_DOWN) {
				pointer_opt ++; if (pointer_opt == 8) {
					pointer_opt = 0; menu_page = (menu_page + 1) & 3; break; 
				}
			}

			if (pad_this_frame & PAD_LEFT) {
				menu_page = (menu_page - 1) & 3; break;
			}

			if (pad_this_frame & PAD_RIGHT) {
				menu_page = (menu_page + 1) & 3; break;
			}

			if (pad_this_frame & (PAD_A | PAD_B | PAD_START)) {
				sfx_play (SFX_START, SC_PLAYER);
				launch = 1; break;
			}

			if (rdc != pointer_opt) {
				rdc = pointer_opt;
				sfx_play (SFX_ENEMY_HIT, SC_PLAYER);
			}
		}

		fade_out ();
		ppu_off ();

		if (launch) {
			music_stop ();
			delay (ticks);			

			rdb = (menu_page << 3) + pointer_opt; 
			if (menu_prg [rdb] == 0xff) {
				trainer_run ();
			} else {
				COMM_GAME_SELECT = menu_gs [rdb];
				m113_comm_pool_checksum_write ();
				m113_rom_pair_jump (menu_prg [rdb], menu_chr [rdb]);
			}
		}

		oam_meta_spr (16, (pointer_opt << 4) + 60, 4, hand);
	}
}
