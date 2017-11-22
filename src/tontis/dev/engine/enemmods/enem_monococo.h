// All hail the monococo!

// Custom version for Sonic Mal

// x1, y1 is where it appears.
// mx is state. my is counter.


	// Counter & state change
	MONOCOCO_COUNTER [gpit] --; if (!MONOCOCO_COUNTER [gpit]) {
		MONOCOCO_STATE [gpit] = (MONOCOCO_STATE [gpit] + 1) & 3; MONOCOCO_COUNTER [gpit] = monococo_state_times [MONOCOCO_STATE [gpit]] - (rand8 () & 0x15);
	}

	// Shoot
	if (MONOCOCO_STATE [gpit] == 2 && MONOCOCO_COUNTER [gpit] == MONOCOCO_FIRE_COCO_AT) {
		rdx = MONOCOCO_X [gpit] + 4; rdy = MONOCOCO_Y [gpit] + 4; simplecoco_aimed_new ();
		sfx_play (SFX_SHOOT, SC_ENEMS);
	}

	// Sprite
	enems_spr ();
	if (!MONOCOCO_STATE [gpit] || (MONOCOCO_STATE [gpit] != 2 && half_life)) spr_id = 0xff; else spr_id = MONOCOCO_CELL_BASE + (MONOCOCO_STATE [gpit] == 2) + (prx < MONOCOCO_X [gpit] ? 2 : 0);

