// Cheril: the Nine
// Copyleft 2016 by The Mojon Twins

// General stuff

void cm_two_points (void) {
	// Calculates at1 & at2 from cx1, cy1 & cx2, cy2
	at1 = scr_attr [cx1 + (cy1 << 4)];
	at2 = scr_attr [cx2 + (cy2 << 4)];
}

unsigned char collide (unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2) {
	return (x1 + 8 >= x2 && x1 <= x2 + 8 && y1 + 8 >= y2 && y1 <= y2 + 8);
}
