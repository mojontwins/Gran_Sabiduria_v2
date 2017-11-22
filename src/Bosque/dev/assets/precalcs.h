// MT MK2 NES v0.3
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

const unsigned char leaves [] = {1, 16};

// CUSTOM {
const unsigned char box_buff [] = {
	17,18,18,18,18,18,18,18,18,18,18,19, 99, 99, 99, 99,
	20,21,21,21,21,21,21,21,21,21,21,22, 99, 99, 99, 99,
	20,21,21,21,21,21,21,21,21,21,21,22, 99, 99, 99, 99,
	23,24,24,24,24,24,24,24,24,24,24,25
};
// } END_OF_CUSTOM
