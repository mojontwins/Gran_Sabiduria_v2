		// Change screen
		// Very basic. Extend when needed.

// CUSTOM {
	if (level) {
// } END_OF_CUSTOM
		if (prx == 4 && pvx < 0) {
			n_pant --;
			px = 244 << FIX_BITS;
		} else if (prx == 244 && pvx > 0) {
			n_pant ++;
			px = 4;
		} else if (pry == 0 && pvy < 0 && n_pant >= MAP_W) {
			n_pant -= MAP_W;
			py = 192 << FIX_BITS;
			//if (pvy > -(PLAYER_VY_JUMP_MAX - (PLAYER_VY_JUMP_MAX >> 1))) pvy = -(PLAYER_VY_JUMP_MAX - (PLAYER_VY_JUMP_MAX >> 1));
			pvy = -PLAYER_VY_JUMP_MAX;
		} else if (pry >= 192 && pvy > 0) {
			n_pant += MAP_W;
			py = 0;
		}

		if (n_pant >= max_pant) n_pant = 0;
// CUSTOM {
	}
// } END_OF_CUSTOM		
		
		if (on_pant != n_pant && do_game) {
			game_prepare_screen ();
			on_pant = n_pant;
		} 
