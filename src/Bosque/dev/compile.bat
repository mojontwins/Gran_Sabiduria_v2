@echo off
if [%1]==[justcompile] goto :justcompile

echo Generating Pals
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltsb.png out=work\palbg0.h label=mypal_game_bg0 silent 
..\..\utils\mkts.exe mode=pals pals=..\gfx\palssb.png out=work\palfg0.h label=mypal_game_fg0 silent 
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltsb2.png out=work\palbg1.h label=mypal_game_bg1 silent 
..\..\utils\mkts.exe mode=pals pals=..\gfx\palssb2.png out=work\palfg1.h label=mypal_game_fg1 silent 
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltsb3.png out=work\palbg2.h label=mypal_game_bg2 silent 
..\..\utils\mkts.exe mode=pals pals=..\gfx\palssb3.png out=work\palfg2.h label=mypal_game_fg2 silent 
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltsb4.png out=work\palbg3.h label=mypal_game_bg3 silent 
..\..\utils\mkts.exe mode=pals pals=..\gfx\palssb4.png out=work\palfg3.h label=mypal_game_fg3 silent 
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltsending.png out=work\palbgending0.h label=mypal_game_bg_ending0 silent 
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltstitle.png out=work\palbgtitle0.h label=mypal_game_bg_title0 silent 
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltsending2.png out=work\palbgending1.h label=mypal_game_bg_ending1 silent 
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltstitle2.png out=work\palbgtitle1.h label=mypal_game_bg_title1 silent 
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltsending3.png out=work\palbgending2.h label=mypal_game_bg_ending2 silent 
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltstitle3.png out=work\palbgtitle2.h label=mypal_game_bg_title2 silent 
copy /b work\palbg0.h + work\palfg0.h + work\palbg1.h + work\palfg1.h + work\palbg2.h + work\palfg2.h + work\palbg3.h + work\palfg3.h + work\palbgending0.h + work\palbgtitle0.h + work\palbgending1.h + work\palbgtitle1.h + work\palbgending2.h + work\palbgtitle2.h assets\palettes.h > nul

echo Exporting chr
cd ..\gfx

echo bank 0 (tileset)
..\..\utils\mkts.exe mode=scripted in=cut_tiles.spt out=tschr.bin silent
..\..\utils\fillto.exe tschr.bin 4096

echo bank 1 (spriteset)
..\..\utils\mkts.exe mode=scripted in=cut_sprites.spt out=sschr.bin silent
..\..\utils\fillto.exe sschr.bin 4096

echo Juntando pichas
copy /b tschr.bin + sschr.bin ..\dev\tsbosque1.chr > nul
del tschr.bin > nul
del sschr.bin > nul

echo bank 2 (tileset)
..\..\utils\mkts.exe mode=scripted in=cut_tiles2.spt out=tschr.bin silent
..\..\utils\fillto.exe tschr.bin 4096

echo bank 3 (spriteset)
..\..\utils\mkts.exe mode=scripted in=cut_sprites2.spt out=sschr.bin silent
..\..\utils\fillto.exe sschr.bin 4096

echo Juntando pichas
copy /b tschr.bin + sschr.bin ..\dev\tsbosque2.chr > nul
del tschr.bin > nul
del sschr.bin > nul

cd ..\dev
if [%1]==[mount2] goto :bank2

copy tsbosque1.chr tileset.chr
goto :donebanks

:bank2
copy tsbosque2.chr tileset.chr

:donebanks

echo Exporting enems
cd ..\enems
..\..\utils\eneexp3b.exe level0.ene ..\dev\assets\enems0.h 0 1
..\..\utils\eneexp3b.exe level1.ene ..\dev\assets\enems1.h 1 1

echo Making map 
cd ..\map
rem ..\..\utils\rlebytemap.exe in=level0.map out=..\dev\assets\map0rle.h size=5,5 prefix=0 tlock=15 scrsizes
rem ..\..\utils\rlebytemap.exe in=level1.map out=..\dev\assets\map1rle.h size=5,7 prefix=1 tlock=15 scrsizes
..\..\utils\packmap2.exe level0.map ..\dev\assets\map0.h 5 5 15 0
..\..\utils\packmap2.exe level1.map ..\dev\assets\map1.h 5 7 15 1

echo Making texts
cd ..\texts
..\..\utils\texts2array.exe dialogue.txt ..\dev\assets\texts.h texts0 19

cd ..\dev
:justcompile

cc65 -Oi game.c --add-source
ca65 crt0.s -o crt0.o
ca65 game.s
ld65 -v -C nes.cfg -o bosque.nes crt0.o game.o runtime.lib -Ln labels.txt

del game.s
del game.o
del crt0.o
