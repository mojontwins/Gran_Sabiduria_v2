// MT MK2 NES v0.4
// Copyleft 2016 by The Mojon Twins

// Bolts

void bolts_load (void) {
	gpit = BOLTS_MAX; while (gpit --) lkact [gpit] = 0;
}

// needs rdc = (y << 4) + x
void bolts_clear_bolt (void) {
	gp_gen = (unsigned char *) c_locks;
	for (gpit = 0; gpit < BOLTS_MAX; gpit ++) {
		rda = *gp_gen ++; // Screen
		rdb = *gp_gen ++; // YX
		if (n_pant == rda) {
			if (rdc == rdb) {
				lkact [gpit] = 1;
			}
		}
	}
}

void bolts_update_screen (void) {
	rdt = 0; gp_gen = (unsigned char *) c_locks;
	for (gpjt = 0; gpjt < BOLTS_MAX; gpjt ++) {
		rda = *gp_gen ++; 	// Screen
		rdb = *gp_gen ++;	// YX
		if (n_pant == rda) {
			if (lkact [gpjt]) {
				scr_buff [rdb] = scr_attr [rdb] = 0;
				rdx = rdb & 0xf; rdx = rdx + rdx;
				rdy = rdb >> 4; rdy = rdy + rdy + TOP_ADJUST;
				draw_tile (); 
			}
		}
	}
}
