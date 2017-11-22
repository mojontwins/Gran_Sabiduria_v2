@echo off
if [%1]==[justcompile] goto :justcompile

echo Generating Pals
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts.png out=work\palbg0.h label=palts0 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\palss.png out=work\palfg0.h label=palss0 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\tbpalts.png out=work\palbg1.h label=palts1 aseprite silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\tbpalss.png out=work\palfg1.h label=palss1 aseprite silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\vvpalts.png out=work\palbg2.h label=palts2 aseprite silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\vvpalss.png out=work\palfg2.h label=palss2 aseprite silent
copy /b work\palfg0.h + work\palbg0.h + work\palfg1.h + work\palbg1.h + work\palfg2.h + work\palbg2.h assets\palettes.h > nul

echo Exporting chr
cd ..\gfx

echo bank 0 (tileset)
..\..\utils\mkts.exe mode=scripted in=cut_tiles.spt out=tschr.bin silent
..\..\utils\fillto.exe tschr.bin 4096

echo bank 1 (spriteset)
..\..\utils\mkts.exe mode=scripted in=cut_sprites.spt out=sschr.bin silent
..\..\utils\fillto.exe sschr.bin 4096

echo Juntando pichas
copy /b tschr.bin + sschr.bin ..\dev\tileset1.chr > nul
del tschr.bin > nul
del sschr.bin > nul

echo bank 2 (tileset)
..\..\utils\mkts.exe mode=scripted in=cut_tiles2.spt out=tschr.bin silent
..\..\utils\fillto.exe tschr.bin 4096

echo bank 3 (spriteset)
..\..\utils\mkts.exe mode=scripted in=cut_sprites2.spt out=sschr.bin silent
..\..\utils\fillto.exe sschr.bin 4096

echo Juntando pichas
copy /b tschr.bin + sschr.bin ..\dev\tileset2.chr > nul
del tschr.bin > nul
del sschr.bin > nul

if [%1]==[mount2] goto :mount2
copy ..\dev\tileset1.chr ..\dev\tileset.chr > nul
goto :next
:mount2
copy ..\dev\tileset2.chr ..\dev\tileset.chr > nul
:next

echo Exporting enems
cd ..\enems
..\..\utils\eneexp3b.exe tb.ene ..\dev\assets\enems0.h 0 1
..\..\utils\eneexp3b.exe vv.ene ..\dev\assets\enems1.h 1 1

echo Making map 
cd ..\map
..\..\utils\rlebytemap.exe in=tb.map out=..\dev\assets\map0.h size=5,4 tlock=15 prefix=0 scrsizes fixmappy
..\..\utils\rlebytemap.exe in=vv.map out=..\dev\assets\map1.h size=20,1 prefix=1 scrsizes

echo Making texts
cd ..\texts
..\..\utils\texts2array.exe dummy.txt ..\dev\assets\texts.h texts0 24

cd ..\dev
:justcompile

cc65 -Oi game.c --add-source
ca65 crt0.s -o crt0.o
ca65 game.s
ld65 -v -C nes.cfg -o menu.nes crt0.o game.o runtime.lib -Ln labels.txt

del game.s
del game.o
del crt0.o
