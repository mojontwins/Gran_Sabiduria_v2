// MT MK2 NES v0.3
// Copyleft 2016 by The Mojon Twins

// ZP globals

unsigned char oam_index;
unsigned char half_life, frame_counter;
unsigned char pad0;

// Main globals

unsigned char gpit, gpjt, bi;
unsigned char rda, rdb, rdc, tap;
unsigned char rdx, rdy, rdt, rdct;
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

unsigned char en_t [N_ENEMS], en_x [N_ENEMS], en_y [N_ENEMS], en_x1 [N_ENEMS], en_y1 [N_ENEMS], en_x2 [N_ENEMS], en_y2 [N_ENEMS];
signed char en_mx [N_ENEMS], en_my [N_ENEMS];
unsigned char en_hl [N_ENEMS], en_v [N_ENEMS];
unsigned char en_state [N_ENEMS], en_ct [N_ENEMS], en_gen_life [N_ENEMS], en_life [N_ENEMS], en_washit [N_ENEMS], en_gen_washit [N_ENEMS], en_fishing [N_ENEMS];
unsigned char en_s [N_ENEMS];

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

// Hotspots

unsigned char hrx, hry, hrt;
unsigned char itcelloffset;

// Flower

unsigned char flwx, flwy;

// Sprite shuffling

unsigned char sstart;

// Cocos

#ifdef ENABLE_COCOS
signed int coco_x [COCOS_MAX], coco_y [COCOS_MAX];
signed int coco_vx [COCOS_MAX], coco_vy [COCOS_MAX];
unsigned char coco_flag [COCOS_MAX];
unsigned char coco_it;
#endif

// Enemies collide with background

#ifdef WALLS_STOP_ENEMIES
unsigned char en_collx, en_colly;
#endif

#ifdef PLAYER_PUSH_BOXES
unsigned char pbx1, pby1;
#endif

unsigned char enitstart;
unsigned char drunk_mode;
