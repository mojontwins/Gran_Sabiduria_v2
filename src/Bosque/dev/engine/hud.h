// MT MK2 NES v0.3
// Copyleft 2016 by The Mojon Twins

// Hud. Of course, this has to be customized for each game

void hud_update (void) {
	if (plife != oplife) {
		p_t2 (6, 2, plife);
		oplife = plife;
	}

	if (pobjs != opobjs) {
		p_t2 (0x1d, 2, max_hotspots_type_1 - pobjs);
		opobjs = pobjs;
	}

	if (pkeys != opkeys) {
		p_t2 (0x10, 2, pkeys);
		opkeys = pkeys;
	}

	if (level == GAME_BEGINS) if (muacs_count != omuacs_count) {
		p_t2 (7, 3, 75 - muacs_count); 
		omuacs_count = muacs_count;
	}
}

void hud_draw (void) {
	p_s (1, 2, "LIFE:");
	p_s (0xb, 2, "KEYS:");
	p_s (0x15, 2, "OBJECTS:");

	if (level == GAME_BEGINS) p_s (1, 3, "MUACS:");
}
