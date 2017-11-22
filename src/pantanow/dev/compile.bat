@echo off
if [%1]==[justcompile] goto :justcompile

echo Generating Pals
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts_pantanow.png out=work\palbg0.h label=mypal_game_bg0 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts_desiertow.png out=work\palbg1.h label=mypal_game_bg1 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts_azoteaw.png out=work\palbg2.h label=mypal_game_bg2 silent aseprite

..\..\utils\mkts.exe mode=pals pals=..\gfx\palts_comandow1.png out=work\palbgc0.h label=mypal_game_bgc0 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts_comandow2.png out=work\palbgc1.h label=mypal_game_bgc1 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts_comandow3.png out=work\palbgc2.h label=mypal_game_bgc2 silent aseprite

..\..\utils\mkts.exe mode=pals pals=..\gfx\palss.png out=work\palfg0.h label=mypal_game_fg0 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palsshelmet.png out=work\palfg1.h label=mypal_game_fg1 silent aseprite
copy /b work\palbg0.h + work\palbg1.h + work\palbg2.h + work\palbgc0.h + work\palbgc1.h + work\palbgc2.h + work\palfg0.h + work\palfg1.h assets\palettes.h > nul

echo Exporting chr
cd ..\gfx

echo bank 0 (tileset)
..\..\utils\mkts.exe mode=scripted in=cut_tiles.spt out=tschr.bin silent
..\..\utils\fillto.exe tschr.bin 4096

echo bank 1 (spriteset)
..\..\utils\mkts.exe mode=scripted in=cut_sprites.spt out=sschr.bin silent
..\..\utils\fillto.exe sschr.bin 4096

echo bank 2 (tileset)
..\..\utils\mkts.exe mode=scripted in=cut_tiles2.spt out=tschr2.bin silent
..\..\utils\fillto.exe tschr2.bin 4096

echo bank 3 (spriteset2)
..\..\utils\mkts.exe mode=scripted in=cut_sprites2.spt out=sschr2.bin silent
..\..\utils\fillto.exe sschr2.bin 4096

echo Juntando pichas
copy /b tschr.bin + sschr.bin ..\dev\tileset1.chr > nul
copy /b tschr2.bin + sschr2.bin ..\dev\tileset2.chr > nul
del tschr.bin > nul
del sschr.bin > nul
del tschr2.bin > nul
del sschr2.bin > nul

cd ..\dev
if [%1]==[mount2] goto :mount2
copy tileset1.chr tileset.chr > nul
goto :goon
:mount2
copy tileset2.chr tileset.chr > nul
:goon

echo Exporting enems

echo Making map 
cd ..\map
..\..\utils\vertmapcnv.exe pantanow.map ..\dev\map0.s map0 -1
..\..\utils\vertmapcnv.exe desiertow.map ..\dev\map1.s map1 -1
..\..\utils\vertmapcnv.exe azoteaw.map ..\dev\map2.s map2 -1

cd ..\dev
:justcompile

cc65 -Oi game.c --add-source
ca65 crt0-pantanow.s -o crt0.o
ca65 map0.s
ca65 map1.s
ca65 map2.s
ca65 game.s
ld65 -v -C nes.cfg -o pantanow.nes crt0.o game.o map0.o map1.o map2.o runtime.lib -Ln labels.txt

del *.o > nul
del game.s
