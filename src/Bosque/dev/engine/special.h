// Special stuff for Cheril of the Bosque en Otro Bosque
// Extremely ugly code ahead. Many things to do and few bytes left...

void ob_init_char_array (void) {
	gpit = 5; while (gpit --) character_order [gpit] = gpit + 1;
	gpit = 10; while (gpit --) {
		rda = rand8 () & 7; if (rda > 4) rda -= 5;
		rdb = rand8 () & 7; if (rdb > 4) rdb -= 5;
		rdc = character_order [rda]; character_order [rda] = character_order [rdb]; character_order [rdb] = rdc;
	}
	character_order_idx = 0;
}

void ob_char_load (void) {
	ob_char_id = 0xff;
	for (gpit = 0; gpit < 6; gpit ++) {
		if (n_pant == ob_char_n_pants [gpit]) {
			ob_char_id = gpit;
			rda = ob_char_yx [gpit];
			ob_char_x = rda << 4; ob_char_y = rda & 0xf0;
		}
	}
}

unsigned char *get_text_pointer (void) {
	// 19 = 16 + 2 + 1
	return (unsigned char *) (texts0 + (rdb << 4) + (rdb << 1) + rdb);
}

void character_talking_self (void) {
	character_talking = (unsigned char *) ob_char_sprites [ob_char_id];
}

void custom_tapestry (void) {
	rdx = 4; rdy = 12; gpjt = 0; rdct = 0; ul = update_list;
	gpit = 48; while (gpit --) {

		rdt = tap ? scr_buff [66 + gpjt ++] : box_buff [gpjt ++]; 
		update_list_tile ();
		rdct = (rdct + 1) & 3; 

		if (!rdct) {
			*ul = NT_UPD_EOF; ppu_wait_frame (); ul = update_list;
		}

		rdx += 2; if (rdx == 28) { rdx = 4; rdy += 2; gpjt += 4; }
	} ppu_wait_frame ();
}

void p_s_upd_show_full (unsigned char x, unsigned char y, unsigned char *s) {
	ul = update_list;
	gp_addr = NAMETABLE_A + (y << 5) + x;
	*ul ++ = MSB (gp_addr) | NT_UPD_HORZ;
	*ul ++ = LSB (gp_addr);
	*ul ++ = 19;
	rdb = 19; while (rdb --) { *ul ++ = *s ++ - 32; }
	*ul = NT_UPD_EOF; ppu_wait_frame ();
}

void text_split (void) {
	// Make a hole
	oam_hide_rest (0);
	tap = 0; custom_tapestry ();

	// Here: Write texts 
	for (gpit = 0; gpit < 4; gpit ++) {
		if (texts [gpit]) p_s_upd_show_full (7, 14 + gpit, texts [gpit]);
	}
	oam_meta_spr (40, 110, 0, character_talking);

	update_list [0] = NT_UPD_EOF;
	rda = (pad_poll (0) != 0); while (1) {
		if (pad_poll (0)) { if (!rda) break; } else rda = 0;
		ppu_wait_frame ();
	}

	// Cover hole
	oam_hide_rest (0);
	tap = 1; custom_tapestry ();
}

void clear_texts (void) {
	gpit = 4; while (gpit --) texts [gpit] = 0;
}

void ob_talk_self (unsigned char *texts0, unsigned char *texts1) {
	character_talking_self ();
	clear_texts (); texts [0] = texts0; texts [1] = texts1;
	text_split ();
}

void ob_char_do (void) {
	if (ob_char_id == 0xff) return;

	oam_index = oam_meta_spr (
		ob_char_x, ob_char_y + SPRITE_ADJUST,
		oam_index,
		ob_char_sprites [ob_char_id]);

	if (collide (prx, pry, ob_char_x, ob_char_y)) {
		px = pcx; py = pcy; player_reset_movement ();
		
		if (character_order_idx < 5) {
			if (character_order [character_order_idx] == ob_char_id || !ob_char_id) {
				// Do the talk
				gp_gen = (unsigned char *) scripts [ob_char_id];
				while ((rdc = *gp_gen ++) != 0xfe) {
					if (rdc == 0xff) character_talking = (unsigned char *) sspl_cheril_00; else character_talking = (unsigned char *) ob_char_sprites [rdc];
					for (gpit = 0; gpit < 4; gpit ++) {
						rdb = *gp_gen ++;
						texts [gpit] = rdb ? get_text_pointer () : 0;
					}
					text_split ();
				}
				// Then
				if (ob_char_id) character_order_idx ++;
				// And refill
				plife += 10;
			} else {
				// I'm Blah
				rdb = ob_char_id; // Used in get_text_pointer
				ob_talk_self (
					(unsigned char *) texts0 + 6 * 19,
					get_text_pointer ()
				);
			}
			// You should now talk to...
			rdb = character_order [character_order_idx];  // Used in get_text_pointer
			ob_talk_self (
				(unsigned char *) texts0 + 7 * 19,
				get_text_pointer ()				
			);
		} else {
			ob_talk_self (
				(unsigned char *) texts0 + 8 * 19,
				(unsigned char *) texts0 + 9 * 19
			);
		}
	}
}
