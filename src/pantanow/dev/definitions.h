// Pantanow Engine rev2b 201703
// Copyleft 2016 by The Mojon Twins

// Main definitions

// Communications

	#define COMM_POOL						((unsigned char*)0x0300)	// Mapper 113 stuff.

	#define COMM_REG						(COMM_POOL[0x0])
	#define COMM_GAME_SELECT				(COMM_POOL[0x1])
	#define COMM_GAME_FLAGS 				(COMM_POOL[0x2])
	#define COMM_CHECKSUM 					(COMM_POOL[0xf])

// Main definitions

	#define SCROLL_BUFFER			((unsigned char*)0x0310)
	#define ATTRIB_BUFFER 			((unsigned char*)0x0330)
	#define SCREEN_BUFFER 			((unsigned char*)(scr_buff))

	#define DBG_POOL				((unsigned char*)0xf0)

	#define UPDATE_LIST_SIZE		32
	#define MSB(x)					((x)>>8)
	#define LSB(x)					((x)&0xff)
	#define SPRITE_ORIGIN			0
	#define TILE_ORIGIN 			0
	#define SPRITE_ADJUST			SPRITE_ORIGIN-1
	#define TOP_ADJUST				0
	#define FIX_BITS				4
	#define FADE_DELAY 				1

	#define SGNI(n)					((n)<0?-1:1)
	#define SGNC(a,b,c)				((a)<(b)?-(c):(c))
	#define SATURATE_Z(n)			((n)<0?0:(n))
	#define SATURATE(v,max)			((v)>=0?((v)>(max)?(max):(v)):((v)<-(max)?-(max):(v)))
	#define ABS(n)					((n)<0?-(n):(n))
	#define DELTA(a,b)				((a)<(b)?(b)-(a):(a)-(b))
	//#define CL(x1,y1,x2,y2)		((x1)+4>=(x2)&&(x1)<=(x2)+12&&(y1)+12>=(y2)&&(y1)<=(y2)+12)
	#define CLE(x1,y1,x2,y2)			((x1)+7>=(x2)&&(x1)<=(x2)+7&&(y1)+14>=(y2)&&(y1)<=(y2)+14)
	#define CLB(x1,y1,x2,y2)			((x1)+7>=(x2)&&(x1)<=(x2)+7&&(y1)+8>=(y2)&&(y1)<=(y2)+14)
	#define SUBSTR_SAT(a,b)			((a)>(b)?(a)-(b):0)
	#define DISABLE_SFX_NEXT_FRAME	*((unsigned char*)0x01bf)=1;
	#define ADD_SIGN2(a,b,v)		((a)==(b))?(0):(((a)>(b))?(v):(-(v)))
	#define ADD_SIGN(a,v) 			((a)?(((a)>0)?(v):(-(v))):(0))

// Change this if you change where digits are stored in the pattern table
	#define DIGIT(n) 				(64+(n))

// Game definitions

// Player

	#define PLAYER_VX_MAX					32
	#define PLAYER_AX						8
	#define PLAYER_RX						4	
	#define PLAYER_VX_MIN 					16

	#define PLAYER_VY_MAX					32
	#define PLAYER_AY						4
	#define PLAYER_RY						2
	#define PLAYER_VY_MIN 					8

	#define PLAYER_V_REBOUND				48
	#define PLAYER_V_REBOUND_MULTI			48
	#define PLAYER_HIT_FRAMES				16
	#define PLAYER_REBOUND_REVERSE_DIRECTION

	#define TURRET_FRAMES					6	
	#define ENEMIES_FIRE_RATE				20 		// Don't fire if less than N frames have passed

// Enemos

	#define ENEMS_MAX						6

// Bullets

	#define BULLETS_MAX						8
	#define BULLETS_V 						8
	#define BULLETS_VE 						4

// Animation cells

	#define CELL_FACING_RIGHT 				0
	#define CELL_FACING_LEFT				6
	#define CELL_FACING_DOWN				12
	#define CELL_FACING_UP					18
	#define CELL_HIT_BASE 					24
	#define CELL_WIN_BASE 					28
	#define CELL_FIRING						5
	#define CELL_IDLE						0
	#define CELL_WALK_BASE 					1

	#define CELL_EN_FACING_RIGHT			0
	#define CELL_EN_FACING_LEFT 			8
	#define CELL_EN_IDLING 					4
	#define CELL_EN_DYING 					6
	#define CELL_EN_FIRING 					7

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

	#define MUSIC_TITLE				1
	#define MUSIC_INGAME 			0

// Enemy states

	#define ENS_CHOOSING			0
	#define ENS_MOVING 				1
	#define ENS_PURSUING 			2
	#define ENS_IDLING 				3
	#define ENS_FIRING 				4
	#define ENS_DYING  				5
