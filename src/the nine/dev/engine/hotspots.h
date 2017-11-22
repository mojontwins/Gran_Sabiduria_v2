// Cheril: the Nine
// Copyleft 2016 by The Mojon Twins

// Hotspots

void hotspots_ini (void) {
	gpit = 48/*MAP_W * MAP_H*/; while (gpit --) hact [gpit] = 1;
}

void hotspots_load (void) {
	if (hact [n_pant]) {
		gp_gen = (unsigned char *) c_hotspots + n_pant + n_pant;
		hrt = *gp_gen ++; rda = *gp_gen;
		hry = rda & 0xf0; hrx = rda << 4;
		if (hrt == HOTSPOT_TYPE_OBJECT && game_cheril) hry += 4;
	} else hrt = 0;
}

void hotspots_do (void) {
	if (hrt) {
		if (hr_hit) hr_hit --;

		// Rendering is rather custom in this game
		if (game_cheril) {
			if (hrt == HOTSPOT_TYPE_REFILL) spr_id = 4; else spr_id = ((frame_counter >> 4) & 1) + ((!!hr_hit) << 1);
		} else spr_id = hrt + 4;
		oam_index = oam_meta_spr (hrx, hry + SPRITE_ADJUST, oam_index, spr_items [spr_id]);

		// Check
		if (collide (prx, pry, hrx, hry)) {
			switch (hrt) {
				case HOTSPOT_TYPE_REFILL:
					plife += l_refill [level]; if (plife > 99) plife = 99;
					pnude = 0;
					break;
				case HOTSPOT_TYPE_OBJECT:
					pobjs ++; 
					break;
				case HOTSPOT_TYPE_KEYS:
					pkeys ++;
					break;
				case HOTSPOT_TYPE_CLOTHES:
					pnude = 0;
					break;
			}
			hact [n_pant] = hrt = 0;
			sfx_play (0, SC_LEVEL);
		}
	}
}
