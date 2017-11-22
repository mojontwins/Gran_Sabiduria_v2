// MT MK2 NES v0.6
// Copyleft 2016 by The Mojon Twins

// Enems

#ifdef PERSISTENT_ENEMIES
void persistent_enems_load (void) {
	gp_gen = (unsigned char *) (c_enems);
	for (ep_it = 0; ep_it < 3 * MAX_PANTS; ep_it ++) {
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
	gpit = MAX_PANTS * N_ENEMS; while (gpit --) ep_flags [gpit] &= 0xfe;
}
#endif

#ifdef ENABLE_TYPE_7	
void enems_type_7_reset (void) {
	en_state [gpit] = 0;
	en_ct [gpit] = TYPE7_SPAWN_TIME;
}
#endif

void enems_load (void) {
	// infested = 0;	// Type 7s active?
	// Each screen holds 3 enemies, each enemy takes 4 bytes, so:
	gp_gen = (unsigned char *) (c_enems + (n_pant << 3) + (n_pant << 2));
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

					// This comes handy when jumping on enemies
#ifdef PLAYER_STEPS_ON_ENEMIES
					if (en_y1 [gpit] > en_y2 [gpit]) {
						rda = en_y1 [gpit]; en_y1 [gpit] = en_y2 [gpit]; en_y2 [gpit] = rda;
					}
#endif
					break;
#endif
#ifdef ENABLE_FANTY
				case 0x30:
					enf_x [gpit] = en_x1 [gpit] << FIX_BITS;
					enf_y [gpit] = en_y1 [gpit] << FIX_BITS;
					enf_vy [gpit] = 0;
					enf_vx [gpit] = (en_x1 [gpit] < 128) ? -(FANTY_MAXV+FANTY_MAXV) : FANTY_MAXV+FANTY_MAXV;
					fanty_timer [gpit] = FANTY_TIMER_BASE;
					break;
#endif
#ifdef ENABLE_CATACROCK
				case 0x40:
#ifdef PERSISTENT_ENEMIES
					en_y [gpit] = en_y1 [gpit];
#endif
					CATACROCK_STATE [gpit] = 0;
					CATACROCK_WAIT [gpit] = CATACROCK_COUNTER [gpit] = rdb << 5;	// In frames
					break;
#endif
#ifdef ENABLE_GENERATONIS
				case 0x50:
					en_s [gpit] = (en_t [gpit] & 0x0f) << 2;
					GENERATONI_WAIT [gpit] = 31 + (rdb << 5);
					GENERATONI_COUNTER [gpit] = 0;
					en_y [gpit] = en_y1 [gpit]; en_x [gpit] = en_x1 [gpit];
					GENERATONI_STATE [gpit] = 0;
					break;
#endif
#ifdef ENABLE_TYPE_7				
				case 0x70:
					en_gen_life [gpit] = TYPE7_GENERATOR_LIFE;
					enems_type_7_reset ();
					en_gen_washit [gpit] = 0;
					//infested ++;
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
					MONOCOCO_STATE [gpit] = 0; MONOCOCO_COUNTER [gpit] = MONOCOCO_BASE_TIME_HIDDEN - (rand8 () & 0x15);
					break;
#endif
#ifdef ENABLE_WALKER
				case 0xa0:
					en_facing [gpit] = 4;
					break;
#endif
#ifdef ENABLE_GYROSAW
				case 0xb0:
					GYROSAW_COUNTER [gpit] = 0; 		// Counter
					GYROSAW_DIRECTION [gpit] = rdb; 	// clockwise = 1; counter-clockwise = 0
					en_x [gpit] = en_x1 [gpit];
					en_y [gpit] = en_y1 [gpit];
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
	en_dying [gpit] = 16;

#ifdef ENABLE_GENERATONIS
	if (rdt == 0x50) {
		GENERATONI_STATE [gpit] = 0;
		GENERATONI_COUNTER [gpit] = GENERATONI_WAIT [gpit]; 	// In frames
	} else
#endif
	{	
		rdt = en_t [gpit] = 0;
		sfx_play (SFX_BUTT_HIT, SC_LEVEL);
#ifdef PERSISTENT_DEATHS	
		ep_flags [enoffs + gpit] |= 1;
#endif		
	}

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
	gpit = (frame_counter & 3);
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
				en_fr = ((en_x [gpit] + 4) >> 4) & 1;
			} else {
				en_fr = ((en_y [gpit] + 4) >> 4) & 1;
			}

			switch (rdt) {
#ifdef ENABLE_LINEAR				
				case 0x10:
				case 0x20:
					#include "engine/enemmods/enem_linear.h"
					break;
#endif
#ifdef ENABLE_FANTY
				case 0x30:
					#include "engine/enemmods/enem_fanty.h"
					break;
#endif
#ifdef ENABLE_CATACROCK
				case 0x40:
					#include "engine/enemmods/enem_catacrock.h"
					break;
#endif
#ifdef ENABLE_GENERATONIS
				case 0x50:
					#include "engine/enemmods/enem_generatoni.h"
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
#ifdef ENABLE_GYROSAW
				case 0xb0:
					#include "engine/enemmods/enem_gyrosaw.h"
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
			if (spr_id != 0xff && !en_dying [gpit]) oam_index = oam_meta_spr (
				spr_x, spr_y + SPRITE_ADJUST, 
				oam_index, 
				spr_enems [spr_id + encelloffset]);

#ifdef ENABLE_TYPE_7
			if (rdt == 0x70) enems_draw_generator ();
#endif		


// CUSTOM { hitter (yet)
			if (hitter_frame >= HIT_F0 && hitter_frame <= HIT_F1
#ifdef ENABLE_MONOCOCO
				&& (rdt != 0x90 || MONOCOCO_STATE [gpit] == 2)
#endif
#ifdef ENABLE_GENERATONIS
				&& (rdt != 0x50 || GENERATONI_STATE [gpit])
#endif
			) {
				if (hitter_x + 12 >= en_x [gpit] && hitter_x <= en_x [gpit] + 12 &&
					hitter_y + 12 >= en_y [gpit] && hitter_y <= en_y [gpit] + 12) {
					enems_kill ();
					continue;
				}
			}
// } END_OF_CUSTOM	

#ifdef PLAYER_STEPS_ON_ENEMIES
			if (prx + 7 >= en_x [gpit] && prx <= en_x [gpit] + 15 && pry + 15 >= en_y [gpit] && pry + 8 <= en_y [gpit]
				&& pvy >= 0
#ifdef PLAYER_BUTT
				&& pbutt
#endif
// CUSTOM {
				&& (game_trabajo_basura || pstatespradder)
// }END_OF_CUSTOM
			) {
				pvy = -PLAYER_VY_BUTT_REBOUND;
#ifdef PLAYER_DOUBLE_JUMP
				njumps = 1;
#endif
#ifdef ENABLE_FUMETTOS				
				fumettos_add ();
#endif				
				sfx_play (SFX_BUTT_HIT, SC_LEVEL);		
				if (rdt == 0x10) en_my [gpit] = ABS (en_my [gpit]);

#ifdef KILLABLE_CONDITION
				if (KILLABLE_CONDITION)
#endif
				{
					enems_kill ();
#ifdef COUNT_KILLED_ON_FLAG
					flags [COUNT_KILLED_ON_FLAG] ++;
#endif
				}
			} else 
#endif

			if (
				CL (prx, pry, en_x [gpit], en_y [gpit])
#ifdef ENABLE_MONOCOCO
				&& (rdt != 0x90 || MONOCOCO_STATE [gpit] == 2)
#endif
#ifdef ENABLE_CATACROCK
				&& (rdt != 0x40 || CATACROCK_STATE [gpit] == 1)
#endif
#ifdef ENABLE_GENERATONIS
				&& (rdt != 0x50 || GENERATONI_STATE [gpit])
#endif
			) {
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
#ifdef ENEMIES_SUFFER_WHEN_HITTING_PLAYER
						enems_drain ();
#endif
#endif
#ifdef ENABLE_GENERATONIS
						if (rdt == 0x50) en_mx [gpit] = -en_mx [gpit];
#endif
						pwashit = 1;
				}
			}

#ifdef ENABLE_PUAS
			// Puas (custom)
			bi = PUAS_MAX; while (bi --) if (puas_y [bi] != 240) {
				if (collide (puas_x [bi], puas_y [bi], en_x [gpit], en_y [gpit])) {
					enems_kill ();
					puas_y [bi] = 240;
				}
			}
#endif

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
							//infested --;
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
