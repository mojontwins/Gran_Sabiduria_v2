// MT MK2 NES v0.4
// Copyleft 2016 by The Mojon Twins

// ZP globals

// CUSTOM {
unsigned char ge_vertical;
unsigned char ge_horizontal;
const unsigned char * const *spr_enems;
const unsigned char * const *spr_player;
const unsigned char * const *spr_items;

unsigned char MAP_W, MAP_H;

unsigned char CELL_FACING_LEFT;

signed char PLAYER_VX_MAX, PLAYER_AX, PLAYER_RX;				// Make horz. axis variable
signed char PLAYER_VY_JUMP_INITIAL, PLAYER_AY_JUMP, PLAYER_VY_JUMP_MAX;		// Make jumping physics variable
// } END_OF_CUSTOM

unsigned char oam_index;
unsigned char half_life, frame_counter;
unsigned char pad0;

// Main globals

unsigned char gpit, gpjt, bi;
unsigned char rda, rdb, rdc, rdd;
unsigned char rdx, rdy, rdt, rdct;
unsigned int gpint;
signed int gpsint;
signed char delta;

unsigned char *gp_gen, *gp_aux, *gp_map, *gp_tmap, *gp_tmap_alt;
unsigned int gp_addr;

// Level stuff which has to be fast

const unsigned char *c_ts_pals;
const unsigned char *c_ts_tmaps;
const unsigned char *c_behs;
unsigned char mapmode_autoshadows;

// Update list

unsigned char *ul;

// Collision

unsigned char cx1, cy1, cx2, cy2, at1, at2;
unsigned char caux;

// Enems

unsigned char en_t [N_ENEMS], en_x [N_ENEMS], en_y [N_ENEMS], en_x1 [N_ENEMS], en_y1 [N_ENEMS], en_x2 [N_ENEMS], en_y2 [N_ENEMS];
signed char en_mx [N_ENEMS], en_my [N_ENEMS];
unsigned char en_hl [N_ENEMS], en_v [N_ENEMS];
unsigned char en_state [N_ENEMS], en_ct [N_ENEMS], en_gen_life [N_ENEMS], en_life [N_ENEMS], en_washit [N_ENEMS], en_gen_washit [N_ENEMS], en_fishing [N_ENEMS];
unsigned char en_s [N_ENEMS], en_dying [N_ENEMS], en_gen_dying [N_ENEMS], en_facing [N_ENEMS];

unsigned char spr_x, spr_y, spr_id, en_fr;
unsigned char enoffs;
unsigned char genflipflop;
unsigned char is_platform;
unsigned char encelloffset;

// Player

unsigned char prx, pry;
signed int px, py;
signed char pvx;
signed int pvy;
unsigned char pj, pctj, pthrust, pjb;
unsigned char pfiring;
unsigned char phit, pflickering;
unsigned char pfacing, pfacingh, pfacingv, pfacinglast, pgotten, ppossee, pregotten;
unsigned char pfixct;
unsigned char psprid; 
unsigned char pgauge;
signed int pvylast;
signed char pgtmx, pgtmy;
unsigned char pjustjumped;
unsigned char pcharacter;
unsigned char pspin;
#ifdef EVIL_TILE_MULTI
signed int pcx, pcy;
#endif
#ifdef PLAYER_DIE_AND_RESPAWN
signed int safe_px, safe_py;
unsigned char safe_n_pant;
#endif
unsigned char pwashit;
#ifdef PLAYER_DOUBLE_JUMP
unsigned char njumps;	// Double jumping stravaganza
#endif
#ifdef PLAYER_STEPS_ON_ENEMIES
unsigned char pbutt;
#endif

// Hotspots

unsigned char hrx, hry, hrt;
unsigned char itcelloffset;

// Flower

//unsigned char flwx, flwy;

// Sprite shuffling

unsigned char sstart;

// Enemies collide with background

#ifdef WALLS_STOP_ENEMIES
unsigned char en_collx, en_colly;
#endif

#ifdef PLAYER_PUSH_BOXES
unsigned char pbx1, pby1;
#endif

unsigned char custom_dont_paint_tile_0;

unsigned char egg;
