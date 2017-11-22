// MT MK2 NES v0.6
// Copyleft 2016 by The Mojon Twins

// BSS globals

// CUSTOM {
const unsigned char *mypal_game_bg_title;
// } END_OF_CUSTOM

// 50 or 60 depending on TV system

unsigned char ticks, halfticks;

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
unsigned char map_w;

unsigned char level, do_game;
unsigned char game_state;
unsigned char game_res;
unsigned char scr_buff [192];
unsigned char scr_attr [192+16];
unsigned char n_pant, on_pant;
unsigned char evil_tile_hit;
#ifdef MAP_ENABLE_AUTOSHADOWS
unsigned char mapmode_autoshadows;
#endif

// Enems

#ifdef PERSISTENT_ENEMIES
unsigned char ep_x [3 * MAX_PANTS];
unsigned char ep_y [3 * MAX_PANTS];
signed char ep_mx [3 * MAX_PANTS];
signed char ep_my [3 * MAX_PANTS];
unsigned int ep_it;
#endif
#if defined(ENEMIES_CAN_DIE) && defined(PERSISTENT_DEATHS)	
unsigned char ep_flags [MAX_PANTS * N_ENEMS];
#endif

// Player

unsigned char pkilled, plife, oplife, pobjs, opobjs, pkeys, opkeys;

// Bullets

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

// Hotspots

unsigned char hact [MAX_PANTS];

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

unsigned char max_hotspots_type_1;

unsigned char flags [MAX_FLAGS];

// CUSTOM
unsigned char prg_rom_sel;
unsigned char chr_rom_sel;
unsigned char gs_sel;

unsigned char menu_page;
unsigned char pointer_opt;
unsigned char launch;

signed int str_x [MAX_STARS];
signed char str_mx [MAX_STARS];
unsigned char str_y [MAX_STARS];
unsigned char str_id [MAX_STARS];

unsigned char game_trabajo_basura;
unsigned char game_vesta_vaal;
unsigned char gs;

unsigned char okilled, pobject; 
unsigned char logox1, logox2, logoy1, logoy2, ff1, ff2;
unsigned char opgauge;

unsigned char hitter_x, hitter_y, hitter_frame, hitter_on;

const unsigned char *SPRITE_EXPLOSION;

unsigned char pal_c [4];
unsigned char max_stars;
