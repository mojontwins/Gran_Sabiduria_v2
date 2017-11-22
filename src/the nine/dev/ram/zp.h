// Cheril: the Nine
// Copyleft 2016 by The Mojon Twins

// ZP globals

unsigned char oam_index;
unsigned char half_life, frame_counter;
unsigned char pad0;

// Main globals

unsigned char gpit, gpjt, bi;
unsigned char rda, rdb, rdc;
unsigned char rdx, rdy, rdt, rdct;
unsigned int gpint;
signed int gpsint;

unsigned char *gp_gen, *gp_aux, *gp_map, *gp_tmap;
unsigned int gp_addr;

// Level stuff which has to be fast

const unsigned char *c_ts_pals;
const unsigned char *c_ts_tmaps;
const unsigned char *c_behs;
const unsigned char *c_pal_bg, *c_pal_fg;

// Update list

unsigned char *ul;

// Collision

unsigned char cx1, cy1, cx2, cy2, at1, at2;

// Enems

unsigned char en_t [N_ENEMS], en_x [N_ENEMS], en_y [N_ENEMS], en_x1 [N_ENEMS], en_y1 [N_ENEMS], en_x2 [N_ENEMS], en_y2 [N_ENEMS];
signed char en_mx [N_ENEMS], en_my [N_ENEMS];
unsigned char en_hl [N_ENEMS], en_v [N_ENEMS];
unsigned char en_state [N_ENEMS], en_ct [N_ENEMS], en_gen_life [N_ENEMS], en_life [N_ENEMS], en_washit [N_ENEMS], en_gen_washit [N_ENEMS], en_fishing [N_ENEMS];
unsigned char en_s [N_ENEMS], en_dying [N_ENEMS], en_gen_dying [N_ENEMS], en_facing [N_ENEMS];
unsigned char en_rdb [N_ENEMS];

unsigned char spr_x, spr_y, spr_id, en_fr;
unsigned char enoffs;
unsigned char genflipflop;
unsigned char encellbase;

// Player

unsigned char prx, pry;
signed int px, py;
signed char pvx, pvy;
unsigned char pfiring;
unsigned char phit;
unsigned char pfacing, pfacingh, pfacingv, pfacinglast;
unsigned char pfixct;
unsigned char psprid; 
unsigned char pgauge;
unsigned char pcellbase;
unsigned char pnude;
unsigned char pflickering;

// Hotspots

unsigned char hrx, hry, hrt;

// Flower

unsigned char flwx, flwy;

// Sprite shuffling

unsigned char sstart;
