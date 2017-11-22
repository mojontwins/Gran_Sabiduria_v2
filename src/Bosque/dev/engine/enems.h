// MT MK2 NES v0.3
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
		ep_x [ep_it] = (rda << 4);

		// YX2
		rda = *gp_gen ++;
		rdc = rda & 0xf0;
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
	//infested = 0;	// Type 7s active?
	enitstart = 0;
	// Each screen holds 3 enemies, each enemy takes 4 bytes, so:
	gpint = n_pant; 
	gp_gen = (unsigned char *) (c_enems + (gpint << 3) + (gpint << 2));
	rdc = enoffs = n_pant + n_pant + n_pant;
	for (gpit = 0; gpit < 3; gpit ++) {
#if defined(ENEMIES_CAN_DIE) && defined(PERSISTENT_DEATHS)	
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

#ifdef PERSISTENT_ENEMIES
			// YX1
			rdb = *gp_gen ++;
			en_x1 [gpit] = rdb << 4;
			en_y1 [gpit] = rdb & 0xf0;

			// YX2
			rdb = *gp_gen ++;
			en_x2 [gpit] = rdb << 4;
			en_y2 [gpit] = rdb & 0xf0;

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

			// Define as per type
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
#ifdef ENABLE_MONOCOCO
				case 0x90:
					en_mx [gpit] = 0; en_my [gpit] = MONOCOCO_BASE_TIME_HIDDEN - (rand8 () & 0x15);
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
//			en_gen_dying [gpit] = 0;

// CUSTOM {
			en_kissed [gpit] = ep_flags [rdc];
// } END_OF_CUSTOM			
		}
		rdc ++;
	}
}

#ifdef ENEMIES_CAN_DIE
void enems_kill (void) {
	rdt = en_t [gpit] = 0;
	sfx_play (SFX_BUTT_HIT, SC_LEVEL);
#ifdef PERSISTENT_DEATHS	
	ep_flags [enoffs + gpit] |= 1;
#endif	
	en_dying [gpit] = 16;
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

/*
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
*/

void enems_do (void) {
	pgotten = 0;
	pgtmx = 0;
	pgtmy = 0;

	genflipflop = half_life;
	gpit = enitstart; enitstart ++; if (enitstart == 3) enitstart = 0;
	gpjt = 3; while (gpjt --) {
		gpit = gpit + 2; if (gpit > 2) gpit -= 3;

#ifdef ENEMIES_CAN_DIE
#ifdef ENABLE_TYPE_7
		if (en_gen_dying [gpit]) {
			en_gen_dying [gpit] --;
			oam_index = oam_meta_spr (en_x1 [gpit], en_y1 [gpit] + SPRITE_ADJUST, oam_index, SPRITE_EXPLOSION);
		}
#endif

		if (en_dying [gpit]) {
			en_dying [gpit] --;
			oam_index = oam_meta_spr (en_x [gpit], en_y [gpit] + SPRITE_ADJUST, oam_index, SPRITE_EXPLOSION);
		}
#endif		

		rdt = en_t [gpit] & 0xf0;
		if (rdt) {
#ifdef ENABLE_PLATFORMS
			is_platform = (rdt == 0x20);
			if (is_platform) {
				rda = en_x [gpit];
				pregotten = (prx + 9 >= rda && prx <= rda + 17);
			}
#endif

			// Move
			if (en_mx [gpit] != 0) {
				en_fr = ((en_x [gpit]) >> 4) & 1;
			} else {
				en_fr = ((en_y [gpit]) >> 4) & 1;
			}

// CUSTOM {
			if (en_kissed [gpit]) {
				#include "engine/enemmods/enem_kissed.h"
			} else
// } END_OF_CUSTOM
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
#ifdef ENABLE_MONOCOCO
				case 0x90:
					#include "engine/enemmods/enem_monococo.h"
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
					if (en_mx [gpit]) {
						if (pry + 18 >= en_y [gpit] && pry + 12 <= en_y [gpit]) {
							pgotten = 1;
							pgtmx = en_mx [gpit] << (FIX_BITS - en_state [gpit]);
							pry = en_y [gpit] - 16; py = pry << FIX_BITS;
							pvy = 0;
						}
					}
					
					// Vertical moving platforms
					if (
						(en_my [gpit] < 0 && pry + 17 >= en_y [gpit] && pry + 12 <= en_y [gpit]) ||
						(en_my [gpit] > 0 && pry + 16 + en_my [gpit] >= en_y [gpit] && pry + 12 <= en_y [gpit])
					) {
						pgotten = 1;
						pgtmy = en_my [gpit] << (FIX_BITS - en_state [gpit]);
						pry = en_y [gpit] - 16; py = pry << FIX_BITS;
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

			if (collide (prx, pry, en_x [gpit], en_y [gpit])) {
#ifdef PLAYER_SPINS_KILLS
				if ((pjustjumped || pspin)
#ifdef ENABLE_PLATFORMS
					&& !is_platform
#endif					
				) {
					enems_kill ();
					pvy = -pvy;
				} else
#endif			

				if (	
#ifdef PLAYER_FLICKERS
					!pflickering
#else				
					!phit
#endif
#ifdef ENABLE_PLATFORMS
					&& !is_platform
#endif				
// CUSTOM {					
					&& !en_kissed [gpit]					
// } END_OF_CUSTOM
				) {
#ifdef PLAYER_REBOUND_REVERSE_DIRECTION	
					if (pvx || pvy) {
						if (ABS (pvx) > ABS (pvy)) {
							pvx = ADD_SIGN (-pvx, PLAYER_V_REBOUND);
						} else {
							pvy = ADD_SIGN (-pvy, PLAYER_V_REBOUND);
						}
					} else 
#endif
					{
						pvx = ADD_SIGN (en_mx [gpit], PLAYER_V_REBOUND);
						pvy = ADD_SIGN (en_my [gpit], PLAYER_V_REBOUND);
					}


#ifdef ENEMIES_CAN_DIE
					//enems_drain ();
#endif					
// CUSTOM {
					if (kissme) {
						ep_flags [enoffs + gpit] = 1;
						en_kissed [gpit] = 1;
						muacs_count ++;
					} else
// } END_OF_CUSTOM					
						player_hit ();
				}
			}

#ifdef PLAYER_CAN_FIRE
			// Bullets
			bi = BULLETS_MAX; while (bi --) if (b_ac [bi]) {
				if (collide (b_x [bi] - 4, b_y [bi] - 4, en_x [gpit], en_y [gpit])) {
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
					if (rdt == 0x70) if (collide (b_x [bi] - 4, b_y [bi] - 4, en_x1 [gpit], en_y1 [gpit])) {
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
	}
}
