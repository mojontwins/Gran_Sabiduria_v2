// MT MK2 NES v0.86 - Sonic Bad is bad
// Copyleft 2017 by The Mojon Twins

//#define STANDALONE		// Comment when assembling to main ROM.

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
#include "assets/enems2.h"
#include "assets/map2.h"
//#include "assets/enems3.h"
//#include "assets/map3.h"
#include "assets/tiledata.h"
#include "assets/metasprites.h"
#include "assets/behs.h"
#include "assets/levelset.h"
//#include "assets/texts.h"
//#include "assets/script_texts.h"
//#include "assets/talk_scripts.h"
//#include "assets/dialogue.h"
#include "assets/title_rle.h"
#include "assets/title_somari_rle.h"
//#include "assets/hud_rle.h"
#include "assets/ending_rle.h"
#include "assets/ending_espinete_rle.h"

// Some variables

#pragma bss-name (push,"ZEROPAGE")
#pragma data-name(push,"ZEROPAGE")

#include "ram/zp.h"

#pragma bss-name (push,"BSS")
#pragma data-name(push,"BSS")

#include "ram/bss.h"

// Engine functions

#include "someprotos.h"
#include "engine/printer.h"
#include "engine/screens.h"
#include "engine/general.h"
#ifdef ENABLE_SPRINGS
#include "engine/spring.h"
#endif
#ifdef ENABLE_PROPELLERS
#include "engine/propellers.h"
#endif
#ifdef ENABLE_ESTRUJATORS
#include "engine/estrujators.h"
#endif
#ifdef ENABLE_CATARACTS
#include "engine/cataracts.h"
#endif
#ifdef SCRIPTING_ON
#ifdef ENABLE_EXTERN_CODE
#include "engine/extern.h"
#endif
#include "engine/mscnes.h"
#endif
#ifdef SHOOTING_DRAINS
#include "engine/flower.h"
#endif
#ifdef BREAKABLE_WALLS
#include "engine/breakable.h"
#endif
#ifdef PLAYER_CAN_FIRE
#include "engine/bullets.h"
#endif
#ifndef DISABLE_HOTSPOTS
#include "engine/hotspots.h"
#endif
#ifdef HOTSPOT_TYPE_KEY
#include "engine/bolts.h"
#endif
#ifdef ENABLE_FUMETTOS
#include "engine/fumettos.h"
#endif
#ifdef ENABLE_PUAS
#include "engine/puas.h"
#endif
#include "engine/hud.h"
#ifdef ENABLE_CONTAINERS
#include "engine/containers.h"
#endif
#ifdef ENABLE_FABOLEES
#include "engine/fabolee_int.h"
#endif
// CUSTOM {
// Custom rings for Sonic Mal
#include "engine/aeuro_aeuro.h"
// }
#include "engine/player.h"
#ifdef ENABLE_COCOS
#include "engine/simplecoco.h"
#endif
#include "engine/enems.h"
#include "engine/mapper113.h"
//#include "engine/talkbox.h"
#include "engine/game.h"

// Holy Holy - hold on to anyone

void main (void) {

#ifndef STANDALONE	
	// If bad checksum, this jumps to PRG 0 / CHR 0 (main menu)
	m113_handle_reset ();
	gs = COMM_GAME_SELECT; 
#else
	gs = 0x22; 
#endif	
	
	// Levesl are not sequenced in this version
	level = gs & 0xf; gs >>= 4;

	game_sonic = (gs == 0);
	game_espinete = (gs == 1);
	game_somari = (gs == 2);

	bank_bg (0);
	bank_spr (1);
			
	ntsc = ppu_system ();
	ticks = ntsc ? 60 : 50;
	halfticks = ticks >> 1;

	oam_size (0);
	pal_bright (0);

	scroll (0, SCROLL_Y);

	// CUSTOM {
	pal_cycle [0] = 0x31;
	pal_cycle [1] = 0x22;
	pal_cycle [2] = 0x12;

	// } END_OF_CUSTOM

	// Run the game here.
	while (1) {
		pal_spr (game_espinete ? palsstitle1 : palsstitle0);
		game_title ();
		pal_spr (game_espinete ? palss1 : palss0);

		plife = (game_somari & level == 2) ? 0 : LIFE_INI;
		pemmeralds = 0;

		hotspots_ini ();

		while (1) {
			
			game_init ();
			game_loop ();

			if (pkilled) {
				if (plife && game_sonic) {
					plife --; 
					delay (10);
				} else {
					if (!game_somari || level != 2) game_over ();
					break;
				}
			} else {
				game_ending ();
				break;
			}
		}
	}
}
