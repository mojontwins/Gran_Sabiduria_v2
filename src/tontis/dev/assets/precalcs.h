// MT MK2 NES v0.4
// Copyleft 2016 by The Mojon Twins

// If you end up not using those in your game, just whipe them for 20 extra bytes (WOW!)
const unsigned char bitmasks [] = { 0xfc, 0xf3, 0xcf, 0x3f };
const unsigned char jitter [] = { 0,1,1,0,0,1,0,1,1,0,0,0,1,0,1,1 };

#ifdef PLAYER_CAN_FIRE
// RIGHT LEFT DOWN UP
const signed char en_dx [] = {1, -1, 0, 0};
const signed char en_dy [] = {0, 0, 1, -1};
const signed char boffsx [] = {12, -4, 8, 1};
const signed char boffsy [] = {5, 5, 12, -4};
#endif

#ifdef ENABLE_COCO_STRAIGHT
// LEFT UP RIGHT DOWN
const signed char coco_vx_precalc [] = { -COCO_V, 0, COCO_V, 0 };
const signed char coco_vy_precalc [] = { 0, -COCO_V, 0, COCO_V };
#endif

#ifdef ENABLE_MONOCOCO
const unsigned char monococo_state_times [] = {
	MONOCOCO_BASE_TIME_HIDDEN, MONOCOCO_BASE_TIME_APPEARING, MONOCOCO_BASE_TIME_ONBOARD, MONOCOCO_BASE_TIME_APPEARING
};
#endif 

//const unsigned char leaves [] = {1, 16};

// CUSTOM {
const unsigned char rendezvous_bg_metatilemap [] = {
	1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 2, 1, 1, 2,
	4, 5, 6, 7, 6, 4, 7, 5, 4, 6, 7, 5, 4, 5, 6, 7
};

const unsigned char init_screens [] = {
	0,	9,	29,	6,	16,	13,	36,	24,
	38,	27,	7,	10,	23,	47, 37,	2
};

const unsigned char init_x [] = {
	8,	5,	5,	8,	1,	6,	10,	8,
	7,	8,	14,	14,	11,	11,	8,	8
};

const unsigned char init_y [] = {
	8,	3,	2,	6,	1,	9,	3,	2,
	3,	10,	2,	5,	5,	5,	4,	2
};

const unsigned char girl_pcharacter [] = { 0, 14 };

const unsigned char * const girl_palette [] = {
	palts_rendezvous_0, palts_rendezvous_1
};
// } END_OF_CUSTOM
