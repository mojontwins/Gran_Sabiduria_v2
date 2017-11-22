// MT MK2 NES v0.6
// Copyleft 2016 by The Mojon Twins

// Main definitions

// Communications

	#define COMM_POOL						((unsigned char*)0x0300)	// Mapper 113 stuff.

	#define COMM_REG						(COMM_POOL[0x0])
	#define COMM_GAME_SELECT				(COMM_POOL[0x1])
	#define COMM_GAME_FLAGS 				(COMM_POOL[0x2])
	#define COMM_CHECKSUM 					(COMM_POOL[0xf])

// Game configuration

	#define GM_RESET 						0
	#define GM_TRABAJO_BASURA				0x10
	#define GM_VESTA_VAAL					0x11
	
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
	#define MAP_H							4
	#define MAX_PANTS						MAP_W * MAP_H
	#define N_ENEMS							3
	#define BOLTS_MAX 						5

	#define LIFE_INI						5
	#define LIFE_REFILL						1

	#define MAP_FORMAT_BYTE_RLE
	//#define MAP_FORMAT_PACKED
	//#define MAP_USE_ALT_TILE
	//#define MAP_ENABLE_AUTOSHADOWS

	//#define MAP_DONT_PAINT_TILE_0			// If you want to use backdrops, make the painter skip tile 0
	//#define MAP_CHECK_TOP
	//#define MAP_CHECK_BOTTOM

// Game engine values

	#define PERSISTENT_DEATHS
	#define PERSISTENT_ENEMIES
	//#define WALLS_STOP_ENEMIES			// 0.3 - only works for linear enemies.
	//#define ENEMS_COLLIDE_WITH_EVERYTHING
	//#define ENEMIES_SUFFER_WHEN_HITTING_PLAYER

// Linear enemies

	#define ENABLE_LINEAR
	#define ENABLE_PLATFORMS

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
	//#define ENABLE_STEADY_SHOOTER
	#define STEADY_SHOOTER_CELL				32

// Monococo
	//#define ENABLE_MONOCOCO
	#define MONOCOCO_BASE_TIME_HIDDEN		150
	#define MONOCOCO_BASE_TIME_APPEARING	50
	#define MONOCOCO_BASE_TIME_ONBOARD		50
	#define MONOCOCO_FIRE_COCO_AT			MONOCOCO_BASE_TIME_ONBOARD/2
	#define MONOCOCO_CELL_BASE				8

// Gyrosaws
	//#define ENABLE_GYROSAW
	#define GYROSAW_CELL_BASE				16
	#define GYROSAW_V						1

// Fanty
	//#define ENABLE_FANTY
	#define FANTY_CELL_BASE 				20
	#define FANTY_TIMER_BASE				120
	#define FANTY_A 						1
	#define FANTY_MAXV 						16

// Catacrock
	//#define ENABLE_CATACROCK
	#define CATACROCK_CELL_BASE 			28
	#define CATACROCK_CROCK_FRAMES			50
	#define CATACROCK_G 					4
	#define CATACROCK_MAXV					64

// Generatonis
	#define ENABLE_GENERATONIS
	#define GENERATONI_G					4
	#define GENERATONI_MAXV					64

// Auxiliary stuff

	#if defined (ENABLE_STEADY_SHOOTER) || defined (ENABLE_MONOCOCO)
	#define ENABLE_COCOS
	#define COCOS_MAX 						3
	#define COCO_PATTERN					1
	#define COCO_PALETTE					1
	#define COCO_V							96

	#if defined (ENABLE_MONOCOCO)
	#define ENABLE_COCO_AIMED
	#define COCO_FAIR_D						64
	#endif

	#if defined (ENABLE_STEADY_SHOOTER)
	#define ENABLE_COCO_STRAIGHT
	#endif

	#endif

	#if defined (ENABLE_FANTY) || defined (ENABLE_GENERATONIS)
	#define ENEMIES_NEED_FP
	#endif

	//#define ENABLE_FUMETTOS
	#define FUMETTOS_MAX 					3
	#define FUMETTO_BASE_PATTERN 			2

// Game states

	#define GS_GAME_OVER					0

// Evil tiles

	// Enable the ones you need. Use a custom way to switch between them if you activate several:
	#define EVIL_TILE_ON_FLOOR
	//#define EVIL_TILE_ON_CEILING
	//#define EVIL_TILE_MULTI

	#if defined (EVIL_TILE_MULTI) || defined (EVIL_TILE_ON_FLOOR) || defined (EVIL_TILE_ON_CEILING)
	#define ENABLE_EVIL_TILE
	#endif

// Player

	// Enable the ones you need. Use a custom way to switch between them if you activate several:
	//#define PLAYER_GENITAL
	#define PLAYER_JUMPS
	//#define PLAYER_DOUBLE_JUMP
	//#define PLAYER_MONONO
	//#define PLAYER_JETPAC

	#define PLAYER_8_PIXELS					// Collision box is 8x8 instead of 8x16

	//#define PLAYER_PUSH_BOXES

	#if defined (PLAYER_JUMPS) || defined (PLAYER_MONONO) || defined (PLAYER_JETPAC)
	#define PLAYER_GRAVITY
	#endif

	#define PLAYER_INI_X					2
	//#define PLAYER_INI_Y					10

	//#define PLAYER_VX_MAX					32
	//#define PLAYER_AX						4
	//#define PLAYER_RX						2	
	#define PLAYER_VX_MIN 					8

	#define PLAYER_VY_FALLING_MAX			64
	#define PLAYER_G						4 
	#define PLAYER_VY_MIN 					16

	//#define PLAYER_VY_JETPAC_MAX			16		// Jetpac values
	//#define PLATER_AY_JETPAC 				3

	//#define PLAYER_VY_JUMP_INITIAL			16
	//#define PLAYER_AY_JUMP					7
	//#define PLAYER_VY_JUMP_MAX 				48

	#define PLAYER_VY_JUMP_A_STEPS 			16

	//#define PLAYER_VY_MAX					32
	//#define PLAYER_AY						4
	//#define PLAYER_RY						2
	//#define PLAYER_VY_MIN 				8

	#define PLAYER_V_REBOUND				96
	#define PLAYER_V_REBOUND_MULTI			48
	#define PLAYER_VY_BUTT_REBOUND			48
	#define PLAYER_HIT_FRAMES				16
	#define PLAYER_REBOUND_REVERSE_DIRECTION

	#define PLAYER_FLICKERS					120
	#define PLAYER_DIE_AND_RESPAWN

// Ways to kill

	//#define PLAYER_SPINS
	//#define PLAYER_SPINS_KILLS
	#define PLAYER_STEPS_ON_ENEMIES
	//#define PLAYER_BUTT
	#define KILLABLE_CONDITION				(en_s [gpit] == 8 && game_trabajo_basura)	// Define if needed

// Things related to shooting

	//#define PLAYER_CAN_FIRE

	// Turret

	//#define PLAYER_TURRET
	#define TURRET_FRAMES					16 	

	// Bullets

	#define BULLETS_MAX						8
	#define BULLETS_V 						8

	//#define SHOOTING_DRAINS

	//#define ENABLE_PUAS
	#define PUAS_MAX						2
	#define PUAS_VX							2

// Hotspots
// Define those to include all related code

	#define HOTSPOT_TYPE_OBJECT				1
	#define HOTSPOT_TYPE_KEY 				2
	#define HOTSPOT_TYPE_REFILL 			3
	
// Expand upon this when needed

	#if defined (PLAYER_CAN_FIRE) || defined (PLAYER_SPINS_KILLS) || defined (PLAYER_STEPS_ON_ENEMIES)
	#define ENEMIES_CAN_DIE
	//#define SPRITE_EXPLOSION 		ssit_tb_03
	#endif

// Handy (expand?)
	#if defined (HOTSPOT_TYPE_KEY) || defined (PLAYER_PUSH_BOXES)
	#define PLAYER_PROCESS_BLOCK
	#endif

// Proto scripting stuff
// (Will change to "proper" scripting stuff when scripting is implemented)

	#define MAX_FLAGS 						16
	#define COUNT_KILLED_ON_FLAG 			1
	#define ONLY_ONE_OBJECT_FLAG 			2

	// Some stuff make hotspots managing slightly more complex

	#if defined (ONLY_ONE_OBJECT_FLAG)
	#define HOTSPOTS_LOGIC_MORE_COMPLEX
	#endif

// Animation cells

	#define CELL_FACING_RIGHT 				0
	//#define CELL_FACING_LEFT				9
	#define CELL_IDLE						0
	#define CELL_WALK_BASE 					1
	#define CELL_DESCENDING					5
	#define CELL_ASCENDING					6
	#define CELL_HIT 						7
	#define CELL_OBJECT 					8
	
	//#define CELL_FACING_DOWN				10
	//#define CELL_FACING_UP				15
	//#define CELL_HIT_BASE 				20
	//#define CELL_FIRING					5
	//#define CELL_AIRBORNE 				7
	//#define CELL_JUMP_BASE				5
	//#define CELL_FALLING 					9

// Sound channels

	#define SC_PLAYER						0
	#define SC_ENEMS						1
	#define SC_LEVEL						1

// SFX

	#define SFX_JUMP						1			
	#define SFX_ENEMY_HIT					3
	#define SFX_CHOF						7
	#define SFX_GET_ITEM					2
	#define SFX_BUTT_FALL					8
	#define SFX_BUTT_HIT					9
	#define SFX_SHOOT						5
	#define SFX_FART						6
	#define SFX_START						0
	#define SFX_EXTRA_1						4
	#define SFX_BLOCO						10

// Music

	#define MUSIC_TITLE						0
	#define MUSIC_INGAME 					1
	#define MUSIC_EVENT						2
	#define MUSIC_GAME_OVER 				3

// Make code more readable:

	#define MONOCOCO_X 						en_x
	#define MONOCOCO_Y						en_y
	#define MONOCOCO_COUNTER 				en_my
	#define MONOCOCO_STATE 					en_state

	#define GYROSAW_COUNTER 				en_mx
	#define GYROSAW_DIRECTION				en_my
	#define GYROSAW_STATE 					en_state

	#define CATACROCK_COUNTER 				en_mx
	#define CATACROCK_WAIT 					en_my
	#define CATACROCK_STATE 				en_state

	#define GENERATONI_COUNTER 				en_x2
	#define GENERATONI_WAIT 				en_y2
	#define GENERATONI_STATE 				en_state
	#define GENERATONI_HL 					en_my

	#define MAX_STARS 						32

// Custom stuff

	#define PGAUGE_MAX 						7
	#define PGAUGE_TRANSFORM_PENALTY		4
