// Cheril: the Nine
// Copyleft 2016 by The Mojon Twins

// Metaspriteset

#include "assets/spritedata.h"
#include "assets/spritedata2.h"

const unsigned char * const spr_enems [] = {
	// six regular enemies. 1st is the fish. R1 R2 L1 L2
	spr_en1_00_a, spr_en1_01_a, spr_en1_00_b, spr_en1_01_b, 
	spr_en1_02_a, spr_en1_03_a, spr_en1_02_b, spr_en1_03_b,
	spr_en1_04_a, spr_en1_05_a, spr_en1_04_b, spr_en1_05_b, 
	spr_en1_06_a, spr_en1_07_a, spr_en1_06_b, spr_en1_07_b,
	spr_en1_08_a, spr_en1_09_a, spr_en1_08_b, spr_en1_09_b, 
	spr_en1_0A_a, spr_en1_0B_a, spr_en1_0A_b, spr_en1_0B_b,

	// Enemy generator, idx = 24
	spr_en2_00, spr_en2_01,

	// Walker, idx = 26 R1 R2 L1 L2 D1 D2 U1 U2 HIT
	spr_en3_00_a, spr_en3_01_a, spr_en3_00_b, spr_en3_01_b,
	spr_en4_00, spr_en4_01, spr_en4_02, spr_en4_03, 
	spr_en4_04,

	// Explosion, idx = 35
	spr_en2_02,

	// Mega Meghan, 36 ...
	spr_en_meghan_00_a, spr_en_meghan_01_a, spr_en_meghan_00_b, spr_en_meghan_01_b,
	spr_en_meghan_02_a, spr_en_meghan_03_a, spr_en_meghan_02_b, spr_en_meghan_03_b,
	spr_en_meghan_04_a, spr_en_meghan_05_a, spr_en_meghan_04_b, spr_en_meghan_05_b,
	spr_en_meghan_06_a, spr_en_meghan_07_a, spr_en_meghan_06_b, spr_en_meghan_07_b,

	// 52 smoke
	spr_it_meghan_03
};

const unsigned char * const spr_player [] = {
	spr_pl_00, spr_pl_01, spr_pl_02, spr_pl_03, spr_pl_04, spr_pl_05,	// RIGHT
	spr_pl_06, spr_pl_07, spr_pl_08, spr_pl_09, spr_pl_0A, spr_pl_0B,	// LEFT
	spr_pl_0C, spr_pl_0D, spr_pl_0E, spr_pl_0F, spr_pl_10, spr_pl_11,	// DOWN
	spr_pl_12, spr_pl_13, spr_pl_14, spr_pl_15, spr_pl_16, spr_pl_17,	// UP
	spr_pl_18, spr_pl_19,												// HIT

	// 26
	// IDLE W1 W2 W3 W4 NULL (saves code)
	spr_pl_meghan_00, spr_pl_meghan_01, spr_pl_meghan_02, spr_pl_meghan_03, spr_pl_meghan_04, 0,	// RIGHT
	spr_pl_meghan_05, spr_pl_meghan_06, spr_pl_meghan_07, spr_pl_meghan_08, spr_pl_meghan_09, 0,	// LEFT
	spr_pl_meghan_0A, spr_pl_meghan_0B, spr_pl_meghan_0C, spr_pl_meghan_0D, spr_pl_meghan_0E, 0,	// DOWN
	spr_pl_meghan_0F, spr_pl_meghan_10, spr_pl_meghan_11, spr_pl_meghan_12, spr_pl_meghan_13, 0,	// UP

	// + 24
	spr_pl_meghan_nude_00, spr_pl_meghan_nude_01, spr_pl_meghan_nude_02, spr_pl_meghan_nude_03, spr_pl_meghan_nude_04, 0,	// RIGHT
	spr_pl_meghan_nude_05, spr_pl_meghan_nude_06, spr_pl_meghan_nude_07, spr_pl_meghan_nude_08, spr_pl_meghan_nude_09, 0,	// LEFT
	spr_pl_meghan_nude_0A, spr_pl_meghan_nude_0B, spr_pl_meghan_nude_0C, spr_pl_meghan_nude_0D, spr_pl_meghan_nude_0E, 0,	// DOWN
	spr_pl_meghan_nude_0F, spr_pl_meghan_nude_10, spr_pl_meghan_nude_11, spr_pl_meghan_nude_12, spr_pl_meghan_nude_13, 0		// UP
};

const unsigned char * const spr_items [] = {
	spr_hos_00, spr_hos_01, spr_hos_02, spr_hos_03,
	spr_it_02,

	// hrt + 4:
	spr_it_meghan_00, spr_it_meghan_01, spr_it_meghan_02, spr_it_meghan_04
};

const unsigned char * const spr_ending [] = {
	spr_ending_00, spr_ending_01, spr_ending_02, spr_ending_03
};

const unsigned char sprplempty [] = {
	-4, -8, 0, 0, 4, -8, 0, 0, 
	-4, 0, 0, 0, 4, 0, 0, 0, 
	-4, 8, 0, 0, 4, 8, 0, 0, 
	0x80
};
