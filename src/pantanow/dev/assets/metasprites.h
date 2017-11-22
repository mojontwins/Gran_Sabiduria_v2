// Pantanow Engine rev2b 201703
// Copyleft 2016 by The Mojon Twins

// Metaspriteset

#include "assets/spritedata.h"

// RIGHT LEFT DOWN UP
// IDLE W1 W2 W3 W4 FIRING
const unsigned char * const spr_player1 [] = {
	sspl_00, sspl_01, sspl_02, sspl_03, sspl_04, sspl_05, 
	sspl_06, sspl_07, sspl_08, sspl_09, sspl_0A, sspl_0B, 
	sspl_0C, sspl_0D, sspl_0E, sspl_0F, sspl_10, sspl_11, 
	sspl_12, sspl_13, sspl_14, sspl_15, sspl_16, sspl_17, 
	sspl_18, sspl_19, sspl_1A, sspl_1B, sspl_1C, sspl_1D
};

// RIGHT LEFT
// W1 W2 W3 W4 I1 I2 D F
const unsigned char * const spr_enems1 [] = {
// W1 W2 W3 W4 I1 I2 D F
	ssena_00_a, ssena_01_a, ssena_02_a, ssena_03_a, ssena_04_a, ssena_05_a, ssena_06_a, ssena_07_a,
	ssena_00_b, ssena_01_b, ssena_02_b, ssena_03_b, ssena_04_b, ssena_05_b, ssena_06_b, ssena_07_b,

	ssena_08_a, ssena_09_a, ssena_0A_a, ssena_0B_a, ssena_0C_a, ssena_0D_a, ssena_0E_a, ssena_0F_a, 
	ssena_08_b, ssena_09_b, ssena_0A_b, ssena_0B_b, ssena_0C_b, ssena_0D_b, ssena_0E_b, ssena_0F_b, 

// R L U D DIE HEART
	ssenb_00, ssenb_01, ssenb_02, ssenb_03, ssenb_04, ssenb_05
};

const unsigned char sprplempty [] = {
	-4, -8, 0, 0, 4, -8, 0, 0, 
	-4, 0, 0, 0, 4, 0, 0, 0, 
	-4, 8, 0, 0, 4, 8, 0, 0, 
	0x80
};

const unsigned char * const spr_title [] = {
	sstitle_pantanow_00, sstitle_pantanow_01
};

#include "assets/spritedata2.h"
#include "assets/spritedata3.h"

// RIGHT LEFT DOWN UP
// IDLE W1 W2 W3 W4 FIRING
const unsigned char * const spr_player2 [] = {
	sspl2_00, sspl2_01, sspl2_02, sspl2_03, sspl2_04, sspl2_05, 
	sspl2_06, sspl2_07, sspl2_08, sspl2_09, sspl2_0A, sspl2_0B, 
	sspl2_0C, sspl2_0D, sspl2_0E, sspl2_0F, sspl2_10, sspl2_11, 
	sspl2_12, sspl2_13, sspl2_14, sspl2_15, sspl2_16, sspl2_17, 
	sspl2_18, sspl2_19, sspl2_1A, sspl2_1B, sspl2_1C, sspl2_1D
};

// RIGHT LEFT
// W1 W2 W3 W4 I1 I2 D F
const unsigned char * const spr_enems2 [] = {
	// W1 W2 W3 W4 I1 I2 D F
	// 0 = 0
	ssen2a_00_a, ssen2a_01_a, ssen2a_02_a, ssen2a_03_a, ssen2a_04_a, ssen2a_05_a, ssen2a_06_a, ssen2a_07_a,
	ssen2a_00_b, ssen2a_01_b, ssen2a_02_b, ssen2a_03_b, ssen2a_04_b, ssen2a_05_b, ssen2a_06_b, ssen2a_07_b,

	// 1 = 16
	ssen2a_08_a, ssen2a_09_a, ssen2a_0A_a, ssen2a_0B_a, ssen2a_0C_a, ssen2a_0D_a, ssen2a_0E_a, ssen2a_0F_a, 
	ssen2a_08_b, ssen2a_09_b, ssen2a_0A_b, ssen2a_0B_b, ssen2a_0C_b, ssen2a_0D_b, ssen2a_0E_b, ssen2a_0F_b, 

	// R L U D DIE HEART +pad
	// 2 = 32
	ssen2b_00, ssen2b_01, ssen2b_02, ssen2b_03, ssen2b_04, ssen2b_05, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,

	// 3 = 48 [BOSS]
	ssen2boss_00, ssen2boss_01, ssen2boss_00, ssen2boss_01, 
	ssen2boss_00, ssen2boss_01, ssen2boss_02, ssen2boss_03,
	ssen2boss_00, ssen2boss_01, ssen2boss_00, ssen2boss_01, 
	ssen2boss_00, ssen2boss_01, ssen2boss_02, ssen2boss_03
};

