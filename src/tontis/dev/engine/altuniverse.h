// Alternate universe stuff. May come up handy for future games.

void altuniverse_init (void) {
	scrtctr = 0;
	altuniverse = 0;
}

void altuniverse_set (void) {
	if (rda) {
		pal_bg (palts_rendezvous_alt);
		pal_spr (palss_rendezvous_alt);
		m113_safe_change_chr_bank (CHR_ROM_ALT);
	} else {
		pal_bg (girl_palette [active_girl]);
		pal_spr (palss_rendezvous);
		m113_safe_change_chr_bank (CHR_ROM_MAIN);
	}
}

void altuniverse_do (void) {
	if (girlact) {
		if (scrtctr < 180) {
			scrtctr ++;
			if (scrtctr > 120) {
				rda = half_life;
				altuniverse_set ();
			}
			if (scrtctr == 180) {
				rda = altuniverse = 1;
				altuniverse_set (); 
			}
		}
	}

	if (altuniverse) scroll (rand8 () & 3, rand8 () & 3);
}
