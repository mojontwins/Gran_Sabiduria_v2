// Mojon Twins Multicart Menu System v0.1
// Copyleft 2016 by The Mojon Twins

// Menu text and mapping information

/*
PRG WHAT                                CHR WHAT                                CHR WHAT
0   Menu                                0   Menu                                8 Jet Puri extra
1   Monono / Jet Puri                   1   Monono / Jet Puri                   9 Cheril of the Bosque mapa 2 / Bits
2   Bosque                              2   Bosque                              A
3   Pantanow                            3   Pantanow                            B
4   Sonic Mal                           4   Sonic Mal                           C
5   The Nine                            5   The Nine                            D
6   Tonterías                           6   Tonterías                           E
7                                       7                                       F
*/

const unsigned char menu_mandanga [] = 
	// 24 chars
	"SGT.HELMET+S COMMANDOW! "	// PRG 3 CHR F GS 3
	"THE LEGEND OF ZELDA III "  // PRG 2 CHR 2 GS 0
	"SONIC THE HEDGEHOG      "  // PRG 4 CHR 4 GS 0
	"E.W. IN THE PANTANOW!   "  // PRG 3 CHR 3 GS 0
	"CHERIL - THE NINE       "  // PRG 5 CHR 5 GS 0
	"POTI POTI GRUFAS        "  // PRG 6 CHR 6 GS 0
	"JET PURI                "  // PRG 1 CHR 1 GS 1
	"NINJAJAR THE PROLOGUE   "  // PRG 2 CHR 2 GS 1

	"THE RENDEZVOUS          "  // PRG 6 CHR 6 GS 1
	"E.W. IN THE DESIERTOW!  "  // PRG 3 CHR 3 GS 1
	"LALA>S P=P=P=P          "	// PRG 1 CHR B GS 4
	"SONIC 2                 "  // PRG 4 CHR 4 GS 1
//	"THE LEGEND OF ZELDA IV  "  // PRG 2 CHR 9 GS 2
	"LOS AMORES DE BRUNILDA  "  // PRG 2 CHR 9 GS 2
	"E.W. IN THE AZOTEAW!    "	// PRG 3 CHR 3 GS 2
//	"MONONO NEW ADVENTURE    "	// PRG 1 CHR 1 GS 0
	"BABOON!                 "	// PRG 1 CHR 1 GS 0
	"LALA LAH                "	// PRG 1 CHR B GS 3

	"JOURNEY TO THE CENTRE..."  // PRG 6 CHR D GS 2
	"MONONA NINONA PANA      "  // PRG 1 CHR 1 GS 2
	"MEGA MEGHAN             "  // PRG 5 CHR C GS 2
	"SONIC 3 OF THE BOSQUE   "  // PRG 4 CHR 4 GS 2
	"ESPINETE                "  // PRG 4 CHR 4 GS 16
	"SOMARI KATAMARI         "  // PRG 4 CHR 4 GS 33
	"CHERIL BEGINS           "  // PRG 2 CHR 2 GS 4
	"ESPINETE STRIKES BACK   "  // PRG 4 CHR 4 GS 17

	"TRABAJO BASURA          "  // PRG 0 CHR 0 GS 16
//	"ZOMBIE CALAVERA PROLOGUE"  // PRG 7 CHR 7 GS 0
	"I.O.T.Z.M.              "  // PRG 7 CHR 7 GS 0
	"MEMORY SOMARI           "  // PRG 4 CHR 4 GS 34
	"ALIENS                  "  // PRG 6 CHR D GS 3
	"VESTA VAAL PROTOTYPE    "  // PRG 0 CHR E GS 17
	"NINJAJAR YOU ARE DRUNK! "  // PRG 2 CHR 2 GS 3
	"ESPINETE CONOCE A ANA   "  // PRG 4 CHR 4 GS 18
	"AN INCREDIBLE CUSTOMIZER"  // SPECIAL
;

const unsigned char menu_prg [] = {
	3, 2, 4, 3, 5, 6, 1, 2, 
	6, 3, 1, 4, 2, 3, 1, 1,
	6, 1, 5, 4, 4, 4, 2, 4,
	0, 7, 4, 6, 0, 2, 4, 0xff
};

const unsigned char menu_chr [] = {
	0xf, 2, 4, 3, 5, 6, 1, 2, 
	6, 3, 0xb, 4, 9, 3, 1, 0xb,
	0xd, 1, 0xc, 4, 4, 4, 2, 4,
	0, 7, 4, 0xd, 0xe, 2, 4, 0xff
};

const unsigned char menu_gs [] = {
	3, 0, 0, 0, 0, 0, 1, 1,
	1, 1, 4, 1, 2, 2, 0, 3,
	2, 2, 2, 2, 16, 33, 4, 17,
	0x10, 0, 34, 3, 0x11, 3, 18, 0xff
};
