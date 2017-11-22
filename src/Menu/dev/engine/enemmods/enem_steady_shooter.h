// MT MK2 NES v0.6
// Copyleft 2016 by The Mojon Twins

	// en_mx [gpit] -> time between shots.
	// en_my [gpit] -> direction, where to shoot at.

	if (!ticker) {
		if (en_ct [gpit]) en_ct [gpit] --; else {
			en_ct [gpit] = en_mx [gpit]; 	// reset timer
			rdx = en_x [gpit] + 4;			//
			rdy = en_y [gpit] + 4;			// Coordinates
			rda = en_my [gpit];				// Direction 0 left 1 up 2 right 3 down
			simplecoco_straight_new ();
			sfx_play (SFX_SHOOT, SC_ENEMS);
		}
	}

	spr_id = en_s [gpit];
	enems_spr ();
