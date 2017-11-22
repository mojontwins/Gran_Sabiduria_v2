// MT MK2 NES v0.4
// Copyleft 2016 by The Mojon Twins

// BSS globals

// CUSTOM {
const unsigned char *mypal_game_bg_title;
// } END_OF_CUSTOM

// 50 or 60 depending on TV system

//unsigned char ticks, halfticks;

// Flow

unsigned char game_time, ticker, display;
unsigned char flash;

// Update list for VBlank updates

unsigned char update_list [UPDATE_LIST_SIZE * 3 + 1];

// Fade in / fade out

signed char fader;

// Attributes table buffer

unsigned char attr_table [64];
unsigned char first_time;

// Level related stuff

unsigned char max_pant;
#ifdef MAP_FORMAT_BYTE_RLE
const unsigned char * const *c_map;
#else
const unsigned char *c_map;
#endif
const unsigned char *c_locks;
const unsigned char *c_enems;
const unsigned char *c_hotspots;
unsigned char c_alt_tile;

unsigned char level, do_game;
unsigned char game_state;
unsigned char game_res;
unsigned char scr_buff [192];
unsigned char scr_attr [192+16];
unsigned char n_pant, on_pant;
unsigned char evil_tile_hit;

// Enems

#ifdef PERSISTENT_ENEMIES
// CUSTOM {
unsigned char ep_x [3*48], ep_y [3*48];
signed char ep_mx [3*48], ep_my [3*48];
/*
unsigned char ep_x [3 * MAP_W * MAP_H];
unsigned char ep_y [3 * MAP_W * MAP_H];
signed char ep_mx [3 * MAP_W * MAP_H];
signed char ep_my [3 * MAP_W * MAP_H];
*/
// } END_OF_CUSTOM
unsigned int ep_it;
#endif
// CUSTOM {
#if defined(ENEMIES_CAN_DIE) && defined(PERSISTENT_DEATHS)	
/*
unsigned char ep_flags [MAP_W * MAP_H * N_ENEMS];
*/
unsigned char ep_flags [3*48];
#endif
// } END_OF_CUSTOM

// Player

unsigned char pkilled, plife, oplife, pobjs, opobjs, pkeys, opkeys;

// Bullets

/*
unsigned char b_x [BULLETS_MAX];
unsigned char b_y [BULLETS_MAX];
signed char b_mx [BULLETS_MAX];
signed char b_my [BULLETS_MAX];
unsigned char b_ac [BULLETS_MAX];
unsigned char b_slots [BULLETS_MAX];
unsigned char b_slot;

// infested

unsigned char infested, generators_active;
unsigned char infsx, infsy;
*/
// Hotspots

// CUSTOM {
//unsigned char hact [MAP_W * MAP_H];
unsigned char hact [48];
// } END_OF_CUSTOM

// Hostage

unsigned char hr_hit;

// Locks

unsigned char lkact [BOLTS_MAX];

// Hud

unsigned char hudbaseline;

// Cocos

#ifdef ENABLE_COCOS
signed int coco_x [COCOS_MAX], coco_y [COCOS_MAX];
signed int coco_vx [COCOS_MAX], coco_vy [COCOS_MAX];
unsigned char coco_flag [COCOS_MAX];
unsigned char coco_it;
#endif

// CUSTOM {
signed int ini_px [2], ini_py [2];
unsigned char ini_n_pant [2];
unsigned char active_girl;
unsigned char rdbg;

unsigned char othergirloffs, girlact, girlx, girly;
unsigned char retries;
unsigned char wins;
unsigned char scrtctr, altuniverse;

unsigned char fumettos_life [FUMETTOS_MAX];
unsigned char fumettos_x [FUMETTOS_MAX], fumettos_y [FUMETTOS_MAX];

unsigned char game_potipoti, game_rendezvous, game_napia;
// } END_OF_CUSTOM

unsigned char max_hotspots_type_1;
unsigned char restart_girl, very_first_time;
