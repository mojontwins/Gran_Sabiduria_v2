// MT MK2 NES v0.6
// Copyleft 2016 by The Mojon Twins

// Hud. Of course, this has to be customized for each game

void p_t1 (unsigned char x, unsigned char y, unsigned char n) {
	gp_addr = NAMETABLE_A + (y << 5) + x;
	*ul ++ = MSB (gp_addr);
	*ul ++ = LSB (gp_addr);
	*ul ++ = DIGIT (n);
}

void hud_update (void) {
	switch (gs) {
		case GM_TRABAJO_BASURA:
			if (plife != oplife) {
				//p_t2 (6, 2, plife);
				p_t1 (30, 2, plife);
				oplife = plife;
			}

			if (pobjs != opobjs) {
				p_t2 (20, 3, max_hotspots_type_1 - pobjs);
				opobjs = pobjs;
			}

			if (okilled != flags [COUNT_KILLED_ON_FLAG]) {
				p_t2 (20, 2, 25 - flags [COUNT_KILLED_ON_FLAG]);
			}

			if (pkeys != opkeys) {
				//p_t2 (0x10, 2, pkeys);
				p_t1 (30, 3, pkeys);
				opkeys = pkeys;
			}

			if (flags [ONLY_ONE_OBJECT_FLAG]) oam_index = oam_meta_spr (56, 12, oam_index, ssit_tb_00);
			break;

		case GM_VESTA_VAAL:
			if (pgauge != opgauge) {
				// Number of full saquares
				gp_addr = NAMETABLE_A + 72; // + 8 + 2 * 32
				*ul ++ = MSB (gp_addr) | NT_UPD_HORZ;
				*ul ++ = LSB (gp_addr);
				*ul ++ = 8;
				for (rda = 0; rda < 8; rda ++) {
					*ul ++ = 62 + (rda > pgauge);
				}
				opgauge = pgauge;
			}
			break;
	}
}

void hud_draw (void) {
	/*
	p_s (1, 2, "LIFE:");
	p_s (0xb, 2, "KEYS:");
	p_s (0x15, 2, "OBJECTS:");
	*/

	switch (gs) {
		case GM_TRABAJO_BASURA:
			p_s (1, 2, "CARRY:    BECARIOS:    LIVES:");
			p_s (14, 3, "DISKS:     KEYS:");
			break;
		case GM_VESTA_VAAL:
			p_s (1, 2, "ENERGY:");
			break;
	}
}
