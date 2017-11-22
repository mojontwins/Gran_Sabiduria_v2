// MT MK2 NES v0.3
// Copyleft 2016 by The Mojon Twins

// Player movement & stuff

void player_reset_movement (void) {
	pvx = pvy = 0;
	pfixct = pfiring = 0;
	phit = 0;
	pvylast = 0;
}

/*
void player_process_block (signed char x, signed char y, unsigned char direction) {

}
*/

void player_init (void) {
	// Init player data

	px = (signed int) (7 << 4) << FIX_BITS;
	py = (signed int) ((240+12) << 4) << FIX_BITS;
	
	pfacing = pfacingv = CELL_FACING_DOWN;		
	pfacinglast = pfacingh = CELL_FACING_RIGHT;

	player_reset_movement ();

	pkilled = 0;
}

void player_hit (void) {
	// Bla bla
	if (plife) {
		plife --;
		hud_life ();
	} else pkilled = 1;
	pflickering = ticks + ticks;
}

void player_move (void) {
	// Player state
	if (phit) {
		phit --;
		if (!phit) player_hit ();
	}
	if (pflickering) pflickering --;

	evil_tile_hit = 0;
	pcx = px; pcy = py;

	// ********
	// Vertical
	// ********

	// Poll pad
	if (!((pad0 & PAD_UP) || (pad0 & PAD_DOWN)) || pfixct || phit) {
		if (pvy > 0) {
			pvy -= PLAYER_RY; if (pvy < 0) pvy = 0; 
		} else if (pvy < 0) {
			pvy += PLAYER_RY; if (pvy > 0) pvy = 0;
		}
		pfacingv = 0xff;
	}
	
	if (!phit) {
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
	}
	
	// Move
	py += pvy; uin = camera_position << FIX_BITS;
	if (py < uin) py = uin;
	uin += (224 << FIX_BITS);
	if (py > uin) py = uin;

	// Collision
	//prx = px >> FIX_BITS;
	//if (py < 0) { py += (256 << FIX_BITS); pscreenoffs -= 256; }
	//if (py > (256 << FIX_BITS)) { py -= (256 << FIX_BITS); pscreenoffs += 256; }

	pry = py >> FIX_BITS;

	cx1 = prx >> 4;
	cx2 = (prx + 7) >> 4;
	if (pvy) {
		if (pvy < 0) {
			cy1 = cy2 = pry >> 4;
			cm_two_points ();
			if ((at1 & 12) || (at2 & 12)) {
				pvy = 0;
				pry = (cy1 + 1) << 4;
				py = pry << FIX_BITS;
			}
			if ((at1 & 1) || (at2 & 1)) {
				pvy = PLAYER_V_REBOUND_MULTI; evil_tile_hit = 1;
			}
		} else {
			cy1 = cy2 = (pry + 15) >> 4; 
			cm_two_points (); 
	 		if ((at1 & 12) || (at2 & 12)) {
				pvy = 0;
				pry = (cy1 - 1) << 4;
				py = pry << FIX_BITS;
			}
			if ((at1 & 1) || (at2 & 1)) {
				pvy = -PLAYER_V_REBOUND_MULTI; evil_tile_hit = 1;
			}
		}
	}

	// **********
	// Horizontal
	// **********
	
	// Poll pad
	if (!((pad0 & PAD_LEFT) || (pad0 & PAD_RIGHT)) || pfixct || phit) {
		if (pvx > 0) {
			pvx -= PLAYER_RX; if (pvx < 0) pvx = 0;
		} else if (pvx < 0) {
			pvx += PLAYER_RX; if (pvx > 0) pvx = 0;
		}
		pfacingh = 0xff;
	}

	if (!phit) {
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
	}

	// Move
	px += pvx;		
	if (pgotten) px += pgtmx;
	
	// Collision
	if (px < (4<<FIX_BITS)) px = 4<<FIX_BITS;
	else if (px > (244<<FIX_BITS)) px = 244<<FIX_BITS;
	
	prx = px >> FIX_BITS;

	cy1 = pry >> 4;
	cy2 = (pry + 15) >> 4;
	if (pvx) {
		if (pvx < 0) {
			cx1 = cx2 = prx >> 4;
			cm_two_points ();
			if ((at1 & 12) || (at2 & 12)) {
				pvx = 0;
				prx = (cx1 + 1) << 4;
				px = prx << FIX_BITS;
			}
			if ((at1 & 1) || (at2 & 1)) {
				pvx = PLAYER_V_REBOUND_MULTI; evil_tile_hit = 1;
			}
		} else {
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
	}

	// Evil tile (continued)

	if (evil_tile_hit) {
		px = pcx; py = pcy;
		if (!pflickering && !phit) phit = 191;
	}

	// Can't remember

	if (pfixct) pfixct --;

	// Solve facing
	if (pfacingv != 0xff) pfacing = pfacingv; else if (pfacingh != 0xff) pfacing = pfacingh;

	// Shoot

	if (!phit && (pad0 & PAD_A)) {
		if (!pfiring) {
			/*rdmx = rdmy = 0;
			switch (pfacing) {
				case CELL_FACING_LEFT: rdmx = -BULLETS_V; break;
				case CELL_FACING_RIGHT: rdmx = BULLETS_V; break;
				case CELL_FACING_UP: rdmy = -BULLETS_V; break;
				case CELL_FACING_DOWN: rdmy = -BULLETS_V; break;
			}*/

			rda = pfacingh != 0xff ? pfacingh : pfacing;
			rdmx = (rda == CELL_FACING_LEFT) ? -BULLETS_V : ((rda == CELL_FACING_RIGHT ? BULLETS_V : 0));
			rda = pfacingv != 0xff ? pfacingv : pfacing;
			rdmy = (rda == CELL_FACING_UP) ? -BULLETS_V : ((rda == CELL_FACING_DOWN ? BULLETS_V : 0));

			// 20161107 we better fire from the center.
			//rdx = rdmy == -BULLETS_V ? prx + 4 : prx - 2 ; rdy = pry + 3;
			rdx = prx; rdy = pry + 3;

			rda = 0xff;
			bullet_create ();
		} 
		pfiring = 1;
		pfixct = TURRET_FRAMES;
	} else pfiring = 0;

	// Sprite cell selection is usually pretty custom...

	if (phit) {
		if (phit > 63) {
			psprid = CELL_HIT_BASE + ((191 - phit) >> 5);
		}
	} else {
		if (ABS (pvy) > PLAYER_VY_MIN) {
			psprid = CELL_WALK_BASE + ((pry >> 3) & 3);
		} else if (ABS (pvx) > PLAYER_VX_MIN) {
			psprid = CELL_WALK_BASE + ((prx >> 3) & 3);
		} else psprid = CELL_IDLE;

		psprid += pfacing;
	}
}

void player_render (void) {
	//	oam_index = oam_meta_spr (prx, pry + SPRITE_ADJUST - camera_position_lsb, oam_index, spr_player [psprid]);
	
	rda = (pry - camera_position) + SPRITE_ADJUST;

	if (!pflickering || half_life) {
		oam_index = oam_meta_spr (prx, rda, oam_index, spr_player [psprid]);	
	} else {
		oam_index = oam_meta_spr (prx, rda, oam_index, sprplempty);
	}	
}
