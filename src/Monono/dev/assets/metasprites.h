// MT MK2 NES v0.1
// Copyleft 2016 by The Mojon Twins

// Metaspriteset

#include "assets/spritedata.h"
#include "assets/spritedata_lah.h"

// Of course, you have to somewhat customize this for every game and make it fit.

// Each sprite: two frames right [a] and left [b].
const unsigned char * const spr_enems [] = {
	// Enems for Monono
	ssen0_00_a, ssen0_01_a, ssen0_00_b, ssen0_01_b, 
	ssen0_02_a, ssen0_03_a, ssen0_02_b, ssen0_03_b, 
	ssen0_04_a, ssen0_05_a, ssen0_04_b, ssen0_05_b, 
	ssplat0, ssplat0, ssplat0, ssplat0,

	// Enems for Jet Puri
	ssen1_00_a, ssen1_01_a, ssen1_00_b, ssen1_01_b, 
	ssen1_02_a, ssen1_03_a, ssen1_02_b, ssen1_03_b, 
	ssen1_04_a, ssen1_05_a, ssen1_04_b, ssen1_05_b, 
	ssplat1, ssplat1, ssplat1, ssplat1,

	// Extra.
	// 32...
	ssenextra0_00, ssenextra0_01, ssenextra0_02, ssenextra0_03,

	// 36

	// Enems for Lala Lah
	ssen_lah_00_a, ssen_lah_01_a, ssen_lah_00_b, ssen_lah_01_b, 
	ssen_lah_02_a, ssen_lah_03_a, ssen_lah_02_b, ssen_lah_03_b, 
	ssen_lah_04_a, ssen_lah_05_a, ssen_lah_04_b, ssen_lah_05_b, 
	ssen_lah_06_a, ssen_lah_07_a, ssen_lah_06_b, ssen_lah_07_b,

	// Enems for PPPP
	ssen_pppp_00_a, ssen_pppp_01_a, ssen_pppp_00_b, ssen_pppp_01_b, 
	ssen_pppp_02_a, ssen_pppp_03_a, ssen_pppp_02_b, ssen_pppp_03_b, 
	ssen_pppp_04_a, ssen_pppp_05_a, ssen_pppp_04_b, ssen_pppp_05_b, 
	ssen_pppp_06_a, ssen_pppp_07_a, ssen_pppp_06_b, ssen_pppp_07_b
};

const unsigned char * const spr_player [] = {
	// Player sprite for Monono
	// Facing right...
	sspl0_00_a,											// Standing
	sspl0_01_a, sspl0_02_a, sspl0_03_a, sspl0_04_a,		// Walk cycle
	sspl0_05_a,											// Descending
	sspl0_06_a,											// Ascending
	sspl0_07_a,											// Hit

	// Facing left...
	sspl0_00_b,											// Standing
	sspl0_01_b, sspl0_02_b, sspl0_03_b, sspl0_04_b,		// Walk cycle
	sspl0_05_b,											// Descending
	sspl0_06_b,											// Ascending
	sspl0_07_b,											// Hit

	// Player sprite for Jet Puri
	// Facing right...
	sspl1_00_a,											// Standing
	sspl1_01_a, sspl1_02_a, sspl1_03_a, sspl1_04_a,		// Walk cycle
	sspl1_05_a,											// Descending
	sspl1_06_a,											// Ascending
	sspl1_07_a,											// Airborne

	// Facing left...
	sspl1_00_b,											// Standing
	sspl1_01_b, sspl1_02_b, sspl1_03_b, sspl1_04_b,		// Walk cycle
	sspl1_05_b,											// Descending
	sspl1_06_b,											// Ascending
	sspl1_07_b,											// Airborne

	// 32
	// Player sprite for Lala
	// Facing right...
	sspl_lah_01_a,												// Standing
	sspl_lah_00_a, sspl_lah_01_a, sspl_lah_02_a, sspl_lah_01_a,	// Walk cycle
	sspl_lah_02_a,												// Descending
	sspl_lah_00_a, 												// Ascending
	sspl_lah_01_a,												// Air idle

	// Facing left...
	sspl_lah_01_b,												// Standing
	sspl_lah_00_b, sspl_lah_01_b, sspl_lah_02_b, sspl_lah_01_b,	// Walk cycle
	sspl_lah_02_b,												// Descending
	sspl_lah_00_b, 												// Ascending
	sspl_lah_01_b,												// Air idle

	// 48

	// Player sprite for Lala (upside down)
	// Facing right...
	sspl_pppp_01_a,												// Standing
	sspl_pppp_00_a, sspl_pppp_01_a, sspl_pppp_02_a, sspl_pppp_01_a,	// Walk cycle
	sspl_pppp_02_a,												// Descending
	sspl_pppp_00_a, 												// Ascending
	sspl_pppp_01_a,												// Air idle

	// Facing left...
	sspl_pppp_01_b,												// Standing
	sspl_pppp_00_b, sspl_pppp_01_b, sspl_pppp_02_b, sspl_pppp_01_b,	// Walk cycle
	sspl_pppp_02_b,												// Descending
	sspl_pppp_00_b, 												// Ascending
	sspl_pppp_01_b,												// Air idle

	// 64

	// Player sprite for Monona
	// Facing right...
	sspl2_00_a,											// Standing
	sspl2_01_a, sspl2_02_a, sspl2_03_a, sspl2_04_a,		// Walk cycle
	sspl2_05_a,											// Descending
	sspl2_06_a,											// Ascending
	sspl2_07_a,											// Hit

	// Facing left...
	sspl2_00_b,											// Standing
	sspl2_01_b, sspl2_02_b, sspl2_03_b, sspl2_04_b,		// Walk cycle
	sspl2_05_b,											// Descending
	sspl2_06_b,											// Ascending
	sspl2_07_b											// Hit
};

const unsigned char sprplempty [] = {
	-4, -8, 0, 0, 4, -8, 0, 0, 
	-4, 0, 0, 0, 4, 0, 0, 0, 
	-4, 8, 0, 0, 4, 8, 0, 0, 
	0x80
};

// Items are: [nothing] object key refill
// The wasted space saves a bit of code
const unsigned char * const spr_items [] = {
	// Items for Monono
	0, ssit0_00, ssit0_01, ssit0_02,

	// Items for Jet Puri
	0, ssit1_00, ssit1_01, ssit1_02,

	// Items for MONONA
	0, ssit2_00, ssit2_01, ssit2_02,

	// Items for Lala Lah
	0, ssit_lah_00, ssit_lah_01, ssit_lah_02,

	// Items for PPPP
	0, ssit_pppp_00, ssit_pppp_01, ssit_pppp_02
};
