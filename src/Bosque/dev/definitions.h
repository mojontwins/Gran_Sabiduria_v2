// MT MK2 NES v0.3
// Copyleft 2016 by The Mojon Twins

// Main definitions

// Communications

	#define COMM_POOL						((unsigned char*)0x0300)	// Mapper 113 stuff.

	#define COMM_REG						(COMM_POOL[0x0])
	#define COMM_GAME_SELECT				(COMM_POOL[0x1])
	#define COMM_GAME_FLAGS 				(COMM_POOL[0x2])
	#define COMM_CHECKSUM 					(COMM_POOL[0xf])

// Game configuration

	#define GAME_BOSQUE						0
	#define GAME_NINJAJAR 					1
	#define GAME_OTRO_BOSQUE 				2
	#define GAME_DRUNK						3
	#define GAME_BEGINS 					4
	
// Macros

	#define UPDATE_LIST_SIZE				32
	#define MSB(x)							((x)>>8)
	#define LSB(x)							((x)&0xff)
	#define TOP_ADJUST						4
	#define SPRITE_ADJUST					(TOP_ADJUST-2) * 8 - 1
	#define FIX_BITS						4
	#define FADE_DELAY 						1

	#define SGNI(n)							((n)<0?-1:1)
	#define SGNC(a,b,c)						((a)<(b)?-(c):(c))
	#define SATURATE_Z(n)					((n)<0?0:(n))
	#define SATURATE(v,max)					((v)>=0?((v)>(max)?(max):(v)):((v)<-(max)?-(max):(v)))
	#define SATURATE_N(v,min)				(v<min?min:v)
	#define ABS(n)							((n)<0?-(n):(n)) 
	#define DELTA(a,b)						((a)<(b)?(b)-(a):(a)-(b))
	#define CL(x1,y1,x2,y2)					((x1)+4>=(x2)&&(x1)<=(x2)+12&&(y1)+12>=(y2)&&(y1)<=(y2)+12)
	#define SUBSTR_SAT(a,b)					((a)>(b)?(a)-(b):0)
	#define DISABLE_SFX_NEXT_FRAME			*((unsigned char*)0x01bf)=1;
	#define ADD_SIGN2(a,b,v)				((a)==(b))?(0):(((a)>(b))?(v):(-(v)))
	#define ADD_SIGN(a,v) 					((a)?(((a)>0)?(v):(-(v))):(0))

	// Change this if you change where digits are stored in the pattern table
	#define DIGIT(n) 						(16+(n))

// Game definitions

	#define MAP_W							5
	#define MAP_H							7
	#define N_ENEMS							3
	#define BOLTS_MAX 						4

	#define LIFE_INI						25
	#define LIFE_REFILL						5

	//#define MAP_FORMAT_BYTE_RLE
	#define MAP_FORMAT_PACKED
	#define MAP_USE_ALT_TILE

// Game engine values

	//#define PERSISTENT_DEATHS
	#define PERSISTENT_ENEMIES
	#define WALLS_STOP_ENEMIES				// 0.3 - only works for linear enemies.

// Linear enemies

	#define ENABLE_LINEAR
	//#define ENABLE_PLATFORMS

// Type7 (with or without generators) enemies

	//#define ENABLE_TYPE_7
	#define TYPE7_BASE_SPRITE 				24
	#define TYPE7_GENERATOR_LIFE			10
	#define TYPE7_MINION_LIFE 				3
	#define TYPE7_SPAWN_TIME				50+(rand8()&63)		// Must be of course > TYPE7_DYING_FRAMES!
	#define TYPE7_MINION_DYING_FRAMES		16
	#define TYPE7_MINION_HIT_FRAMES			16
	#define TYPE7_GENERATOR_DYING_FRAMES	16
	#define TYPE7_GENERATOR_HIT_FRAMES		16

// Walker 

	//#define ENABLE_WALKER
	#define WALKER_BASE_SPRITE				26
	#define WALKER_MIN_RUN					4
	#define WALKER_EXPRESSION				(WALKER_MIN_RUN + (rand8 () & 3))
	#define WALKER_HIT_FRAMES				16

// Steady shooters
	#define ENABLE_STEADY_SHOOTER
	#define STEADY_SHOOTER_CELL				16

// Monococo
	//#define ENABLE_MONOCOCO
	#define MONOCOCO_BASE_TIME_HIDDEN		150
	#define MONOCOCO_BASE_TIME_APPEARING	50
	#define MONOCOCO_BASE_TIME_ONBOARD		50
	#define MONOCOCO_FIRE_COCO_AT			MONOCOCO_BASE_TIME_ONBOARD/2
	#define MONOCOCO_CELL_BASE				16

// Auxiliary stuff

	#if defined (ENABLE_STEADY_SHOOTER) || defined (ENABLE_MONOCOCO)
	#define ENABLE_COCOS
	#define COCOS_MAX 						2
	#define COCO_PATTERN					1
	#define COCO_PALETTE					3
	#define COCO_V							96

	#if defined (ENABLE_MONOCOCO)
	#define ENABLE_COCO_AIMED
	#define COCO_FAIR_D						64
	#endif

	#if defined (ENABLE_STEADY_SHOOTER)
	#define ENABLE_COCO_STRAIGHT
	#endif

	#endif

// Game states

	#define GS_GAME_OVER					0

// Evil tiles

	// Enable the ones you need. Use a custom way to switch between them if you activate several:
	//#define EVIL_TILE_ON_FLOOR
	#define EVIL_TILE_MULTI

	#if defined (EVIL_TILE_MULTI) || defined (EVIL_TILE_ON_FLOOR)
	#define ENABLE_EVIL_TILE
	#endif

// Player

	// Enable the ones you need. Use a custom way to switch between them if you activate several:
	#define PLAYER_GENITAL
	//#define PLAYER_JUMPS
	//#define PLAYER_MONONO
	//#define PLAYER_JETPAC

	#define PLAYER_8_PIXELS					// Collision box is 8x8 instead of 8x16

	#define PLAYER_PUSH_BOXES

	#if defined (PLAYER_JUMPS) || defined (PLAYER_MONONO) || defined (PLAYER_JETPAC)
	#define PLAYER_GRAVITY
	#endif

	#define PLAYER_INI_X					7
	#define PLAYER_INI_Y					3

	#define PLAYER_VX_MAX					32
	#define PLAYER_AX						4
	#define PLAYER_RX						2	
	#define PLAYER_VX_MIN 					8

	//#define PLAYER_VY_FALLING_MAX			64
	//#define PLAYER_G						4 
	//#define PLAYER_VY_MIN 				16

	//#define PLAYER_VY_JETPAC_MAX			16		// Jetpac values
	//#define PLATER_AY_JETPAC 				3

	//#define PLAYER_VY_JUMP_INITIAL		16
	//#define PLAYER_AY_JUMP				8
	//#define PLAYER_VY_JUMP_MAX 			64
	//#define PLAYER_VY_JUMP_A_STEPS 		16

	#define PLAYER_VY_MAX					32
	#define PLAYER_AY						4
	#define PLAYER_RY						2
	#define PLAYER_VY_MIN 					8

	#define PLAYER_V_REBOUND				48
	#define PLAYER_V_REBOUND_MULTI			48
	#define PLAYER_HIT_FRAMES				16
	#define PLAYER_REBOUND_REVERSE_DIRECTION

	//#define PLAYER_FLICKERS				120

// Ways to kill

	//#define PLAYER_SPINS
	//#define PLAYER_SPINS_KILLS

// Things related to shooting

	//#define PLAYER_CAN_FIRE

	// Turret

	//#define PLAYER_TURRET
	#define TURRET_FRAMES					16 	

	// Bullets

	#define BULLETS_MAX						8
	#define BULLETS_V 						8

	//#define SHOOTING_DRAINS

// Hotspots
// Define those to include all related code

	#define HOTSPOT_TYPE_REFILL 			3
	#define HOTSPOT_TYPE_OBJECT				1
	#define HOTSPOT_TYPE_KEY 				2

// Expand upon this when needed

	#if defined (PLAYER_CAN_FIRE) || defined (PLAYER_SPINS_KILLS)
	#define ENEMIES_CAN_DIE
	#define SPRITE_EXPLOSION 		ssextra
	#endif

// Animation cells

	#define CELL_FACING_RIGHT 				0
	#define CELL_FACING_LEFT				5
	#define CELL_FACING_DOWN				10
	#define CELL_FACING_UP					15
	#define CELL_HIT_BASE 					20
	//#define CELL_FIRING					5
	#define CELL_IDLE						0
	#define CELL_WALK_BASE 					1
	//#define CELL_DESCENDING				5
	//#define CELL_ASCENDING				6
	//#define CELL_HIT 						10
	//#define CELL_AIRBORNE 				7
	//#define CELL_JUMP_BASE				5
	//#define CELL_FALLING 					9

	#define CELL_CHERIL						0
	#define CELL_NINJAJAR 					22
	#define CELL_CHERIL_BABY 				44

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
	#define MUSIC_EVENT				2
	#define MUSIC_GAME_OVER 		3

// Make code more readable:

	#define MONOCOCO_X 					en_x
	#define MONOCOCO_Y					en_y
	#define MONOCOCO_COUNTER 			en_my
	#define MONOCOCO_STATE 				en_mx

// custom

	#define DRUNK						(rand8 () & 0x0f) - 8
	#define MAX_HEARTS					8
