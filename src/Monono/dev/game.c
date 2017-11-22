// MT MK2 NES v0.1
// Copyleft 2016 by The Mojon Twins

//#define STANDALONE	// Comment when assembling to main ROM.

// Shiru's

#include "neslib.h"

// Some needed stuff...

#include "definitions.h"

// Main const includes

#include "assets/palettes.h"
#include "assets/enems0.h"
#include "assets/map0.h"
#include "assets/enems1.h"
#include "assets/map1.h"
#include "assets/tiledata0.h"
#include "assets/tiledata1.h"
#include "assets/tiledata_lah.h"
#include "assets/tiledata4.h"
#include "assets/metasprites.h"
#include "assets/behs.h"
#include "assets/precalcs.h"
#include "assets/lah_title_rle.h"
#include "assets/lah_ending_rle.h"
#include "assets/pppp_title_rle.h"
#include "assets/pppp_ending_rle.h"
#include "assets/monona_title_rle.h"
#include "assets/monona_ending_rle.h"
#include "assets/monono_title_rle.h"
#include "assets/jetpuri_title_rle.h"
#include "assets/jetpuri_ending_rle.h"
#include "assets/levelset.h"

// Some variables

#pragma bss-name (push,"ZEROPAGE")
#pragma data-name(push,"ZEROPAGE")

#include "ram/zp.h"

#pragma bss-name (push,"BSS")
#pragma data-name(push,"BSS")

#include "ram/bss.h"

// Engine functions

#include "engine/mapper113.h"
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
#include "engine/fumettos.h"
// } END_OF_CUSTOM
#include "engine/player.h"
#ifdef ENABLE_COCOS
#include "engine/simplecoco.h"
#endif
#include "engine/enems.h"
#include "engine/hud.h"
#include "engine/game.h"

// Functions

void main (void) {
#ifndef STANDALONE	
	m113_handle_reset ();		// If bad checksum, this jumps to PRG 0 / CHR 0 (main menu)
#else
	level = /* GAME_JET_PURI */ GAME_MONONO ;	
#endif	
	level = COMM_GAME_SELECT;

	game_jet_puri = (level == GAME_JET_PURI);
	game_monono = (level == GAME_MONONO);
	game_monona = (level == GAME_MONONA);
	game_pppp = (level == GAME_PPPP);

	// Some rather sensible stuff...
	// If space is tight, rewrite this in a more clever way, pleeze.
	inverted_screen = 0;
	TOP_ADJUST = l_TOP_ADJUST [level];
	SPRITE_ADJUST = l_SPRITE_ADJUST [level];
	PLAYER_G = l_PLAYER_G [level];
	pcharacter = l_pcharacter [level];
	encelloffset = l_encelloffset [level];
	itcelloffset = level << 2; //l_itcelloffset [level];
	pal_spr (l_pal_spr [level]);
	hudbaseline = l_hudbaseline [level];
	PLAYER_AX = l_PLAYER_AX [level];
	inverted_screen = (game_pppp);
	n_bolts = 5;
	map_w = (level < GAME_LAH) ? 3 : 6;

	please_continue = 0;
	already_played = 0;

	ticks = ppu_system () ? 60 : 50;
	halfticks = ticks >> 1;

	bank_bg (0);
	bank_spr (1);
	oam_size (0);
	pal_bright (0);

	while (1) {
		game_title ();
		cls ();
		hud_draw ();
		game_init ();
		game_loop ();
		already_played = 1;

		if (pkilled) game_over (); else game_ending ();
	}
}
