// MT MK2 NES v0.6
// Copyleft 2016 by The Mojon Twins

	// Catacrock. Appears, falls, and catacrocks.

	switch (CATACROCK_STATE [gpit]) {
		case 0:
			if (CATACROCK_COUNTER [gpit]) CATACROCK_COUNTER [gpit] --; else {
				CATACROCK_STATE [gpit] = 1;
				enf_y [gpit] = en_y [gpit] << FIX_BITS; enf_vy [gpit] = 0;
			}
			break;
		case 1:
			enf_vy [gpit] += CATACROCK_G; if (enf_vy [gpit] > CATACROCK_MAXV) enf_vy [gpit] = CATACROCK_MAXV;
			enf_y [gpit] += enf_vy [gpit];
			en_y [gpit] = enf_y [gpit] >> FIX_BITS;
			if (en_y [gpit] > en_y2 [gpit]) {
				CATACROCK_STATE [gpit] = 2;
				CATACROCK_COUNTER [gpit] = CATACROCK_CROCK_FRAMES;
				en_y [gpit] = en_y2 [gpit];
			}
			break;
		case 2:
			if (CATACROCK_COUNTER [gpit]) CATACROCK_COUNTER [gpit] --; else {
				CATACROCK_STATE [gpit] = 0;
				CATACROCK_COUNTER [gpit] = CATACROCK_WAIT [gpit];
				en_y [gpit] = en_y1 [gpit];
			}
			break;
	}

	spr_id = CATACROCK_CELL_BASE + CATACROCK_STATE [gpit];
	enems_spr ();
