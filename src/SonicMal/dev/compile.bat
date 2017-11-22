@echo off
if [%1]==[justcompile] goto :justcompile

echo Generating Pals
..\..\utils\mkts.exe mode=pals pals=..\gfx\son_palts0.png out=work\palbg0.h label=palts0 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\son_palts1.png out=work\palbg1.h label=palts1 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\son_palts2.png out=work\palbg2.h label=palts2 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\esp_palts0.png out=work\palbg3.h label=palts3 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\esp_palts1.png out=work\palbg4.h label=palts4 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\esp_palts2.png out=work\palbg5.h label=palts5 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\som_palts1.png out=work\palbg7.h label=palts7 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\som_palts2.png out=work\palbg8.h label=palts8 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\son_paltstitle.png out=work\palbgtitle0.h label=paltstitle0 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\esp_paltstitle.png out=work\palbgtitle1.h label=paltstitle1 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\son_palss.png out=work\palfg0.h label=palss0 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\esp_palss.png out=work\palfg1.h label=palss1 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\son_palsstitle.png out=work\palfgtitle0.h label=palsstitle0 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\esp_palsstitle.png out=work\palfgtitle1.h label=palsstitle1 silent aseprite

copy /b work\palbg0.h + work\palbg1.h + work\palbg2.h + work\palbg3.h + work\palbg4.h + work\palbg5.h + work\palbg7.h + work\palbg8.h + work\palbgtitle0.h + work\palbgtitle1.h + work\palbgtitle2.h + work\palfg0.h + work\palfg1.h + work\palfgtitle0.h + work\palfgtitle1.h assets\palettes.h > nul

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
del sschr.bin > nul

echo Exporting enems
cd ..\enems
..\..\utils\eneexp3c.exe level0.ene ..\dev\assets\enems0.h 0 1
..\..\utils\eneexp3c.exe level1.ene ..\dev\assets\enems1.h 1 1
..\..\utils\eneexp3c.exe level2.ene ..\dev\assets\enems2.h 2 1
rem ..\..\utils\eneexp3c.exe level3.ene ..\dev\assets\enems3.h 3 1

echo Making map 
cd ..\map
..\..\utils\rle44map.exe in=level0.map out=..\dev\assets\map0.h size=10,3 prefix=0 nodecos scrsizes fixmappy
..\..\utils\rle44map.exe in=level1.map out=..\dev\assets\map1.h size=25,1 prefix=1 nodecos scrsizes fixmappy
..\..\utils\rle44map.exe in=level2.map out=..\dev\assets\map2.h size=1,20 prefix=2 nodecos scrsizes fixmappy
rem ..\..\utils\rle44map.exe in=level3.map out=..\dev\assets\map3.h size=4,5 prefix=3 nodecos scrsizes

echo Making texts
cd ..\dev
rem cd ..\texts
rem ..\..\utils\texts2array.exe dialogue.txt ..\dev\assets\texts.h texts0 19
rem ..\..\utils\diacom.exe ..\texts\dialogue-a.txt assets\dialogue.h 21

cd ..\dev

rem ..\..\utils\msc4nes.exe in=..\script\sonicbad.spt out=..\dev\engine\mscnes.h maxpants=30 mapadjust=1

:justcompile

cc65 -Oi game.c --add-source
ca65 crt0.s -o crt0.o
ca65 game.s
ld65 -v -C nes.cfg -o sonic.nes crt0.o game.o runtime.lib -Ln labels.txt

del game.s
del game.o
del crt0.o
