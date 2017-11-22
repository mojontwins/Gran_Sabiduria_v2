		// Change screen
		// Very basic. Extend when needed.

		if (prx == 4 && pvx < 0) {
			n_pant --;
			px = 244 << FIX_BITS;
		} else if (prx == 244 && pvx > 0) {
			n_pant ++;
			px = 4;
		} else if (pry == 0 && pvy < 0 && n_pant >= map_w) {
			n_pant -= map_w;
			py = 192 << FIX_BITS;
			pvy = -PLAYER_VY_JUMP_MAX;
		} else if (pry >= 192 && pvy > 0) {
			n_pant += map_w;
			py = 0;
		}

		if (on_pant != n_pant && do_game) {
			game_prepare_screen ();
			on_pant = n_pant;
		} 
