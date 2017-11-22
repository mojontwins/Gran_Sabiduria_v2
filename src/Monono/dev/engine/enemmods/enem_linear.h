 if (!en_state [gpit] || half_life) {
#ifdef LINEAR_COLLIDES		
		rdx = _en_x;
#endif
		_en_x += _en_mx;

#ifdef LINEAR_COLLIDES		
		if (_en_mx) {
			cy1 = _en_y >> 4; 
			cy2 = (_en_y + 15) >> 4;
			if (_en_mx < 0) {
				cx1 = cx2 = _en_x >> 4;
			} else {
				cx1 = cx2 = (_en_x + 15) >> 4;
			}
			cm_two_points ();

			if (at1 + at2) {
				//en_collx = 1;
				_en_x = rdx;
				_en_mx = -_en_mx;
			}
		}		
#endif

#ifdef LINEAR_COLLIDES		
		rdy = _en_y;
#endif
		_en_y += _en_my;

#ifdef LINEAR_COLLIDES
		if (_en_my) {
			cx1 = _en_x >> 4;
			cx2 = (_en_x + 15) >> 4;
			if (_en_my < 0) {
				cy1 = cy2 = _en_y >> 4;	
			} else  {
				cy1 = cy2 = (_en_y + 15) >> 4;
			}				
			cm_two_points ();

			if (at1 + at2) {
				//en_colly = 1;
				_en_y = rdy;
				_en_my = -_en_my;
			}				
		}
#endif

		if (_en_x == _en_x1 || _en_x == _en_x2) _en_mx = -_en_mx;	
		if (_en_y == _en_y1 || _en_y == _en_y2) _en_my = -_en_my;		
	}

	spr_id = en_s [gpit] + en_fr + (_en_mx ? ((_en_mx > 0) ? 0 : 2) : ((_en_my > 0) ? 0 : 2));
	enems_spr ();
