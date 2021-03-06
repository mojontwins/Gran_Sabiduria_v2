// MT MK2 NES v0.4
// Copyleft 2016 by The Mojon Twins

	if (en_gen_washit [gpit]) en_gen_washit [gpit] --;

	if (en_state [gpit]) {
		// Minion on
		if (en_washit [gpit]) en_washit [gpit] --; else	if (!phit && (en_hl [gpit] || half_life) && !en_fishing [gpit]) {
			// Pursue relentlessly
			en_mx [gpit] = ADD_SIGN2 ((prx >> 2) << 2, en_x [gpit], en_v [gpit]);
			en_my [gpit] = ADD_SIGN2 ((pry >> 2) << 2, en_y [gpit], en_v [gpit]);

			// Move, check colision
			// if en_s [gpit] == 0, the minion is a fish, which only collides with 8.
			if (en_s [gpit]) rda = 12; else rda = 8;

			if (en_mx [gpit]) {
				en_x [gpit] += en_mx [gpit];
				
				cy1 = (en_y [gpit] + 8) >> 4; cy2 = (en_y [gpit] + 15) >> 4;
				if (en_mx [gpit] < 0) {
					cx1 = cx2 = (en_x [gpit] + 4) >> 4;
					rdb = ((cx1 + 1) << 4) - 4;
				} else if (en_mx [gpit] > 0) {
					cx1 = cx2 = (en_x [gpit] + 11) >> 4;
					rdb = ((cx1 - 1) << 4) + 4;
				}
				cm_two_points ();
				if ((at1 & rda) || (at2 & rda)) en_x [gpit] = rdb;
			}

			if (en_my [gpit]) {
				en_y [gpit] += en_my [gpit];

				cx1 = (en_x [gpit] + 4) >> 4; cx2 = (en_x [gpit] + 11) >> 4;
				if (en_my [gpit] < 0) {
					cy1 = cy2 = (en_y [gpit] + 8) >> 4;
					rdb = ((cy1 + 1) << 4) - 8;
				} else if (en_my [gpit] > 0) {
					cy1 = cy2 = (en_y [gpit] + 15) >> 4;
					rdb = ((cy1 - 1) << 4);
				}
				cm_two_points ();
				if ((at1 & rda) || (at2 & rda)) en_y [gpit] = rdb;
				
			}

			if ((rand8 () & 0xf) == 2) en_fishing [gpit] = 16 + rand8 () & 0xf;
		}

		if (en_fishing [gpit]) en_fishing [gpit] --;
		spr_id = en_s [gpit] + ((en_mx [gpit] > 0) ? 0 : 2) + ((frame_counter >> 4) & 1);
	} else {
		// Idling
		if (en_ct [gpit]) en_ct [gpit] --; else {

			if (generators_active) { // this is custom
				// Spawn. 
				en_x [gpit] = en_x1 [gpit]; 
				en_y [gpit] = en_y1 [gpit];

				/*
				// Velocities may be .5 1 2 1
				rda = rand8 () & 3;
				if (!rda) { rda = 1; en_hl [gpit] = 0; } else {
					if (rda == 3) rda = 1;
					en_hl [gpit] = 1;
				}
				en_v [gpit] = rda;
				*/
				// Velocities 0.5 1
				en_hl [gpit] = rand8 () & 1;
				en_v [gpit] = 1;

				// Type
				if (en_t [gpit] & 0x0f) {
					en_s [gpit] = 0;
				} else {
					rda = rand8 () & 7; if (rda > 4) rda -= 3;
					en_s [gpit] = 4 + (rda << 2);
				}

				en_state [gpit] = 1;
				en_life [gpit] = TYPE7_MINION_LIFE;
			}

		}

		spr_id = 0xff;
	}

	enems_spr ();
	
