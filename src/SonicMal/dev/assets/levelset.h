// MT MK2 NES v0.8b
// Copyleft 2017 by The Mojon Twins

// Levelset
// Coment whichever doesn't apply

const unsigned char * const l_ts_pals [] = { ts0_pals, ts1_pals, ts2_pals };
const unsigned char * const l_ts_tmaps [] = { ts0_tmaps, ts1_tmaps, ts2_tmaps };
const unsigned char * const l_behs [] = { behs0, behs1, behs2 };
const unsigned char * const * const l_map [] = { map_0, map_1, map_2 };
//const unsigned char * const * const l_decos [] = { map_0_decos, map_1_decos, map_1_decos, map_1_decos };
#ifdef ENEMS_FORMAT_UNPACKED
const unsigned char * const l_enems [] = { enems_0, enems_1, enems_2 } ;
#else
const unsigned char * const * const l_enems [] =  { enems_0, enems_1, enems_2 } ;
#endif
const unsigned char * const l_hotspots [] = { hotspots_0, hotspots_1, hotspots_2 };
const unsigned char * const l_locks [] = { 0, 0, 0 };
const unsigned char * const l_pal_bgs [] = { 
	palts0, palts1, palts2,
	palts3, palts4, palts5,
	palts4, palts7, palts8
};
//const unsigned char * const l_pal_fgs [] = { palss0, palss0, palss0, palss0 };
// const unsigned char * const t_pal_bgs [] = { palts0, palts0 };
// const unsigned char * const t_pal_fgs [] = { palss0, palss0 };
const unsigned char l_max_hotspots_type_1 [] = { MAX_HOTSPOTS_0_TYPE_1, MAX_HOTSPOTS_1_TYPE_1, MAX_HOTSPOTS_2_TYPE_1 };
/*const unsigned char l_max_killable_enems [] = { 
	MAX_ENEMS_1_TYPE_10,
	MAX_ENEMS_1_TYPE_10 + MAX_ENEMS_1_TYPE_30,
	MAX_ENEMS_1_TYPE_10 + MAX_ENEMS_1_TYPE_30,
	MAX_ENEMS_3_TYPE_10 + MAX_ENEMS_3_TYPE_30,
};*/
const unsigned char l_map_w [] = { 10, 25, 1 };
// const unsigned char l_plife [] = { 5, 5, 5 };
const unsigned char l_scr_ini [] = { 0, 24, 19 };
const unsigned char player_ini_x [] = { 2, 14, 2 };
const unsigned char player_ini_y [] = { 2, 2, 2 };
const unsigned char level_musics [] = { 
	1, 2, 3,
	4, 4, 4,
	5, 5, 5 };

const unsigned char l_custom_on_off [] = {
	0,
	FLAG_BOTTOM_SPLIT,
	FLAG_BACKDROP_OVERLAYER | FLAG_MAP_ONE_COLUMN | FLAG_PAL_CYCLE,
};

// Special values selectors
const unsigned char * const * const l_spr_player [] = { spr_player_0, spr_player_1, spr_player_2 };
const unsigned char l_PLAYER_VX_MAX [] = { 64, 32, 32 };
const unsigned char l_PLAYER_AX [] = { 2, 4, 2 };
const unsigned char l_PLAYER_RX [] = { 4, 4, 2 };
const unsigned char * const pal_ts_title [] = { paltstitle0, paltstitle1, palts7 };
