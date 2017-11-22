// Pantanow Engine rev2b 201703
// Copyleft 2016 by The Mojon Twins

// Zero page variables

// General stuff

const unsigned char *map_ptr;
const unsigned char *behs;
unsigned char *ul;
unsigned int gp_addr;

unsigned char pad0, prevpad, pad_once, half_life, frame_counter, hl_proc;
unsigned char oam_index;

unsigned char gpit, gpjt, bit;
unsigned char rda, rdb, rdc, rdt;
signed char rds;
unsigned char rdx;
signed int rdy;
signed char rdmx, rdmy;
signed int gpiit, gpijt;
unsigned int uin;

// Scroller

unsigned int camera_position;
unsigned char camera_position_lsb;
signed int scroll_y;
unsigned int map_postn;
unsigned char map_tilepos;
unsigned char map_flipflop, update_flag;
unsigned char delta;
unsigned char scroll_lock;

// Scroller aux

unsigned char wtp;
unsigned char at_bm, at_sh;
unsigned char a1, a2, a3, a4, a5;

// Scroller pointers

const unsigned char *map_gptr;
unsigned char *gpp;
unsigned char *gpr;
unsigned char *gpq;

// Level (fast) pointers

const unsigned char *c_ts_tmaps_0, *c_ts_tmaps_1, *c_ts_tmaps_2, *c_ts_tmaps_3;
const unsigned char *c_ts_pals;

// Buffer

unsigned char gbuffer_y;

// Player

unsigned char prx;
signed int pry;
signed int px;
unsigned int py;
signed char pvx;
signed char pvy;
unsigned char pfiring;
unsigned char phit, pflickering;
unsigned char pfacing, pfacingh, pfacingv, pfacinglast;
unsigned char pfixct;
unsigned char psprid; 
signed int pcx, pcy;

signed int pscreenoffs, pry_world;

// Collision

unsigned char cx1, cy1, cx2, cy2, at1, at2;
unsigned char caux;

// Enems strip

const unsigned char *strip_pointer;

// Enems

unsigned char _enx;
unsigned int _eny;
signed char _enmx, _enmy;
unsigned char _enctf;
unsigned char _enstate, _enctstate;
unsigned char _enfacing;
unsigned char _ent;
unsigned char _enlastf;
unsigned char _enspr;

unsigned char enit, enjt;
unsigned char enfirehl;
unsigned char enstart;
unsigned char enmustfire;
unsigned char encollidedx, encollidedy;
unsigned char encount;

unsigned char ensprid;
unsigned char ts_base;

// Bullets

unsigned char bx [BULLETS_MAX];
unsigned int by [BULLETS_MAX];
signed char bmx [BULLETS_MAX], bmy [BULLETS_MAX];
unsigned char _bx;
unsigned int _by;
