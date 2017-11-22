// Cheril: the Nine
// Copyleft 2016 by The Mojon Twins

// Hud

void hud_update (void) {
	if (game_cheril) {
		if (plife != oplife) p_t2 (22, 2, plife); 	
		if (pobjs != opobjs) {
			gp_addr = 0x2000 + 64 + 28;
			update_list_write (DIGIT(pobjs));
		}
	} else {
		if (plife != oplife) p_t2 (5, 2, plife); 
		if (pobjs != opobjs) p_t2 (17, 2, pobjs);
		if (pkeys != opkeys) {
			gp_addr = 0x2000 + 64 + 29;
			update_list_write (DIGIT(pkeys));
		}
		opkeys = pkeys;
	}
	oplife = plife;
	opobjs = pobjs;
}

void hud_draw (void) {
	/*
	if (game_cheril) {
		c_ts_pals = hud_pals;
		c_ts_tmaps = hud_tmaps;
	} else {
		c_ts_pals = hudmeghan_pals;
		c_ts_tmaps = hudmeghan_tmaps;
	}
	rdt = 0; rdx = 0; rdy = 0;
	for (rdt = 0; rdt < 32; rdt ++) draw_tile_advance (); */
	
	vram_adr (NAMETABLE_A);
	vram_unrle (game_cheril ? the_nine_hud_rle : meghan_hud_rle);
}
