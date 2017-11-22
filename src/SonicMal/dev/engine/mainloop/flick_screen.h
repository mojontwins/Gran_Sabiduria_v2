		// Change screen
		// Very basic. Extend when needed.

		// CUSTOM {
		if (!(custom_on_off & FLAG_MAP_ONE_COLUMN)) {
			if (prx == 4 && pvx < 0) {
				n_pant --;
				px = 244 << FIX_BITS;
			} else if (prx == 244 && pvx > 0) {
				n_pant ++;
				px = 8<<FIX_BITS;
			} 
		} 

		if (pry == 0 && pvy < 0
#ifdef MAP_CHECK_TOP
			&& n_pant >= map_w
#endif
		) {
			n_pant -= map_w;
			py = 192<<FIX_BITS;
#if defined (PLAYER_JUMPS) || defined (PLAYER_MONONO)
		
#ifdef ENABLE_WATER
			if (pwater) pvy = -PLAYER_VY_FLICK_TOP_SWIMMING; else
#endif
			{ pvy = -PLAYER_VY_FLICK_TOP; pj = 0; }
#endif
		} else if (pry >= 192 && pvy > 0) {
			n_pant += map_w;
			py = 0;
		}

		if (on_pant != n_pant && do_game) {
			game_prepare_screen ();
			on_pant = n_pant;
		} 
