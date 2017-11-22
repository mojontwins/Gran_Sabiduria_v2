// MT MK2 NES v0.87ZCP - Peyejo pendejo!
// Copyleft 2017 by The Mojon Twins

// Projectiles

void bullets_ini (void) {
	gpit = BULLETS_MAX; while (gpit --) {
		b_ac [gpit] = 0;
		b_slots [gpit] = gpit;
	}
	b_slot = BULLETS_MAX;
}

/*
unsigned char bullets_get_slot (void) {
	if (b_slot == 0) return 0xff;
	b_slot --; return b_slots [b_slot];
}
*/

void bullets_fire (void) {
#ifdef MAX_AMMO
	if (pammo == 0) return;
#endif
	
	/*
	rda = bullets_get_slot ();
	if (rda == 0xff) return;
	*/

	// Get slot
	if (b_slot == 0) return;
	b_slot --; rda = b_slots [b_slot];

	pammo --;

#ifdef PLAYER_GENITAL
	switch (pfacing) {
		case CELL_FACING_RIGHT: rdb = 0; break;
		case CELL_FACING_LEFT: rdb = 1; break;
		case CELL_FACING_DOWN: rdb = 2; break;
		case CELL_FACING_UP: rdb = 3; break;
	}

	b_mx [rda] = ADD_SIGN (en_dx [rdb], BULLETS_V);
	b_my [rda] = ADD_SIGN (en_dy [rdb], BULLETS_V);
	b_x [rda] = prx + boffsx [rdb];
	b_y [rda] = pry + boffsy [rdb];
#else
	b_mx [rda] = pfacing ? -BULLETS_V : BULLETS_V;
	b_x [rda] = prx + boffsx [!!pfacing];
	b_y [rda] = _b_y = pry + 2;
#endif

	b_ac [rda] = 1;
	
	// bullets_deplete ();
#ifdef PLAYER_VX_RECOIL
	pvx = pfacing ? PLAYER_VX_RECOIL : -PLAYER_VX_RECOIL;
#endif

	sfx_play (SFX_SHOOT, SC_PLAYER);
}

void bullets_destroy (void) {
	b_ac [bi] = 0;
	b_slots [b_slot] = bi; b_slot ++;	// Free slot
}

void player_hit (void);

void bullets_do (void) {
	bi = frame_counter & 3;
	gpjt = BULLETS_MAX; while (gpjt --) {
		bi += BULLETS_MAX-1; if (bi >= BULLETS_MAX) bi -= BULLETS_MAX;

		if (b_ac [bi]) {
			_b_x = b_x [bi] + b_mx [bi];
#ifdef PLAYER_GENITAL
			_b_y = b_y [bi] + b_my [bi];			
#endif

			oam_index = oam_spr (
				_b_x, SPRITE_ADJUST + _b_y,
				1, 2, oam_index
			);

			rdi = ((_b_x + 4) >> 4) | ((_b_y + 4 - 16) & 0xf0);
			rda = scr_attr [rdi];

#ifdef BREAKABLE_WALLS
			if (rda & 128) {
				breakable_break ();
				bullets_destroy ();
			}
#endif			

			if (
				_b_x < 8 || 
				_b_x > 240 || 
				_b_y < 8 || 
				_b_y > 208 || 
				(rda & 8)
			) {
				bullets_destroy ();
			}

			/*
			if (collide (b_x [bi] - 4, b_y [bi] - 4, hrx, hry) && hrt == HOTSPOT_TYPE_OBJECT) {
				hr_hit = 16;
				pwashit = 1;
				bullets_destroy ();
			}
			*/

			b_x [bi] = _b_x;
#ifdef PLAYER_GENITAL			
			b_y [bi] = _b_y;
#endif			
		}
	}
}
