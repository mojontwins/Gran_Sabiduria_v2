// MT MK2 NES v0.4
// Copyleft 2016 by The Mojon Twins

// General printing functions

void fade_out (void) { fader = 5; while (fader --) { pal_bright (fader); ppu_wait_frame (); } }
	
void fade_in (void) { fader = 5; while (fader --) { pal_bright (4 - fader); ppu_wait_frame (); } }
	
void cls (void) { vram_adr (0x2000); vram_fill (0,0x400); }

void reset_attributes (void) {
	gpit = 64; while (gpit --) attr_table [gpit] = 0x00;
}

void show_attributes (void) {
	if (game_napia) {
		vram_adr (NAMETABLE_A + 0x03c8);
		vram_write (attr_table+8, 48);
	} else {
		vram_adr (NAMETABLE_A + 0x03c0);
		vram_write (attr_table, 64);
	}
}

void write_attr (void) {
	rdc = (rdx >> 2) + ((rdy >> 2) << 3);
	rdb = ((rdx >> 1) & 1) + (((rdy >> 1) & 1) << 1);
	rda = attr_table [rdc];
	rda = (rda & bitmasks [rdb]) | (c_ts_pals [rdt] << (rdb << 1));
	attr_table [rdc] = rda;
}

void update_list_write (unsigned char a) {
	*ul ++ = MSB(gp_addr);
	*ul ++ = LSB(gp_addr++);
	*ul ++ = a;
}

void draw_tile (void) {
#ifdef MAP_DONT_PAINT_TILE_0
	if (!rdt && custom_dont_paint_tile_0) return;
#endif

	write_attr ();
	
	gp_tmap = (unsigned char *) c_ts_tmaps + (rdt << 2);
	gp_addr = ((rdy << 5) + rdx + 0x2000);

	if (mapmode_autoshadows && !scr_attr [gpit] && rdt < 16) {
		vram_adr (gp_addr++);
		vram_put (*((scr_attr [gpit - 17] ? 64 : 0) + gp_tmap));
		gp_tmap ++;
		vram_put (*((scr_attr [gpit - 16] ? 64 : 0) + gp_tmap));
		gp_tmap ++;
		gp_addr += 31;
		vram_adr (gp_addr++);
		vram_put (*((scr_attr [gpit - 1] ? 64 : 0) + gp_tmap));
		gp_tmap ++;
		vram_put (*gp_tmap);
	} else {
		vram_adr (gp_addr++);
		vram_put (*gp_tmap++);
		vram_put (*gp_tmap++);
		gp_addr += 31;
		vram_adr (gp_addr++);
		vram_put (*gp_tmap++);
		vram_put (*gp_tmap);
	}
}

void draw_tile_advance (void) {
	draw_tile (); rdx = (rdx + 2) & 31; if (!rdx) rdy += 2;
}

void update_list_horz_2 () {
	*ul ++ = MSB (gp_addr) | NT_UPD_HORZ;
	*ul ++ = LSB (gp_addr);
	*ul ++ = 2;	
}

void update_list_tile () {
	write_attr ();
	
	gp_addr = 0x23c0 + rdc;
	update_list_write (rda);
	
	// tiles
	gp_tmap = (unsigned char *) c_ts_tmaps + (rdt << 2);
	gp_addr = ((rdy << 5) + rdx + 0x2000);
	update_list_horz_2 ();
	*ul ++ = *gp_tmap ++;
	*ul ++ = *gp_tmap ++;
	gp_addr += 32;
	update_list_horz_2 ();
	*ul ++ = *gp_tmap ++;
	*ul ++ = *gp_tmap;
}

void set_map_tile (unsigned char x, unsigned char y, unsigned char t) {
	rdx = x + x; rdy = y + y + TOP_ADJUST; rdt = t;
	scr_buff [x + (y << 4)] = rdt; scr_attr [x + (y << 4)] = c_behs [rdt];
	update_list_tile ();
}

void p_t1 (unsigned char x, unsigned char y, unsigned char n) {
	gp_addr = NAMETABLE_A + (y << 5) + x;
	update_list_write (DIGIT(n));
}

void p_t2 (unsigned char x, unsigned char y, unsigned char n) {
	gp_addr = NAMETABLE_A + (y << 5) + x;
	update_list_horz_2 ();
	*ul ++ = DIGIT ((n / 10));
	*ul ++ = DIGIT ((n % 10));
}

void advance_worm (void) {
#ifdef MAP_USE_ALT_TILE
	if (rdt == 0 && (rand8 () & 7) == 1) rdt = c_alt_tile;
#endif
	scr_buff [gpit] = rdt; scr_attr [gpit] = c_behs [rdt]; draw_tile_advance (); gpit ++;
}

void draw_scr (void) {
	// Draw current screen
	set_rand (1 + n_pant);

#ifdef MAP_FORMAT_BYTE_RLE
	gp_map = (unsigned char *) c_map [n_pant];
	gpit = 0; rdx = 0; rdy = TOP_ADJUST;
	while (gpit < 192) {
		rdt = *gp_map ++;
		if (rdt & 128) {
			rdt &= 127;
			rdct = *gp_map ++; while (rdct --) advance_worm ();
		} else advance_worm ();
	}
#endif

#ifdef MAP_FORMAT_PACKED
	// n_pant * 96 = n_pant * 64 + n_pant * 32
	gp_map = (unsigned char *) c_map + (n_pant << 6) + (n_pant << 5);
	gpit = 0; rdx = 0; rdy = TOP_ADJUST;
	while (gpit < 192) {
		rdct = *gp_map ++;
		rdt = rdct >> 4; advance_worm ();
		rdt = rdct & 15; advance_worm ();
	}
#endif 

	show_attributes ();
}

/*
void p_s (unsigned char x, unsigned char y, unsigned char *s) {
	vram_adr (NAMETABLE_A + (y << 5) + x);
	while (rda = *s ++) vram_put (rda - 32);
}
*/
void p_s (unsigned char x, unsigned char y, unsigned char *s) {
	vram_adr (NAMETABLE_A + (y << 5) + x);
	while (rda = *s ++) {
		if (rda == '%') {
			y ++; vram_adr (NAMETABLE_A + (y << 5) + x);
		} else vram_put (rda - 32);
	}
}

void un_rle_screen (const unsigned char *rle) {
	rdx = 0; rdy = 0; 
	gpit = 240;

	while (gpit) {
		rdt = (*rle);
		rle ++;
		if (rdt & 128) {
			gpjt = rdt & 127;
			rdt = (*rle);
			rle ++;
			while (gpjt --) {
				draw_tile_advance ();
				gpit --;
			}
		} else {
			draw_tile_advance ();
			gpit --;
		}
	}

	vram_adr (NAMETABLE_A + 0x03c0);
	vram_write ((unsigned char *) rle, 64);
}

// CUSTOM {
void draw_metatile_block (unsigned char ct, unsigned char nt) {
	rdt = nt; while (ct --) draw_tile_advance ();
}

void rendezvous_backdrop (void) {
	rdbg = n_pant >> 3;					// Row of screens
	rdx = 0; rdy = TOP_ADJUST;

	// paint sky
	//gpit = (rdbg + 2) << 4; rdt = 36; while (gpit --) draw_tile_advance ();
	draw_metatile_block ((rdbg + 2) << 4, 36);

	// paint clouds / buildings
	gp_gen = (unsigned char *) rendezvous_bg_metatilemap; 
	gpit = 32; while (gpit --) { rdt = *gp_gen ++; draw_tile_advance (); }

	// paint cyclorama
	//gpit = (8 - rdbg) << 4; rdt = 3; while (gpit --) draw_tile_advance ();
	draw_metatile_block ((8 - rdbg) << 4, 3);
}
// } END_OF_CUSTOM
