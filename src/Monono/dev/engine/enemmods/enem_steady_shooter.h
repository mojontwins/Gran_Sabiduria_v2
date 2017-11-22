	// _en_mx -> time between shots.
	// _en_my -> direction, where to shoot at.

	if (!ticker) {
		if (_en_ct) _en_ct --; else {
			_en_ct = _en_mx; 	// reset timer
			rdx = _en_x + 4;			//
			rdy = _en_y + 4;			// Coordinates
			rda = _en_my;				// Direction 0 left 1 up 2 right 3 down
			simplecoco_straight_new ();
			sfx_play (SFX_SHOOT, SC_ENEMS);
		}
	}

	spr_id = en_s [gpit];
	enems_spr ();
