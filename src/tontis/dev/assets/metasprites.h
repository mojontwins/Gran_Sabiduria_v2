// MT MK2 NES v0.4
// Copyleft 2016 by The Mojon Twins

// Metaspriteset

#include "assets/spritedata.h"
#include "assets/spritedata2.h"
#include "assets/spritedata3.h"

// Of course, you have to somewhat customize this for every game and make it fit.

// *********
// POTI POTI
// *********

// Each sprite: two frames right [a] and left [b].
const unsigned char * const spr_enems_potipoti [] = {
	ssen_potipoti_a_00_a, ssen_potipoti_a_01_a, ssen_potipoti_a_00_b, ssen_potipoti_a_01_b,
	ssen_potipoti_b_00_a, ssen_potipoti_b_01_a, ssen_potipoti_b_00_b, ssen_potipoti_b_01_b, 
	0, 0, 0, 0,
	ssen_potipoti_c, ssen_potipoti_c, ssen_potipoti_c, ssen_potipoti_c
};

const unsigned char * const spr_player_potipoti [] = {
	sspl_potipoti_00_a, sspl_potipoti_01_a, sspl_potipoti_02_a,	// W1 W2 J RIGHT
	sspl_potipoti_00_b, sspl_potipoti_01_b, sspl_potipoti_02_b  // W1 W2 J LEFT
};

// Items are: [nothing] object key refill
// The wasted space saves a bit of code
const unsigned char * const spr_items_potipoti [] = {
	0, ssit_potipoti
};

// **********
// RENDEZVOUS
// **********

// A bit of dirtyness ensues...
const unsigned char * const spr_enems_rendezvous [] = {
	ssen_rendezvous_a_00_a, ssen_rendezvous_a_01_a, ssen_rendezvous_a_00_b, ssen_rendezvous_a_01_b, 	// Linear sprid #0
	ssen_rendezvous_a_02_a, ssen_rendezvous_a_03_a, ssen_rendezvous_a_02_b, ssen_rendezvous_a_03_b, 	// Linear sprid #1
	ssen_rendezvous_a_04_a, ssen_rendezvous_a_05_a, ssen_rendezvous_a_04_b, ssen_rendezvous_a_05_b, 	// Monococo, base = 8
	ssen_rendezvous_c_00, ssen_rendezvous_c_01, ssen_rendezvous_c_00, ssen_rendezvous_c_01, 			// Platform sprid #3
	ssen_rendezvous_b_00, ssen_rendezvous_b_01	 														// Gyrosaw, base = 16
};

// P1, P2; RIGHT, LEFT; IDLE, W1 W2 W3 W4, UP, DOWN
const unsigned char * const spr_player_rendezvous [] = {
	sspl_rendezvous_00_a, sspl_rendezvous_01_a, sspl_rendezvous_02_a, sspl_rendezvous_03_a, sspl_rendezvous_04_a, sspl_rendezvous_05_a, sspl_rendezvous_06_a, // P1 RIGHT
	sspl_rendezvous_00_b, sspl_rendezvous_01_b, sspl_rendezvous_02_b, sspl_rendezvous_03_b, sspl_rendezvous_04_b, sspl_rendezvous_05_b, sspl_rendezvous_06_b, // P1 LEFT

	sspl_rendezvous_07_a, sspl_rendezvous_08_a, sspl_rendezvous_09_a, sspl_rendezvous_0A_a, sspl_rendezvous_0B_a, sspl_rendezvous_0C_a, sspl_rendezvous_0D_a, // P2 RIGHT
	sspl_rendezvous_07_b, sspl_rendezvous_08_b, sspl_rendezvous_09_b, sspl_rendezvous_0A_b, sspl_rendezvous_0B_b, sspl_rendezvous_0C_b, sspl_rendezvous_0D_b // P2 LEFT
};

// Items are: [nothing] object key refill
// The wasted space saves a bit of code
const unsigned char * const spr_items_rendezvous [] = {
	0, ssit_potipoti, ssit_potipoti, ssit_potipoti
};

// ***************************
// VIAJE AL CENTRO DE LA NAPIA
// ***************************

// Rock the Kashbah
const unsigned char * const spr_enems_napia [] = {
	ssen_napia_00_a, ssen_napia_01_a, ssen_napia_00_b, ssen_napia_01_b, 
	ssen_napia_02_a, ssen_napia_03_a, ssen_napia_02_b, ssen_napia_03_b, 
	ssen_napia_04_a, ssen_napia_05_a, ssen_napia_04_b, ssen_napia_05_b, 
	ssmp_napia_00, ssmp_napia_01, ssmp_napia_00, ssmp_napia_01
};

// RIGHT, LEFT; IDLE, W1 W2 W3 W4, UP, DOWN
const unsigned char * const spr_player_napia [] = {
	sspl_napia_00_a, sspl_napia_01_a, sspl_napia_02_a, sspl_napia_03_a, sspl_napia_04_a, sspl_napia_05_a, sspl_napia_06_a, sspl_napia_07_a, sspl_napia_08_a, // RIGHT
	sspl_napia_00_b, sspl_napia_01_b, sspl_napia_02_b, sspl_napia_03_b, sspl_napia_04_b, sspl_napia_05_b, sspl_napia_06_b, sspl_napia_07_b, sspl_napia_08_b, // LEFT

	// Reborde
	ssrb_napia_00_a, ssrb_napia_01_a, ssrb_napia_02_a, ssrb_napia_03_a, ssrb_napia_04_a, ssrb_napia_05_a, ssrb_napia_06_a, ssrb_napia_07_a, ssrb_napia_08_a, // RIGHT
	ssrb_napia_00_b, ssrb_napia_01_b, ssrb_napia_02_b, ssrb_napia_03_b, ssrb_napia_04_b, ssrb_napia_05_b, ssrb_napia_06_b, ssrb_napia_07_b, ssrb_napia_08_b // LEFT
};

// Items are: [nothing] object key refill
// The wasted space saves a bit of code
const unsigned char * const spr_items_napia [] = {
	0, ssit_napia_00, ssit_napia_01, ssit_napia_02, ssit_napia_04
};

// FUCK

const unsigned char sprplempty [] = {
	-4, -8, 0, 0, 4, -8, 0, 0, 
	-4, 0, 0, 0, 4, 0, 0, 0, 
	-4, 8, 0, 0, 4, 8, 0, 0, 
	0x80
};
