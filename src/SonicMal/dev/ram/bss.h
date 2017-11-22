// MT MK2 NES v0.86 - Sonic Bad is bad
// Copyleft 2017 by The Mojon Twins

// BSS globals

// 50 or 60 depending on TV system

unsigned char ticks, halfticks;

// Flow

unsigned char game_time, ticker, display, paused;
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

#if defined (MAP_FORMAT_BYTE_RLE) || defined (MAP_FORMAT_RLE53) || defined (MAP_FORMAT_RLE44)
	const unsigned char * const *c_map;
#else
	const unsigned char *c_map;
#endif

#ifdef MAP_WITH_DECORATIONS
	const unsigned char * const *c_decos;
#endif

const unsigned char *c_locks;
#if defined ENEMS_FORMAT_UNPACKED
	const unsigned char *c_enems;
#else
	const unsigned char * const *c_enems;
#endif
const unsigned char *c_hotspots;
const unsigned char *c_pal_bg;

unsigned char c_alt_tile;
unsigned char map_w;
unsigned char max_hotspots_type_1;

unsigned char level, do_game;
unsigned char game_state;
unsigned char game_res;
unsigned char spacer;
unsigned char scr_buff [192];
//unsigned char scr_attr [192+16];
unsigned char scr_attr [192];
unsigned char n_pant, on_pant;
unsigned char evil_tile_hit;

// Enems

unsigned char en_t [N_ENEMS];
unsigned char en_x [N_ENEMS];
unsigned char en_y [N_ENEMS];
unsigned char en_x1 [N_ENEMS];
unsigned char en_y1 [N_ENEMS];
unsigned char en_x2 [N_ENEMS];
unsigned char en_y2 [N_ENEMS];
signed char en_mx [N_ENEMS];
signed char en_my [N_ENEMS];

unsigned char en_state [N_ENEMS];
unsigned char en_ct [N_ENEMS];

#ifdef PERSISTENT_ENEMIES
	unsigned char ep_x [3 * MAX_PANTS];
	unsigned char ep_y [3 * MAX_PANTS];
	signed char ep_mx [3 * MAX_PANTS];
	signed char ep_my [3 * MAX_PANTS];
	unsigned int ep_it;
#endif

#if defined(ENEMIES_CAN_DIE) && defined(PERSISTENT_DEATHS)	
	unsigned char ep_killed [MAX_PANTS * N_ENEMS];
#endif

#ifdef ENEMS_UPSIDE_DOWN
	unsigned char en_ud [N_ENEMS];
#endif

unsigned char spr_x, spr_y, spr_id, en_fr;
unsigned char enoffs;
unsigned char genflipflop;
unsigned char is_platform;
unsigned char encelloffset;

// Player

unsigned char pkilled, pbodycount, opbodycount, plife, oplife, pobjs, opobjs, pkeys, opkeys, pammo, opammo;
unsigned char pemmeralds;
unsigned char pinv;
unsigned char guay_ct, use_ct, no_ct;

// Bullets

#ifdef PLAYER_CAN_FIRE
	unsigned char b_x [BULLETS_MAX];
	unsigned char b_y [BULLETS_MAX];
	signed char b_mx [BULLETS_MAX];
	signed char b_my [BULLETS_MAX];
	unsigned char b_ac [BULLETS_MAX];
	unsigned char b_slots [BULLETS_MAX];
	unsigned char b_slot;
#endif

// infested

// unsigned char infested, generators_active;
// unsigned char infsx, infsy;

// Hotspots

#ifndef DEACTIVATE_HOTSPOTS
	unsigned char hact [MAX_PANTS];
	#ifdef HOTSPOTS_MAY_CHANGE
	unsigned char ht [MAX_PANTS];
	#endif
#endif

// Hostage

// unsigned char hr_hit;

// Locks

unsigned char lkact [BOLTS_MAX];

// Cocos

#ifdef ENABLE_COCOS
	signed int coco_x [COCOS_MAX], coco_y [COCOS_MAX];
	signed int coco_vx [COCOS_MAX], coco_vy [COCOS_MAX];
	unsigned char coco_flag [COCOS_MAX];
#endif

// Scripting

unsigned char flags [MAX_FLAGS];

// Talk Box

// unsigned char tap;
// const unsigned char *texts [4];

// Fumettos

#ifdef ENABLE_FUMETTOS
	unsigned char fumettos_life [FUMETTOS_MAX];
	unsigned char fumettos_x [FUMETTOS_MAX], fumettos_y [FUMETTOS_MAX];
	unsigned char thrustct;
#endif

// Breakable walls

#ifdef BREAKABLE_WALLS
	unsigned char brk_ac [BREAKABLE_MAX], brk_slots [BREAKABLE_MAX];
	unsigned char brk_slot;
	unsigned char brk_x [BREAKABLE_MAX], brk_y [BREAKABLE_MAX];
	unsigned char process_breakable;
#endif

// Containers

#ifdef ENABLE_CONTAINERS
	unsigned char c_idx;
	unsigned char c_x [CONTAINERS_MAX];
	unsigned char c_y [CONTAINERS_MAX];
	unsigned char c_f [CONTAINERS_MAX];
	unsigned char containers_get;
#endif

// Springs

#ifdef ENABLE_SPRINGS
	unsigned char springs_x [SPRINGS_MAX];
	unsigned char springs_y [SPRINGS_MAX];
	unsigned char springs_idx;
#endif

// Propellers

#ifdef ENABLE_PROPELLERS
	unsigned char propellers_add_hi [PROPELLERS_MAX];
	unsigned char propellers_add_lo [PROPELLERS_MAX];
	unsigned char propellers_idx;
#endif

// Fabolees

#ifdef ENABLE_FABOLEES
	unsigned char fbl_y [FABOLEES_MAX], fbl_x [FABOLEES_MAX];
	unsigned char fbl_idx_x [FABOLEES_MAX], fbl_idx_y [FABOLEES_MAX];
	unsigned char fbl_idx_my [FABOLEES_MAX];
	unsigned char fbl_ct [FABOLEES_MAX];
	unsigned char fbl_facing [FABOLEES_MAX];
	unsigned char fbl_lock_on [FABOLEES_MAX];
#endif

// Estrujators

#if defined (ENABLE_ESTRUJATORS) || defined (ENABLE_CATARACTS)
	unsigned char est_x [ESTRUJATORS_MAX], est_y [ESTRUJATORS_MAX];
	unsigned char est_ct [ESTRUJATORS_MAX];
	unsigned char est_state [ESTRUJATORS_MAX];
#endif

#ifdef ENABLE_ESTRUJATORS
	unsigned char est_max_ct [ESTRUJATORS_MAX];
	unsigned char est_ini_delay;
#endif

// Cataracts

#ifdef ENABLE_CATARACTS
	unsigned char cataracts_on;
#endif

// Tile Get

#ifdef ENABLE_TILE_GET
#ifndef TILE_GET_COUNT_ON_FLAG
	unsigned char tile_get_ctr;
#endif

#ifdef PERSISTENT_TILE_GET 
	unsigned char tile_got [MAX_PANTS*12];
	unsigned int tile_got_offset;
#endif

#endif

// Custom ring

unsigned char mission_done;
unsigned char ring_on;
signed int ring_x, ring_y;
signed char ring_vx, ring_vy;
unsigned char ring_timer;
unsigned char ring_signal;

// More custom

unsigned char last_level;
unsigned char custom_on_off;
unsigned char pal_cycle [3];

unsigned char gs, game_espinete, game_somari, game_sonic;

#ifdef ENABLE_PUAS
	unsigned char puas_x [PUAS_MAX], puas_y [PUAS_MAX];
	signed char puas_mx [PUAS_MAX];
#endif
