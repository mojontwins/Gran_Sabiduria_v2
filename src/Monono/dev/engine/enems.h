// MT MK2 NES v0.1
// Copyleft 2016 by The Mojon Twins

// Enems

#ifdef PERSISTENT_ENEMIES
void persistent_enems_load (void) {
	gp_gen = (unsigned char *) (c_enems);
	for (ep_it = 0; ep_it < 3 * MAP_W * MAP_H; ep_it ++) {
		// Skip t
		gp_gen ++;

		// YX1
		rda = *gp_gen ++;
		ep_y [ep_it] = rda & 0xf0;
		if (inverted_screen) ep_y [ep_it] = 208 - ep_y [ep_it]; // Upside down
		ep_x [ep_it] = (rda << 4);

		// YX2
		rda = *gp_gen ++;
		rdc = rda & 0xf0;
		if (inverted_screen) rdc = 208 - rdc; // Upside down
		rdb = rda << 4;

		// P, here used for speed
		rda = *gp_gen ++;
		if (rda > 1) rda >>= 1;
		ep_mx [ep_it] = ADD_SIGN2 (rdb, ep_x [ep_it], rda);
		ep_my [ep_it] = ADD_SIGN2 (rdc, ep_y [ep_it], rda);	
	}
}

void persistent_update (void) {
	if (on_pant != 99) {
		for (gpit = 0; gpit < 3; gpit ++) {
			ep_x [enoffs] = en_x [gpit];
			ep_y [enoffs] = en_y [gpit];
			ep_mx [enoffs] = en_mx [gpit];
			ep_my [enoffs] = en_my [gpit];	
			enoffs ++;		
		}	
	}
}
#endif

#if defined(ENEMIES_CAN_DIE) && defined(PERSISTENT_DEATHS)
void enems_persistent_deaths_init (void) {
	gpit = MAP_W * MAP_H * N_ENEMS; while (gpit --) ep_flags [gpit] &= 0xfe;
}
#endif

#ifdef ENABLE_TYPE_7	
void enems_type_7_reset (void) {
	en_state [gpit] = 0;
	en_ct [gpit] = TYPE7_SPAWN_TIME;
}
#endif

void enems_load (void) {
	infested = 0;	// Type 7s active?
	// Each screen holds 3 enemies, each enemy takes 4 bytes, so:
	gp_gen = (unsigned char *) (c_enems + (rn_pant << 3) + (rn_pant << 2));
	rdc = enoffs = rn_pant + rn_pant + rn_pant;
	for (gpit = 0; gpit < 3; gpit ++) {
#ifdef ENEMIES_CAN_DIE		
		// Kill enemy
		if (ep_flags [rdc] & 1) {
			en_t [gpit] = 0;	// Inactive
			gp_gen += 4; 		// Next enemy
		} else 
#endif		
		{
			// T YX1 YX2 P
			// Type 
			rda = *gp_gen ++;
			en_t [gpit] = rda; rdt = en_t [gpit] & 0xf0;

// CUSTOM {
			// This converts shooters to linear for JET_PURI
			if (game_jet_puri) {
				switch (rdt) {
					case 0x80:
						en_t [gpit] = (en_t [gpit] & 0x0f) | 0x10;
						break;
					case 0x20:
						en_t [gpit] = 0x12;
						break;
				}
				rdt = 0x10;
			}
// } END_OF_CUSTOM

#ifdef PERSISTENT_ENEMIES
			// YX1
			rdb = *gp_gen ++;
			en_x1 [gpit] = rdb << 4;
			en_y1 [gpit] = rdb & 0xf0;
			if (inverted_screen) en_y1 [gpit] = 208 - en_y1 [gpit]; // Upside down

			// YX2
			rdb = *gp_gen ++;
			en_x2 [gpit] = rdb << 4;
			en_y2 [gpit] = rdb & 0xf0;
			if (inverted_screen) en_y2 [gpit] = 208 - en_y2 [gpit]; // Upside down

			// Attribute
			rdb = *gp_gen ++;

			// But...
			en_x [gpit] = ep_x [rdc];
			en_y [gpit] = ep_y [rdc];
#else
			// YX1
			rdb = *gp_gen ++;
			en_x1 [gpit] = en_x [gpit] = rdb << 4;
			en_y1 [gpit] = en_y [gpit] = rdb & 0xf0;

			// YX2
			rdb = *gp_gen ++;
			en_x2 [gpit] = rdb << 4;
			en_y2 [gpit] = rdb & 0xf0;

			// Attribute
			rdb = *gp_gen ++;
#endif
			en_state [gpit] = 0;

			// Custom as per type
			switch (rdt) {
#ifdef ENABLE_LINEAR
				case 0x10:
				case 0x20:
					en_s [gpit] = (en_t [gpit] & 0x0f) << 2;
					
#ifdef PERSISTENT_ENEMIES
					en_mx [gpit] = ep_mx [rdc];
					en_my [gpit] = ep_my [rdc];
					if (rdb == 1) {
						en_state [gpit] = 1;
					} 
#else
					if (rdb == 1) {
						en_state [gpit] = 1;
					} else {
						rdb >>= 1;
					}
					en_mx [gpit] = ADD_SIGN2 (en_x2 [gpit], en_x1 [gpit], rdb);
					en_my [gpit] = ADD_SIGN2 (en_y2 [gpit], en_y1 [gpit], rdb);
#endif
					break;
#endif		
#ifdef ENABLE_TYPE_7				
				case 0x70:
					en_gen_life [gpit] = TYPE7_GENERATOR_LIFE;
					enems_type_7_reset ();
					en_gen_washit [gpit] = 0;
					infested ++;
					break;
#endif
#ifdef ENABLE_STEADY_SHOOTER
				case 0x80:
					// Let's calculate where to shoot at: 
					rda = ADD_SIGN2 (en_x2 [gpit], en_x1 [gpit], 1);
					if (rda) en_my [gpit] = rda + 1; else en_my [gpit] = ADD_SIGN2 (en_y2 [gpit], en_y1 [gpit], 1) + 2;
					en_s [gpit] = STEADY_SHOOTER_CELL + en_my [gpit];
					// Seconds between shoots.
					en_mx [gpit] = rdb;	
					en_ct [gpit] = rdb; 
					break;
#endif
#ifdef ENABLE_WALKER
				case 0xa0:
					en_facing [gpit] = 4;
					break;
#endif					
				default:
					break;
			}

			// Finally
			en_washit [gpit] = 0;
			en_dying [gpit] = 0;
			en_gen_dying [gpit] = 0;
		}
		rdc ++;
	}
}

#ifdef ENEMIES_CAN_DIE
void enems_kill (void) {
	rdt = en_t [gpit] = 0;
	ep_flags [enoffs + gpit] |= 1;
}
#endif

void enems_spr (void) {
	spr_x = en_x [gpit];
	spr_y = en_y [gpit];
}

#ifdef ENABLE_TYPE_7
void enems_draw_generator (void) {
	// Add generator
	if (genflipflop) oam_index = oam_meta_spr (
		en_x1 [gpit], en_y1 [gpit] + SPRITE_ADJUST, 
		oam_index, 
		spr_enems [TYPE7_BASE_SPRITE + !!en_gen_washit [gpit]]);
	genflipflop = 1 - genflipflop;
}
#endif

#ifdef ENEMIES_CAN_DIE
void enems_drain (void) {
	// Substract life from enemy (type 7 minion in this game)
	// REFINE WHEN NEEDED
	if (en_life [gpit]) {
		en_life [gpit] --;
		en_washit [gpit] = TYPE7_MINION_HIT_FRAMES;
	} else {
		enems_type_7_reset ();
		en_dying [gpit] = TYPE7_MINION_DYING_FRAMES;
	}
}
#endif

void enems_do (void) {
	pgotten = 0;
	pgtmx = 0;
	pgtmy = 0;

	genflipflop = half_life;
	gpit = (frame_counter & 3);
	gpjt = 3; while (gpjt --) {
		gpit = gpit + 2; if (gpit > 2) gpit -= 3;

		// Local copies to save time & space (last time custom)
		_en_x = en_x [gpit]; _en_y = en_y [gpit];
		_en_mx = en_mx [gpit]; _en_my = en_my [gpit];
		_en_ct = en_ct [gpit];
		_en_x1 = en_x1 [gpit]; _en_y1 = en_y1 [gpit];
		_en_x2 = en_x2 [gpit]; _en_y2 = en_y2 [gpit];

#ifdef ENEMIES_CAN_DIE
#ifdef ENABLE_TYPE_7
		if (en_gen_dying [gpit]) {
			en_gen_dying [gpit] --;
			oam_index = oam_meta_spr (_en_x1, _en_y1 + SPRITE_ADJUST, oam_index, spr_en2_02);
		}
#endif

		if (en_dying [gpit]) {
			en_dying [gpit] --;
			oam_index = oam_meta_spr (_en_x, _en_y + SPRITE_ADJUST, oam_index, spr_en2_02);
		}
#endif		

		rdt = en_t [gpit] & 0xf0;
		if (rdt) {
#ifdef ENABLE_PLATFORMS
			is_platform = (rdt == 0x20);
			rda = _en_x;
			pregotten = (prx + 9 >= rda && prx <= rda + 17);
#endif

			// Move
			if (_en_mx != 0) {
				en_fr = ((_en_x) >> 4) & 1;
			} else {
				en_fr = ((_en_y) >> 4) & 1;
			}

			switch (rdt) {
#ifdef ENABLE_LINEAR				
				case 0x10:
				case 0x20:
					#include "engine/enemmods/enem_linear.h"
					break;
#endif
#ifdef ENABLE_TYPE_7				
				case 0x70:
					enems_draw_generator ();
					#include "engine/enemmods/enem_type_7.h"
					break;
#endif
#ifdef ENABLE_STEADY_SHOOTER
				case 0x80:
					#include "engine/enemmods/enem_steady_shooter.h"
					break;
#endif
#ifdef ENABLE_WALKER					
				case 0xa0:
					#include "engine/enemmods/enem_walker.h"
					break;
#endif					
				default:
					break;
			}

#ifdef ENABLE_PLATFORMS			
			// Moving platforms
			if (is_platform) {
				if (pregotten && !pgotten && !(pj && pvy <= 0)) {
					// Horizontal moving platforms
					if (_en_mx) {
						if (
							(inverted_screen && pj == 0 && (pry >= _en_y + 12 && pry <= _en_y + 18)) ||
							(!inverted_screen && (pry + 18 >= _en_y && pry + 12 <= _en_y)) 

						) {
							pgotten = 1;
							pgtmx = _en_mx << (FIX_BITS - en_state [gpit]);
							if (inverted_screen) pry = _en_y + 16; else pry = _en_y - 16; 
							py = pry << FIX_BITS;
							pvy = 0;
						}
					}
					
					// Vertical moving platforms
					if (
						(inverted_screen && pj == 0 && (	
							(_en_my < 0 && pry >= _en_y + 13 && pry <= _en_y + 17 + _en_my) ||
							(_en_my > 0 && pry >= _en_y + 12 && pry <= _en_y + 17)
						)) ||
						(!inverted_screen && (	
							(_en_my < 0 && pry + 17 >= _en_y && pry + 12 <= _en_y) ||
							(_en_my > 0 && pry + 16 + _en_my >= _en_y && pry + 12 <= _en_y)
						))
					) {
						pgotten = 1;
						pgtmy = _en_my << (FIX_BITS - en_state [gpit]);
						if (inverted_screen) pry = _en_y + 16; else pry = _en_y - 16; 
						py = pry << FIX_BITS;
						pvy = 0;
					}
				}
			}
#endif

			// Paint
			if (spr_id != 0xff) oam_index = oam_meta_spr (
				spr_x, spr_y + SPRITE_ADJUST, 
				oam_index, 
				spr_enems [spr_id + encelloffset]);

#ifdef ENABLE_TYPE_7
			if (rdt == 0x70) enems_draw_generator ();
#endif		

			// Patched in "steps on enemies", otherwise the game
			// is much tooo frustrating
			if (
				(game_monono || game_monona)
				&& pregotten 
				&& pry + 15 >= _en_y
				&& pry + 8 <= _en_y
				&& pvy >= 0
			) {
				if (pad0 & PAD_A) {
					pj = 1; pctj = 0; 
					pvy = -PLAYER_VY_JUMP_INITIAL;
				} else pvy = -PLAYER_VY_BUTT_REBOUND;
				fumettos_add ();
				sfx_play (SFX_BUTT_HIT, SC_LEVEL);
				_en_my = ABS (_en_my);
			} else

			if (collide (prx, pry, _en_x, _en_y)
#ifdef ENABLE_PLATFORMS
				&& !is_platform
#endif				
#ifdef PLAYER_FLICKERS
				&& !pflickering
#else				
				&& !phit
#endif
#ifdef ENABLE_STEADY_SHOOTER
				&& rdt != 0x80
#endif
			) {
					pvx = ADD_SIGN (_en_mx, PLAYER_V_REBOUND);
					//pvy = ADD_SIGN (_en_my, PLAYER_V_REBOUND);

#ifdef ENEMIES_CAN_DIE
					enems_drain ();
#endif					
					player_hit ();
			}

#ifdef PLAYER_CAN_FIRE
			// Bullets
			bi = BULLETS_MAX; while (bi --) if (b_ac [bi]) {
				if (collide (b_x [bi] - 4, b_y [bi] - 4, _en_x, _en_y)) {
					switch (rdt) {
#ifdef ENABLE_TYPE_7						
						case 0x70:
							if (en_state [gpit] && !en_dying [gpit]) {
								enems_drain (); bullets_destroy ();
							}
							break;
#endif
#ifdef ENABLE_WALKER							
						case 0xa0:
							en_washit [gpit] = WALKER_HIT_FRAMES;
							player_hit ();
							bullets_destroy ();
							break;
#endif							
					}
				} 

#ifdef ENABLE_TYPE_7
				if (b_ac [bi]) {
					if (rdt == 0x70) if (collide (b_x [bi] - 4, b_y [bi] - 4, _en_x1, _en_y1)) {
						bullets_destroy ();
						if (en_gen_life [gpit]) {
							en_gen_life [gpit] --;
							en_gen_washit [gpit] = TYPE7_GENERATOR_HIT_FRAMES;
						} else {
							enems_kill ();
							infested --;
							en_gen_dying [gpit] = TYPE7_GENERATOR_DYING_FRAMES;
							if (en_state [gpit]) en_dying [gpit] = TYPE7_MINION_DYING_FRAMES;
						}
					}
				}
#endif				
			}
#endif			
		}

		// Undo local copies to save time & space (last time custom)
		en_x [gpit] = _en_x; en_y [gpit] = _en_y;
		en_mx [gpit] = _en_mx; en_my [gpit] = _en_my;
		en_ct [gpit] = _en_ct;
	}
}
