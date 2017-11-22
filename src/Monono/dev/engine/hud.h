// MT MK2 NES v0.1
// Copyleft 2016 by The Mojon Twins

// Hud. Of course, this has to be customized for each game

void hud_update (void) {
	if (level < GAME_LAH) {
		if (plife != oplife) {
			p_t2 (7, hudbaseline + 1, plife);
			oplife = plife;
		}

		if (pobjs != opobjs) {
			p_t2 (0x1c, hudbaseline, max_hotspots_type_1 - pobjs);
			opobjs = pobjs;
		}

		if (pkeys != opkeys) {
			p_t2 (7, hudbaseline, pkeys);
			opkeys = pkeys;
		}
	} else {
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
	}
}

void hud_draw (void) {
	switch (level) {
		case GAME_MONONO:
			p_s (0x14, hudbaseline, "BANANAS\\");
			p_s (1, hudbaseline + 1, "MONOS\\");
			break;
		case GAME_MONONA:
			p_s (0x14, hudbaseline, "WWFORBS\\");
			p_s (1, hudbaseline + 1, "LIVES\\");
			break;
		case GAME_JET_PURI:
			p_s (0, 24, (unsigned char *) hud1);
			p_s (0, 25, (unsigned char *) hud2);
			p_s (0, 26, (unsigned char *) hud2);
			p_s (0, 27, (unsigned char *) hud3);
			p_s (0x14, hudbaseline, "CRYSTAL\\");
			p_s (1, hudbaseline + 1, "STEEM\\");
			break;
		case GAME_LAH:
		case GAME_PPPP:
			p_s (1, 2, "LIFE:");
			p_s (0xb, 2, "KEYS:");
			p_s (0x15, 2, "OBJECTS:");
			break;
	}
			
	if (level < GAME_LAH) p_s (2, hudbaseline, "KEYS\\");
}
