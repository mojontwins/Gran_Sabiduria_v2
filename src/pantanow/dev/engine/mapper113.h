// MT MK2 NES v0.3
// Copyleft 2016 by The Mojon Twins

// Communication pool utilites.
// Needs 
// #define COMM_POOL ((unsigned char*)0x0300)
// #define COMM_CHECKSUM COMM_POOK [0xf]

// Mapper 11 (Colordreams) is MCPPPCCC

void m113_comm_pool_checksum_calculate (void) {
	rda = 0; for (gpit = 1; gpit < 15; gpit ++) rda += COMM_POOL [gpit];
}

// You can comment out these from "head" ROM if space is tight:

unsigned char m113_comm_pool_checksum_check (void) {
	m113_comm_pool_checksum_calculate ();	// Written to rda
	return (COMM_CHECKSUM == rda);
}

void m113_handle_reset (void) {
	if (m113_comm_pool_checksum_check ()) {
		COMM_CHECKSUM = 0xff; 				// Bad
		return;
	}
	COMM_GAME_SELECT = 0x00;
	COMM_REG = 0x80; // MCPPPCCC
	__asm__ ("jmp _change_rom");
}
