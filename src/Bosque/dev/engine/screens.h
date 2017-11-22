// MT MK2 NES v0.3
// Copyleft 2016 by The Mojon Twins

// Code for fixed screens

void enter_screen (const unsigned char *pal, void (*func) (void)) {
	scroll (0, 0);
	
	cls ();
	reset_attributes ();
	rda = 0;
	(*func) ();
	if (rda) show_attributes ();
	
	pal_bg (pal);
	ppu_on_all ();
	fade_in ();
}

void exit_cleanly (void) {
	//set_vram_update (0);
	music_stop ();
	fade_out (); 
	oam_hide_rest (0);
	ppu_off ();	
}

void wait_time_or_input (void) {
	rda = (pad_poll (0) != 0);
	while (game_time) { 
		ticker ++; if (ticker == 50) {
			ticker = 0;
			game_time --;
		}

		if (pad_poll (0)) {
			if (!rda) break;
		} else {
			rda = 0;
		}

		ppu_wait_frame ();
	}
}

void do_screen (unsigned char seconds) {
	game_time = seconds; ticker = 0;
	wait_time_or_input ();
	exit_cleanly ();
}

void screen_title (void) {
	if (drunk_mode) {
		/*p_s (9, 14, "GOSH, NINJAJAR%%YOU ARE DRUNK!");
		p_s (10, 24, "PRESS START!");
		*/
		p_s (9, 14, "GOSH, NINJAJAR%%YOU ARE DRUNK!%%%%%%%%%% PRESS START!");
	} else {
		vram_adr (NAMETABLE_A);
		vram_unrle (title_rle [level]);

		switch (level) {
			case 1:
				p_s (17, 14, "NINJAJAR!% PROLOGUE");
				break;
			case 4:
				p_s (5, 19, "      PRESS START%%%%%@ 2016 THE MOJON TWINS%%  DEDICATED TO: ^NES");
				break;
		}
	}
}

void screen_game_over (void) {
	p_s (11, 14, "GAME OVER!"); rda = 1;
}

void screen_game_ending (void) {
	vram_adr (NAMETABLE_A);
	vram_unrle (bosque_ending_rle);

	/*
	p_s (5, 16, "AND THIS IS HOW CHERIL");
	p_s (5, 18, "GOT OUT OF THE BOSQUE.");
	p_s (4, 20, "NOW HER ADVENTURE BEGINS");
	p_s (4, 22, "SEE YOU SOON, CATUNAMBU!");
	*/
	if (level == 4) {
		p_s (5, 16, "ALE, BONICA, QUE VERAS%%LA DE COSAS CHULAS QUE%%TE ESPERAN A PARTIR DE%%AHORA, ^NES! MUACS!");
		oam_hide_rest (oam_meta_spr (88, 47, 0, ssdress_00));
	} else {
		p_s (4, 16, " AND THIS IS HOW CHERIL%% GOT OUT OF THE BOSQUE.%%NOW HER ADVENTURE BEGINS%%SEE YOU SOON, CATUNAMBU!");
	}	
}
