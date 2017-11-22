// Cheril: the Nine
// Copyleft 2016 by The Mojon Twins

// General printing functions

void fade_out (void) { fader = 5; while (fader --) { pal_bright (fader); ppu_wait_frame (); } }
	
void fade_in (void) { fader = 5; while (fader --) { pal_bright (4 - fader); ppu_wait_frame (); } }
	
void cls (void) { vram_adr (0x2000); vram_fill (0, 0x400); }

void reset_attributes (void) {
	gpit = 64; while (gpit --) attr_table [gpit] = 0;
}

void show_attributes (void) {
	vram_adr (NAMETABLE_A + 0x03c0);
	vram_write (attr_table, 64);
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
	write_attr ();
	
	gp_tmap = (unsigned char *) c_ts_tmaps + (rdt << 2);
	gp_addr = ((rdy << 5) + rdx + 0x2000);
	vram_adr (gp_addr++);
	vram_put (*gp_tmap++);
	vram_put (*gp_tmap++);
	gp_addr += 31;
	vram_adr (gp_addr++);
	vram_put (*gp_tmap++);
	vram_put (*gp_tmap);	
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

void p_t2 (unsigned char x, unsigned char y, unsigned char n) {
	gp_addr = NAMETABLE_A + (y << 5) + x;
	*ul ++ = MSB (gp_addr) | NT_UPD_HORZ;
	*ul ++ = LSB (gp_addr);
	*ul ++ = 2;	
	*ul ++ = DIGIT ((n / 10));
	*ul ++ = DIGIT ((n % 10));
}

void advance_worm (void) {
	if (game_meghan && !rdt && (rand8() & 15) == 1) rdt = 16; // Alt tile
	scr_buff [gpit] = rdt; scr_attr [gpit] = c_behs [rdt]; draw_tile_advance (); gpit ++;
	if (game_meghan && rdt == 16) rdt = 0;
}

void draw_scr (void) {
	// Draw current screen
	set_rand (1 + n_pant);

	gp_map = (unsigned char *) c_map [n_pant];
	gpit = 0; rdx = 0; rdy = TOP_ADJUST;
	while (gpit < 192) {
		rdt = *gp_map ++;
		if (rdt & 128) {
			rdt &= 127;
			rdct = *gp_map ++; while (rdct --) advance_worm ();
		} else advance_worm ();
	}

	// CUSTOM {
	if (n_pant == 35) {
		// QR
		gp_gen = (unsigned char *) meghan_qr_raw;
		rdx = 8; rdy = TOP_ADJUST + 4; 
		vram_adr (NAMETABLE_A + (rdy << 5) + rdx);
		gpit = 0; while (-- gpit) {
			vram_put (*gp_gen ++); rdx ++;
			if (rdx == 24) {
				rdx = 8; rdy ++;
				vram_adr (NAMETABLE_A + (rdy << 5) + rdx);
			}
		} vram_put (*gp_gen);
	}
	// }

	show_attributes ();
}

#ifdef DEBUG
void fill_scr_data (void) {
	rdx = 0; rdy = TOP_ADJUST;
	for (gpit = 0; gpit < 192; gpit ++) {
		ul = update_list;
		p_t2 (rdx, rdy, scr_buff [gpit]);
		p_t2 (rdx, rdy+1, scr_attr [gpit]);
		rdx+=2; if (rdx == 32) {rdx = 0; rdy += 2;}
		*ul = NT_UPD_EOF;
		ppu_wait_frame ();
	}
}
#endif

void p_s (unsigned char x, unsigned char y, unsigned char *s) {
	vram_adr (NAMETABLE_A + (y << 5) + x);
	while (rda = *s ++) vram_put (rda - 32);
}
