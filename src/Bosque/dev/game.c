// MT MK2 NES v0.3
// Copyleft 2016 by The Mojon Twins

//#define STANDALONE	// Comment when assembling to main ROM.

// Shiru's

#include "neslib.h"

// Some needed stuff...

#include "definitions.h"

// Main const includes

#include "assets/precalcs.h"
#include "assets/palettes.h"
#include "assets/enems0.h"
#include "assets/map0.h"
#include "assets/enems1.h"
#include "assets/map1.h"
#include "assets/tiledata.h"
#include "assets/tiledata2.h"
#include "assets/metasprites.h"
#include "assets/behs.h"
#include "assets/levelset.h"
#include "assets/texts.h"
#include "assets/text_scripts.h"
#include "assets/ob_consts.h"
#include "assets/bosque_title_rle.h"
#include "assets/bosque_title2_rle.h"
#include "assets/bosque_ending_rle.h"
#include "assets/begins_title_rle.h"

// CUSTOM {
	const unsigned char * const title_rle [] = {
		bosque_title_rle, bosque_title_rle, bosque_title2_rle, bosque_title_rle, begins_title_rle
	};
// } END_OF_CUSTOM

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
// CUSTOM {
#include "engine/heart.h"
// } END_OF_CUSTOM
#include "engine/player.h"
#ifdef ENABLE_COCOS
#include "engine/simplecoco.h"
#endif
#include "engine/enems.h"
#include "engine/hud.h"
#include "engine/mapper113.h"
#include "engine/special.h"
#include "engine/game.h"

// Functions

void main (void) {
#ifndef STANDALONE	
	m113_handle_reset ();		// If bad checksum, this jumps to PRG 0 / CHR 0 (main menu)
	level = COMM_GAME_SELECT;
#else
	level = 4;
#endif	
	// level 3 = level 1, drunk mode.
	if (level == 3) {
		drunk_mode = 1; level -= 2;
	} else drunk_mode = 0;

	encelloffset = 0;
	itcelloffset = 0;
	
	switch (level) {
		case GAME_BOSQUE:
		case GAME_OTRO_BOSQUE:
			pcharacter = CELL_CHERIL;
			break;
		case GAME_NINJAJAR:
			pcharacter = CELL_NINJAJAR;
			break;
		case GAME_BEGINS:
			pcharacter = CELL_CHERIL_BABY;
			encelloffset = 20;
			itcelloffset = 4;
			break;
	}

	kissme = (level == 4);
			
	bank_bg (0);
	bank_spr (1);
	
	c_alt_tile = 16;

	oam_size (0);
	pal_bright (0);

	while (1) {
		game_title ();
		cls ();
		hud_draw ();
		game_init ();
		game_loop ();

		if (pkilled) game_over (); else game_ending ();
	}
}
