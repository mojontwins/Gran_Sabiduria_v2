// MT MK2 NES v0.6
// Copyleft 2016 by The Mojon Twins

// Player movement & stuff

// CUSTOM {
void player_powers (void) {
	if (pstatespradder) {
		// Slow, can fire
		PLAYER_VX_MAX = 24;
		PLAYER_AX = 2;
		PLAYER_RX = 2;
		PLAYER_VY_JUMP_INITIAL = 16;
		PLAYER_AY_JUMP = 7;
		PLAYER_VY_JUMP_MAX = 24;
	} else {
		// Fast, can jump a lot
		PLAYER_VX_MAX = 40;
		PLAYER_AX = 4;
		PLAYER_RX = 8;
		PLAYER_VY_JUMP_INITIAL = 16;
		PLAYER_AY_JUMP = 8;
		PLAYER_VY_JUMP_MAX = 64;
	} 
}
// } END OF CUSTOM

#ifdef PLAYER_DIE_AND_RESPAWN
void player_register_safe_spot (void) {
	safe_px = px; safe_py = py;
	safe_n_pant = n_pant;
}
#endif

void player_reset_movement (void) {
	pvx = pvy = 0;
	pfixct = pfiring = 0;
	phit = 0;
	pvylast = 0;
#ifdef PLAYER_JUMPS	
	pjustjumped = 0;
#endif
#ifdef PLAYER_JETPAC	
	pthrust = 0;
#endif
#ifdef PLAYER_SPINS	
	pspin = 0;
#endif	
#ifdef PLAYER_BUTT
	pbutt = 0;
#endif
}

#ifdef PLAYER_PROCESS_BLOCK
void player_process_block (signed char x, signed char y/*, unsigned char direction*/) {
	if (y) y --;
	rdc = x + (y << 4);
	rda = scr_buff [rdc];
	switch (rda) {
#ifdef PLAYER_PUSH_BOXES		
		case 14:
			// push block
#ifdef PLAYER_GRAVITY
			pbx1 = x;
			if (pad0 & PAD_LEFT) {
				if (x > 0) if (0 == scr_attr [x - 1 + (y << 4)]) pbx1 = x - 1;
			} else if (pad0 & PAD_RIGHT) {
				if (x < 15) if (0 == scr_attr [x + 1 + (y << 4)]) pbx1 = x + 1;
			}
			if (pbx1 != x) {
				set_map_tile (x, y, 0); set_map_tile (pbx1, y, 14);
				sfx_play (SFX_BUTT_HIT, SC_LEVEL);
			}
#endif		
#ifdef PLAYER_GENITAL
			pbx1 = x; pby1 = y;
			if (direction) {
				if (pad0 & PAD_LEFT) {
					if (x > 0) if (0 == scr_attr [x - 1 + (y << 4)]) pbx1 = x - 1;
				} else if (pad0 & PAD_RIGHT) {
					if (x < 15) if (0 == scr_attr [x + 1 + (y << 4)]) pbx1 = x + 1;
				}
			} else {
				if (pad0 & PAD_UP) {
					if (y > 0) if (0 == scr_attr [x + ((y - 1) << 4)]) pby1 = y - 1;
				} else if (pad0 & PAD_DOWN) {
					if (y < 11) if (0 == scr_attr [x + ((y + 1) << 4)]) pby1 = y + 1;
				}
			}
			if (pbx1 != x || pby1 != y) {
				set_map_tile (x, y, 0); set_map_tile (pbx1, pby1, 14);
				sfx_play (SFX_BUTT_HIT, SC_LEVEL);
			}
#endif		
			break;
#endif
#ifdef HOTSPOT_TYPE_KEY			
		case 15:
			// Key hole
			if (pkeys) {
				pkeys --;
				bolts_clear_bolt ();
				set_map_tile (x, y, 0);
				sfx_play (SFX_CHOF, SC_LEVEL);
			}
			break;
#endif				
	}
}
#endif

void player_init (void) {
	// Init player data
	prx = (signed int) (PLAYER_INI_X << 4); px = prx << FIX_BITS;
	pry = (signed int) (PLAYER_INI_Y << 4); py = pry << FIX_BITS;

#ifdef PLAYER_DIE_AND_RESPAWN
	player_register_safe_spot ();
#endif
	
#ifdef PLAYER_GENITAL
	pfacing = pfacingv = CELL_FACING_DOWN;		
	pfacinglast = pfacingh = CELL_FACING_RIGHT;
#else
	pfacing = CELL_FACING_RIGHT;
#endif

	player_reset_movement ();
	pkilled = 0;

	// Custom
	if (game_vesta_vaal) player_powers ();
	pgauge = PGAUGE_MAX;
}

void player_render (void) {
	if (!pflickering || half_life) {
		oam_meta_spr (prx, pry + SPRITE_ADJUST, 4, spr_player [psprid]);	
	} else {
		oam_meta_spr (prx, pry + SPRITE_ADJUST, 4, sprplempty);
	}
}

void player_hit (void) {
	sfx_play (SFX_ENEMY_HIT, SC_PLAYER);

	// Custom
	if (game_vesta_vaal && pgauge >= 6) {
		pgauge -= 6; 
	} else 
	// end_of_custom
	{
		pgauge = 0; ul = update_list; hud_update (); *ul = NT_UPD_EOF;
		ppu_wait_frame ();
#ifdef PLAYER_DIE_AND_RESPAWN
		player_render ();
		music_pause (1);
		delay (60);
		player_reset_movement ();
		music_pause (0);
		px = safe_px; py = safe_py; n_pant = safe_n_pant;
#endif

		if (plife) {
			plife --;
		} else pkilled = 1;
	}

	phit = PLAYER_HIT_FRAMES;
#ifdef PLAYER_FLICKERS
	pflickering = PLAYER_FLICKERS;
#endif
	pwashit = 0;
}

void player_move (void) {
	// custom
	if (pobject) {
		pobject --;
		pad0 = 0;
	}

	// Player state
	if (phit) phit --;
	if (pflickering) pflickering --;

#ifdef ENABLE_EVIL_TILE
	evil_tile_hit = 0;
#endif

#ifdef EVIL_TILE_MULTI
	pcx = px; pcy = py;
#endif

	// ********
	// Vertical
	// ********

#ifdef PLAYER_GRAVITY
	// Gravity
	if (!pgotten
#ifdef PLAYER_JETPAC
		&& !pthrust
#endif
	) {
		if (pvy < PLAYER_VY_FALLING_MAX) pvy += PLAYER_G; else pvy = PLAYER_VY_FALLING_MAX;
	}
#endif

#ifdef PLAYER_GENITAL
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
#endif

	// Move
	py += pvy;

	// Collision
	//prx = px >> FIX_BITS;
	if (py < 0) { py = pry = 0; }
	else if (py > (192<<FIX_BITS)) pry = 192;
	else pry = py >> FIX_BITS;

	cx1 = prx >> 4;
	cx2 = (prx + 7) >> 4;
	if (pvy + pgtmy) {
		if (pvy + pgtmy < 0) {
#ifdef PLAYER_8_PIXELS
			cy1 = cy2 = (pry + 8) >> 4;
#else
			cy1 = cy2 = pry >> 4;
#endif
			cm_two_points ();
			if ((at1 & 8) || (at2 & 8)) {
				pgotten = pvy = 0;
#ifdef PLAYER_8_PIXELS
				pry = ((cy1 + 1) << 4) - 8;
#else
				pry = (cy1 + 1) << 4;
#endif
				py = pry << FIX_BITS;
			}
#ifdef EVIL_TILE_MULTI
			if ((at1 & 1) || (at2 & 1)) {
				pvy = PLAYER_V_REBOUND_MULTI; evil_tile_hit = 1;
			}
#endif
		} else if (pvy + pgtmy > 0)	{
			cy1 = cy2 = (pry + 15) >> 4; 
			cm_two_points (); 
	 		if (((pry - 1) & 15) < 4 && ((at1 & 12) || (at2 & 12))) {
				pgotten = pvy = 0;
				pry = (cy1 - 1) << 4;
				py = pry << FIX_BITS;
			}
#ifdef EVIL_TILE_MULTI
			if ((at1 & 1) || (at2 & 1)) {
				pvy = -PLAYER_V_REBOUND_MULTI; evil_tile_hit = 1;
			}
#endif
		}
#ifdef PLAYER_PROCESS_BLOCK
#ifdef PLAYER_GENITAL		
		if (at1 == 10) player_process_block (cx1, cy1/*, 0*/);
		if (at2 == 10) player_process_block (cx2, cy2/*, 0*/);
#endif		
#endif
	}

#ifdef PLAYER_GRAVITY
	// Floor detections: possee and possibly more in the future.

	cy1 = cy2 = (pry + 16) >> 4;
	cm_two_points ();
	ppossee = ((at1 & 14) || (at2 & 14));
#ifdef PLAYER_JUMPS	
	if (ppossee || pgotten) {
		pjustjumped = 0;
#ifdef PLAYER_DOUBLE_JUMP
		njumps = 0;
#endif		
	}
#endif	
#endif	

	// Evil tile

#ifdef ENABLE_EVIL_TILE
#ifdef EVIL_TILE_ON_FLOOR
	cy1 = cy2 = (pry + 12) >> 4;	// Let it bleed a bit
	cm_two_points ();
	if (at1 == 1 || at2 == 1) evil_tile_hit = 1;
#endif	
#endif

#ifdef PLAYER_JUMPS
	if (pad0 & PAD_A) {
		if (!pjb) {
			pjb = 1;
			if (!pj) {
				if (
					(pgotten || ppossee || phit)
#ifdef PLAYER_DOUBLE_JUMP
					|| (njumps < 2)
#endif
				) {
#ifdef PLAYER_DOUBLE_JUMP					
					if (njumps) {
						fumettos_add ();
						pctj = 2;
					} else
#endif					
					pctj = 0; 
#ifdef PLAYER_DOUBLE_JUMP
					njumps ++;
#endif					
					pj = 1; pjustjumped = 1;
					pvy = -PLAYER_VY_JUMP_INITIAL;
					sfx_play (SFX_JUMP, SC_PLAYER);

#ifdef PLAYER_DIE_AND_RESPAWN
					if (ppossee) {
						player_register_safe_spot ();
					}
#endif					
				}
			} 
		}
		if (pj) {
			rda = PLAYER_AY_JUMP - (pctj >> 2) - (pctj >> 3);
			pvy -= (rda > 1 ? rda : 1);
			if (pvy < -PLAYER_VY_JUMP_MAX) pvy = -PLAYER_VY_JUMP_MAX;
			pctj ++; if (pctj == PLAYER_VY_JUMP_A_STEPS) pj = 0;
		}
	} else pj = pjb = 0;
#endif

#ifdef PLAYER_MONONO
	if (!(pad0 & PAD_A)) { pj = 0; pvylast = -PLAYER_VY_JUMP_INITIAL; } else {
		if (ppossee || pgotten) {
			pvy = SATURATE_N (pvylast - PLAYER_AY_JUMP, -PLAYER_VY_JUMP_MAX);
			pvylast = pvy;
			pj = 1;
			sfx_play (SFX_JUMP, SC_PLAYER);
		}
	}
#endif	

#ifdef PLAYER_JETPAC
	if (pad0 & PAD_A) {
		pvy = SATURATE_N (pvy - PLATER_AY_JETPAC, -PLAYER_VY_JETPAC_MAX);		
		pthrust = 1;
	} else pthrust = 0;
#endif

#ifdef PLAYER_SPINS
	if (!pvy < 0) pspin = 0;
	if (pad0 & PAD_DOWN) {
		if (ppossee && ABS (pvx) > PLAYER_VX_MIN) {
			pspin = 1; sfx_play (SFX_BUTT_FALL, SC_PLAYER);
		}
	}
#endif

	// **********
	// Horizontal
	// **********
	
	// Poll pad
	if (pad0 & PAD_LEFT) {
		if (!pfixct) if (pvx > -PLAYER_VX_MAX) {
			pvx -= PLAYER_AX;			
		}
#ifdef PLAYER_GENITAL
		pfacinglast = pfacingh = CELL_FACING_LEFT;
#else
		pfacing = CELL_FACING_LEFT;
#endif
	} else if (pad0 & PAD_RIGHT) {
		if (!pfixct) if (pvx < PLAYER_VX_MAX) {
			pvx += PLAYER_AX;
		}
#ifdef PLAYER_GENITAL		
		pfacinglast = pfacingh = CELL_FACING_RIGHT;		
#else
		pfacing = CELL_FACING_RIGHT;
#endif		
	} else {
#ifdef PLAYER_SPINS
		if (!pspin)
#endif
		if (pvx > 0) {
			pvx -= PLAYER_RX; if (pvx < 0) pvx = 0;
		} else if (pvx < 0) {
			pvx += PLAYER_RX; if (pvx > 0) pvx = 0;
		}
#ifdef PLAYER_GENITAL
		pfacingh = 0xff;
#endif		
	}

	// Move
	px += pvx;		
	if (pgotten) px += pgtmx;
	
	// Collision
	if (px < (4<<FIX_BITS)) prx = 4;
	else if (px > (244<<FIX_BITS)) prx = 244;
	else prx = px >> FIX_BITS;


#ifdef PLAYER_8_PIXELS
	cy1 = (pry + 8) >> 4;
#else
	cy1 = pry >> 4;
#endif
	cy2 = (pry + 15) >> 4;
	if (pvx + pgtmx) {
		if (pvx + pgtmx < 0) {
			cx1 = cx2 = prx >> 4;
			cm_two_points ();
			if ((at1 & 8) || (at2 & 8)) {
				pvx = 0;
				prx = (cx1 + 1) << 4;
				px = prx << FIX_BITS;
			}
#ifdef EVIL_TILE_MULTI
			if ((at1 & 1) || (at2 & 1)) {
				pvx = PLAYER_V_REBOUND_MULTI; evil_tile_hit = 1;
			}
#endif
		} else if (pvx + pgtmx > 0)	{
			cx1 = cx2 = (prx + 7) >> 4; 
			cm_two_points (); 
	 		if ((at1 & 8) || (at2 & 8)) {
				pvx = 0;
				prx = ((cx1 - 1) << 4) + 8;
				px = prx << FIX_BITS;
			}
#ifdef EVIL_TILE_MULTI
			if ((at1 & 1) || (at2 & 1)) {
				pvx = -PLAYER_V_REBOUND_MULTI; evil_tile_hit = 1;
			}
#endif
		}
#ifdef PLAYER_PROCESS_BLOCK
		if (at1 == 10) player_process_block (cx1, cy1/*, 1*/);
		if (at2 == 10) player_process_block (cx2, cy2/*, 1*/);
#endif
	}

	// Evil tile (continued)

#ifdef ENABLE_EVIL_TILE
	if (evil_tile_hit) {
#ifdef PLAYER_SPINS
		pspin = 0;
#endif
#ifdef PLAYER_JUMPS
		pjustjumped = 0;
#endif

#ifdef EVIL_TILE_ON_FLOOR
		pvy = -PLAYER_V_REBOUND; 
#endif
#ifdef EVIL_TILE_MULTI
		px = pcx; py = pcy;
#endif
		if (
#ifdef PLAYER_FLICKERS
		!pflickering
#else				
		!phit
#endif
		) pwashit = 1; //player_hit ();
	}
#endif	

	// Spinning

#ifdef PLAYER_SPINS
	if (!pvx) pspin = 0;
#endif

	// Can't remember

	if (pfixct) pfixct --;

	// Shoot

#ifdef PLAYER_PUAS
	if (pad0 & PAD_B) {
		if (!pfiring) {
			sfx_play (SFX_SHOOT, SC_PLAYER);
			puas_create ();
		}
		pfiring = 1;
	} else pfiring = 0;
#endif
#ifdef PLAYER_CAN_FIRE
	if (pad0 & PAD_A) {
		if (!pfiring) bullets_fire ();
		pfiring = 1;
		pfixct = TURRET_FRAMES;
		sfx_play (SFX_SHOOT, SC_PLAYER);
	} else pfiring = 0;
#endif	
	
	// Butt

#ifdef PLAYER_BUTT
	if (ppossee || phit) pbutt = 0; else {
		if (pad0 & PAD_B) {
			if (!pbutt) {
				pbutt = 1; pj = 0;
				sfx_play (SFX_BUTT_FALL, SC_PLAYER);			
			}
		}
	}
#endif	

	// Custom Vesta Vaal

	if (game_vesta_vaal && pgauge == PGAUGE_MAX) {
		if ((pad0 & (PAD_A | PAD_B | PAD_DOWN)) == (PAD_A | PAD_B | PAD_DOWN)) {
			sfx_play (SFX_FART, SC_PLAYER); pal_col (0, 0x30); delay (2); pal_col (0, 0x0d);
			pstatespradder = 12 - pstatespradder;
			pgauge = PGAUGE_MAX - PGAUGE_TRANSFORM_PENALTY; 
			player_powers ();
		}
	}
	if ((pad0 & PAD_B) && !hitter_on && pstatespradder) {
		hitter_on = 1; hitter_frame = 0;
		sfx_play (SFX_SHOOT, SC_PLAYER);
	}
	
	// Solve facing
#ifdef PLAYER_GENITAL	
	if (pfacingv != 0xff) pfacing = pfacingv; else if (pfacingh != 0xff) pfacing = pfacingh;
#endif

	// Sprite cell selection is usually pretty custom...

	switch (gs) {
		case GM_TRABAJO_BASURA:
			if (pobject) {
				psprid = CELL_OBJECT;
			} else if (phit) {
				psprid = CELL_HIT;
			} else if (ppossee || pgotten) {
				if (ABS (pvx) > PLAYER_VX_MIN) {
					psprid = CELL_WALK_BASE + ((prx >> 4) & 3);
				} else psprid = CELL_IDLE;
			} else if (pvy < PLAYER_VY_MIN) {
				psprid = CELL_ASCENDING;
			} else psprid = CELL_DESCENDING;

			psprid += pfacing;
			break;
		case GM_VESTA_VAAL:
			if (ppossee || pgotten) {
				if (ABS (pvx) > PLAYER_VX_MIN) {
					psprid = CELL_WALK_BASE + ((prx >> 4) & 3);
				} else psprid = CELL_IDLE;
			} else {
				psprid = CELL_DESCENDING;
			}
			if (hitter_on) psprid += 12;
			psprid += 18 + pstatespradder + pfacing; 
			break;
	}
}
