// Cheril: the Nine
// Copyleft 2016 by The Mojon Twins

// Flower

// They call me the Wild Rose
// But my name was Eliza Day.

void flower_ini (void) {
	flwy = 240;
}

// Why they call me it I do not know
// For my name was Eliza Day

void flower_create (void) {
	do {
		rdx = rand8 () & 0xf;
		rdy = rand8 () & 0xf;
	} while (rdy > 11 || scr_attr [rdx + (rdy << 4)]);
	flwx = rdx << 4; flwy = rdy << 4;
}

void bullets_draw_gauge_offline (void) {
	vram_adr (0x2000 + 96 + 9);
	vram_fill (63, 15);
}

void bullets_full_gauge (void) {
	pgauge = 30;

	gp_addr = (0x2000 + 96 + 9);
	*ul ++ = MSB (gp_addr) | NT_UPD_HORZ;
	*ul ++ = LSB (gp_addr);
	*ul ++ = 15;
	gpit = 15; while (gpit --) *ul ++ = 63;
}

void bullets_deplete (void) {
	pgauge --;
	rda = (pgauge + 1) >> 1;
	if (rda < 15) {
		gp_addr = (0x2000 + 96 + 9 + rda);
		update_list_write (0);
	}
	if (!pgauge) flower_create ();
}

void flower_do (void) {
	if (flwy != 240) {
		oam_index = oam_meta_spr (
			flwx + jitter [frame_counter & 0xf], flwy + jitter [15 - (frame_counter & 0xf)] + SPRITE_ADJUST,
			oam_index,
			spr_it_01);

		if (collide (prx, pry, flwx, flwy)) {
			flwy = 240;
			bullets_full_gauge ();
			sfx_play (SFX_GET_ITEM, SC_LEVEL);
		}
	}
}

/*
	Flower, seize the hour I did
	I wait
	Waiting, waiting for your wake
	I'll wait . . .
*/
