		// Change screen
		// Very basic. Extend when needed.

		if (prx == 0 && pvx < 0) {
			n_pant --;
			px = 240 << FIX_BITS;
		} else if (prx == 240 && pvx > 0) {
			n_pant ++;
			px = 0;
		} else if (pry == 0 && pvy < 0 && n_pant >= map_w) {
			n_pant -= map_w;
			py = 176 << FIX_BITS;
		} else if (pry == 176 && pvy > 0) {
			n_pant += map_w;
			py = 0;
		}
		
		if (on_pant != n_pant && do_game) {
			game_prepare_screen ();
			on_pant = n_pant;
		} 