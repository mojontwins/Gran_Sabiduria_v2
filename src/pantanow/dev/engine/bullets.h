// Pantanow Engine rev2b 201703
// Copyleft 2016 by The Mojon Twins

// Projectiles et al

void bullets_init (void) {
	bit = BULLETS_MAX; while (bit --) {
		ba [bit] = 0; 
		bslots [bit] = bit; 
	}
	bsloti = BULLETS_MAX;
}

// Creates at rdx, rdy; mx = rdmx, my = rdmy;
// rda contains who fired the bullet.
void bullet_create (void) {
	// Get slot
	if (!bsloti) return;
	bsloti --;
	bit = bslots [bsloti];

	sfx_play (SFX_SHOOT, SC_PLAYER);

	ba [bit] = 1;
	bx [bit] = rdx; by [bit] = rdy;
	bmx [bit] = rdmx; bmy [bit] = rdmy;

	bagent [bit] = rda; // Who fired the bullet!
}

// Frees bullet #bit
void bullet_free (void) {
	ba [bit] = 0;
	by [bit] = 0; // Helps visualizing stuff when debugging, may remove this
	bslots [bsloti] = bit; bsloti ++;
}

void bullets_do (void) {
	bit = BULLETS_MAX; while (bit --) {
		if (ba [bit]) {
			rdc = (bagent [bit] != 0xff);

			if (hl_proc) {
				hl_proc = 0;

				// Move
				
				bx [bit] += bmx [bit]; _bx = bx [bit];
				by [bit] += bmy [bit]; _by = by [bit];

				// Paint
				
				oam_index = oam_spr (_bx, _by - camera_position + SPRITE_ADJUST, 1 + rdc, rdc ? 3 : 0, oam_index);
				
				// Collide / etc
				
				rdb = ABS (bmx [bit]);
				if (
					(attr ((_bx + 4) >> 4, (_by + 4) >> 4) & 8) ||
					(bmx [bit] < 0 && _bx < rdb) ||
					(bmx [bit] > 0 && _bx > 248 - rdb) ||
					(_by < camera_position) ||
					(_by > 240 + camera_position)
				) {
					bullet_free (); continue;
				}

				// Who fired the bullet?
				
				if (rdc) {
					if (CLB (_bx, _by, prx, pry) && !(phit || pflickering)) {
						sfx_play (SFX_CHOF, SC_PLAYER);
						phit = 191;
						bullet_free (); continue;
					}
				} else {
					enit = ENEMS_MAX; while (enit --) {
						if (CLB (_bx, _by, enx [enit], eny [enit]) && enstate [enit] != ENS_DYING) {
							sfx_play (SFX_ENEMY_HIT, SC_PLAYER);
							enstate [enit] = ENS_DYING; 
							enctstate [enit] = (enspr [enit] == 0x30) ? 100 : 32;
							bullet_free (); continue;
						}
					}
				}
			} else hl_proc = 1;
			
		} 
	}
}
