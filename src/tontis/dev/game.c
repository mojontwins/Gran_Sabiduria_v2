// MT MK2 NES v0.4
// Copyleft 2016 by The Mojon Twins

//#define STANDALONE	// Comment when assembling to main ROM.

// Shiru's

#include "neslib.h"

// Some needed stuff...

#include "definitions.h"

// Main const includes

#include "assets/palettes.h"
#include "assets/precalcs.h"
#include "assets/enems_potipoti.h"
#include "assets/enems_rendezvous.h"
#include "assets/enems_napia.h"
#include "assets/map_potipoti.h"
#include "assets/map_rendezvous.h"
#include "assets/map_napia.h"
#include "assets/tiledata.h"
#include "assets/tiledata3.h"
#include "assets/metasprites.h"
#include "assets/behs.h"
#include "assets/rlescreens.h"
#include "assets/texts.h"
#include "assets/napia_hud_rle.h"
#include "assets/napia_title_rle.h"
#include "assets/napia_ending_rle.h"
#include "assets/levelset.h"

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
#include "engine/fumettos.h"
// } END_OF_CUSTOM
#include "engine/player.h"
#ifdef ENABLE_COCOS
#include "engine/simplecoco.h"
#endif
#include "engine/enems.h"
#include "engine/hud.h"
#include "engine/mapper113.h"
// CUSTOM {
#include "engine/girl.h"
#include "engine/altuniverse.h"
// } END_OF_CUSTOM

#include "engine/game.h"

// Functions

void main (void) {
#ifndef STANDALONE	
	m113_handle_reset ();		// If bad checksum, this jumps to PRG 0 / CHR 0 (main menu)
	level = COMM_GAME_SELECT;
#else
	level = GM_NAPIA;
	//level = GM_RENDEZVOUS; 
	//level = GM_POTIPOTI;
#endif	
	game_potipoti = (level == GM_POTIPOTI);
	game_rendezvous = (level == GM_RENDEZVOUS);
	game_napia = (level == GM_NAPIA || level == GM_ALIEN);

	egg = pcharacter = 0;
	//encelloffset = 0;
	//itcelloffset = 0;
	restart_girl = very_first_time = 1;
	retries = wins = 0; 
	mapmode_autoshadows = game_napia;
	custom_dont_paint_tile_0 = game_rendezvous;
	
	bank_bg (0);
	bank_spr (1);
			
	//ticks = ppu_system () ? 60 : 50;
	//halfticks = ticks >> 1;
	c_alt_tile = 16;

	oam_size (0);
	pal_bright (0);

	switch (level) {
		case GM_POTIPOTI:
			pal_bg (palts_potipoti);
			pal_spr (palss_potipoti);
			mypal_game_bg_title = palts_potipoti;
			break;
		case GM_RENDEZVOUS:
			pal_spr (palss_rendezvous);
			mypal_game_bg_title = palts_rendezvous_t;
			music_play (3);
			break;
		case GM_NAPIA:
			pal_bg (palts_napia);
			pal_spr (palss_napia);
			mypal_game_bg_title = palts_napia;
			break;
		case GM_ALIEN:
			pal_bg (palts_alien);
			pal_spr (palss_alien);
			mypal_game_bg_title = palts_alien;
			egg = 1;
			level = GM_NAPIA; // easy peasy
			break;
	}

	while (1) {
		if (wins >= 3) mypal_game_bg_title = palts_rendezvous_alt;
		game_title ();
		cls ();
		hud_draw ();
		game_init ();
		game_loop ();

		if (game_rendezvous) {
			// Save position:
			ini_px [active_girl] = safe_px;
			ini_py [active_girl] = safe_py;
			ini_n_pant [active_girl] = safe_n_pant;

			// flip:
			active_girl = 1 - active_girl;	
		}

		if (pkilled) {
			if (!game_rendezvous) game_over ();
			if (wins >= 5) { restart_girl = 1; retries = 0; }
			retries ++;
		} else {
			music_stop ();
			game_ending ();
			if (game_rendezvous) {
				restart_girl = 1;
				wins ++;
				retries = 0;
				music_play (3);
			}
		}
	}
}
