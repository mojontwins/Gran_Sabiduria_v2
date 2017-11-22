// MT MK2 NES v0.86 - Sonic Bad is bad
// Copyleft 2017 by The Mojon Twins
	switch (_en_state) {
		case 0:
			// Idling
			enf_vx [gpit] = enf_vy [gpit] = 0;
			if (!phidden) _en_state = 1;
			break;

		case 1:
			// Pursuing
			if (!half_life) {
				if (enf_x [gpit] > px) {
					enf_vx [gpit] -= (ESPECTRO_A+ESPECTRO_A); if (enf_vx [gpit] < -ESPECTRO_MAXV) enf_vx [gpit] = -ESPECTRO_MAXV;
				} else if (enf_x [gpit] < px) {
					enf_vx [gpit] += (ESPECTRO_A+ESPECTRO_A); if (enf_vx [gpit] > ESPECTRO_MAXV) enf_vx [gpit] = ESPECTRO_MAXV;
				}
				if (enf_y [gpit] > py) {
					enf_vy [gpit] -= (ESPECTRO_A+ESPECTRO_A); if (enf_vy [gpit] < -ESPECTRO_MAXV) enf_vy [gpit] = -ESPECTRO_MAXV;
				} else if (enf_y [gpit] < py) {
					enf_vy [gpit] += (ESPECTRO_A+ESPECTRO_A); if (enf_vy [gpit] > ESPECTRO_MAXV) enf_vy [gpit] = ESPECTRO_MAXV;
				}
			}

			if (phidden) _en_state = 2;
			break;

		case 2:
			// Retreating
			if (!half_life) {
				enf_vx [gpit] = (enf_x [gpit] > px) ? ESPECTRO_V_RETREATING : -ESPECTRO_V_RETREATING;
				enf_vy [gpit] = (enf_y [gpit] > py) ? ESPECTRO_V_RETREATING : -ESPECTRO_V_RETREATING;
			}

			if (!phidden) _en_state = 1;

			if (enf_x [gpit] < 0 | 
				enf_x [gpit] > 240 << FIX_BITS ||
				enf_y [gpit] < 0 ||
				enf_y [gpit] > 192 << FIX_BITS) _en_state = 0;

			break;
		case 3:
			// Stopped
			enf_vx [gpit] = enf_vy [gpit] = 0;
			if (_en_ct) _en_ct --; else _en_state = 2;
			break;
	}

	// Horizontal
	enf_x [gpit] += enf_vx [gpit]; 
	enf_y [gpit] += enf_vy [gpit]; 
	
	_en_x = enf_x [gpit] >> FIX_BITS;
	_en_y = enf_y [gpit] >> FIX_BITS;
	
	spr_id = _en_state ? ESPECTRO_CELL_BASE + ((frame_counter >> 3) & 3) : 0xff;
	// enems_spr ();
