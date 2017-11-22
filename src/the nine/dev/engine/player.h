// Cheril: the Nine
// Copyleft 2016 by The Mojon Twins

// Player movement & stuff

void player_reset_movement (void) {
	pvx = pvy = 0;
	pfixct = pfiring = 0;
	phit = 0;
}

void player_process_block (signed char x, signed char y, unsigned char direction) {
	rdb = direction;
	rdc = x + (y << 4);
	rda = scr_buff [rdc];
	
	if (scr_buff [rdc] == 15 && pkeys) {
		pkeys --;
		bolts_clear_bolt ();
		set_map_tile (x, y, 0);
		sfx_play (SFX_CHOF, SC_LEVEL);
	}
}

void player_init (void) {
	// Init player data

	prx = l_player_ini_x [level] << 4;
	pry = l_player_ini_y [level] << 4;
	px = prx << FIX_BITS;
	py = pry << FIX_BITS;
	
	pfacing = pfacingv = CELL_FACING_DOWN;		
	pfacinglast = pfacingh = CELL_FACING_RIGHT;
	player_reset_movement ();

	pflickering = pnude = pkilled = 0;
}

void player_hit (void) {
	//phit = PLAYER_HIT_FRAMES;
	if (game_meghan) pflickering = PLAYER_FLICKERING_FRAMES; else pflickering = PLAYER_HIT_FRAMES;

	sfx_play (SFX_ENEMY_HIT, SC_PLAYER);
	
	if (game_meghan && !pnude && !evil_tile_hit) {
		pnude = 1;
	} else if (plife) {
		pnude = 0;
		plife --;
	} else pkilled = 1;
}

void player_move (void) {
	// Player state
	if (phit) phit --;
	if (pflickering) pflickering --;

	evil_tile_hit = 0;
	pcx = px; pcy = py;

	// ********
	// Vertical
	// ********

	// Poll pad
	if (!((pad0 & PAD_UP) || (pad0 & PAD_DOWN)) || pfixct) {
		if (pvy > 0) {
			pvy -= PLAYER_RY; if (pvy < 0) pvy = 0; 
		} else if (pvy < 0) {
			pvy += PLAYER_RY; if (pvy > 0) pvy = 0;
		}
		pfacingv = 0xff;
	}
	
	if (pad0 & PAD_UP) {
		if (!pfixct) if (pvy > -PLAYER_VY_MAX) {
			pvy -= PLAYER_AY;			
		}
		pfacingv = CELL_FACING_UP;
	}
	
	if (pad0 & PAD_DOWN) {
		if (!pfixct) if (pvy < PLAYER_VY_MAX) {
			pvy += PLAYER_AY;
		}
		pfacingv = CELL_FACING_DOWN;		
	}

	// Move
	py += pvy;

	// Collision
	prx = px >> FIX_BITS;
	if (py < 0) pry = 0;
	else if (py > (176<<FIX_BITS)) pry = 176;
	else pry = py >> FIX_BITS;

	cx1 = prx >> 4;
	cx2 = (prx + 7) >> 4;
	if (pvy) {
		if (pvy < 0) {
			cy1 = cy2 = (pry + 8) >> 4;
			cm_two_points ();
			if ((at1 & 12) || (at2 & 12)) {
				pvy = 0;
				pry = ((cy1 + 1) << 4) - 8;
				py = pry << FIX_BITS;
			}
			if ((at1 & 1) || (at2 & 1)) {
				pvy = PLAYER_V_REBOUND_MULTI; evil_tile_hit = 1;
			}
		} else /*if (pvy > 0)*/	{
			cy1 = cy2 = (pry + 15) >> 4; 
			cm_two_points (); 
	 		if ((at1 & 12) || (at2 & 12)) {
				pvy = 0;
				pry = ((cy1 - 1) << 4);
				py = pry << FIX_BITS;
			}
			if ((at1 & 1) || (at2 & 1)) {
				pvy = -PLAYER_V_REBOUND_MULTI; evil_tile_hit = 1;
			}
		}
		if (at1 == 10) player_process_block (cx1, cy1, 0);
		if (at2 == 10) player_process_block (cx2, cy2, 0);
	}

	// **********
	// Horizontal
	// **********
	
	// Poll pad
	if (!((pad0 & PAD_LEFT) || (pad0 & PAD_RIGHT)) || pfixct) {
		if (pvx > 0) {
			pvx -= PLAYER_RX; if (pvx < 0) pvx = 0;
		} else if (pvx < 0) {
			pvx += PLAYER_RX; if (pvx > 0) pvx = 0;
		}
		pfacingh = 0xff;
	}

	if (pad0 & PAD_LEFT) {
		if (!pfixct) if (pvx > -PLAYER_VX_MAX) {
			pvx -= PLAYER_AX;			
		}
		pfacinglast = pfacingh = CELL_FACING_LEFT;
	}
	
	if (pad0 & PAD_RIGHT) {
		if (!pfixct) if (pvx < PLAYER_VX_MAX) {
			pvx += PLAYER_AX;
		}
		pfacinglast = pfacingh = CELL_FACING_RIGHT;		
	}

	// Move
	px += pvx;		
	
	// Collision
	if (px < 0) prx = 0;
	else if (px > (240<<FIX_BITS)) prx = 240;
	else prx = px >> FIX_BITS;

	cy1 = (pry + 8) >> 4;
	cy2 = (pry + 15) >> 4;
	if (pvx) {
		if (pvx < 0) {
			cx1 = cx2 = prx >> 4;
			cm_two_points ();
			if ((at1 & 12) || (at2 & 12)) {
				pvx = 0;
				prx = ((cx1 + 1) << 4);
				px = prx << FIX_BITS;
			}
			if ((at1 & 1) || (at2 & 1)) {
				pvx = PLAYER_V_REBOUND_MULTI; evil_tile_hit = 1;
			}
		} else /*if (pvx > 0)*/	{
			cx1 = cx2 = (prx + 7) >> 4; 
			cm_two_points (); 
	 		if ((at1 & 12) || (at2 & 12)) {
				pvx = 0;
				prx = ((cx1 - 1) << 4) + 8;
				px = prx << FIX_BITS;
			}
			if ((at1 & 1) || (at2 & 1)) {
				pvx = -PLAYER_V_REBOUND_MULTI; evil_tile_hit = 1;
			}
		}
		if (at1 == 10) player_process_block (cx1, cy1, 1);
		if (at2 == 10) player_process_block (cx2, cy2, 1);
	}

	if (evil_tile_hit) {
		px = pcx; py = pcy;
		if (!pflickering) player_hit (); else pvx = pvy = 0;
	}

	if (pfixct) pfixct --;

	if (pad0 & PAD_A) {
		if (!pfiring) bullets_fire ();
		pfiring = 1;
		if (game_cheril) pfixct = TURRET_FRAMES;
	} else pfiring = 0;
	
	// Solve facing
	if (pfacingv != 0xff) pfacing = pfacingv; else if (pfacingh != 0xff) pfacing = pfacingh;
	
	switch (level) {
		case 0:
		case 1:
			// Cheril

			if (phit) {
				psprid = CELL_HIT_BASE + !!pfacingh;
			} else {
				if (pfiring) {
					psprid = CELL_FIRING;
				} else if (ABS (pvy) > PLAYER_VY_MIN) {
					psprid = CELL_WALK_BASE + ((pry >> 4) & 3);
				} else if (ABS (pvx) > PLAYER_VX_MIN) {
					psprid = CELL_WALK_BASE + ((prx >> 4) & 3);
				} else psprid = CELL_IDLE;

				psprid += pfacing;
			}
			break;
		case 2:
			// Meghan

			if (ABS (pvy) > PLAYER_VY_MIN) {
				psprid = CELL_WALK_BASE + ((pry >> 3) & 3);
			} else if (ABS (pvx) > PLAYER_VX_MIN) {
				psprid = CELL_WALK_BASE + ((prx >> 3) & 3);
			} else psprid = CELL_IDLE;

			psprid += pfacing;
			if (pnude) psprid += CELL_ADD_NUDE;

			break;
	}
	psprid += pcellbase;
}

void player_render (void) {
	if (!pflickering || half_life) {
		oam_meta_spr (prx, pry + SPRITE_ADJUST, 4, spr_player [psprid]);	
	} else {
		oam_meta_spr (prx, pry + SPRITE_ADJUST, 4, sprplempty);
	}
}
