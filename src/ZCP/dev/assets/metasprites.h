// MT MK2 NES v0.7a
// Copyleft 2016 by The Mojon Twins

// Metaspriteset

#include "assets/spritedata.h"

// Customize as fit

const unsigned char * const spr_enems0 [] = {
	// ZCP
	ssen_00, ssen_01, ssen_02, ssen_03,
	ssen_04, ssen_05, ssen_06, ssen_07,
	ssen_08, ssen_09, ssen_0A, ssen_0B,
	ssen_0C, ssen_0D, ssen_0E, ssen_0F,
	// 16: Saw
	sssaw_00, sssaw_01
};

const unsigned char * const spr_player0 [] = {
	// ZCP

	// Santos...
	// RIGHT
	sspla_00_a,								// IDLE
	sspla_01_a, 							// FIRING
	sspla_02_a, sspla_03_a, sspla_04_a, 	// /
	sspla_05_a, sspla_06_a, sspla_07_a, 	// \ WALK CYCLE
	sspla_08_a, 							// ASCENDING
	sspla_09_a, 							// DESCENDING

	// LEFT
	sspla_00_b,								// IDLE
	sspla_01_b, 							// FIRING
	sspla_02_b, sspla_03_b, sspla_04_b, 	// /
	sspla_05_b, sspla_06_b, sspla_07_b, 	// \ WALK CYCLE
	sspla_08_b, 							// ASCENDING
	sspla_09_b	 							// DESCENDING
};

const unsigned char * const spr_player1 [] = {
	// María
	// RIGHT
	ssplb_00_a,								// IDLE
	ssplb_01_a, 							// FIRING
	ssplb_02_a, ssplb_03_a, ssplb_04_a, 	// /
	ssplb_05_a, ssplb_06_a, ssplb_07_a, 	// \ WALK CYCLE
	ssplb_08_a, 							// ASCENDING
	ssplb_09_a, 							// DESCENDING

	// LEFT
	ssplb_00_b,								// IDLE
	ssplb_01_b, 							// FIRING
	ssplb_02_b, ssplb_03_b, ssplb_04_b, 	// /
	ssplb_05_b, ssplb_06_b, ssplb_07_b, 	// \ WALK CYCLE
	ssplb_08_b, 							// ASCENDING
	ssplb_09_b, 							// DESCENDING
};

const unsigned char * const spr_player2 [] = {
	// YUN
	ssyun_00_a,                                   // IDLE
	ssyun_01_a, ssyun_02_a, ssyun_03_a, ssyun_04_a,  // WALK
	ssyun_05_a,                                   // UP
	ssyun_06_a,                                   // DOWN

	ssyun_00_b,                                   // IDLE
	ssyun_04_b, ssyun_03_b, ssyun_02_b, ssyun_01_b,  // WALK
	ssyun_05_b,                                   // UP
	ssyun_06_b,                                   // DOWN
};

const unsigned char * const spr_fabolee [] = {
	ssfabolee_00, ssfabolee_01, ssfabolee_02, ssfabolee_01
};

// Items are: [nothing] object key refill
// The wasted space saves a bit of code
const unsigned char * const spr_items [] = {
	// ZCP
	0, ssit_00, 0, ssit_01, ssit_05, ssit_06, ssit_07, ssit_08, ssit_09, ssit_0A
};

const unsigned char sprplempty [] = {
	-4, -8, 0, 0, 4, -8, 0, 0, 
	-4, 0, 0, 0, 4, 0, 0, 0, 
	-4, 8, 0, 0, 4, 8, 0, 0, 
	0x80
};
