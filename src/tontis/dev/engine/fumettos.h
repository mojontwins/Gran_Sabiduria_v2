// Custom fumettos

void fumettos_init (void) {
	gpit = FUMETTOS_MAX; while (gpit --) fumettos_life [gpit] = 0;
}

void fumettos_add (void) {
	gpit = FUMETTOS_MAX; while (gpit --) {
		if (!fumettos_life [gpit]) {
			fumettos_life [gpit] = 32;
			//if (pfacing) fumettos_x [gpit] = prx + 4; else fumettos_x [gpit] = prx - 4;
			fumettos_x [gpit] = prx;
			fumettos_y [gpit] = pry + 4;
			break;
		}
	}
}

void fumettos_do (void) {
	gpit = FUMETTOS_MAX; while (gpit --) {
		if (fumettos_life [gpit]) {
			fumettos_life [gpit] --;
			oam_index = oam_spr (fumettos_x [gpit], fumettos_y [gpit] + SPRITE_ADJUST, FUMETTO_BASE_PATTERN + 3-(fumettos_life [gpit] >> 3), 2, oam_index);
		}
	}
}
