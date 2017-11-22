@echo off
if [%1]==[justcompile] goto :justcompile

echo Generating Pals
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts.png out=work\palbg0.h label=palts0 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\palss.png out=work\palfg0.h label=palss0 silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\palss-ending-yun.png out=work\palfgend.h label=palssend silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\paltsend.png out=work\palbgend.h label=paltsend silent
..\..\utils\mkts.exe mode=pals pals=..\gfx\pallightning.png out=work\pallightning.h label=pal_lightning silent
copy /b work\palfg0.h + work\palbg0.h + work\palbgend.h + work\palfgend.h + work\pallightning.h assets\palettes.h > nul

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

rem echo bank 2 (tileset)
rem ..\..\utils\mkts.exe mode=scripted in=cut_tiles2.spt out=tschr.bin silent
rem ..\..\utils\fillto.exe tschr.bin 4096

rem echo bank 3 (spriteset)
rem ..\..\utils\mkts.exe mode=scripted in=cut_sprites2.spt out=sschr.bin silent
rem ..\..\utils\fillto.exe sschr.bin 4096

rem echo Juntando pichas
rem copy /b tschr.bin + sschr.bin ..\dev\tileset2.chr > nul
rem del tschr.bin > nul
rem del sschr.bin > nul

if [%1]==[mount2] goto :mount2
copy ..\dev\tileset1.chr ..\dev\tileset.chr > nul
goto :next
:mount2
copy ..\dev\tileset2.chr ..\dev\tileset.chr > nul
:next

echo Exporting enems
cd ..\enems
..\..\utils\eneexp3c.exe calavera.ene ..\dev\assets\enems0.h 0 1
..\..\utils\eneexp3c.exe yun.ene ..\dev\assets\enems1.h 1 1

echo Making map 
cd ..\map
..\..\utils\rle53map.exe in=calavera.map out=..\dev\assets\map0.h size=10,6 prefix=0 scrsizes fixmappy
..\..\utils\mapreordenator.exe in=yun.map out=yunr.map orderfile=orderfile.bin fixmappy
..\..\utils\rle53map.exe in=yunr.map out=..\dev\assets\map1.h size=10,6 prefix=1 scrsizes fixmappy

rem echo Making texts
rem cd ..\texts
rem ..\..\utils\texts2array.exe dialogue.txt ..\dev\assets\texts.h texts0 19

cd ..\dev
:justcompile

cc65 -Oi game.c --add-source
ca65 crt0.s -o crt0.o
ca65 game.s
ld65 -v -C nes.cfg -o zcp.nes crt0.o game.o runtime.lib -Ln labels.txt

del game.s
del game.o
del crt0.o
