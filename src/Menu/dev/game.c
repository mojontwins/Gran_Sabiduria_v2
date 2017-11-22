// MT MK2 NES v0.6
// Copyleft 2016 by The Mojon Twins

//#define STANDALONE	// Comment when assembling to main ROM.

//#define AUTO_BOOT
#define AUTO_BOOT_PRG 1
#define AUTO_BOOT_CHR 11
#define AUTO_BOOT_GS  3

// Shiru's

#include "neslib.h"

// Some needed stuff...

#include "definitions.h"

// Main const includes

#include "assets/palettes.h"
#include "assets/precalcs.h"
#include "assets/enems0.h"
#include "assets/map0.h"
#include "assets/enems1.h"
#include "assets/map1.h"
#include "assets/tiledata.h"
#include "assets/tiledata2.h"
#include "assets/metasprites.h"
#include "assets/behs.h"
#include "assets/rlescreens.h"
#include "assets/texts.h"
#include "assets/levelset.h"
#include "assets/tb_ending_rle.h"
#include "assets/tb_qr_rle.h"
#include "assets/vv_qr_rle.h"

#include "assets/menudata.h"

// Some variables

#pragma bss-name (push,"ZEROPAGE")
#pragma data-name(push,"ZEROPAGE")

#include "ram/zp.h"

#pragma bss-name (push,"BSS")
#pragma data-name(push,"BSS")

#include "ram/bss.h"

// Engine functions

#include "engine/printer.h"
#include "engine/screens.h"
#include "engine/general.h"
#ifdef SHOOTING_DRAINS
#include "engine/flower.h"
#endif
#ifdef PLAYER_CAN_FIRE
#include "engine/bullets.h"
#endif
#include "engine/hotspots.h"
#ifdef HOTSPOT_TYPE_KEY
#include "engine/bolts.h"
#endif
#ifdef ENABLE_FUMETTOS
#include "engine/fumettos.h"
#endif
#ifdef ENABLE_PUAS
#include "engine/puas.h"
#endif
// CUSTOM {
#include "engine/hitter.h"
// } END_OF_CUSTOM
#include "engine/hud.h"
#include "engine/player.h"
#ifdef ENABLE_COCOS
#include "engine/simplecoco.h"
#endif
#include "engine/enems.h"
#include "engine/mapper113.h"

#include "menustuff.h"

#include "engine/game.h"

// Functions

void main (void) {
#ifndef STANDALONE
	if (m113_comm_pool_checksum_check ()) 
		gs = COMM_GAME_SELECT;
	else {
		COMM_REG = 0x80;
		m113_safe_change_chr_bank (0); // Vesta Vaal may have changed it!
		gs = 0;
	}
	m113_comm_pool_init ();
#else
	gs = GM_TRABAJO_BASURA;
	//gs = GM_VESTA_VAAL;
#endif	

	game_trabajo_basura = (gs == GM_TRABAJO_BASURA);
	game_vesta_vaal = (gs == GM_VESTA_VAAL);

	level = gs - 0x10;	// Ojal con esto!

	if (game_trabajo_basura) {
		pcharacter = encelloffset = itcelloffset = 0;

		CELL_FACING_LEFT = 9;
		PLAYER_INI_Y = 10;
		PLAYER_VX_MAX = 32;
		PLAYER_AX = 4;
		PLAYER_RX = 8;
		PLAYER_VY_JUMP_INITIAL = 16;
		PLAYER_AY_JUMP = 7;
		PLAYER_VY_JUMP_MAX = 48;
		SPRITE_EXPLOSION = ssit_tb_03;
	} else {
		pcharacter = 18;
		encelloffset = 16;
		itcelloffset = 4;

		CELL_FACING_LEFT = 6;
		PLAYER_INI_Y = 2;
		SPRITE_EXPLOSION = ssit_tb_02_a;
	}
	
#ifdef MAP_ENABLE_AUTOSHADOWS	
	mapmode_autoshadows = 1;
#endif
	
	bank_bg (0);
	bank_spr (1);
			
	ticks = ppu_system () ? 60 : 50;
	halfticks = ticks >> 1;
	c_alt_tile = 16;

	oam_size (0);
	pal_bright (0);
	
#ifdef AUTO_BOOT
	COMM_GAME_SELECT = AUTO_BOOT_GS;
	m113_comm_pool_checksum_write ();
	m113_rom_pair_jump (AUTO_BOOT_PRG, AUTO_BOOT_CHR);
#endif	

	if (!gs) menu_do ();

	// Run the game here.
	while (1) {
		game_title ();
		cls ();
		hud_draw ();
		game_init ();
		game_loop ();

		if (pkilled) game_over (); else game_ending ();
	}
}
