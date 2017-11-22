// MT MK2 NES v0.3
// Copyleft 2016 by The Mojon Twins

// Metaspriteset

#include "assets/spritedata.h"
#include "assets/spritedata2.h"

// Of course, you have to somewhat customize this for every game and make it fit.

// Each sprite: two frames right [a] and left [b].
const unsigned char * const spr_enems [] = {
	// Enems for Bosque 1 (CHR ROM 1)
	ssen_00_a, ssen_01_a, ssen_00_b, ssen_01_b, 
	ssen_02_a, ssen_03_a, ssen_02_b, ssen_03_b, 
	ssen_04_a, ssen_05_a, ssen_04_b, ssen_05_b, 
	ssen_06_a, ssen_07_a, ssen_06_b, ssen_07_b,

	// Cannon. Offset = 32, encelloffset = 16, define = 16, please
	ssen_cannon_00, ssen_cannon_01, ssen_cannon_02, ssen_cannon_03,

	// encelloffset = 20 para enemigos del beberito
	ssen3_00_a, ssen3_01_a, ssen3_00_b, ssen3_01_b, 
	ssen3_02_a, ssen3_03_a, ssen3_02_b, ssen3_03_b, 
	ssen3_04_a, ssen3_05_a, ssen3_04_b, ssen3_05_b, 
	ssen3_06_a, ssen3_07_a, ssen3_06_b, ssen3_07_b
};

const unsigned char * const spr_player [] = {
	sspl_cheril_00, sspl_cheril_01, sspl_cheril_02, sspl_cheril_03, sspl_cheril_04,								// RIGHT
	sspl_cheril_05, sspl_cheril_06, sspl_cheril_07, sspl_cheril_08, sspl_cheril_09,								// LEFT
	sspl_cheril_0A, sspl_cheril_0B, sspl_cheril_0C, sspl_cheril_0D, sspl_cheril_0E,								// DOWN
	sspl_cheril_0F, sspl_cheril_10, sspl_cheril_11, sspl_cheril_12, sspl_cheril_13,								// UP
	sspl_cheril_14, sspl_cheril_15,

	sspl_ninjajar_00, sspl_ninjajar_01, sspl_ninjajar_02, sspl_ninjajar_03, sspl_ninjajar_04,					// RIGHT
	sspl_ninjajar_05, sspl_ninjajar_06, sspl_ninjajar_07, sspl_ninjajar_08, sspl_ninjajar_09,					// LEFT
	sspl_ninjajar_0A, sspl_ninjajar_0B, sspl_ninjajar_0C, sspl_ninjajar_0D, sspl_ninjajar_0E, 					// DOWN
	sspl_ninjajar_0F, sspl_ninjajar_10, sspl_ninjajar_11, sspl_ninjajar_12, sspl_ninjajar_13,					// UP
	sspl_ninjajar_14, sspl_ninjajar_15,

	sspl_cheril_baby_00, sspl_cheril_baby_01, sspl_cheril_baby_02, sspl_cheril_baby_03, sspl_cheril_baby_04,	// RIGHT
	sspl_cheril_baby_05, sspl_cheril_baby_06, sspl_cheril_baby_07, sspl_cheril_baby_08, sspl_cheril_baby_09,	// LEFT
	sspl_cheril_baby_0A, sspl_cheril_baby_0B, sspl_cheril_baby_0C, sspl_cheril_baby_0D, sspl_cheril_baby_0E,	// DOWN
	sspl_cheril_baby_0F, sspl_cheril_baby_10, sspl_cheril_baby_11, sspl_cheril_baby_12, sspl_cheril_baby_13,	// UP
	sspl_cheril_baby_14, sspl_cheril_baby_15
};

// Items are: [nothing] object key refill
// The wasted space saves a bit of code
const unsigned char * const spr_items [] = {
	// Plain
	0, ssit_00, ssit_01, ssit_02,

	// Extra, offset = 4
	0, ssit3_00, ssit3_01, ssit3_02
};

const unsigned char sprplempty [] = {
	-4, -8, 0, 0, 4, -8, 0, 0, 
	-4, 0, 0, 0, 4, 0, 0, 0, 
	-4, 8, 0, 0, 4, 8, 0, 0, 
	0x80
};
