// Scripts

// These texts are not referenced as they are used
// directly:

// Indexes 0-5: character names.
// Index 6 "THIS IS..."
// Index 7, "YOU MUST TALK TO..."
// Index 8, "YOU ARE DONE WITH US!"
// Index 9, "NOW COLLECT THE NUTS!"

// Script for Johnny Limite

const unsigned char script_0 [] = {
	0,
	10, 11, 0, 0,
	0,
	12, 13, 14, 15,
	0,
	16, 17, 18, 19,
	0xfe
};

// Script for Ramire the Vampire

const unsigned char script_1 [] = {
	1,
	20, 21, 22, 0,
	0xff,
	23, 24, 25, 0,
	1,
	26, 27, 28, 29,
	0xff,
	30, 31, 0, 0,
	1,
	32, 33, 0, 0,
	0xfe
};

// Script for Amador
 
const unsigned char script_2 [] = {
	2, 
	34, 35, 36, 37,
	0xff,
	38, 39, 0, 0,
	2,
	40, 41, 42, 0,
	0xff,
	43, 44, 45, 46,
	0xfe
};

// Script for Yun

const unsigned char script_3 [] = {
	3,
	47, 48, 0, 0,
	0xff,
	49, 50, 0, 0,
	3,
	51, 52, 53, 54,
	0xff,
	55, 56, 0, 0,
	3,
	57, 58, 59, 0,
	0xfe
};

// Script for Sir Ababol

const unsigned char script_4 [] = {
	4, 
	60, 61, 62, 0,
	0xff,
	63, 0, 0, 0,
	4,
	64, 65, 66, 67,
	0xff,
	68, 0, 0, 0,
	4,
	69, 70, 0, 0,
	0xff,
	71, 0, 0, 0,
	0xfe
};

// Script for Lala

const unsigned char script_5 [] = {
	5,
	72, 73, 0, 0,
	0xff,
	74, 75, 76, 0,
	5,
	77, 78, 79, 80,
	0xff,
	81, 82, 0, 0,
	0xfe
};

// Scripts index

const unsigned char * const scripts [] = {
	script_0, script_1, script_2, script_3, script_4, script_5
};

