// Cheril: the Nine
// Copyleft 2016 by The Mojon Twins

// Enems

void enems_persistent_deaths_init (void) {
	gpit = MAP_W * MAP_H * N_ENEMS; while (gpit --) ep_flags [gpit] &= 0xfe;
}

void enems_type_7_reset (void) {
	en_state [gpit] = 0;
	en_ct [gpit] = TYPE7_SPAWN_TIME;
	if (game_meghan) en_ct [gpit] += ticks;
}

void enems_load (void) {
	infested = 0;	// Type 7s active?

	if (game_cheril) {
		// Simple enemies. Each screen holds 4*2 bytes, so
		gp_gen = (unsigned char *) (c_enems + (n_pant << 3));
		rdc = enoffs = (n_pant << 2);
		rdct = 4;
	} else {
		// Each screen holds 3 enemies, each enemy takes 4 bytes, so:
		gp_gen = (unsigned char *) (c_enems + (n_pant << 3) + (n_pant << 2));
		rdc = enoffs = n_pant + n_pant + n_pant;
		rdct = 3;	
	}
	for (gpit = 0; gpit < rdct; gpit ++) {
		// Kill enemy
		if (game_cheril && (ep_flags [rdc] & 1)) {
			en_t [gpit] = 0;	// Inactive
			gp_gen += 2; 		// Next enemy
		} else {
			// Type and attribute
			rda = *gp_gen ++;
			en_t [gpit] = rda;

			// YX
			en_rdb [gpit] = rdb = *gp_gen ++;
			en_x1 [gpit] = en_x [gpit] = rdb << 4;
			en_y1 [gpit] = en_y [gpit] = rdb & 0xf0;

			if (game_meghan) {
				// YX2
				rdb = *gp_gen ++;
				en_x2 [gpit] = rdb << 4;
				en_y2 [gpit] = rdb & 0xf0;

				// Attribute
				rdb = *gp_gen ++;
			}

			// Custom as per type
			switch (en_t [gpit] & 0xf0) {
				case 0x10:
				case 0x20:
					en_s [gpit] = (en_t [gpit] & 0x0f) << 2;
					if (rdb == 1) {
						en_state [gpit] = 1;
					} else {
						rdb >>= 1;
					}
					en_mx [gpit] = ADD_SIGN2 (en_x2 [gpit], en_x1 [gpit], rdb);
					en_my [gpit] = ADD_SIGN2 (en_y2 [gpit], en_y1 [gpit], rdb);
					en_life [gpit] = TYPE7_MINION_LIFE; // Custom
					break;
				case 0x70:
					en_gen_life [gpit] = TYPE7_GENERATOR_LIFE;
					enems_type_7_reset ();
					en_gen_washit [gpit] = 0;
					infested ++;

					// Modify map attributes
					if (game_cheril) scr_attr [en_rdb [gpit]] = 4;
					break;
				case 0xa0:
					en_facing [gpit] = 4;
					break;
			}

			// Finally
			en_state [gpit] = 0;
			en_washit [gpit] = 0;
			en_dying [gpit] = 0;
			en_gen_dying [gpit] = 0;
		}
		rdc ++;
	}

	if (game_meghan) {
		en_dying [3] = en_gen_dying [3] = en_washit [3] = en_t [3] = 0;
	}
}

void enems_kill (void) {
	sfx_play (SFX_BUTT_HIT, SC_LEVEL);
	rdt = en_t [gpit] = 0;
	if (game_cheril) ep_flags [enoffs + gpit] |= 1;
}

void enems_spr (void) {
	spr_x = en_x [gpit];
	spr_y = en_y [gpit];
}

void enems_draw_generator (void) {
	// Add generator
	if (game_meghan) return;
	if (genflipflop) oam_index = oam_meta_spr (
		en_x1 [gpit], en_y1 [gpit] + SPRITE_ADJUST, 
		oam_index, 
		spr_enems [TYPE7_BASE_SPRITE + !!en_gen_washit [gpit]]);
	genflipflop = 1 - genflipflop;
}

void enems_drain (void) {
	 sfx_play (SFX_BUTT_HIT, SC_LEVEL);
	// Substract life from enemy (type 7 minion in this game)
	if (en_life [gpit]) {
		en_life [gpit] --;
		en_washit [gpit] = TYPE7_MINION_HIT_FRAMES;
	} else {
		en_washit [gpit] = 0;
		switch (rdt) {
			case 0x10:
			case 0x20:
				en_dying [gpit] = TYPE7_MINION_DYING_FRAMES;
				enems_kill (); // Euh...
				break;
			case 0x70:
				enems_type_7_reset ();
				en_dying [gpit] = TYPE7_MINION_DYING_FRAMES;
				break;
		}
	}
}

void enems_do (void) {
	genflipflop = half_life;
	gpit = (frame_counter & 3);
	gpjt = 4; while (gpjt --) {
		gpit = gpit + 3; if (gpit > 3) gpit -= 4;

		if (game_meghan && en_washit [gpit]) {
			// Extra explossion
			oam_index = oam_meta_spr (en_whx [gpit] + jitter [frame_counter & 0xf], en_why [gpit] + SPRITE_ADJUST + jitter [(frame_counter + 8) & 0xf], oam_index, spr_it_meghan_03);
		}

		if (game_cheril && en_gen_dying [gpit]) {
			en_gen_dying [gpit] --;
			oam_index = oam_meta_spr (en_x1 [gpit], en_y1 [gpit] + SPRITE_ADJUST, oam_index, spr_en2_02);
		}

		if (en_dying [gpit]) {
			en_dying [gpit] --;
			oam_index = oam_meta_spr (en_x [gpit], en_y [gpit] + SPRITE_ADJUST, oam_index, game_meghan ? spr_it_meghan_03 : spr_en2_02);
		}

		rdt = en_t [gpit] & 0xf0;
		if (rdt) {
			// Move
			if (en_mx [gpit] != 0) {
				en_fr = ((en_x [gpit]) >> 4) & 1;
			} else {
				en_fr = ((en_y [gpit]) >> 4) & 1;
			}

			switch (rdt) {
				case 0x10:
				case 0x20:
					#include "engine/enemmods/enem_linear.h"
					break;
				case 0x70:
					enems_draw_generator ();
					#include "engine/enemmods/enem_type_7.h"
					break;
				case 0xa0:
					#include "engine/enemmods/enem_walker.h"
					break;
			}

			// Paint
			if (spr_id != 0xff) oam_index = oam_meta_spr (
				spr_x, spr_y + SPRITE_ADJUST, 
				oam_index, 
				spr_enems [encellbase + spr_id]);

			if (rdt == 0x70) enems_draw_generator ();

			if (collide (prx, pry, en_x [gpit], en_y [gpit]) &&
				!pflickering) {
				if ((rdt == 0x70 && en_state [gpit]) || rdt < 0x70) {
					pvx = ADD_SIGN (en_mx [gpit], PLAYER_V_REBOUND);
					pvy = ADD_SIGN (en_my [gpit], PLAYER_V_REBOUND);

					if (game_meghan) en_life [gpit] = 0;
					enems_drain ();
					player_hit ();
				}
			}

			// Bullets
			bi = BULLETS_MAX; while (bi --) if (b_ac [bi]) {
				if (collide (b_x [bi] - 4, b_y [bi] - 4, en_x [gpit], en_y [gpit])) {
					en_whx [gpit] = b_x [bi] - 8; en_why [gpit] = b_y [bi] - 8;
					switch (rdt) {
						case 0x10:
						case 0x20:
							enems_drain (); bullets_destroy ();
							break;
						case 0x70:
							if (en_state [gpit] && !en_dying [gpit]) {
								enems_drain (); bullets_destroy ();
							}
							break;
						case 0xa0:
							en_washit [gpit] = WALKER_HIT_FRAMES;
							player_hit ();
							bullets_destroy ();
							break;
					}
				} 

				if (game_cheril) {
					if (b_ac [bi]) {
						if (rdt == 0x70) if (collide (b_x [bi] - 4, b_y [bi] - 4, en_x1 [gpit], en_y1 [gpit])) {
							bullets_destroy ();
							sfx_play (SFX_BUTT_HIT, SC_LEVEL);
							if (en_gen_life [gpit]) {
								en_gen_life [gpit] --;
								en_gen_washit [gpit] = TYPE7_GENERATOR_HIT_FRAMES;
							} else {
								enems_kill ();
								sfx_play (7, SC_LEVEL);
								infested --;
								en_gen_dying [gpit] = TYPE7_GENERATOR_DYING_FRAMES;
								if (en_state [gpit]) en_dying [gpit] = TYPE7_MINION_DYING_FRAMES;
								scr_attr [en_rdb [gpit]] = 0;
							}
						}
					}
				}
			}
		}
	}
}
