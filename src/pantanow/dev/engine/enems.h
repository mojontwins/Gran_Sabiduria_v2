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

}

void enems_spawn (void) {
	// Spawn a new enemy from the strip 
	// uses map_tilepos from the scroller

	if (strip_pointer [0] && strip_pointer [0] == map_tilepos) {
		// Decode data & create MMMCCCDD XXXXSSSS
		rda = strip_pointer [1]; rdb = strip_pointer [2];
		rdc = rdb << 4;

		if (rdc == 0x30 && full_game == 0) {
			// Pantanow / Desiertow / Azoteaw
		} else if (rdc == 0xe0) {
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
			enlastf [enit] = enctf [enit] = enstate [enit] = enctstate [enit] = enmx [enit] = enmy [enit] = 0;
			enfacing [enit] = enctout [enit] = 0;

			// Boss
			if (enspr [enit] == 0x30) {
				enl [enit] = 3;
			}
		}

		// Advance, regardless
		if (strip_pointer [0]) strip_pointer += 3;
	} 
}

// 8<--------------------------------

void enems_destroy (void) {
	if (_ent != 0xff) encount --;
	ena [enit] = 0;
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
				_enstate = ENS_IDLING;
				_enctstate = rdb;
				break;
			case 0x40:
				// ADVANCE
				_enmx = endx [rdc];
				_enmy = endy [rdc];
				_enctstate = rdt << 4;
				_enstate = ENS_MOVING;
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
		_ent = 1;				// Tweak?
	}
}

void enems_choose_random (void) {
	if ((rand8 () & 0x3) == 1) {
		_enstate = ENS_IDLING;
		_enctstate = (2 + (rand8 () & 3)) << 5;
	} else {
		if (_eny >= camera_position + 224) rda = 6;	// Move upwards!
		else if (_eny < camera_position + 64) rda = rand8 () & 3; 
		else rda = rand8 () & 7;

		_enmx = endx [rda];
		_enmy = endy [rda];
		_enctstate = ((rand8 () & 7) + 1) << 4;
		_enstate = ENS_MOVING;
	}
}

void enems_advance_ctstate (void) {
	if (_enctstate) _enctstate --; else _enstate = ((_ent == 3 && (rand8 () & 7) < 5) ? ENS_PURSUING : ENS_CHOOSING);
}

void enems_do (void) {
	// Out of order
	enit = enstart;
	enjt = ENEMS_MAX; while (enjt --) {
		enit += (ENEMS_MAX-1); if (enit >= ENEMS_MAX) enit -= ENEMS_MAX;
		encollidedx = encollidedy = enmustfire = 0;

		if (ena [enit]) {

			// Local array copies. Saves your butt. 
			#include "engine/enemmods/local_array_copy.h"
			
			if (_enlastf) _enlastf --;

			if (_enctf) _enctf --; else _enctf = ticks + halfticks;

			// Move & collide
			if (_enstate == ENS_MOVING || _enstate == ENS_PURSUING) {
				rdx = _enx;
				_enx += _enmx;

				if (_ent == 4) {
					if (_enx < 4) _enx = 4;
					if (_enx > 244) _enx = 244;
				} else {
					if (_enx < 4) { _enx = 4; _enmx = -_enmx; }
					if (_enx > 244) { _enx = 244; _enmx = -_enmx; }
				}

				if (_enmx) {
					if (_enmx < 0) {
						cx1 = cx2 = _enx >> 4;
					} else {
						cx1 = cx2 = (_enx + 7) >> 4;
					}
					cy1 = _eny >> 4;
					cy2 = (15 + _eny) >> 4;
					cm_two_points ();
					if (at1 || at2) {
						_enx = rdx;
						encollidedx = 1;
					}
				}

				uin = _eny;
				_eny += _enmy;

				if (_enmy) {
					if (_enmy < 0) {
						cy1 = cy2 = _eny >> 4;
					} else {
						cy1 = cy2 = (15 + _eny) >> 4;
					}
					cx1 = _enx >> 4;
					cx2 = (_enx + 7) >> 4;
					cm_two_points ();
					if (at1 || at2) {
						_eny = uin;
						encollidedy = 1;
					}
				}

				if (_eny < camera_position && _enmy == -1) _enmy = 1;	// Hack

				// Collision checks
				if (encollidedx || encollidedy) {
					switch (enc [enit] & 3) {
						case 0:
							// Just stop
							if (encollidedx) _enmx = 0;
							if (encollidedy) _enmy = 0;
							break;
						case 1:
							// Invert axes
							if (encollidedx) _enmx = -_enmx;
							if (encollidedy) _enmy = -_enmy;
							break;
						case 2:
							// Choose direction
							_enmx = _enmy = 0;
							_enstate = ENS_CHOOSING;
							break;
						case 3:
							// ???
							break;
					}
					enmustfire = (enc [enit] & 0x4); 
				}
			}

			// Do it
			if (_ent && _ent != 0xff) {

				// Types 1, 2 & 3
				switch (_enstate) {
					case ENS_CHOOSING: 
						// Choose direction, any type.
						if (_ent == 4) {
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
						if (_ent != 1) enems_advance_ctstate ();
						if (_enmx) rda = (_enx >> 3) & 3; else rda = (_eny >> 3) & 3;
						break;
					case ENS_PURSUING:
						// Only type = 3 will enter this state ever.
						_enmx = ADD_SIGN2 (prx, _enx, 1);
						_enmy = ADD_SIGN2 (pry, _eny, 1);
						if (_enmx) rda = (_enx >> 3) & 3; else rda = (_eny >> 3) & 3;
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
						if (_enctstate) _enctstate --;
						rda = CELL_EN_DYING;
				}

				if (_enstate <= ENS_PURSUING) {
					if (_enmx < 0) _enfacing = CELL_EN_FACING_LEFT;
					if (_enmx > 0) _enfacing = CELL_EN_FACING_RIGHT;
				}
					
				ensprid = _enspr + _enfacing + rda;
			} else {
				if (_enstate == ENS_DYING) {
					if (_enctstate) _enctstate --;
					ensprid = _enspr + 4;
				} else {
					// Type 0 = Turret
					if (pry > _eny) rda = 3; 
					else if (pry < _eny) rda = 2;
					else rda = (prx < _enx);

					ensprid = _enspr + rda;
				}
			}

			// Fire?
			if (!enmustfire && _ent != 4) {
				if (end [enit] & 1) {
					// Every second
					enmustfire = !_enctf;
				} else {
					enmustfire = !(rand8 () & 63); 
				}
			}

			// Fuck a bit
			if (_enstate == ENS_DYING) enmustfire = 0;

			if (_ent == 0xff) {
				enmustfire = 0;
				ensprid = 0x25;
			}

			// Only if into the screen... FIRE!
			if (_eny >= camera_position && _eny <= camera_position + 224) {
				if (enmustfire && !_enlastf) {
					_enlastf = ENEMIES_FIRE_RATE;

					rdx = _enx + 4;
					rdy = _eny + 4;		// TWEAK THIS LATER!

					// Where?
					if (enspr [enit] == 0x30) {
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
						
						_enstate = ENS_FIRING;
						_enctstate = 16;
					} else {
						if (end [enit] & 2) {
							// Towards player
							rds = prx + 32 < _enx ? -1 : (prx > _enx + 32 ? 1 : 0);
							rdmx = ADD_SIGN (rds, BULLETS_VE);
							rds = pry + 32 < _eny ? -1 : (pry > _eny + 32 ? 1 : 0);
							rdmy = ADD_SIGN (rds, BULLETS_VE);
						} else {
							// Same direction as enemy
							if (_ent) {
								rdmx = ADD_SIGN (_enmx, BULLETS_VE);
								rdmy = ADD_SIGN (_enmy, BULLETS_VE);
							} else {
								rdmx = 0; rdmy = BULLETS_VE;
							}
						}
						if (rdmx < 0) _enfacing = CELL_EN_FACING_LEFT;
						if (rdmx > 0) _enfacing = CELL_EN_FACING_RIGHT;

						if (rdmx || rdmy) {
							rda = enit;
							bullet_create ();

							_enstate = ENS_FIRING;
							_enctstate = 16;
						}
					}
				}

				// Reset this
				enctout [enit] = 0;

				// RENDER
				if (enspr [enit] != 0x30 || _enstate != ENS_DYING || half_life)			
					oam_index = oam_meta_spr (
						_enx, _eny - camera_position + SPRITE_ADJUST,
						oam_index,
						spr_enems [ensprid]);
			} else enctout [enit] ++;

			// COLLIDE WITH PLAYER
			if (CLE (prx, pry, _enx, _eny)) {
				if (_ent == 0xff) {
					plife ++;
					hud_life ();
					sfx_play (SFX_GET_ITEM, SC_PLAYER);
					enems_destroy ();
				} else if (!(phit || pflickering)) {
					if (_enx > _eny) {
						pvx = ADD_SIGN2 (prx, _enx, PLAYER_V_REBOUND_MULTI);
					} else {
						pvy = ADD_SIGN2 (pry, _eny, PLAYER_V_REBOUND_MULTI);
					}
					phit = 191;
					_enstate = ENS_DYING; 
					_enctstate = (enspr [enit] == 0x30) ? 100 : 32;
					sfx_play (SFX_CHOF, SC_PLAYER);
				}
			}

			// DESTROY?
			if (enspr [enit] == 0x30) {
				if (_enstate == ENS_DYING && !_enctstate) {
					if (enl [enit]) {
						enl [enit] --;
						_enstate = 0;
					} else enems_destroy ();
				}
			} else if (/*_eny <= camera_position - 32 || */
				_eny >= camera_position + 256 ||
				(_enstate == ENS_DYING && !_enctstate) ||
				enctout [enit] >= 150
			) 
				enems_destroy ();


			// Undo Local array copies. 
			#include "engine/enemmods/local_array_restore.h"
		} 
	}
	enstart ++; if (enstart == ENEMS_MAX) enstart = 0;
}
