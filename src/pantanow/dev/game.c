// Pantanow Engine rev2b 201703
// Copyleft 2016 by The Mojon Twins

//#define STANDALONE

#include "neslib-pantanow.h"

// Definitions

#include "definitions.h"

// Assets

extern const unsigned char map0 [];
extern const unsigned char map1 [];
extern const unsigned char map2 [];

#include "assets/precalcs.h"
#include "assets/palettes.h"
#include "assets/metasprites.h"
#include "assets/behs.h"
#include "assets/strips.h"
#include "assets/enems.h"
#include "assets/title_pantanow_rle.h"
#include "assets/title_desiertow_rle.h"
#include "assets/title_azoteaw_rle.h"
#include "assets/title_comandow_rle.h"
#include "assets/level_ending_rle.h"
#include "assets/level_ending_comandow_rle.h"
#include "assets/tiledata.h"
#include "assets/tiledata2.h"
#include "assets/levels.h"
#include "assets/texts.h"
#include "assets/texts2.h"

// Some variables

#pragma bss-name (push,"ZEROPAGE")
#pragma data-name(push,"ZEROPAGE")

#include "ram/zp.h"

#pragma bss-name (push,"BSS")
#pragma data-name(push,"BSS")

#include "ram/bss.h"

// Engine functions

#include "engine/printer.h"
#include "engine/mapper113.h"
#include "engine/scroller.h"
#include "engine/gbuffer.h"
#include "engine/bullets.h"
#include "engine/hud.h"
#include "engine/enems.h"
#include "engine/player.h"
#include "engine/screens.h"
#include "engine/game.h"

// Main

void main (void) {
#ifndef STANDALONE	
	m113_handle_reset ();		// If bad checksum, this jumps to PRG 0 / CHR 0 (main menu)
	level = COMM_GAME_SELECT;
#else
	level = 3;
#endif	

	// level == 0..2 pantanow / desiertow / azoteaw
	// level == 3 commando - cycles levels.

	full_game = (level == 3);

	ticks = ppu_system () ? 60 : 50;
	halfticks = ticks >> 1;

	bank_bg (0);
	bank_spr (1);

	set_scroll_write (0);

	while (1) {
		if (full_game) {
			pal_bg (mypal_game_bgc0);
			pal_spr (mypal_game_fg1);
			spr_player = spr_player2;
			spr_enems = spr_enems2;
			strs_texts = strs_texts2;
		} else {
			pal_bg (level_pal_bg [level]);
			pal_spr (mypal_game_fg0);
			spr_player = spr_player1;
			spr_enems = spr_enems1;
			strs_texts = strs_texts1;
		}	

		if (full_game) level = 0;
		game_title ();

		plife = 7; pflickering = ticks + ticks;
		
		while (1) {
			if (full_game) {
				pal_bg (mypal_game_bg0);
				game_level ();
				pal_bg (level_pal_bg [level + 3]);
			}

			ts_base = level << 6;			
			//if (plife < 5) plife = 5;

			game_init ();
			game_loop ();

			if (pkilled) {
				if (full_game) pal_bg (mypal_game_bg0);
				game_over (); break;
			} else if (full_game && level < 2) {
				level ++;
				plife ++;
			} else {
				if (full_game) pal_bg (mypal_game_bg0);
				game_ending (); break;
			}
		}
	}
}
