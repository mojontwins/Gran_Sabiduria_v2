// Pantanow Engine rev2b 201703
// Copyleft 2016 by The Mojon Twins

// BSS variables

// 50 or 60 depending on TV system

unsigned char ticks, halfticks;

// Flow

unsigned char level, game_time, ticker, display;
unsigned char flash;
unsigned char paused;
unsigned char cheat_on;

// Level related

const unsigned char * const *spr_player;
const unsigned char * const *spr_enems;

// Update list for VBlank updates

unsigned char update_list [UPDATE_LIST_SIZE * 3 + 1];

// Fade in / fade out

signed char fader;

// Attributes table buffer

unsigned char attr_table [64];

// Collision circular buffer
 
unsigned char scr_buff [256];

// Player extra

unsigned char pkilled, pwins, plife, evil_tile_hit;

// Bullets

unsigned char bslots [BULLETS_MAX], bsloti;
unsigned char bagent [BULLETS_MAX]; // Who fired the bullet?
unsigned char ba [BULLETS_MAX];

// Enems extra

unsigned char enslots [ENEMS_MAX], ensloti;
unsigned char ent [ENEMS_MAX], enc [ENEMS_MAX], end [ENEMS_MAX];
unsigned char ena [ENEMS_MAX];
unsigned char enfacing [ENEMS_MAX];
const unsigned char *enbehptr [ENEMS_MAX];
unsigned char enlastf [ENEMS_MAX];
unsigned char enctout [ENEMS_MAX];
unsigned char enstate [ENEMS_MAX], enctstate [ENEMS_MAX], enspr [ENEMS_MAX];

unsigned char enx [ENEMS_MAX];
unsigned int eny [ENEMS_MAX];
signed char enmx [ENEMS_MAX], enmy [ENEMS_MAX];
unsigned char enctf [ENEMS_MAX];
unsigned char enl [ENEMS_MAX];

// Debug

unsigned char dbgp;

// Full game?

unsigned char full_game;

// Texts arrays

const unsigned char * const *strs_texts;
