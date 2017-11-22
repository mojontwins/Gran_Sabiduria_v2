void simplecoco_init (void) {
	coco_it = COCOS_MAX; while (coco_it --) {
		coco_flag [coco_it] = 0;
	}
}

#ifdef ENABLE_COCO_AIMED
void simplecoco_aimed_new () {
	// Create coco @ rdx, rdy
	coco_it = COCOS_MAX; while (coco_it --) if (!coco_flag [coco_it]) {
		// Calculate distance
		rda = DELTA (prx, rdx); // dx
		rdb = DELTA (pry, rdy); // dy
		rdc = MIN (rda, rdb);	// MIN (dx, dy)
		rdct = rda + rdb - (rdc >> 1) - (rdc >> 2) + (rdc >> 4);
		
		if (rdct > COCO_FAIR_D) {
			// Shoot towards the player.
			coco_x [coco_it] = rdx << FIX_BITS;
			coco_y [coco_it] = rdy << FIX_BITS;

			// Apply formula. Looks awkward but it's optimized for space and shitty compiler
			gpsint = COCO_V * rda / rdct; coco_vx [coco_it] = ADD_SIGN2 (px, coco_x [coco_it], gpsint);
			gpsint = COCO_V * rdb / rdct; coco_vy [coco_it] = ADD_SIGN2 (py, coco_y [coco_it], gpsint);

			coco_flag [coco_it] = 1;
		}
		
		break;
	}
}
#endif

#ifdef ENABLE_COCO_STRAIGHT
void simplecoco_straight_new () {
	// Create coco @ rdx, rdy, direction rda
	coco_it = COCOS_MAX; while (coco_it --) if (!coco_flag [coco_it]) {
		coco_x [coco_it] = rdx << FIX_BITS;
		coco_y [coco_it] = rdy << FIX_BITS;
		coco_vx [coco_it] = coco_vx_precalc [rda];
		coco_vy [coco_it] = coco_vy_precalc [rda];
		coco_flag [coco_it] = 1;
		break;
	} 
}
#endif

void simplecoco_do (void) {
	coco_it = COCOS_MAX; while (coco_it --) if (coco_flag [coco_it]) {
		// Move
		coco_x [coco_it] += coco_vx [coco_it];
		coco_y [coco_it] += coco_vy [coco_it];

		// Out of bounds
		if (coco_x [coco_it] < 0 || coco_x [coco_it] > 256<<FIX_BITS || coco_y [coco_it] < 0 || coco_y [coco_it] > 192<<FIX_BITS) {
			coco_flag [coco_it] = 0; break;
		}

		rdx = coco_x [coco_it] >> FIX_BITS;
		rdy = coco_y [coco_it] >> FIX_BITS;

		// Render
		oam_index = oam_spr (rdx, rdy + SPRITE_ADJUST, COCO_PATTERN, COCO_PALETTE, oam_index);

		// Collide w/player
		if (rdx >= prx + 1 && rdx <= prx + 7 && rdy + 7 >= pry && rdy <= pry + 12
#ifdef PLAYER_FLICKERS
			&& !pflickering
#else				
			&& !phit
#endif
		) {
			player_hit ();
			coco_flag [coco_it] = 0; 
		}
	} 
}
