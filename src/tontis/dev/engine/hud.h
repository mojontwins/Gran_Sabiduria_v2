// MT MK2 NES v0.4
// Copyleft 2016 by The Mojon Twins

// Hud. Of course, this has to be customized for each game

void hud_update (void) {
	if (game_potipoti) return;

	

	if (game_napia) {
		if (pobjs != opobjs) p_t2 (16, 2, MAX_HOTSPOTS_NAPIA_TYPE_1 - pobjs);
		if (pkeys != opkeys) p_t1 (29, 2, pkeys);
		if (plife != oplife) p_t1 (4, 2, plife);
	} else if (plife != oplife) p_t2 (7, 2, plife);

	opobjs = pobjs;
	opkeys = pkeys;
	oplife = plife;
}

void hud_draw (void) {
	switch (level) {
		case GM_RENDEZVOUS:
			p_s (0x01, 2, "LIVES:");
			p_s (0x0b, 2, "ATTEMPTS:");
			p_s (0x18, 2, "WINS:");
			break;
		case GM_NAPIA:
			vram_adr (NAMETABLE_A);
			vram_unrle (napia_hud_rle);
			if (egg) p_s (9, 2, "   EGG");
			break;
	}
}
