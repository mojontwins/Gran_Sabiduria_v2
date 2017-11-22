// Cheril: the Nine
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

const unsigned char * const *c_map;
const unsigned char *c_enems;
const unsigned char *c_hotspots;

unsigned char level, do_game;
unsigned char game_state;
unsigned char game_res;
unsigned char scr_buff [192];
unsigned char scr_attr [192];
unsigned char n_pant, on_pant;

// Enems

unsigned char ep_flags [/*MAP_W * MAP_H*/ 48 * N_ENEMS];

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

unsigned char hact [48/*MAP_W * MAP_H*/];

// Hostage

unsigned char hr_hit;

// Ending

unsigned char ending_sprid [10];

// Cacca
// Stuff created in a hurry when I felt the need of adding Mega Meghan as a hidden gem in this ROM

unsigned char lkact [MAX_BOLTS];
const unsigned char *c_locks;
unsigned char game_cheril, game_meghan;
unsigned char evil_tile_hit;
signed int pcx, pcy; 
unsigned char map_w;

unsigned char en_whx [N_ENEMS], en_why [N_ENEMS];
unsigned char boffsoff;

unsigned char stop_rate, stop_frames;