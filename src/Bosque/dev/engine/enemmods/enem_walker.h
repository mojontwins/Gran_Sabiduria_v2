// MT MK2 NES v0.3
// Copyleft 2016 by The Mojon Twins

// Enem type walker
	if (en_state [gpit]) {
		if (en_x1 [gpit] == en_x [gpit] && en_y1 [gpit] == en_y [gpit]) en_state [gpit] = 0; else {
			if (en_washit [gpit]) en_washit [gpit] --; else if (half_life) {
				en_x [gpit] += en_mx [gpit];
				en_y [gpit] += en_my [gpit];
			}
		}
	} else {
		// Decide new direction
		rda = rand8 () & 3;

		do {
			en_mx [gpit] = en_dx [rda];
			en_my [gpit] = en_dy [rda];

			// Decide range
			rdb = WALKER_EXPRESSION;

			// Trim range & set destination
			rdx = en_x [gpit] >> 4; rdy = en_y [gpit] >> 4;
			rdc = 0; while (rdc < rdb) {
				en_x1 [gpit] = rdx << 4; en_y1 [gpit] = rdy << 4;
				rdx += en_mx [gpit]; rdy += en_my [gpit];
				if (scr_attr [rdx + (rdy << 4)]) break;
				rdc ++;
			}

			// Facing
			en_facing [gpit] = (rda << 1);

			rda ++; rda &= 3;
		} while (en_x1 [gpit] == en_x [gpit] && en_y1 [gpit] == en_y [gpit]);

		en_state [gpit] = 1;
	}

	enems_spr ();
	spr_id = WALKER_BASE_SPRITE + en_fr + en_facing [gpit];
