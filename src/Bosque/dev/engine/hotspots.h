// MT MK2 NES v0.3
// Copyleft 2016 by The Mojon Twins

// Hotspots

void hotspots_ini (void) {
	gpit = MAP_W * MAP_H; while (gpit --) hact [gpit] = 1;
}

void hotspots_load (void) {
	if (hact [n_pant]) {
		gp_gen = (unsigned char *) c_hotspots + n_pant + n_pant;
		hrt = *gp_gen ++; rda = *gp_gen;
		hry = rda & 0xf0; hrx = rda << 4;
	} else hrt = 0;
}

void hotspots_do (void) {
	if (hrt) {
		if (hr_hit) hr_hit --;

		oam_index = oam_meta_spr (hrx, hry + SPRITE_ADJUST, oam_index, spr_items [itcelloffset + hrt]);

		// Check
		if (collide (prx, pry, hrx, hry)) {
			switch (hrt) {
#ifdef HOTSPOT_TYPE_REFILL
				case HOTSPOT_TYPE_REFILL:
					plife += LIFE_REFILL; if (plife > 99) plife = 99;
					break;
#endif
#ifdef HOTSPOT_TYPE_OBJECT
				case HOTSPOT_TYPE_OBJECT:
					pobjs ++;
					break;
#endif
#ifdef HOTSPOT_TYPE_KEY
				case HOTSPOT_TYPE_KEY:
					pkeys ++;
					break;
#endif
			}
			sfx_play (0, SC_LEVEL);
			hact [n_pant] = hrt = 0;
		}
	}
}
