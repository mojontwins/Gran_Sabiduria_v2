// Pantanow Engine rev2b 201703
// Copyleft 2016 by The Mojon Twins

// gbuffer.h - Circular game buffer

// This buffer contains a representation of an upacked screen
// (which is more or less what's shown on screen at once)

/*
unsigned char qtile (signed char x, signed char y) {
	if (x < 0 || x > 15) return 8;
	y -= map_tilepos;
	if (y < 0 || y > 15) return 0;
	return SCREEN_BUFFER [x + (((y + gbuffer_y) & 15) << 4)];
}
*/
unsigned char attr (signed char x, signed char y) {
	if (x < 0 || x > 15) return 8;
	y -= map_tilepos;
	if (y < 0 || y > 15) return 0;
	return behs [SCREEN_BUFFER [x + (((y + gbuffer_y) & 15) << 4)]];
}

void cm_two_points (void) {
	/*
	at1 = attr (cx1, cy1);
	at2 = attr (cx2, cy2);
	*/
	caux = cy1 - map_tilepos; at1 = behs [SCREEN_BUFFER [cx1 + (((caux + gbuffer_y) & 15) << 4)]];
	caux = cy2 - map_tilepos; at2 = behs [SCREEN_BUFFER [cx2 + (((caux + gbuffer_y) & 15) << 4)]];
}
