// Pantanow Engine rev2b 201703
// Copyleft 2016 by The Mojon Twins

// Scroller

void scroll_init (void) {
	// camera_position, map_postn, map_tilepos, gbuffer_y have to be
	// in sync:

	// map_postn = map_tileposR * 8;
	// camera_position = map_tileposR * 16;
	// gbuffer_y = map_tileposR & 0xf;
	// map_tilepos = map_tileposR & 0xff;

	// map_tileposR does not exist. start @ 0 and wrap around.

	// Start with map_flipflop = 0 and update_flag = 1 ALWAYS!
	// Start with scroll_y = 480, the end of the buffer

	camera_position = 4096;		// Camera position in pixels
	scroll_y = 480;				// Viewport position in pixels
	map_postn = 2048;			// Map position in bytes
	map_tilepos = 0;			// Map position in tiles
	map_flipflop = 0;			// Flip, flop...
	update_flag = 1;			// Copy new data!
	gbuffer_y = 0;
}

void scroll_advance (unsigned char pixels) {
	// Update scroll
	scroll_y -= pixels;
	if (scroll_y < 0) scroll_y += 480;	
	scroll (0, scroll_y);
	
	// Update write address
	wtp = (scroll_y >> 3);
	if (wtp < 30) {
		set_scroll_write (0x2000 + (wtp << 5));
		set_attrib_write (0x2300 + attrs_adds [wtp >> 2]);
	} else {
		wtp -= 30;
		set_scroll_write (0x2800 + (wtp << 5));
		set_attrib_write (0x2b00 + attrs_adds [wtp >> 2]);
	}
	if ((wtp >> 1) & 1) {
		at_bm = 0x0f;
		at_sh = 4;
	} else {
		at_bm = 0xf0;
		at_sh = 0;
	}
	
	// Update buffer?
	if (camera_position & 7) {
		update_flag = 1;
	} else {
		if (update_flag) {
			update_flag = 0;
			if (map_flipflop) {
				map_flipflop = 0;
			} else {
				map_flipflop = 1;
				map_postn -= 8;
				map_tilepos --;
				gbuffer_y = (gbuffer_y - 1) & 15;
			}
			
			map_gptr = map_ptr + map_postn;
			a4 = map_flipflop << 1;
			//a4 += ts_base;

			gpp = SCROLL_BUFFER;
			gpr = ATTRIB_BUFFER;
			gpq = SCREEN_BUFFER + (gbuffer_y << 4);
			
#ifdef UNROLLED
			if (a4) {
				// Unrolled
				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_2 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_2 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];

				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_2 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_2 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];

				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_2 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_2 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];

				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_2 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_2 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];

				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_2 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_2 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];

				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_2 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_2 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];

				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_2 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_2 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];

				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_2 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_2 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];
			} else {
				// Unrolled
				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_0 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_0 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];

				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_0 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_0 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];

				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_0 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_0 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];

				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_0 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_0 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];

				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_0 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_0 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];

				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_0 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_0 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];

				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_0 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_0 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];

				a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
				*gpq ++ = a2; *gpq ++ = a3;
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				*gpp ++ = c_ts_tmaps_0 [a2];
				*gpp ++ = c_ts_tmaps_3 [a2];
				*gpp ++ = c_ts_tmaps_0 [a3];
				*gpp ++ = c_ts_tmaps_3 [a3];
			}
#else
			if (a4) {
				gpit = 8; while (gpit --) {
					// Unrolled
					a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
					*gpq ++ = a2; *gpq ++ = a3;
					a5 = *gpr;
					*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
					*gpp ++ = c_ts_tmaps_2 [a2];
					*gpp ++ = c_ts_tmaps_3 [a2];
					*gpp ++ = c_ts_tmaps_2 [a3];
					*gpp ++ = c_ts_tmaps_3 [a3];
				}
			} else {
				gpit = 8; while (gpit --) {
					// Unrolled
					a1 = *map_gptr ++; a2 = (a1 >> 4); a3 = (a1 & 15);
					*gpq ++ = a2; *gpq ++ = a3;
					a5 = *gpr;
					*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
					*gpp ++ = c_ts_tmaps_0 [a2];
					*gpp ++ = c_ts_tmaps_1 [a2];
					*gpp ++ = c_ts_tmaps_0 [a3];
					*gpp ++ = c_ts_tmaps_1 [a3];				
				}
			}
#endif


			/*
			for (gpit = 0; gpit < 8; gpit ++) {
				a1 = *map_gptr ++;
				
				a2 = (a1 >> 4);
				a3 = (a1 & 15);
				
				// Store in our gbuffer!
				*gpq ++ = a2;
				*gpq ++ = a3;
				
				// Modify attribute
				a5 = *gpr;
				*gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
				
				// Calculate char #s
				a2 = a4 + (a2 << 2);
				a3 = a4 + (a3 << 2);
				
				// Draw half tile!
				*gpp ++ = a2;
				*gpp ++ = a2 + 1;
				*gpp ++ = a3;
				*gpp ++ = a3 + 1;				
			}
			*/
		}
	}
	
	// Update position
	camera_position -= pixels;
	camera_position_lsb = LSB(camera_position);
}
