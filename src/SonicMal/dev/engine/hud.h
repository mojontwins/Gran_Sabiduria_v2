// MT MK2 NES v0.86 - Sonic Bad is bad
// Copyleft 2017 by The Mojon Twins

// Hud. Of course, this has to be customized for each game
/*
void p_t1 (unsigned char x, unsigned char y, unsigned char n) {
	gp_addr = NAMETABLE_A + (y << 5) + x;
	*ul ++ = MSB (gp_addr);
	*ul ++ = LSB (gp_addr);
	*ul ++ = DIGIT (n);
}
*/
void hud_update (void) {
	if ((!game_somari || level < 2) && plife != oplife) {
		p_t2 (6, 2, plife);
		oplife = plife;
	}

	if (game_sonic && tile_get_ctr != opobjs) {
		p_t2 (0x1d, 2, tile_get_ctr);
		opobjs = tile_get_ctr;
	}
	/*
	if (pkeys != opkeys) {
		p_t2 (0x10, 2, pkeys);
		opkeys = pkeys;
	}
	*/
}

void hud_draw (void) {
	if (!game_somari || level < 2) p_s (1, 2, "LIFE:");
	//p_s (0xb, 2, "KEYS:");
	if (game_sonic) p_s (0x16, 2, "RINGOS:");
}
