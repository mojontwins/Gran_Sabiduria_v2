// MT MK2 NES v0.1
// Copyleft 2016 by The Mojon Twins

// Main definitions

// Communications

	#define COMM_POOL				((unsigned char*)0x0300)	// Mapper 113 stuff.

	#define COMM_REG				(COMM_POOL[0x0])
	#define COMM_GAME_SELECT		(COMM_POOL[0x1])
	#define COMM_GAME_FLAGS 		(COMM_POOL[0x2])
	#define COMM_CHECKSUM 			(COMM_POOL[0xf])

// Game configuration

	#define GAME_MONONO				0
	#define GAME_JET_PURI			1
	#define GAME_MONONA				2
	#define GAME_LAH 				3
	#define GAME_PPPP				4

// Macros

	#define UPDATE_LIST_SIZE		32
	#define MSB(x)					((x)>>8)
	#define LSB(x)					((x)&0xff)
	#define SPRITE_ORIGIN			40
	// Custom: make these variables for this ROM.
	//#define SPRITE_ADJUST			SPRITE_ORIGIN-1
	//#define TOP_ADJUST				4
	#define FIX_BITS				4
	#define FADE_DELAY 				1

	#define SGNI(n)					((n)<0?-1:1)
	#define SGNC(a,b,c)				((a)<(b)?-(c):(c))
	#define SATURATE_Z(n)			((n)<0?0:(n))
	#define SATURATE(v,max)			((v)>=0?((v)>(max)?(max):(v)):((v)<-(max)?-(max):(v)))
	#define SATURATE_N(v,min)		(v<min?min:v)
	#define ABS(n)					((n)<0?-(n):(n))
	#define DELTA(a,b)				((a)<(b)?(b)-(a):(a)-(b))
	#define CL(x1,y1,x2,y2)			((x1)+4>=(x2)&&(x1)<=(x2)+12&&(y1)+12>=(y2)&&(y1)<=(y2)+12)
	#define SUBSTR_SAT(a,b)			((a)>(b)?(a)-(b):0)
	#define DISABLE_SFX_NEXT_FRAME	*((unsigned char*)0x01bf)=1;
	#define ADD_SIGN2(a,b,v)		((a)==(b))?(0):(((a)>(b))?(v):(-(v)))
	#define ADD_SIGN(a,v) 			((a)?(((a)>0)?(v):(-(v))):(0))

	// Change this if you change where digits are stored in the pattern table
	#define DIGIT(n) 				(16+(n))

// Game definitions

	#define MAP_W					3
	#define MAP_H					10
	#define N_ENEMS					3
	#define BOLTS_MAX 				8

	//#define MAP_FORMAT_BYTE_RLE
	#define MAP_FORMAT_PACKED
	#define MAP_WITH_DECORATIONS	
	
// Game engine values

	//#define PERSISTENT_DEATHS
	#define PERSISTENT_ENEMIES

// Linear enemies

	#define ENABLE_LINEAR
	#define ENABLE_PLATFORMS
	#define LINEAR_COLLIDES

// Type7 (with or without generators) enemies

	//#define ENABLE_TYPE_7
	#define TYPE7_BASE_SPRITE 		24
	#define TYPE7_GENERATOR_LIFE	10
	#define TYPE7_MINION_LIFE 		3
	#define TYPE7_SPAWN_TIME		50+(rand8()&63)		// Must be of course > TYPE7_DYING_FRAMES!
	#define TYPE7_MINION_DYING_FRAMES	16
	#define TYPE7_MINION_HIT_FRAMES		16
	#define TYPE7_GENERATOR_DYING_FRAMES	16
	#define TYPE7_GENERATOR_HIT_FRAMES		16

// Walker 

	//#define ENABLE_WALKER
	#define WALKER_BASE_SPRITE		26
	#define WALKER_MIN_RUN			4
	#define WALKER_EXPRESSION		(WALKER_MIN_RUN + (rand8 () & 3))
	#define WALKER_HIT_FRAMES		16

// Steady shooters
	#define ENABLE_STEADY_SHOOTER
	#define STEADY_SHOOTER_CELL		32

// Monococo
	//#define ENABLE_MONOCOCO

// Auxiliary stuff

	#if defined (ENABLE_STEADY_SHOOTER) || defined (ENABLE_MONOCOCO)
	#define ENABLE_COCOS
	#define COCOS_MAX 				3
	#define COCO_PATTERN			1
	#define COCO_V					96

	#if defined (ENABLE_MONOCOCO)
	#define ENABLE_COCO_AIMED
	#define COCO_FAIR_D				64
	#endif

	#if defined (ENABLE_STEADY_SHOOTER)
	#define ENABLE_COCO_STRAIGHT
	#endif

	#endif

// Game states

	#define GS_GAME_OVER			0

// Evil tiles

	// Enable the ones you need. Use a custom way to switch between them if you activate several:
	#define EVIL_TILE_ON_FLOOR
	//#define EVIL_TILE_MULTI

	#if defined (EVIL_TILE_MULTI) || defined (EVIL_TILE_ON_FLOOR)
	#define ENABLE_EVIL_TILE
	#endif

// Player

	// Enable the ones you need. Use a custom way to switch between them if you activate several:
	//#define PLAYER_GENITAL
	//#define PLAYER_JUMPS
	#define PLAYER_MONONO
	#define PLAYER_JETPAC

	#define PLAYER_PUSH_BOXES

	#if defined (PLAYER_JUMPS) || defined (PLAYER_MONONO) || defined (PLAYER_JETPAC)
	#define PLAYER_GRAVITY
	#endif

	#define PLAYER_INI_X			7
	#define PLAYER_INI_Y			3

	#define PLAYER_VX_MAX			32
	//#define PLAYER_AX				2
	#define PLAYER_RX				4
	#define PLAYER_VX_MIN 			8

	#define PLAYER_VY_FALLING_MAX	64
	//#define PLAYER_G				4 		// CUSTOM: This is a variable in this game
	#define PLAYER_VY_MIN 			16

	#define PLAYER_VY_JETPAC_MAX	12		// Jetpac values
	#define PLATER_AY_JETPAC 		2

	#define PLAYER_VY_JUMP_INITIAL	16
	#define PLAYER_AY_JUMP			8
	#define PLAYER_VY_JUMP_MAX 		64
	#define PLAYER_VY_JUMP_A_STEPS 	16

	#define PLAYER_VY_JUMP_INITIAL_MONONO	32
	#define PLAYER_AY_JUMP_MONONO			16
	#define PLAYER_VY_JUMP_MAX_MONONO		96

	//#define PLAYER_VY_MAX			32
	//#define PLAYER_AY				2
	//#define PLAYER_RY				4
	//#define PLAYER_VY_MIN 		8

	#define PLAYER_V_REBOUND		64
	#define PLAYER_V_REBOUND_MULTI	32
	#define PLAYER_VY_BUTT_REBOUND			48
	#define PLAYER_HIT_FRAMES		32

	#define PLAYER_FLICKERS			120

// Animation cells

	#define CELL_FACING_RIGHT 		0
	#define CELL_FACING_LEFT		8
	#define CELL_MONONO				0
	#define CELL_JET_PURI			16
	#define CELL_LAH 				32
	#define CELL_PPPP				48
	#define CELL_MONONA				64
	//#define CELL_FACING_DOWN		12
	//#define CELL_FACING_UP		18
	//#define CELL_HIT_BASE 		24
	//#define CELL_FIRING			5
	#define CELL_IDLE				0
	#define CELL_WALK_BASE 			1
	#define CELL_DESCENDING			5
	#define CELL_ASCENDING			6
	#define CELL_HIT 				7
	#define CELL_AIRBORNE 			7

	#define CELL_ENEMS_MONONO		0
	#define CELL_ENEMS_JET_PURI		16
	#define CELL_ENEMS_LAH 			36
	#define CELL_ENEMS_PPPP			52

	#define CELL_ITEMS_MONONO		0
	#define CELL_ITEMS_JET_PURI		4
	#define CELL_ITEMS_MONONA		16
	#define CELL_ITEMS_LAH 			8
	#define CELL_ITEMS_PPPP			12

// Things related to shooting

	//#define PLAYER_CAN_FIRE

	// Turret

	//#define PLAYER_TURRET
	#define TURRET_FRAMES			16 	

	// Bullets

	#define BULLETS_MAX				8
	#define BULLETS_V 				8

	//#define SHOOTING_DRAINS

// Hotspots
// Define those to include all related code

	#define HOTSPOT_TYPE_REFILL 	3
	#define HOTSPOT_TYPE_OBJECT		1
	#define HOTSPOT_TYPE_KEY 		2

// Expand upon this when needed

	#if defined (PLAYER_CAN_FIRE)
	#define ENEMIES_CAN_DIE
	#endif
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

// Make code more readable:

	#define MONOCOCO_X 						en_x
	#define MONOCOCO_Y						en_y
	#define MONOCOCO_COUNTER 				en_my
	#define MONOCOCO_STATE 					en_mx

// Custom

	#define FUMETTOS_MAX 					8
	#define FUMETTO_BASE_PATTERN			2

// CHR banks. For the multicart.

	#define CHR_BANK_ENDING					8
	#define CHR_BANK_MAIN					1