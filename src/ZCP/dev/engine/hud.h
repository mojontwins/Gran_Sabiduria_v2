// MT MK2 NES v0.87ZCP - Peyejo pendejo!
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
	if (game_zcp) {
		if (plife != oplife) {
			p_t2 (6, 2, plife);
		}

		if (pobjs != opobjs) {
			p_t2 (12, 2, max_hotspots_type_1 - pobjs);
			opobjs = pobjs;
		}
	} else {
		if (plife != oplife) {
			p_t2 (8, 1, plife);
		}

		if (pbodycount != opbodycount) {
			p_t2 (8, 2, l_body_count [level] - pbodycount);
			opbodycount = pbodycount;
		}
	}

	oplife = plife;
}

void hud_draw (void) {
	if (game_zcp) {
		vram_adr (NAMETABLE_A);
		vram_unrle (zcp_hud_rle);
	} else {
		p_s (2, 1, "\xed\x18\x17\x0d\x0e\xe4\xff"); // LIWES:
		p_s (2, 2, "\x19\x01\x01\x16\x0e\xe4\xff"); // GOONS:
	}
}
