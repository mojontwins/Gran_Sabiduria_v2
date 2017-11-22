// MT MK2 NES v0.3
// Copyleft 2016 by The Mojon Twins

// Bolts

void bolts_load (void) {
	gpit = n_bolts; while (gpit --) lkact [gpit] = 0;
}

// needs rdc = (y << 4) + x
void bolts_clear_bolt (void) {
	gp_gen = (unsigned char *) c_locks;
	for (gpit = 0; gpit < n_bolts; gpit ++) {
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
	for (gpjt = 0; gpjt < n_bolts; gpjt ++) {
		rda = *gp_gen ++; 	// Screen
		rdb = *gp_gen ++;	// YX
		if (n_pant == rda) {
			if (lkact [gpjt]) {
				scr_buff [rdb] = scr_attr [rdb] = 0;
				rdx = rdb & 0xf; rdx = rdx + rdx;
				rdy = rdb >> 4; rdy = rdy + rdy + TOP_ADJUST;
				draw_tile (); 
				break;
			}
		}
	}
}
