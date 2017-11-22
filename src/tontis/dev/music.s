;this file for FamiTone2 library generated by text2data tool

music_music_data:
	.byte 5
	.word @instruments
	.word @samples-3
	.word @song0ch0,@song0ch1,@song0ch2,@song0ch3,@song0ch4,307,256
	.word @song1ch0,@song1ch1,@song1ch2,@song1ch3,@song1ch4,307,256
	.word @song2ch0,@song2ch1,@song2ch2,@song2ch3,@song2ch4,307,256
	.word @song3ch0,@song3ch1,@song3ch2,@song3ch3,@song3ch4,307,256
	.word @song4ch0,@song4ch1,@song4ch2,@song4ch3,@song4ch4,307,256

@instruments:
	.byte $30 ;instrument $00
	.word @env2,@env0,@env0
	.byte $00
	.byte $30 ;instrument $01
	.word @env1,@env0,@env11
	.byte $00
	.byte $30 ;instrument $06
	.word @env5,@env0,@env0
	.byte $00
	.byte $30 ;instrument $0b
	.word @env3,@env10,@env0
	.byte $00
	.byte $30 ;instrument $0c
	.word @env6,@env0,@env0
	.byte $00
	.byte $30 ;instrument $0d
	.word @env4,@env0,@env0
	.byte $00
	.byte $30 ;instrument $0e
	.word @env7,@env0,@env0
	.byte $00
	.byte $b0 ;instrument $0f
	.word @env8,@env0,@env0
	.byte $00
	.byte $30 ;instrument $10
	.word @env9,@env0,@env0
	.byte $00

@samples:
@env0:
	.byte $c0,$00,$00
@env1:
	.byte $c6,$c4,$c2,$c1,$00,$03
@env2:
	.byte $cc,$00,$00
@env3:
	.byte $cd,$cb,$c9,$c8,$c5,$c3,$c1,$c0,$00,$07
@env4:
	.byte $c7,$c2,$c0,$00,$02
@env5:
	.byte $ca,$c5,$c3,$c2,$c0,$00,$04
@env6:
	.byte $cc,$ca,$c8,$c6,$c4,$c3,$c2,$c1,$c0,$00,$08
@env7:
	.byte $ca,$c4,$c1,$c0,$00,$03
@env8:
	.byte $cf,$cc,$c9,$c7,$c5,$c4,$c3,$c3,$c2,$03,$c8,$c6,$c4,$c3,$c3,$c2
	.byte $02,$c1,$03,$c4,$c3,$c2,$04,$c1,$04,$c3,$c2,$c1,$07,$c0,$00,$1d
@env9:
	.byte $c6,$c5,$c4,$c3,$c3,$c2,$04,$c1,$c1,$c5,$c3,$c2,$c2,$c1,$07,$c2
	.byte $c2,$c1,$0a,$c2,$c1,$07,$c0,$00,$16
@env10:
	.byte $c7,$c3,$c0,$bd,$00,$02
@env11:
	.byte $c0,$0e,$bf,$be,$bd,$bc,$bd,$be,$bf,$c0,$00,$02


@song0ch0:
	.byte $fb,$0a
@song0ch0loop:
@ref0:
	.byte $9f
@ref1:
	.byte $9f
@ref2:
	.byte $9f
@ref3:
	.byte $9f
	.byte $fd
	.word @song0ch0loop

@song0ch1:
@song0ch1loop:
@ref4:
	.byte $9f
@ref5:
	.byte $9f
@ref6:
	.byte $9f
@ref7:
	.byte $9f
	.byte $fd
	.word @song0ch1loop

@song0ch2:
@song0ch2loop:
@ref8:
	.byte $80,$28,$00,$28,$00,$22,$00,$22,$00,$1e,$00,$1e,$00,$22,$00,$22
	.byte $00
@ref9:
	.byte $28,$00,$28,$00,$22,$00,$22,$00,$1e,$00,$1e,$00,$22,$00,$1e,$81
@ref10:
	.byte $28,$00,$28,$00,$22,$00,$22,$00,$1e,$00,$1e,$00,$22,$00,$22,$00
	.byte $ff,$10
	.word @ref9
	.byte $fd
	.word @song0ch2loop

@song0ch3:
@song0ch3loop:
@ref12:
	.byte $88,$21,$21,$86,$0a,$85,$88,$21,$21,$86,$0a,$85
	.byte $ff,$08
	.word @ref12
	.byte $ff,$08
	.word @ref12
@ref15:
	.byte $88,$21,$21,$86,$0a,$85,$88,$21,$21,$86,$0a,$0a,$0a,$0a
	.byte $fd
	.word @song0ch3loop

@song0ch4:
@song0ch4loop:
@ref16:
	.byte $9f
@ref17:
	.byte $9f
@ref18:
	.byte $9f
@ref19:
	.byte $9f
	.byte $fd
	.word @song0ch4loop


@song1ch0:
	.byte $fb,$0a
@song1ch0loop:
@ref20:
	.byte $9f
@ref21:
	.byte $9f
@ref22:
	.byte $9f
@ref23:
	.byte $9f
	.byte $fd
	.word @song1ch0loop

@song1ch1:
@song1ch1loop:
@ref24:
	.byte $8c,$33,$33,$33,$37,$3a,$8d
@ref25:
	.byte $37,$37,$37,$3b,$3d,$37,$36,$85
@ref26:
	.byte $33,$41,$33,$41,$32,$8d
@ref27:
	.byte $37,$37,$37,$3b,$32,$8d
	.byte $fd
	.word @song1ch1loop

@song1ch2:
@song1ch2loop:
@ref28:
	.byte $80,$1b,$23,$1b,$23,$11,$29,$29,$24,$81
@ref29:
	.byte $1f,$25,$1f,$25,$1f,$07,$07,$06,$81
@ref30:
	.byte $1b,$23,$1b,$23,$11,$29,$23,$1a,$81
@ref31:
	.byte $1f,$25,$1f,$11,$1a,$8d
	.byte $fd
	.word @song1ch2loop

@song1ch3:
@song1ch3loop:
@ref32:
	.byte $88,$21,$21,$86,$0f,$88,$21,$20,$8d
@ref33:
	.byte $21,$21,$86,$0f,$88,$21,$20,$8d
	.byte $ff,$06
	.word @ref33
	.byte $ff,$06
	.word @ref33
	.byte $fd
	.word @song1ch3loop

@song1ch4:
@song1ch4loop:
@ref36:
	.byte $9f
@ref37:
	.byte $9f
@ref38:
	.byte $9f
@ref39:
	.byte $9f
	.byte $fd
	.word @song1ch4loop


@song2ch0:
	.byte $fb,$06
@ref40:
	.byte $82,$28,$85,$26,$85,$24,$85,$22,$a5,$00,$bd
@song2ch0loop:
@ref41:
	.byte $81
	.byte $fd
	.word @song2ch0loop

@song2ch1:
@ref42:
	.byte $82,$32,$85,$30,$85,$2e,$85,$2c,$a5,$00,$bd
@song2ch1loop:
@ref43:
	.byte $81
	.byte $fd
	.word @song2ch1loop

@song2ch2:
@ref44:
	.byte $f9,$85
@song2ch2loop:
@ref45:
	.byte $81
	.byte $fd
	.word @song2ch2loop

@song2ch3:
@ref46:
	.byte $f9,$85
@song2ch3loop:
@ref47:
	.byte $81
	.byte $fd
	.word @song2ch3loop

@song2ch4:
@ref48:
	.byte $f9,$85
@song2ch4loop:
@ref49:
	.byte $81
	.byte $fd
	.word @song2ch4loop


@song3ch0:
	.byte $fb,$0c
@song3ch0loop:
@ref50:
	.byte $8e,$62,$85,$52,$58,$62,$6a,$6e,$85,$56,$5c,$66,$6e,$70,$8d,$6a
	.byte $8d
@ref51:
	.byte $62,$85,$52,$58,$62,$6a,$6e,$85,$69,$64,$68,$6a,$9d
@ref52:
	.byte $bf
@ref53:
	.byte $bf
@ref54:
	.byte $bf
@ref55:
	.byte $bf
@ref56:
	.byte $52,$85,$4b,$59,$56,$85,$59,$5d,$60,$8d,$59,$57,$53,$4e,$81
@ref57:
	.byte $4a,$85,$51,$59,$56,$85,$4f,$57,$52,$8d,$61,$63,$69,$62,$81
	.byte $ff,$0f
	.word @ref56
@ref59:
	.byte $4a,$85,$51,$59,$56,$85,$4f,$57,$52,$9d
@ref60:
	.byte $00,$bd
@ref61:
	.byte $bf
@ref62:
	.byte $60,$8d,$5c,$60,$5c,$58,$53,$59,$60,$85,$66,$85,$60,$85,$66,$85
@ref63:
	.byte $60,$8d,$5c,$60,$5c,$58,$53,$59,$60,$85,$6a,$85,$60,$85,$6a,$85
@ref64:
	.byte $62,$85,$52,$58,$62,$6a,$6e,$85,$56,$5c,$66,$6e,$70,$8d,$6a,$8d
	.byte $ff,$0d
	.word @ref51
	.byte $ff,$10
	.word @ref62
	.byte $ff,$10
	.word @ref63
	.byte $ff,$10
	.word @ref64
	.byte $ff,$0d
	.word @ref51
	.byte $ff,$0f
	.word @ref56
	.byte $ff,$0f
	.word @ref57
	.byte $ff,$0f
	.word @ref56
	.byte $ff,$0a
	.word @ref59
@ref74:
	.byte $00,$bd
@ref75:
	.byte $bf
	.byte $ff,$10
	.word @ref62
	.byte $ff,$10
	.word @ref63
	.byte $fd
	.word @song3ch0loop

@song3ch1:
@song3ch1loop:
@ref78:
	.byte $00,$90,$62,$85,$52,$58,$62,$6a,$6e,$85,$56,$5c,$66,$6e,$70,$8d
	.byte $6a,$8b
@ref79:
	.byte $81,$62,$85,$52,$58,$62,$6a,$6e,$85,$69,$64,$68,$6a,$9b
@ref80:
	.byte $bf
@ref81:
	.byte $bf
@ref82:
	.byte $bf
@ref83:
	.byte $bf
@ref84:
	.byte $81,$52,$85,$4b,$59,$56,$85,$59,$5d,$60,$8d,$59,$57,$53,$4e
@ref85:
	.byte $81,$4a,$85,$51,$59,$56,$85,$4f,$57,$52,$8d,$61,$63,$69,$62
	.byte $ff,$0f
	.word @ref84
@ref87:
	.byte $81,$4a,$85,$51,$59,$56,$85,$4f,$57,$52,$9b
@ref88:
	.byte $00,$bd
@ref89:
	.byte $bf
@ref90:
	.byte $81,$60,$8d,$5c,$60,$5c,$58,$53,$59,$60,$85,$66,$85,$60,$85,$66
	.byte $83
@ref91:
	.byte $81,$60,$8d,$5c,$60,$5c,$58,$53,$59,$60,$85,$6a,$85,$60,$85,$6a
	.byte $83
@ref92:
	.byte $00,$62,$85,$52,$58,$62,$6a,$6e,$85,$56,$5c,$66,$6e,$70,$8d,$6a
	.byte $8b
	.byte $ff,$0e
	.word @ref79
	.byte $ff,$11
	.word @ref90
	.byte $ff,$11
	.word @ref91
	.byte $ff,$11
	.word @ref92
	.byte $ff,$0e
	.word @ref79
	.byte $ff,$0f
	.word @ref84
	.byte $ff,$0f
	.word @ref85
	.byte $ff,$0f
	.word @ref84
	.byte $ff,$0b
	.word @ref87
@ref102:
	.byte $00,$bd
@ref103:
	.byte $bf
	.byte $ff,$11
	.word @ref90
	.byte $ff,$11
	.word @ref91
	.byte $fd
	.word @song3ch1loop

@song3ch2:
@song3ch2loop:
@ref106:
	.byte $00,$bd
@ref107:
	.byte $bf
@ref108:
	.byte $80,$22,$9d,$28,$89,$27,$22,$85,$18,$85
@ref109:
	.byte $22,$9d,$19,$1b,$18,$1a,$19,$15,$19,$20,$85
@ref110:
	.byte $22,$9d,$28,$89,$27,$22,$85,$18,$85
	.byte $ff,$0b
	.word @ref109
@ref112:
	.byte $10,$85,$1a,$85,$0e,$85,$1e,$85,$10,$85,$06,$85,$10,$85,$0e,$85
@ref113:
	.byte $02,$85,$08,$85,$06,$85,$14,$85,$0a,$8d,$19,$1b,$21,$28,$81
	.byte $ff,$10
	.word @ref112
@ref115:
	.byte $02,$85,$08,$85,$06,$85,$14,$85,$0a,$8d,$18,$8d
@ref116:
	.byte $00,$bd
@ref117:
	.byte $bf
@ref118:
	.byte $22,$85,$30,$85,$22,$85,$28,$85,$22,$85,$30,$85,$22,$85,$28,$85
	.byte $ff,$10
	.word @ref118
@ref120:
	.byte $1a,$85,$28,$85,$1e,$85,$26,$85,$28,$8d,$22,$8d
@ref121:
	.byte $1a,$85,$28,$85,$20,$85,$26,$85,$22,$9d
	.byte $ff,$10
	.word @ref118
	.byte $ff,$10
	.word @ref118
	.byte $ff,$0c
	.word @ref120
	.byte $ff,$0a
	.word @ref121
	.byte $ff,$10
	.word @ref112
	.byte $ff,$0f
	.word @ref113
	.byte $ff,$10
	.word @ref112
	.byte $ff,$0c
	.word @ref115
@ref130:
	.byte $00,$bd
@ref131:
	.byte $bf
@ref132:
	.byte $00,$bd
@ref133:
	.byte $bf
	.byte $fd
	.word @song3ch2loop

@song3ch3:
@song3ch3loop:
@ref134:
	.byte $00,$bd
@ref135:
	.byte $bf
@ref136:
	.byte $84,$1e,$85,$1e,$85,$1e,$85,$1e,$85,$1e,$85,$1e,$85,$1e,$85,$1e
	.byte $85
@ref137:
	.byte $1e,$85,$1e,$85,$1e,$85,$1e,$85,$1e,$85,$1e,$85,$1e,$85,$1e,$85
	.byte $ff,$10
	.word @ref137
	.byte $ff,$10
	.word @ref137
	.byte $ff,$10
	.word @ref137
	.byte $ff,$10
	.word @ref137
	.byte $ff,$10
	.word @ref137
	.byte $ff,$10
	.word @ref137
	.byte $ff,$10
	.word @ref137
	.byte $ff,$10
	.word @ref137
@ref146:
	.byte $88,$20,$85,$84,$1f,$88,$21,$20,$85,$84,$1e,$85,$88,$20,$85,$84
	.byte $1f,$88,$21,$20,$85,$84,$1e,$85
	.byte $ff,$10
	.word @ref146
	.byte $ff,$10
	.word @ref146
	.byte $ff,$10
	.word @ref146
	.byte $ff,$10
	.word @ref146
	.byte $ff,$10
	.word @ref146
	.byte $ff,$10
	.word @ref146
	.byte $ff,$10
	.word @ref146
	.byte $ff,$10
	.word @ref137
	.byte $ff,$10
	.word @ref137
	.byte $ff,$10
	.word @ref137
	.byte $ff,$10
	.word @ref137
	.byte $ff,$10
	.word @ref137
	.byte $ff,$10
	.word @ref137
@ref160:
	.byte $00,$bd
@ref161:
	.byte $bf
	.byte $fd
	.word @song3ch3loop

@song3ch4:
@song3ch4loop:
@ref162:
	.byte $bf
@ref163:
	.byte $bf
@ref164:
	.byte $bf
@ref165:
	.byte $bf
@ref166:
	.byte $bf
@ref167:
	.byte $bf
@ref168:
	.byte $bf
@ref169:
	.byte $bf
@ref170:
	.byte $bf
@ref171:
	.byte $bf
@ref172:
	.byte $bf
@ref173:
	.byte $bf
@ref174:
	.byte $bf
@ref175:
	.byte $bf
@ref176:
	.byte $bf
@ref177:
	.byte $bf
@ref178:
	.byte $bf
@ref179:
	.byte $bf
@ref180:
	.byte $bf
@ref181:
	.byte $bf
@ref182:
	.byte $bf
@ref183:
	.byte $bf
@ref184:
	.byte $bf
@ref185:
	.byte $bf
@ref186:
	.byte $bf
@ref187:
	.byte $bf
@ref188:
	.byte $bf
@ref189:
	.byte $bf
	.byte $fd
	.word @song3ch4loop


@song4ch0:
	.byte $fb,$06
@song4ch0loop:
@ref190:
	.byte $f9,$85
@ref191:
	.byte $f9,$85
@ref192:
	.byte $f9,$85
@ref193:
	.byte $f9,$85
@ref194:
	.byte $f9,$85
@ref195:
	.byte $f9,$85
@ref196:
	.byte $f9,$85
@ref197:
	.byte $f9,$85
@ref198:
	.byte $f9,$85
@ref199:
	.byte $f9,$85
@ref200:
	.byte $f9,$85
@ref201:
	.byte $f9,$85
	.byte $fd
	.word @song4ch0loop

@song4ch1:
@song4ch1loop:
@ref202:
	.byte $f9,$85
@ref203:
	.byte $f9,$85
@ref204:
	.byte $f9,$85
@ref205:
	.byte $f9,$85
@ref206:
	.byte $f9,$85
@ref207:
	.byte $f9,$85
@ref208:
	.byte $f9,$85
@ref209:
	.byte $f9,$85
@ref210:
	.byte $f9,$85
@ref211:
	.byte $f9,$85
@ref212:
	.byte $f9,$85
@ref213:
	.byte $f9,$85
	.byte $fd
	.word @song4ch1loop

@song4ch2:
@song4ch2loop:
@ref214:
	.byte $80,$52,$83,$00,$60,$8b,$00,$5c,$58,$56,$5c,$58,$83,$00,$52,$8b
	.byte $00,$4e,$85,$4a,$83,$00,$62,$89,$01,$60,$5c,$58,$60,$5c,$99,$00
	.byte $81
@ref215:
	.byte $52,$83,$00,$60,$89,$01,$5c,$58,$56,$5c,$58,$83,$00,$52,$89,$01
	.byte $4e,$83,$00,$4b,$01,$4b,$01,$4e,$00,$4f,$01,$52,$99,$00,$85
@ref216:
	.byte $52,$83,$00,$60,$8b,$00,$5c,$58,$56,$5c,$58,$83,$00,$52,$8b,$00
	.byte $4e,$85,$4a,$83,$00,$62,$89,$01,$60,$5c,$58,$60,$5c,$99,$00,$81
	.byte $ff,$1f
	.word @ref215
@ref218:
	.byte $56,$89,$01,$56,$83,$00,$5c,$83,$00,$59,$57,$59,$5d,$60,$89,$01
	.byte $62,$85,$01,$63,$60,$85,$5c,$85,$60,$9d
@ref219:
	.byte $56,$85,$01,$57,$58,$83,$00,$5c,$85,$58,$83,$00,$56,$83,$00,$52
	.byte $89,$01,$4a,$87,$00,$56,$87,$00,$5c,$83,$00,$60,$91,$62,$00,$60
	.byte $83,$00
	.byte $ff,$20
	.word @ref216
	.byte $ff,$1f
	.word @ref215
	.byte $ff,$20
	.word @ref216
	.byte $ff,$1f
	.word @ref215
@ref224:
	.byte $56,$87,$00,$53,$4e,$83,$00,$5c,$83,$00,$60,$87,$00,$5d,$58,$83
	.byte $00,$60,$83,$00,$62,$83,$00,$60,$83,$00,$5c,$83,$00,$62,$83,$00
	.byte $60,$99,$00,$81
@ref225:
	.byte $62,$00,$62,$62,$66,$00,$62,$00,$60,$83,$00,$58,$85,$56,$00,$56
	.byte $56,$58,$00,$5c,$00,$58,$83,$00,$53,$4f,$62,$95,$4b,$63,$60,$95
	.byte $48,$85
	.byte $fd
	.word @song4ch2loop

@song4ch3:
@song4ch3loop:
@ref226:
	.byte $88,$21,$8a,$16,$16,$86,$0f,$8a,$16,$16,$88,$21,$8a,$16,$16,$86
	.byte $0f,$8a,$16,$16,$88,$21,$8a,$16,$16,$86,$0f,$8a,$16,$16,$88,$21
	.byte $86,$0f,$0f,$8a,$16,$16,$88,$21,$8a,$16,$16,$86,$0f,$8a,$16,$16
	.byte $88,$21,$8a,$16,$16,$86,$0f,$8a,$16,$16,$88,$21,$8a,$16,$16,$86
	.byte $0f,$8a,$16,$16,$88,$21,$86,$0f,$0f,$0e,$0e
	.byte $ff,$2e
	.word @ref226
	.byte $ff,$2e
	.word @ref226
	.byte $ff,$2e
	.word @ref226
	.byte $ff,$2e
	.word @ref226
	.byte $ff,$2e
	.word @ref226
	.byte $ff,$2e
	.word @ref226
	.byte $ff,$2e
	.word @ref226
	.byte $ff,$2e
	.word @ref226
	.byte $ff,$2e
	.word @ref226
	.byte $ff,$2e
	.word @ref226
	.byte $ff,$2e
	.word @ref226
	.byte $fd
	.word @song4ch3loop

@song4ch4:
@song4ch4loop:
@ref238:
	.byte $f9,$85
@ref239:
	.byte $f9,$85
@ref240:
	.byte $f9,$85
@ref241:
	.byte $f9,$85
@ref242:
	.byte $f9,$85
@ref243:
	.byte $f9,$85
@ref244:
	.byte $f9,$85
@ref245:
	.byte $f9,$85
@ref246:
	.byte $f9,$85
@ref247:
	.byte $f9,$85
@ref248:
	.byte $f9,$85
@ref249:
	.byte $f9,$85
	.byte $fd
	.word @song4ch4loop
