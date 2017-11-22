// MT MK2 NES v0.1
// Copyleft 2016 by The Mojon Twins

// General printing functions

void fade_out (void) { fader = 5; while (fader --) { pal_bright (fader); ppu_wait_frame (); } }
	
void fade_in (void) { fader = 5; while (fader --) { pal_bright (4 - fader); ppu_wait_frame (); } }
	
void cls (void) { vram_adr (0x2000); vram_fill (255,0x400); }

void reset_attributes (void) {
	gpit = 64; while (gpit --) attr_table [gpit] = 0xff;
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
	//vram_put (DIGIT (scr_attr [gpit]));gp_tmap++;
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
	rn_pant = n_pant;
	if (inverted_screen) {
		// Map is upside down
		if (n_pant < 6) rn_pant = 12 + n_pant;
		else if (n_pant > 11) rn_pant = n_pant - 12;
	}

	gp_map = (unsigned char *) c_map + (rn_pant << 6) + (rn_pant << 5);	

	if (inverted_screen) {
		for (rdyb = 11; rdyb < 0xff; rdyb --) {
			rdy = TOP_ADJUST + rdyb + rdyb; gpit = rdyb << 4; rdx = 0;
			gpjt = 8; while (gpjt --) {
				rdct = *gp_map ++;
				rdt = rdct >> 4; advance_worm ();
				rdt = rdct & 15; advance_worm ();
			}
		}
	} else {
		gpit = 0; rdx = 0; rdy = TOP_ADJUST;
		while (gpit < 192) {
			rdct = *gp_map ++;
			rdt = rdct >> 4; advance_worm ();
			rdt = rdct & 15; advance_worm ();
		}
	}

#ifdef MAP_WITH_DECORATIONS
	if (c_decos && c_decos [rn_pant]) {
		gp_gen = (unsigned char *) c_decos [rn_pant];
	
		while (rdt = *gp_gen ++) {
			if (rdt & 0x80) {
				rdt &= 0x7F;
				rdct = 1;
			} else {
				rdct = *gp_gen ++;
			}
			while (rdct --) {
				gpit = *gp_gen ++;
				rdx = gpit & 15; 
				rdy = gpit >> 4; if (inverted_screen) {
					rdy = 11 - rdy;
					gpit = (rdy << 4) | rdx;
				}
				rdx = rdx + rdx; rdy = TOP_ADJUST + rdy + rdy;
				advance_worm ();
			}
		}
	}
#endif	
#endif 

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
		if (rda == '/') {
			y ++; vram_adr (NAMETABLE_A + (y << 5) + x);
		} else vram_put (rda - 32);
	}
}
