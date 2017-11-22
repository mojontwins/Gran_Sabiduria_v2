// MT MK2 NES v0.5
// Copyleft 2016 by The Mojon Twins

// Levelset

//const unsigned char * const l_ts_pals [] = { ts_calavera_pals, ts_calavera_pals, ts_calavera_pals };
//const unsigned char * const l_ts_tmaps [] = { ts_calavera_tmaps, ts_calavera_tmaps, ts_calavera_tmaps };
//const unsigned char * const l_behs [] = { behs0, behs0, behs0 };
const unsigned char l_scr_ini [] = { 4, 8, 50 };
const unsigned char * const * const l_map [] = { map_0, map_0, map_1 };
const unsigned char * const * const l_decos [] = { map_0_decos, map_0_decos, map_1_decos };
const unsigned char * const * const l_enems [] = { enems_0, enems_0, enems_1 } ;
const unsigned char * const l_hotspots [] = { hotspots_0, hotspots_0, hotspots_1 };
//const unsigned char * const l_locks [] = { 0, 0, 0 };
//const unsigned char * const l_pal_bgs [] = { palts0, palts0, palts0 };
//const unsigned char * const l_pal_fgs [] = { palss0, palss0, palss0 };
//const unsigned char * const t_pal_bgs [] = { palts0, palts0, palts0 };
//const unsigned char * const t_pal_fgs [] = { palss0, palss0, palss0 };
const unsigned char l_max_hotspots_type_1 [] = { MAX_HOTSPOTS_0_TYPE_1, MAX_HOTSPOTS_0_TYPE_1, 0 };
//const unsigned char l_map_w [] = { 10, 10, 10 };
const unsigned char l_plife [] = { 25, 25, 7 };
const unsigned char player_ini_x [] = { 6, 8, 7 };
const unsigned char player_ini_y [] = { 8, 6, 6 };
const unsigned char * const * const l_spr_enems [] = { spr_enems0, spr_enems0, spr_enems0 };
const unsigned char * const * const l_spr_player [] = { spr_player0, spr_player1, spr_player2 };
const unsigned char l_custom_on_off [] = { 0, 0, 0 };
const unsigned char l_body_count [] = { 
	0, 
	0,
	MAX_ENEMS_1_TYPE_10 + MAX_ENEMS_1_TYPE_60
};

// Constants made variable:
const unsigned char l_player_vy_jump_initial [] = { 48, 48, 56 };
