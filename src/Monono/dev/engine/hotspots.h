// MT MK2 NES v0.1
// Copyleft 2016 by The Mojon Twins

// Hotspots

void hotspots_ini (void) {
	gpit = MAP_W * MAP_H; while (gpit --) hact [gpit] = 1;
}

void hotspots_load (void) {
	if (hact [rn_pant]) {
		gp_gen = (unsigned char *) c_hotspots + rn_pant + rn_pant;
		hrt = *gp_gen ++; rda = *gp_gen;
		hry = rda & 0xf0; hrx = rda << 4;
		if (game_jet_puri && hrt == HOTSPOT_TYPE_KEY) hrt = HOTSPOT_TYPE_REFILL;
		if (inverted_screen) hry = 208 - hry;
		//if (hrt == HOTSPOT_TYPE_OBJECT) hry += 4;
	} else hrt = 0;
}

void hotspots_do (void) {
	if (hrt) {
		if (hr_hit) hr_hit --;

		// Rendering is rather custom in this game
		// if (hrt == HOTSPOT_TYPE_REFILL) spr_id = 4; else spr_id = ((frame_counter >> 4) & 1) + ((!!hr_hit) << 1);
		///oam_index = oam_meta_spr (hrx, hry + SPRITE_ADJUST, oam_index, spr_items [spr_id]);
		oam_index = oam_meta_spr (hrx, hry + SPRITE_ADJUST, oam_index, spr_items [itcelloffset + hrt]);
		//p_t2 (1,1,level);p_t2(5,1,hrt);

		// Check
		if (collide (prx, pry, hrx, hry)) {
			switch (hrt) {
#ifdef HOTSPOT_TYPE_REFILL
				case HOTSPOT_TYPE_REFILL:
					plife ++; if (plife > 9) plife = 9;
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
			hact [rn_pant] = hrt = 0;
		}
	}
}
