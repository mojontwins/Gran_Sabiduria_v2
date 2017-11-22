// Puas.h
// spikes for espinete, may be of use in other games
// (maybe with some changes)

void puas_init (void) {
	gpit = PUAS_MAX; while (gpit --) puas_y [gpit] = 240;
}

void puas_create (void) {
	// Pinchos en la espalda
	gpit = PUAS_MAX; while (gpit --) {
		if (puas_y [gpit] == 240) {
			puas_y [gpit] = pry;
			puas_x [gpit] = prx;
			puas_mx [gpit] = pfacing ? PUAS_VX : -PUAS_VX;
			break;
		}
	}
}

void puas_do (void) {
	gpit = PUAS_MAX; while (gpit --) {
		if (puas_y [gpit] != 240) {
			_puas_x = puas_x [gpit] + puas_mx [gpit];
			if (_puas_x < PUAS_VX || _puas_x > 248 - PUAS_VX) puas_y [gpit] = 240;
			oam_index = oam_spr (
				_puas_x, puas_y [gpit] + SPRITE_ADJUST,
				3,
				puas_mx [gpit] > 0 ? 0 : 0x40,
				oam_index
			);
			puas_x [gpit] = _puas_x;
		}
	}
}
