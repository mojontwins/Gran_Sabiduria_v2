// MT MK2 NES v0.1
// Copyleft 2016 by The Mojon Twins

// BSS globals


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

#ifdef MAP_FORMAT_BYTE_RLE
const unsigned char * const *c_map;
#else
const unsigned char *c_map;
#ifdef MAP_WITH_DECORATIONS
const unsigned char * const *c_decos;
#endif
#endif
const unsigned char *c_locks;
const unsigned char *c_enems;
const unsigned char *c_hotspots;
unsigned char n_bolts;
unsigned char max_hotspots_type_1;

unsigned char level, do_game;
unsigned char game_state;
unsigned char game_res;
unsigned char scr_buff [192];
unsigned char scr_attr [192+16];
unsigned char n_pant, on_pant;
unsigned char evil_tile_hit;

// Enems

#ifdef PERSISTENT_ENEMIES
unsigned char ep_x [3 * MAP_W * MAP_H];
unsigned char ep_y [3 * MAP_W * MAP_H];
signed char ep_mx [3 * MAP_W * MAP_H];
signed char ep_my [3 * MAP_W * MAP_H];
unsigned int ep_it;
#endif
#if defined(ENEMIES_CAN_DIE) && defined(PERSISTENT_DEATHS)	
unsigned char ep_flags [MAP_W * MAP_H * N_ENEMS];
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

unsigned char hact [MAP_W * MAP_H];

// Hostage

unsigned char hr_hit;

// Locks

unsigned char lkact [BOLTS_MAX];

// Hud

unsigned char hudbaseline;

// Custom

unsigned char please_continue, already_played;

unsigned char fumettos_life [FUMETTOS_MAX];
unsigned char fumettos_x [FUMETTOS_MAX], fumettos_y [FUMETTOS_MAX];
unsigned char thrustct; 
unsigned char rn_pant;

unsigned char map_w;

// Enems

unsigned char en_x [N_ENEMS], en_y [N_ENEMS], en_x1 [N_ENEMS], en_y1 [N_ENEMS], en_x2 [N_ENEMS], en_y2 [N_ENEMS];
signed char en_mx [N_ENEMS], en_my [N_ENEMS];
unsigned char en_ct [N_ENEMS];
