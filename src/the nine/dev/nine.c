// Cheril: the Nine
// Copyleft 2016 by The Mojon Twins

//#define STANDALONE
//#define DEBUG

// Shiru's

#include "neslib.h"

// Some needed stuff...

#include "definitions.h"

// Main const includes

#include "assets/precalcs.h"
#include "assets/palettes.h"
#include "assets/enems.h"
#include "assets/map.h"
#include "assets/enems_meghan.h"
#include "assets/map_meghan.h"
#include "assets/tiledata.h"
#include "assets/tiledata2.h"
#include "assets/metasprites.h"
#include "assets/behs.h"
#include "assets/levelset.h"

// RLE'd fixed screens

#include "assets/the_nine_title_rle.h"
#include "assets/the_nine_hud_rle.h"
#include "assets/the_nine_ending_rle.h"
#include "assets/meghan_title_rle.h"
#include "assets/meghan_hud_rle.h"
#include "assets/meghan_ending_rle.h"

// QR

#include "assets/meghan_qr_raw.h"

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
#include "engine/flower.h"
#include "engine/bullets.h"
#include "engine/hotspots.h"
#include "engine/bolts.h"
#include "engine/player.h"
#include "engine/enems.h"
#include "engine/hud.h"
#include "engine/game.h"

// Functions

void main (void) {
#ifndef STANDALONE	
	m113_handle_reset ();
	level = COMM_GAME_SELECT;
#else
	level = 2;
#endif	

	game_cheril = (level < 2);
	game_meghan = !game_cheril;

	ticks = ppu_system () ? 60 : 50;
	halfticks = ticks >> 1;

	c_pal_bg = l_pal_bg [level];
	c_pal_fg = l_pal_fg [level];

	pal_bg (c_pal_bg); 
	pal_spr (c_pal_fg);

	if (game_cheril) {
		map_w = MAP_W;
		pcellbase = CELL_CHERIL;
		encellbase = CELL_ENEMS_CHERIL;
		boffsoff = 0;
		stop_rate = 0x0f; stop_frames = 0x0f;
	} else {
		map_w = 4;
		pcellbase = CELL_MEGHAN;
		encellbase = CELL_ENEMS_MEGHAN;
		boffsoff = 4;
		stop_rate = 0x07; stop_frames = 0x1f;
	}

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
		while (pad_poll(0));
		if (pkilled) game_over (); else game_ending ();
	}
}
