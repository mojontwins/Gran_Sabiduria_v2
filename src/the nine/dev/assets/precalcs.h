// Cheril: the Nine
// Copyleft 2016 by The Mojon Twins

const unsigned char bitmasks [] = {0xfc, 0xf3, 0xcf, 0x3f};

// RIGHT LEFT DOWN UP
const signed char en_dx [] = {1, -1, 0, 0};
const signed char en_dy [] = {0, 0, 1, -1};
const signed char boffsx [] = {
	8, -4, 0, 0, 		// Cheril
	4, -4, -5, 6, 		// Meghan
};
const signed char boffsy [] = {
	5, 5, 12, -4, 		// Cheril
	1, 1, 7, 8 			// Meghan
};

const unsigned char jitter [] = {
	0,1,1,0,0,1,0,1,1,0,0,0,1,0,1,1
};

// 9 + cheril
const unsigned char ending_x [] = {
	48, 51, 67, 106, 108, 145, 143, 212, 214
};

const unsigned char ending_y [] = {
	80, 131, 106, 82, 130, 84, 129, 81, 136
};
