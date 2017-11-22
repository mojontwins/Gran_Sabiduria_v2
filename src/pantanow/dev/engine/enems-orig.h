// Pantanow Engine rev2b 201703
// Copyleft 2016 by The Mojon Twins

// Enemies

void enems_init (void) {
	enit = ENEMS_MAX; while (enit --) {
		ena [enit] = 0; enslots [enit] = enit;
	}
	ensloti = ENEMS_MAX;
	enstart = 0;
	encount = 0;

	enboss = 0xff;
}

void enems_enem_init_values (void) {
	enlastf [enit] = enctf [enit] = enstate [enit] = enctstate [enit] = enmx [enit] = enmy [enit] = 0;
	enfacing [enit] = enctout [enit] = 0;
}

void enems_spawn (void) {
	// Spawn a new enemy from the strip 
	// uses map_tilepos from the scroller

	if (strip_pointer [0] && strip_pointer [0] == map_tilepos) {
		// Decode data & create MMMCCCDD XXXXSSSS
		rda = strip_pointer [1]; rdb = strip_pointer [2];
		rdc = rdb << 4;

		if (rdc == 0xe0) {
			// Scroll locker!
			if (encount) scroll_lock = 1;
		} else if (ensloti) {
			// Find an empty slot
			ensloti --;
			enit = enslots [ensloti];
			ena [enit] = 1;
						
			enx [enit] = rdb & 0xf0;
			eny [enit] = map_tilepos << 4;
			
			enspr [enit] = rdc;

			if (enspr [enit] == 0xf0) {
				// Special: heart.
				ent [enit] = 0xff;
			} else {
				encount ++;

				if ((rda & 0xe0) == 0x80) {
					// Programmed enemy
					ent [enit] = 4;
					enc [enit] = end [enit] = 0;
					enbehptr [enit] = enbehs [rda & 0x1f];
				} else {
					if (rda & 0x80) eny [enit] += 240;
					ent [enit] = (rda >> 5) & 0x3;
					enc [enit] = (rda >> 2) & 0x7;
					end [enit] = rda & 0x3;
				}
			}
			
			if (ent [enit] && ent [enit] != 0xff) enx [enit] += 4; // Cosmetic adjust

			// Init
			enems_enem_init_values ();

			// Boss
			if (enspr [enit] == 0x30) {
				if (full_game) {
					enboss = enit;
					enl [enit] = 5;
				} else enspr [enit] == 0x10;
			}
		}

		// Advance, regardless
		if (strip_pointer [0]) strip_pointer += 3;
	} 
}

void enems_destroy (void) {
	if (ent [enit] != 0xff) encount --;
	ena [enit] = 0;
	if (enspr [enit] == 0x30) enboss = 0xff;	 // Destroy boss
	enslots [ensloti] = enit;
	ensloti ++;
	if (!encount) scroll_lock = 0;
}

void enems_choose_from_behaviour (void) {
	rda = *enbehptr [enit];
	if (rda) {
		enbehptr [enit] ++;

		rdb = rda & 0xc0;			// 0x00, 0x40, 0x80
		rdc = (rda & 0x38) >> 3;
		rdt = rda & 0x07;
		switch (rdb) {
			case 0x00:
				// IDLE
				rdb = 1; while (rdt --) rdb += halfticks;
				enstate [enit] = ENS_IDLING;
				enctstate [enit] = rdb;
				break;
			case 0x40:
				// ADVANCE
				enmx [enit] = endx [rdc];
				enmy [enit] = endy [rdc];
				enctstate [enit] = rdt << 4;
				enstate [enit] = ENS_MOVING;
				break;
			case 0x80:
				// FIRE
				enmustfire = 1;
				end [enit] = rdt;	// Direction
				break;
			case 0xC0:
				// RETURN
				enbehptr [enit] -= rda & 0x3f;
				break;
		}
	} else {
		// Transform
		ent [enit] = 1;				// Tweak?
	}
}

void enems_choose_random (void) {
	if ((rand8 () & 0x3) == 1) {
		enstate [enit] = ENS_IDLING;
		enctstate [enit] = (2 + (rand8 () & 3)) << 5;
	} else {
		if (eny [enit] >= camera_position + 224) rda = 6;	// Move upwards!
		else if (eny [enit] < camera_position + 64) rda = rand8 () & 3; 
		else rda = rand8 () & 7;

		enmx [enit] = endx [rda];
		enmy [enit] = endy [rda];
		enctstate [enit] = ((rand8 () & 7) + 1) << 4;
		enstate [enit] = ENS_MOVING;
	}
}

void enems_advance_ctstate (void) {
	if (enctstate [enit]) enctstate [enit] --; else enstate [enit] = ((ent [enit] == 3 && (rand8 () & 7) < 5) ? ENS_PURSUING : ENS_CHOOSING);
}

void enems_do (void) {
	// Out of order
	enit = enstart;
	enjt = ENEMS_MAX; while (enjt --) {
		enit += (ENEMS_MAX-1); if (enit >= ENEMS_MAX) enit -= ENEMS_MAX;
		encollidedx = encollidedy = enmustfire = 0;

		if (ena [enit]) {
			if (enlastf [enit]) enlastf [enit] --;

			if (enctf [enit]) enctf [enit] --; else enctf [enit] = ticks + halfticks;

			// Move & collide
			if (enstate [enit] == ENS_MOVING || enstate [enit] == ENS_PURSUING) {
				rdx = enx [enit];
				enx [enit] += enmx [enit];

				if (ent [enit] == 4) {
					/*
					if (enx [enit] < 4 || enx [enit] >= 244) {
						enems_destroy ();
						continue;
					}
					*/
					if (enx [enit] < 4) enx [enit] = 4;
					if (enx [enit] > 244) enx [enit] = 244;
				} else {
					if (enx [enit] < 4) { enx [enit] = 4; enmx [enit] = -enmx [enit]; }
					if (enx [enit] > 244) { enx [enit] = 244; enmx [enit] = -enmx [enit]; }
				}

				if (enmx [enit]) {
					if (enmx [enit] < 0) {
						cx1 = cx2 = enx [enit] >> 4;
					} else {
						cx1 = cx2 = (enx [enit] + 7) >> 4;
					}
					cy1 = eny [enit] >> 4;
					cy2 = (15 + eny [enit]) >> 4;
					cm_two_points ();
					if (at1 || at2) {
						enx [enit] = rdx;
						encollidedx = 1;
					}
				}

				uin = eny [enit];
				eny [enit] += enmy [enit];

				if (enmy [enit]) {
					if (enmy [enit] < 0) {
						cy1 = cy2 = eny [enit] >> 4;
					} else {
						cy1 = cy2 = (15 + eny [enit]) >> 4;
					}
					cx1 = enx [enit] >> 4;
					cx2 = (enx [enit] + 7) >> 4;
					cm_two_points ();
					if (at1 || at2) {
						eny [enit] = uin;
						encollidedy = 1;
					}
				}

				if (eny [enit] < camera_position && enmy [enit] == -1) enmy [enit] = 1;	// Hack

				// Collision checks
				if (encollidedx || encollidedy) {
					switch (enc [enit] & 3) {
						case 0:
							// Just stop
							if (encollidedx) enmx [enit] = 0;
							if (encollidedy) enmy [enit] = 0;
							break;
						case 1:
							// Invert axes
							if (encollidedx) enmx [enit] = -enmx [enit];
							if (encollidedy) enmy [enit] = -enmy [enit];
							break;
						case 2:
							// Choose direction
							enmx [enit] = enmy [enit] = 0;
							enstate [enit] = ENS_CHOOSING;
							break;
						case 3:
							// ???
							break;
					}
					enmustfire = (enc [enit] & 0x4); 
				}
			}

			// Do it
			if (ent [enit] && ent [enit] != 0xff) {

				// Types 1, 2 & 3
				switch (enstate [enit]) {
					case ENS_CHOOSING: 
						// Choose direction, any type.
						if (ent [enit] == 4) {
							// Get & parse next byte
							enems_choose_from_behaviour ();
						} else {
							// Random
							enems_choose_random (); 
						}
						rda = 0;
						break;
					case ENS_MOVING:
						// Type 1s don't use a counter.
						if (ent [enit] != 1) enems_advance_ctstate ();
						if (enmx [enit]) rda = (enx [enit] >> 3) & 3; else rda = (eny [enit] >> 3) & 3;
						break;
					case ENS_PURSUING:
						// Only type = 3 will enter this state ever.
						enmx [enit] = ADD_SIGN2 (prx, enx [enit], 1);
						enmy [enit] = ADD_SIGN2 (pry, eny [enit], 1);
						if (enmx [enit]) rda = (enx [enit] >> 3) & 3; else rda = (eny [enit] >> 3) & 3;
						break;
					case ENS_IDLING:
						enems_advance_ctstate ();
						rda = CELL_EN_IDLING + ((frame_counter >> 5) & 1);
						break;
					case ENS_FIRING:
						enems_advance_ctstate ();
						rda = CELL_EN_FIRING;
						break;
					case ENS_DYING:
						if (enctstate [enit]) enctstate [enit] --;
						rda = CELL_EN_DYING;
				}

				if (enstate [enit] <= ENS_PURSUING) {
					if (enmx [enit] < 0) enfacing [enit] = CELL_EN_FACING_LEFT;
					if (enmx [enit] > 0) enfacing [enit] = CELL_EN_FACING_RIGHT;
				}
					
				ensprid = enspr [enit] + enfacing [enit] + rda;
			} else {
				if (enstate [enit] == ENS_DYING) {
					if (enctstate [enit]) enctstate [enit] --;
					ensprid = enspr [enit] + 4;
				} else {
					// Type 0 = Turret
					if (pry > eny [enit]) rda = 3; 
					else if (pry < eny [enit]) rda = 2;
					else rda = (prx < enx [enit]);

					ensprid = enspr [enit] + rda;
				}
			}

			// Fire?
			if (!enmustfire && ent [enit] != 4) {
				if (end [enit] & 1) {
					// Every second
					enmustfire = !enctf [enit];
				} else {
					enmustfire = !(rand8 () & 63); 
				}
			}

			// Fuck a bit
			if (enstate [enit] == ENS_DYING) enmustfire = 0;

			if (ent [enit] == 0xff) {
				enmustfire = 0;
				ensprid = 0x25;
			}

			// Only if into the screen... FIRE!
			if (eny [enit] >= camera_position && eny [enit] <= camera_position + 224) {
				if (enmustfire && !enlastf [enit]) {
					enlastf [enit] = ENEMIES_FIRE_RATE;

					rdx = enx [enit] + 4;
					rdy = eny [enit] + 4;		// TWEAK THIS LATER!

					// Where?
					if (enit == enboss) {
						if (enfirehl) {
							rdmx = BULLETS_VE;
							rdmy = BULLETS_VE;
							bullet_create ();
							rdmy = -BULLETS_VE;
							bullet_create ();
							rdmx = -BULLETS_VE;
							bullet_create ();
							rdmy = BULLETS_VE;
							bullet_create ();							
						} else {
							rdmy = 0;
							rdmx = BULLETS_VE;
							bullet_create ();
							rdmx = -BULLETS_VE;
							bullet_create ();
							rdmx = 0;
							rdmy = BULLETS_VE;
							bullet_create ();
							rdmy = -BULLETS_VE;
							bullet_create ();							
						}
						enfirehl = 1 - enfirehl;
						
						enstate [enit] = ENS_FIRING;
						enctstate [enit] = 16;
					} else {
						if (end [enit] & 2) {
							// Towards player
							rds = prx + 32 < enx [enit] ? -1 : (prx > enx [enit] + 32 ? 1 : 0);
							rdmx = ADD_SIGN (rds, BULLETS_VE);
							rds = pry + 32 < eny [enit] ? -1 : (pry > eny [enit] + 32 ? 1 : 0);
							rdmy = ADD_SIGN (rds, BULLETS_VE);
						} else {
							// Same direction as enemy
							if (ent [enit]) {
								rdmx = ADD_SIGN (enmx [enit], BULLETS_VE);
								rdmy = ADD_SIGN (enmy [enit], BULLETS_VE);
							} else {
								rdmx = 0; rdmy = BULLETS_VE;
							}
						}
						if (rdmx < 0) enfacing [enit] = CELL_EN_FACING_LEFT;
						if (rdmx > 0) enfacing [enit] = CELL_EN_FACING_RIGHT;

						if (rdmx || rdmy) {
							rda = enit;
							bullet_create ();

							enstate [enit] = ENS_FIRING;
							enctstate [enit] = 16;
						}
					}
				}

				// Reset this
				enctout [enit] = 0;

				// RENDER
				if (enit != enboss || enstate [enit] != ENS_DYING || half_life)			
					oam_index = oam_meta_spr (
						enx [enit], eny [enit] - camera_position + SPRITE_ADJUST,
						oam_index,
						spr_enems [ensprid]);
			} else enctout [enit] ++;

			// COLLIDE WITH PLAYER
			if (CLE (prx, pry, enx [enit], eny [enit])) {
				if (ent [enit] == 0xff) {
					plife ++;
					hud_life ();
					sfx_play (SFX_GET_ITEM, SC_PLAYER);
					enems_destroy ();
				} else if (!(phit || pflickering)) {
					if (enx [enit] > eny [enit]) {
						pvx = ADD_SIGN2 (prx, enx [enit], PLAYER_V_REBOUND_MULTI);
					} else {
						pvy = ADD_SIGN2 (pry, eny [enit], PLAYER_V_REBOUND_MULTI);
					}
					phit = 191;
					enstate [enit] = ENS_DYING; 
					enctstate [enit] = 32;
					sfx_play (SFX_CHOF, SC_PLAYER);
				}
			}

			// DESTROY?
			if (enit == enboss) {
				if (enstate [enit] == ENS_DYING && !enctstate [enit]) {
					if (enl [enit]) {
						enl [enit] --;
						enems_enem_init_values ();
					} else enems_destroy ();
				}
			} else if (/*eny [enit] <= camera_position - 32 || */
				eny [enit] >= camera_position + 256 ||
				(enstate [enit] == ENS_DYING && !enctstate [enit]) ||
				enctout [enit] >= 150
			) 
				enems_destroy ();
		} 
	}
	enstart ++; if (enstart == ENEMS_MAX) enstart = 0;
}
