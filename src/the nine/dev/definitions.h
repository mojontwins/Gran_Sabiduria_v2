// Cheril: the Nine
// Copyleft 2016 by The Mojon Twins

// Main definitions

	#define COMM_POOL						((unsigned char*)0x0300)	// Mapper 113 stuff.

	#define COMM_REG						(COMM_POOL[0x0])
	#define COMM_GAME_SELECT				(COMM_POOL[0x1])
	#define COMM_GAME_FLAGS 				(COMM_POOL[0x2])
	#define COMM_CHECKSUM 					(COMM_POOL[0xf])

	#define UPDATE_LIST_SIZE		32
	#define MSB(x)					((x)>>8)
	#define LSB(x)					((x)&0xff)
	#define SPRITE_ORIGIN			40
	#define TILE_ORIGIN 			2
	#define SPRITE_ADJUST			SPRITE_ORIGIN-1
	#define TOP_ADJUST				4
	#define FIX_BITS				4
	#define FADE_DELAY 				1

	#define SGNI(n)					((n)<0?-1:1)
	#define SGNC(a,b,c)				((a)<(b)?-(c):(c))
	#define SATURATE_Z(n)			((n)<0?0:(n))
	#define SATURATE(v,max)			((v)>=0?((v)>(max)?(max):(v)):((v)<-(max)?-(max):(v)))
	#define ABS(n)					((n)<0?-(n):(n))
	#define DELTA(a,b)				((a)<(b)?(b)-(a):(a)-(b))
	#define CL(x1,y1,x2,y2)			((x1)+4>=(x2)&&(x1)<=(x2)+12&&(y1)+12>=(y2)&&(y1)<=(y2)+12)
	#define SUBSTR_SAT(a,b)			((a)>(b)?(a)-(b):0)
	#define DISABLE_SFX_NEXT_FRAME	*((unsigned char*)0x01bf)=1;
	#define ADD_SIGN2(a,b,v)		((a)==(b))?(0):(((a)>(b))?(v):(-(v)))
	#define ADD_SIGN(a,v) 			((a)?(((a)>0)?(v):(-(v))):(0))

// Change this if you change where digits are stored in the pattern table
	#define DIGIT(n) 				(64+(n))

// Game definitions

	#define MAP_W					5
	#define MAP_H					5
	#define N_ENEMS					4

// Game engine values

	#define TYPE7_BASE_SPRITE 		24
	#define TYPE7_GENERATOR_LIFE	10
	#define TYPE7_MINION_LIFE 		4
	#define TYPE7_SPAWN_TIME		50+(rand8()&63)		// Must be of course > TYPE7_DYING_FRAMES!
	#define TYPE7_SMOKE_TIME		80 //40
	#define TYPE7_MINION_DYING_FRAMES	16
	#define TYPE7_MINION_HIT_FRAMES		16
	#define TYPE7_GENERATOR_DYING_FRAMES	16
	#define TYPE7_GENERATOR_HIT_FRAMES		16


	#define WALKER_BASE_SPRITE		26
	#define WALKER_MIN_RUN			4
	#define WALKER_EXPRESSION		(WALKER_MIN_RUN + (rand8 () & 3))
	#define WALKER_HIT_FRAMES		16

// Game states

	#define GS_GAME_OVER			0

// Player

	#define PLAYER_INI_X			7
	#define PLAYER_INI_Y			3

	#define PLAYER_VX_MAX			32		// Velocidad máxima horizontal (192/64 = 3 píxels/frame)
	#define PLAYER_AX				2		// Aceleración horizontal (24/64 = 0,375 píxels/frame^2)
	#define PLAYER_RX				4		// Fricción horizontal (32/64 = 0,5 píxels/frame^2)
	#define PLAYER_VX_MIN 			8

	#define PLAYER_VY_MAX			32		// Velocidad máxima horizontal (192/64 = 3 píxels/frame)
	#define PLAYER_AY				2		// Aceleración horizontal (24/64 = 0,375 píxels/frame^2)
	#define PLAYER_RY				4		// Fricción horizontal (32/64 = 0,5 píxels/frame^2)
	#define PLAYER_VY_MIN 			8

	#define PLAYER_V_REBOUND		64
	#define PLAYER_V_REBOUND_MULTI	32
	#define PLAYER_HIT_FRAMES		16
	#define PLAYER_FLICKERING_FRAMES 100

	#define CELL_FACING_RIGHT 		0
	#define CELL_FACING_LEFT		6
	#define CELL_FACING_DOWN		12
	#define CELL_FACING_UP			18
	#define CELL_HIT_BASE 			24
	#define CELL_FIRING				5
	#define CELL_IDLE				0
	#define CELL_WALK_BASE 			1

	#define CELL_CHERIL				0
	#define CELL_MEGHAN				26

	#define CELL_ADD_NUDE			24

	#define CELL_ENEMS_CHERIL		0
	#define CELL_ENEMS_MEGHAN		36

	#define TURRET_FRAMES			16 	

// Bullets

	#define BULLETS_MAX				8
	#define BULLETS_V 				8
	#define BULLET_PATTERN 			1

// Hotspots

	#define HOTSPOT_TYPE_REFILL 	1
	#define HOTSPOT_TYPE_OBJECT		2
	#define HOTSPOT_TYPE_KEYS		3
	#define HOTSPOT_TYPE_CLOTHES	4

// Sound channels

	#define SC_PLAYER				0
	#define SC_ENEMS				1
	#define SC_LEVEL				1

// SFX

	#define SFX_JUMP				1			
	#define SFX_ENEMY_HIT			3
	#define SFX_CHOF				7
	#define SFX_GET_ITEM			2
	#define SFX_BUTT_FALL			8
	#define SFX_BUTT_HIT			9
	#define SFX_SHOOT				5
	#define SFX_FART				6
	#define SFX_START				0
	#define SFX_EXTRA_1				4
	#define SFX_BLOCO				10

// Music

	#define MUSIC_TITLE				0
	#define MUSIC_INGAME 			1
	#define MUSIC_EVENT 			2

// Added...

	#define MAX_BOLTS 				4
	