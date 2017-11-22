@echo off
if [%1]==[justcompile] goto :justcompile

echo Generating Pals
..\..\utils\mkts.exe mode=pals pals=..\gfx\paleta-tiles.png out=work\palbg0.h label=mypal_game_bg0 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\paleta-sprites.png out=work\palfg0.h label=mypal_game_fg0 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palredbg.png out=work\palreds.h label=mypal_game_reds silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltsmeghan.png out=work\palbg2.h label=mypal_game_bg2 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palssmeghan.png out=work\palfg2.h label=mypal_game_fg2 silent aseprite
copy /b work\palbg0.h + work\palfg0.h + work\palbg2.h + work\palfg2.h + work\palreds.h assets\palettes.h > nul

echo Exporting chr
cd ..\gfx

echo bank 0 (tileset)
..\..\utils\mkts.exe mode=scripted in=cut_tiles.spt out=tschr.bin silent
..\..\utils\fillto.exe tschr.bin 4096

echo bank 1 (spriteeset)
..\..\utils\mkts.exe mode=scripted in=cut_sprites.spt out=sschr.bin silent
..\..\utils\fillto.exe sschr.bin 4096

echo Juntando pichas
copy /b tschr.bin + sschr.bin ..\dev\tileset1.chr > nul
del tschr.bin > nul
del sschr.bin > nul

echo bank 2 (tileset)
..\..\utils\mkts.exe mode=scripted in=cut_tiles2.spt out=tschr.bin silent
..\..\utils\fillto.exe tschr.bin 4096

echo bank 3 (spriteeset)
..\..\utils\mkts.exe mode=scripted in=cut_sprites2.spt out=sschr.bin silent
..\..\utils\fillto.exe sschr.bin 4096

echo Juntando pichas
copy /b tschr.bin + sschr.bin ..\dev\tileset2.chr > nul
del tschr.bin > nul
del sschr.bin > nul

if [%1]==[mount2] goto :mount2

copy ..\dev\tileset1.chr ..\dev\tileset.chr
goto :next

:mount2
copy ..\dev\tileset2.chr ..\dev\tileset.chr

:next

echo Exporting enems
cd ..\enems
..\..\utils\enexpmin.exe in=enems.ene out=..\dev\assets\enems.h prefix=0
..\..\utils\eneexp3b.exe meghan.ene ..\dev\assets\enems_meghan.h 2 0

echo Making map 
cd ..\map
..\..\utils\rlebytemap.exe in=mapa.map out=..\dev\assets\map.h size=5,5 prefix=0 fixmappy scrsizes
..\..\utils\rlebytemap.exe in=meghan.map out=..\dev\assets\map_meghan.h size=4,12 prefix=2 tlock=15 fixmappy scrsizes

cd ..\dev
:justcompile

cc65 -Oi nine.c --add-source
ca65 crt0.s -o crt0.o
ca65 nine.s
ld65 -v -C nes.cfg -o nine.nes crt0.o nine.o runtime.lib -Ln labels.txt

del nine.s
del nine.o
del crt0.o
