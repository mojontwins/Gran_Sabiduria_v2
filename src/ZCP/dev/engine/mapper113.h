// MT MK2 NES v0.3
// Copyleft 2016 by The Mojon Twins

// Communication pool utilites.

void m113_handle_reset (void) {
	rda = 0; for (gpit = 1; gpit < 15; gpit ++) rda += COMM_POOL [gpit];
	if (COMM_CHECKSUM == rda) {
		COMM_CHECKSUM = 0xff; return;
	}
	COMM_GAME_SELECT = 0x00; COMM_REG = 0x00; 
	__asm__ ("jmp _change_rom");	
}
