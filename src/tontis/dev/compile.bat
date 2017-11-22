@echo off
if [%1]==[justcompile] goto :justcompile

echo Generating Pals
..\..\utils\mkts.exe mode=pals pals=..\gfx\potipotipalts.png out=work\palbg0.h label=palts_potipoti silent aseprite 
..\..\utils\mkts.exe mode=pals pals=..\gfx\potipotipalss.png out=work\palfg0.h label=palss_potipoti silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\rendezpalts.png out=work\palbg1.h label=palts_rendezvous_0 silent aseprite 
..\..\utils\mkts.exe mode=pals pals=..\gfx\rendezpalts2.png out=work\palbg2.h label=palts_rendezvous_1 silent aseprite 
..\..\utils\mkts.exe mode=pals pals=..\gfx\rendezpaltst.png out=work\palbg3.h label=palts_rendezvous_t silent aseprite 
..\..\utils\mkts.exe mode=pals pals=..\gfx\rendezpalss.png out=work\palfg1.h label=palss_rendezvous silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\rendezalterpalts.png out=work\palbgalt.h label=palts_rendezvous_alt silent aseprite 
..\..\utils\mkts.exe mode=pals pals=..\gfx\rendezalterpalss.png out=work\palfgalt.h label=palss_rendezvous_alt silent aseprite 
..\..\utils\mkts.exe mode=pals pals=..\gfx\rendezendingpalss.png out=work\palfgendingalt.h label=palss_rendezvous_ending_alt silent aseprite 
..\..\utils\mkts.exe mode=pals pals=..\gfx\napiapalts.png out=work\palbg4.h label=palts_napia silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\napiapalss.png out=work\palfg4.h label=palss_napia silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\alienpalts.png out=work\palbg5.h label=palts_alien silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\alienpalss.png out=work\palfg5.h label=palss_alien silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palreds.png out=work\palreds.h label=pal_reds silent aseprite

copy /b work\palfg0.h + work\palbg0.h + work\palfg1.h + work\palbg1.h + work\palbg2.h + work\palbg3.h + work\palbg4.h + work\palfg4.h + work\palbg5.h + work\palfg5.h + work\palbgalt.h + work\palfgalt.h + work\palreds.h + work\palfgendingalt.h assets\palettes.h > nul

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

echo bank 4 (tileset)
..\..\utils\mkts.exe mode=scripted in=cut_tiles3.spt out=tschr.bin silent
..\..\utils\fillto.exe tschr.bin 4096

echo bank 5 (spriteset)
..\..\utils\mkts.exe mode=scripted in=cut_sprites3.spt out=sschr.bin silent
..\..\utils\fillto.exe sschr.bin 4096

echo Juntando pichas
copy /b tschr.bin + sschr.bin ..\dev\tileset3.chr > nul
del tschr.bin > nul
del sschr.bin > nul

if [%1]==[mount2] goto :bank2
copy ..\dev\tileset1.chr ..\dev\tileset.chr
goto :next
:bank2
copy ..\dev\tileset3.chr ..\dev\tileset.chr
:next

echo Exporting enems
cd ..\enems
..\..\utils\eneexp3b.exe potipoti.ene ..\dev\assets\enems_potipoti.h potipoti 1
..\..\utils\eneexp3b.exe rendezvous.ene ..\dev\assets\enems_rendezvous.h rendezvous 1
..\..\utils\eneexp3b.exe napia.ene ..\dev\assets\enems_napia.h napia 1

echo Making map 
cd ..\map
..\..\utils\rlebytemap.exe in=potipoti.map out=..\dev\assets\map_potipoti.h size=1,1 prefix=potipoti scrsizes fixmappy
..\..\utils\rlebytemap.exe in=rendezvous.map out=..\dev\assets\map_rendezvous.h size=8,6 prefix=rendezvous scrsizes fixmappy
..\..\utils\rlebytemap.exe in=napia.map out=..\dev\assets\map_napia.h size=4,9 tlock=15 prefix=napia scrsizes fixmappy

rem ..\..\utils\packmap2.exe level0.map ..\dev\assets\map0.h 5 5 15 0

echo Making texts
cd ..\texts
..\..\utils\texts2array.exe rendezvous.txt ..\dev\assets\texts.h texts_rendezvous 24

cd ..\dev
:justcompile

cc65 -Oi game.c --add-source
ca65 crt0.s -o crt0.o
ca65 game.s
ld65 -v -C nes.cfg -o tontis.nes crt0.o game.o runtime.lib -Ln labels.txt

del game.s
del game.o
del crt0.o
