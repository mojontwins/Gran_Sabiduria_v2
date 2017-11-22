// MT MK2 NES v0.6
// Copyleft 2016 by The Mojon Twins

// Enem. type linear

	if (!en_state [gpit] || half_life) {
#ifdef WALLS_STOP_ENEMIES		
		rdx = en_x [gpit];
#endif
		en_x [gpit] += en_mx [gpit];

#ifdef WALLS_STOP_ENEMIES		
		if (en_mx [gpit]) {
			cy1 = en_y [gpit] >> 4;
			cy2 = (en_y [gpit] + 15) >> 4;
			if (en_mx [gpit] < 0) {
				cx1 = cx2 = en_x [gpit] >> 4;
			} else {
				cx1 = cx2 = (en_x [gpit] + 15) >> 4;
			}
			cm_two_points ();
#ifdef ENEMS_COLLIDE_WITH_EVERYTHING
			if (at1 + at2)
#else
			if ((at1 & 8) || (at2 & 8))
#endif
			{
				en_collx = 1;
				en_x [gpit] = rdx;
				en_mx [gpit] = -en_mx [gpit];
			}
		}		
#endif

#ifdef WALLS_STOP_ENEMIES		
		rdy = en_y [gpit];
#endif
		en_y [gpit] += en_my [gpit];

#ifdef WALLS_STOP_ENEMIES
		if (en_my [gpit]) {
			cx1 = en_x [gpit] >> 4;
			cx2 = (en_x [gpit] + 15) >> 4;
			if (en_my [gpit] < 0) {
				cy1 = cy2 = en_y [gpit] >> 4;	
			} else  {
				cy1 = cy2 = (en_y [gpit] + 15) >> 4;
			}				
			cm_two_points ();
#ifdef ENEMS_COLLIDE_WITH_EVERYTHING
			if (at1 + at2)
#else
			if ((at1 & 8) || (at2 & 8))
#endif
			{
				en_colly = 1;
				en_y [gpit] = rdy;
				en_my [gpit] = -en_my [gpit];
			}				
		}
#endif

		if (en_x [gpit] == en_x1 [gpit] || en_x [gpit] == en_x2 [gpit]) en_mx [gpit] = -en_mx [gpit];
#ifdef PLAYER_STEPS_ON_ENEMIES
		if (en_my [gpit]) {
			if (en_y [gpit] <= en_y1 [gpit]) en_my [gpit] = ABS (en_my [gpit]);
			if (en_y [gpit] >= en_y2 [gpit]) en_my [gpit] = -ABS (en_my [gpit]);
		}
#else		
		if (en_y [gpit] == en_y1 [gpit] || en_y [gpit] == en_y2 [gpit]) en_my [gpit] = -en_my [gpit];		
#endif
	}

	en_facing [gpit] = ((en_mx [gpit] > 0 || en_my [gpit] > 0) ? 0 : 2);
	spr_id = en_s [gpit] + en_fr + en_facing [gpit];
	enems_spr ();
