@echo off
if [%1]==[justcompile] goto :justcompile

echo Generating Pals
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts0.png out=work\palbg0.h label=mypal_game_bg0 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts1.png out=work\palbg1.h label=mypal_game_bg1 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltspose.png out=work\palbg2.h label=mypal_game_bg2 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltslah.png out=work\palbg3.h label=mypal_game_bg3 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltspppp.png out=work\palbg4.h label=mypal_game_bg4 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltslahtitle.png out=work\palbg5.h label=mypal_game_bg5 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts2.png out=work\palbg6.h label=mypal_game_bg6 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltsmononatitle.png out=work\palbg7.h label=mypal_game_bg7 silent

..\..\utils\mkts.exe mode=pals pals=..\gfx\palss0.png out=work\palfg0.h label=mypal_game_fg0 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\palss1.png out=work\palfg1.h label=mypal_game_fg1 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\palsslah.png out=work\palfg3.h label=mypal_game_fg3 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\palsspppp.png out=work\palfg4.h label=mypal_game_fg4 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\palssppppending.png out=work\palfg5.h label=mypal_game_fg5 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\palss2.png out=work\palfg6.h label=mypal_game_fg6 silent
copy /b work\palbg0.h + work\palfg0.h + work\palbg1.h + work\palfg1.h + work\palbg2.h + work\palbg3.h + work\palfg3.h + work\palbg4.h + work\palfg4.h + work\palbg5.h + work\palfg5.h + work\palbg6.h + work\palfg6.h + work\palbg7.h assets\palettes.h > nul

echo Exporting chr
cd ..\gfx

echo bank 0 (tileset)
..\..\utils\mkts.exe mode=scripted in=cut_tiles.spt out=tschr.bin silent
..\..\utils\fillto.exe tschr.bin 4096

echo bank 1 (spriteset)
..\..\utils\mkts.exe mode=scripted in=cut_sprites.spt out=sschr.bin silent
..\..\utils\fillto.exe sschr.bin 4096

echo Juntando pichas
copy /b tschr.bin + sschr.bin ..\dev\tileset.chr > nul
del tschr.bin > nul

rem extra bank
echo bank2 (tileset)
..\..\utils\mkts.exe mode=scripted in=cut_tiles2.spt out=tschr.bin silent
..\..\utils\fillto.exe tschr.bin 4096

echo bank3 (tileset)
..\..\utils\mkts.exe mode=scripted in=cut_sprites2.spt out=sschr.bin silent
..\..\utils\fillto.exe sschr.bin 4096

echo Juntando pichas
copy /b tschr.bin + sschr.bin ..\dev\tileset2.chr > nul

del tschr.bin > nul
del sschr.bin > nul

rem lah bank
echo bank4 (tileset)
..\..\utils\mkts.exe mode=scripted in=cut_tiles_lah.spt out=tschr.bin 
..\..\utils\fillto.exe tschr.bin 4096

echo bank5 (spriteset)
..\..\utils\mkts.exe mode=scripted in=cut_sprites_lah.spt out=sschr.bin silent
..\..\utils\fillto.exe sschr.bin 4096

echo Juntando pichas
copy /b tschr.bin + sschr.bin ..\dev\tileset3.chr > nul

del tschr.bin > nul
del sschr.bin > nul

echo Exporting enems
cd ..\enems
..\..\utils\eneexp3b.exe level0.ene ..\dev\assets\enems0.h 0 1
..\..\utils\eneexp3b.exe level1.ene ..\dev\assets\enems1.h 1 1

echo Making map 
cd ..\map
rem ..\..\utils\rlebytemap.exe in=level0.map out=..\dev\assets\map0.h size=3,10 prefix=0 tlock=15 scrsizes
rem ..\..\utils\rlebytemap.exe in=level1.map out=..\dev\assets\map1.h size=6,3 prefix=1 tlock=15 scrsizes
..\..\utils\packmap2.exe level0.map ..\dev\assets\map0.h 3 10 15 0
..\..\utils\packmap2.exe level1.map ..\dev\assets\map1.h 6 3 15 1

cd ..\dev
:justcompile

cc65 -Oi game.c --add-source
ca65 crt0.s -o crt0.o
ca65 game.s
ld65 -v -C nes.cfg -o monono.nes crt0.o game.o runtime.lib -Ln labels.txt

del game.o
del crt0.o
