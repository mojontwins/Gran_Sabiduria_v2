// MT MK2 NES v0.6
// Copyleft 2016 by The Mojon Twins

// Metaspriteset

#include "assets/spritedata.h"
#include "assets/spritedata2.h"

// Customize as fit

const unsigned char * const spr_enems [] = {
	// Trabajo Basura
	ssen_tb_00, ssen_tb_01, ssen_tb_00, ssen_tb_01, 
	ssen_tb_02, ssen_tb_03, ssen_tb_02, ssen_tb_03, 
	ssen_tb_04, ssen_tb_05, ssen_tb_04, ssen_tb_05, 
	ssen_tb_06, ssen_tb_06, ssen_tb_06, ssen_tb_06,

	// Vesta Vaal (+16)

	ssen_vv_00_a, ssen_vv_01_a, ssen_vv_00_b, ssen_vv_01_b, 
	ssen_vv_02_a, ssen_vv_03_a, ssen_vv_02_b, ssen_vv_03_b, 
	ssen_vv_04_a, ssen_vv_05_a, ssen_vv_04_b, ssen_vv_05_b, 
	ssen2_vv_00, ssen2_vv_00, ssen2_vv_00, ssen2_vv_00,

	ssen2_vv_01
};

const unsigned char * const spr_player [] = {
	// Trabajo Basura

	// RIGHT
	sspl_tb_01_a, 												// STANDING
	sspl_tb_00_a, sspl_tb_01_a, sspl_tb_02_a, sspl_tb_01_a,		// WALK
	sspl_tb_03_a,												// ASCENDING
	sspl_tb_00_a,												// DESCENDING
	sspl_tb_02_a,												// HIT
	sspl_tb_04_a, 												// OBJECT

	// LEFT
	sspl_tb_01_b, 												// STANDING
	sspl_tb_00_b, sspl_tb_01_b, sspl_tb_02_b, sspl_tb_01_b,		// WALK
	sspl_tb_03_b,												// ASCENDING
	sspl_tb_00_b,												// DESCENDING
	sspl_tb_02_b,												// HIT
	sspl_tb_04_b, 												// OBJECT

	// Vesta Vaal
	// Offset = 18

	// BASIC
	// RIGHT
	sspl_vv_00_a,												// STANDING
	sspl_vv_01_a, sspl_vv_02_a, sspl_vv_03_a, sspl_vv_04_a,		// RUN
	sspl_vv_05_a,												// JUMP

	// LEFT (+6)
	sspl_vv_00_b,												// STANDING
	sspl_vv_01_b, sspl_vv_02_b, sspl_vv_03_b, sspl_vv_04_b,		// RUN
	sspl_vv_05_b,												// JUMP

	// ENH (+12) Offset = 30
	// RIGHT
	sspl_vv_06_a,												// STANDING
	sspl_vv_07_a, sspl_vv_08_a, sspl_vv_09_a, sspl_vv_0A_a,		// RUN
	sspl_vv_0B_a,												// JUMP

	// LEFT
	sspl_vv_06_b,												// STANDING
	sspl_vv_07_b, sspl_vv_08_b, sspl_vv_09_b, sspl_vv_0A_b,		// RUN
	sspl_vv_0B_b,												// JUMP

	// ENH FIRING (+24) Offset = 42
	// RIGHT
	sspl_vv_0C_a,												// STANDING
	sspl_vv_0D_a, sspl_vv_0E_a, sspl_vv_0F_a, sspl_vv_10_a,		// RUN
	sspl_vv_11_a,												// JUMP

	// RIGHT
	sspl_vv_0C_b,												// STANDING
	sspl_vv_0D_b, sspl_vv_0E_b, sspl_vv_0F_b, sspl_vv_10_b,		// RUN
	sspl_vv_11_b												// JUMP
};

// Items are: [nothing] object key refill
// The wasted space saves a bit of code
const unsigned char * const spr_items [] = {
	// Trabajo Basura
	0, ssit_tb_00, ssit_tb_01, ssit_tb_02, 

	// Vesta Vaal (+4)
	0, ssit_tb_00_a, 0, 0
};

const unsigned char sprplempty [] = {
	-4, -8, 0, 0, 4, -8, 0, 0, 
	-4, 0, 0, 0, 4, 0, 0, 0, 
	-4, 8, 0, 0, 4, 8, 0, 0, 
	0x80
};
