// MT MK2 NES v0.1
// Copyleft 2016 by The Mojon Twins

// ZP globals

// CUSTOM {
	unsigned char SPRITE_ADJUST;
	unsigned char TOP_ADJUST;
	unsigned char PLAYER_G;
	unsigned char PLAYER_AX;
// } END_OF_CUSTOM

unsigned char oam_index;
unsigned char half_life, frame_counter;
unsigned char pad0;

// Main globals

unsigned char gpit, gpjt, bi;
unsigned char rda, rdb, rdc;
unsigned char rdx, rdy, rdt, rdct;
unsigned char rdyb;
unsigned int gpint;
signed int gpsint;

unsigned char *gp_gen, *gp_aux, *gp_map, *gp_tmap;
unsigned int gp_addr;

// Level stuff which has to be fast

const unsigned char *c_ts_pals;
const unsigned char *c_ts_tmaps;
const unsigned char *c_behs;

// Update list

unsigned char *ul;

// Collision

unsigned char cx1, cy1, cx2, cy2, at1, at2;
unsigned char caux;

// Enems

unsigned char _en_x, _en_y, _en_x1, _en_x2, _en_y1, _en_y2;
signed char _en_mx, _en_my;
unsigned char _en_ct;

unsigned char en_t [N_ENEMS]; 
unsigned char en_hl [N_ENEMS], en_v [N_ENEMS];
unsigned char en_state [N_ENEMS], en_gen_life [N_ENEMS], en_life [N_ENEMS], en_washit [N_ENEMS], en_gen_washit [N_ENEMS], en_fishing [N_ENEMS];
unsigned char en_s [N_ENEMS], en_dying [N_ENEMS], en_gen_dying [N_ENEMS], en_facing [N_ENEMS];

unsigned char spr_x, spr_y, spr_id, en_fr;
unsigned char enoffs;
unsigned char genflipflop;
unsigned char is_platform;
unsigned char encelloffset;

// Player

unsigned char prx, pry;
signed int px, py;
signed int pcx, pcy;
signed char pvx;
signed int pvy;
unsigned char pj, pctj, pthrust, pjb;
unsigned char pfiring;
unsigned char phit, pflickering;
unsigned char pfacing, pfacingh, pfacingv, pfacinglast, pgotten, ppossee, pregotten;
unsigned char pfixct;
unsigned char psprid; 
//unsigned char pgauge;
unsigned char pcharacter;
signed int pvylast;
signed char pgtmx, pgtmy;

// Hotspots

unsigned char hrx, hry, hrt;
unsigned char itcelloffset;

// Flower

//unsigned char flwx, flwy;

// Sprite shuffling

unsigned char sstart;

// Cocos

#ifdef ENABLE_COCOS
signed int coco_x [COCOS_MAX], coco_y [COCOS_MAX];
signed int coco_vx [COCOS_MAX], coco_vy [COCOS_MAX];
unsigned char coco_flag [COCOS_MAX];
unsigned char coco_it;
#endif

unsigned char inverted_screen;

unsigned char game_jet_puri, game_monono, game_monona, game_pppp;