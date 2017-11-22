// MT MK2 NES v0.6
// Copyleft 2016 by The Mojon Twins

	// Generatonis
	// Generates stupid enemies which walk, turn, and fall.

	switch (GENERATONI_STATE [gpit]) {
		case 0:
			if (GENERATONI_COUNTER [gpit]) GENERATONI_COUNTER [gpit] --; else {
				GENERATONI_STATE [gpit] = 1;
				GENERATONI_HL [gpit] = (rand8 () & 1);
				en_mx [gpit] = (rand8 () & 1) ? 1 : -1;
			}
			break;
		case 1:
			// General walk.
			rda = en_x [gpit];
			if (!GENERATONI_HL [gpit] || half_life) en_x [gpit] += en_mx [gpit];

			// Detect a state change:
			cx1 = (en_x [gpit] + 4) >> 4; cx2 = (en_x [gpit] + 12) >> 4;
			cy1 = cy2 = (en_y [gpit] + 16) >> 4;
			cm_two_points ();
			if (!(at1 | at2)) {
				GENERATONI_STATE [gpit] = 2;	// Falling
				enf_y [gpit] = en_y [gpit] << FIX_BITS; enf_vy [gpit] = 0;
			}

			cy1 = en_y [gpit] >> 4; cy2 = (en_y [gpit] + 15) >> 4;
			if (en_mx [gpit] < 0) {
				cx1 = cx2 = (en_x [gpit] + 4) >> 4;
			} else {
				cx1 = cx2 = (en_x [gpit] + 12) >> 4;
			}
			cm_two_points ();
			if (at1 || at2 || en_x [gpit] == 0 || en_x [gpit] >= 240) { 
				en_x [gpit] = rda;
				en_mx [gpit] = -en_mx [gpit];
			}
			break;

		case 2:
			enf_vy [gpit] += GENERATONI_G; if (enf_vy [gpit] > GENERATONI_MAXV) enf_vy [gpit] = GENERATONI_MAXV;
			enf_y [gpit] += enf_vy [gpit];
			en_y [gpit] = enf_y [gpit] >> FIX_BITS;

			cx1 = (en_x [gpit] + 4) >> 4; cx2 = (en_x [gpit] + 12) >> 4;
			cy1 = cy2 = (en_y [gpit] + 15) >> 4;

			cm_two_points ();
			if ((at1 & 1) || (at2 & 1)) {
				enems_kill ();
			} else if (at1 || at2) {
				en_y [gpit] = (cy1 - 1) << 4;
				enf_y [gpit] = en_y [gpit] << FIX_BITS;
				GENERATONI_STATE [gpit] = 1;
			}
			break;
	}

	if (GENERATONI_STATE [gpit]) {
		en_facing [gpit] = (en_mx [gpit] > 0) ? 0 : 2;
		spr_id = en_s [gpit] + en_fr + en_facing [gpit];		
	} else {
		if (GENERATONI_COUNTER [gpit] < 60) {
			en_y [gpit] = en_y1 [gpit]; en_x [gpit] = en_x1 [gpit];
			spr_id = 16;
		} else spr_id = 0xff; 
	}
	enems_spr ();
	
