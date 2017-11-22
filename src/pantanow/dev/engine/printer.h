// Pantanow Engine rev2b 201703
// Copyleft 2016 by The Mojon Twins

// printer.h - Printing functions

void fade_out (void) { fader = 5; while (fader --) { pal_bright (fader); ppu_wait_frame (); } }
	
void fade_in (void) { fader = 5; while (fader --) { pal_bright (4 - fader); ppu_wait_frame (); } }
	
void cls (void) { vram_adr (NAMETABLE_A); vram_fill (0xff, 960); vram_fill (level == 2 ? 0xff : 0x55, 64); }

void reset_attributes (void) {
	gpit = 64; while (gpit --) attr_table [gpit] = 0x55;
}

void show_attributes (void) {
	vram_adr (NAMETABLE_A + 0x03c0);
	vram_write (attr_table, 64);
}

void p_t2 (unsigned char x, unsigned char y, unsigned char n) {
	gp_addr = NAMETABLE_A + (y << 5) + x;
	*ul ++ = MSB (gp_addr) | NT_UPD_HORZ;
	*ul ++ = LSB (gp_addr);
	*ul ++ = 2;	
	*ul ++ = DIGIT ((n / 10));
	*ul ++ = DIGIT ((n % 10));
}

void p_s (unsigned char x, unsigned char y, const unsigned char *s) {
	vram_adr (NAMETABLE_A + (y << 5) + x);
	while (0xff != (rdt = *s ++)) vram_put (rdt);
}