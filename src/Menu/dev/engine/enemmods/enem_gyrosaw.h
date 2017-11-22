// MT MK2 NES v0.6
// Copyleft 2016 by The Mojon Twins

	// Gyrosaws
	// Clockwise is L U R D, place here:
	// ···
	// ·Xv
	// ·<o with SPEED = 1

	// Counter-clockwise is L D R U, place here:
	// ·<o
	// ·X^
	// ··· with SPEED = 0

	// en_r is GYROSAW_STATE.
	// en_mx is GYROSAW_COUNTER.
	// en_my = 1 means "clockwise" GYROSAW_DIRECTION
	
	if (half_life) {
		delta = (GYROSAW_DIRECTION [gpit] ? (GYROSAW_STATE [gpit] >> 1) : (((GYROSAW_STATE [gpit] + 1) & 3) >> 1)) ? GYROSAW_V : -GYROSAW_V;
		if (GYROSAW_STATE [gpit] & 1) en_y [gpit] += delta; else en_x [gpit] += delta;
		GYROSAW_COUNTER [gpit] = (GYROSAW_COUNTER [gpit] + GYROSAW_V) & 31; if (!GYROSAW_COUNTER [gpit]) GYROSAW_STATE [gpit] = (GYROSAW_STATE [gpit] + 1) & 3;
	}
	
	spr_id = GYROSAW_CELL_BASE + half_life;
	enems_spr ();
