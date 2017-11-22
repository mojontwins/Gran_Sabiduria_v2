// heart.h, a simple particle

void heart_create (void) {
	bi = MAX_HEARTS; while (bi --) if (!hearts_l [bi]) {
		hearts_l [bi] = 25 + (rand8 () & 0xf); hearts_x [bi] = en_x [gpit] + 4; hearts_y [bi] = en_y [gpit] - 4;
		break;
	}
}

void hearts_move (void) {
	bi = MAX_HEARTS; while (bi --) if (hearts_l [bi]) {
		hearts_l [bi] --; hearts_y [bi] -= (1 + (rand8 () & 1)); hearts_x [bi] += ((rand8 () & 1) << 1) - 1;
		if (hearts_y [bi] < 16) hearts_l [bi] = 0;
		
		oam_index = oam_spr (hearts_x [bi], hearts_y [bi] + SPRITE_ADJUST, 2, 0, oam_index);
	}
}

void hearts_init (void) {
	bi = MAX_HEARTS; while (bi --) hearts_l [bi] = 0;
}
