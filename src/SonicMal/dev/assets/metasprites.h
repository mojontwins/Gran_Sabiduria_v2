// MT MK2 NES v0.86 - Sonic Bad is bad
// Copyleft 2017 by The Mojon Twins

// Metaspritesets (in nice arrays)

#include "assets/spritedata.h"

// Of course, you have to somewhat customize this for every game and make it fit.

// Rock the Kashbah
const unsigned char * const spr_enems_0 [] = {
	// Enems
	ssen0_00_a, ssen0_01_a, ssen0_00_b, ssen0_01_b, 
	ssen0_02_a, ssen0_03_a, ssen0_02_b, ssen0_03_b, 
	ssen0_04_a, ssen0_05_a, ssen0_04_b, ssen0_05_b, 
	ssen0_06_a, ssen0_07_a, ssen0_06_a, ssen0_07_a, 

	// Extra.
	// 16: monococo
	ssenextra_00_a, ssenextra_01_a, ssenextra_00_b, ssenextra_01_b,

	// 20: fanty
	ssenfanty_00_a, ssenfanty_01_a, ssenfanty_00_b, ssenfanty_01_b,

	// 24: Tronquito (0x26)
	ssentronquit_00, ssentronquit_01, ssentronquit_00, ssentronquit_01,

	// 28: catacrock (3 + 1 (NULL))
	ssencatacrock_00, ssencatacrock_01, ssencatacrock_02, 0
};

// RIGHT, LEFT x IDLE, W1 W2 W3 W4, UP, DOWN
// Sonic
const unsigned char * const spr_player_0 [] = {
	// Facing right...
	sspla0_01_a,										// Standing
	sspla0_01_a, sspla0_02_a, sspla0_01_a, sspla0_00_a,	// Walk cycle
	ssplb0_00, ssplb0_01, ssplb0_00, ssplb0_02,			// Ball cycle
	sspla0_02_a,										// Falling
	sspla0_03_a,										// Hit
	0,

	sspla0_01_b,										// Standing
	sspla0_01_b, sspla0_02_b, sspla0_01_b, sspla0_00_b,	// Walk cycle
	ssplb0_00, ssplb0_01, ssplb0_00, ssplb0_02,			// Ball cycle
	sspla0_02_b,										// Falling
	sspla0_03_b,										// Hit
	0,
};

// Espinete
const unsigned char * const spr_player_1 [] = {
	sspla1_01_a,										// Standing
	sspla1_01_a, sspla1_02_a, sspla1_01_a, sspla1_00_a,	// Walk cycle
	sspla1_00_a, sspla1_00_a, sspla1_00_a, sspla1_00_a,	// Jump / pad unused
	sspla1_02_a,										// Falling
	sspla1_03_a,										// Hit
	0,

	sspla1_01_b,										// Standing
	sspla1_01_b, sspla1_02_b, sspla1_01_b, sspla1_00_b,	// Walk cycle
	sspla1_00_b, sspla1_00_b, sspla1_00_b, sspla1_00_b,	// Jump / pad unused
	sspla1_02_b,										// Falling
	sspla1_03_b,										// Hit
	0
};

// Somari
const unsigned char * const spr_player_2 [] = {
	sspla2_00_a,										// Standing
	sspla2_00_a, sspla2_01_a, sspla2_02_a, sspla2_03_a,	// Walk cycle
	sspla2_00_a, sspla2_00_a, sspla2_00_a, sspla2_00_a,	// Jump / pad unused
	sspla2_02_a,										// Falling
	sspla2_01_a,										// Hit
	0,

	sspla2_00_b,										// Standing
	sspla2_03_b, sspla2_02_b, sspla2_01_b, sspla2_00_b,	// Walk cycle
	sspla2_00_b, sspla2_00_b, sspla2_00_b, sspla2_00_b,	// Jump / pad unused
	sspla2_02_b,										// Falling
	sspla2_01_b,										// Hit
	0
};

// Items 
const unsigned char * const spr_items [] = {
	0, sscarthe, ssit0_01, ssit0_02, ssemerald, ssit0b
};

// FUCK

const unsigned char sprplempty [] = {
	-4, -8, 0, 0, 4, -8, 0, 0, 
	-4, 0, 0, 0, 4, 0, 0, 0, 
	-4, 8, 0, 0, 4, 8, 0, 0, 
	0x80
};

// CUSTOM { 
// Sprites for the title screen
const unsigned char * const spr_title [] = {
	sstitle0_00, sstitle0_01, sstitle0_02,
	sstitle1_00, sstitle1_01, sstitle1_02
};

// Sprites for the rotating ring
const unsigned char * const spr_ring [] = {
	ssit0_00, ssring_00, ssring_01, ssring_02
};
// } END_OF_CUSTOM
