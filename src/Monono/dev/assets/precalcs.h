// MT MK2 NES v0.1
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

// Custom
const unsigned char *hud1 = "#$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$%";
const unsigned char *hud2 = "'                              (";
const unsigned char *hud3 = ")******************************+";

const unsigned char * const mypal_game_bg_title [] = { mypal_game_bg0,mypal_game_bg1, mypal_game_bg7,mypal_game_bg5, mypal_game_bg4  };
const unsigned char * const mypal_game_bg [] = { mypal_game_bg0,mypal_game_bg1, mypal_game_bg6, mypal_game_bg3, mypal_game_bg4 };
const unsigned char * const mypal_game_bg_ending [] = { mypal_game_bg0, mypal_game_bg2, mypal_game_bg7, mypal_game_bg3, mypal_game_bg4 };

const unsigned char music_track_ingame [] = { 0, 1, 0, 2, 2 };

