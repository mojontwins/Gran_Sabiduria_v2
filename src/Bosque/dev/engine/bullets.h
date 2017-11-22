// MT MK2 NES v0.3
// Copyleft 2016 by The Mojon Twins

// Projectiles

void bullets_ini (void) {
	gpit = BULLETS_MAX; while (gpit --) {
		b_ac [gpit] = 0;
		b_slots [gpit] = gpit;
	}
	b_slot = BULLETS_MAX;
}

unsigned char bullets_get_slot (void) {
	if (b_slot == 0) return 0xff;
	b_slot --; return b_slots [b_slot];
}

void bullets_fire (void) {
	if (!pgauge) return;

	rda = bullets_get_slot ();
	if (rda == 0xff) return;
	switch (pfacing) {
		case 0: rdb = 0; break;
		case 6: rdb = 1; break;
		case 12: rdb = 2; break;
		case 18: rdb = 3; break;
	}

	b_mx [rda] = ADD_SIGN (en_dx [rdb], BULLETS_V);
	b_my [rda] = ADD_SIGN (en_dy [rdb], BULLETS_V);
	b_x [rda] = prx + boffsx [rdb];
	b_y [rda] = pry + boffsy [rdb];

	b_ac [rda] = 1;
	
	bullets_deplete (); // Custom
	// PIÑAON (sonido)
}

void bullets_destroy (void) {
	b_ac [bi] = 0;
	b_slots [b_slot] = bi; b_slot ++;	// Free slot
}

void player_hit (void);

void bullets_do (void) {
	bi = frame_counter & 7;
	gpjt = BULLETS_MAX; while (gpjt --) {
		bi += 7; if (bi > 7) bi -= 8;

		if (b_ac [bi]) {
			b_x [bi] += b_mx [bi];
			b_y [bi] += b_my [bi];

			oam_index = oam_spr (
				b_x [bi], SPRITE_ADJUST + b_y [bi],
				255, 1, oam_index
			);

			if (b_x [bi] < 8 || b_x [bi] > 240 || b_y [bi] < 8 || b_y [bi] > 176 || (scr_attr [((b_x [bi] + 4) >> 4) + ((b_y [bi] + 4) & 0xf0)] & 8)) {
				bullets_destroy ();
			}

			if (collide (b_x [bi] - 4, b_y [bi] - 4, hrx, hry) && hrt == HOTSPOT_TYPE_OBJECT) {
				hr_hit = 16;
				player_hit ();
				bullets_destroy ();
			}
		}
	}
}
