@echo off

echo Remember: bosque menu monono pantanow sonicmal thenine tontis zcp assemble

if [%1]==[bosque] goto :bosque
if [%1]==[menu] goto :menu
if [%1]==[monono] goto :monono
if [%1]==[pantanow] goto :pantanow
if [%1]==[sonicmal] goto :sonicmal
if [%1]==[thenine] goto :thenine
if [%1]==[tontis] goto :tontis
if [%1]==[zcp] goto :zcp
if [%1]==[assemble] goto :assemble

:menu
echo Building Menu
cd src\Menu\dev\
call compile.bat > nul
copy menu.nes ..\..\work\rom0.nes > nul
copy tileset1.chr ..\..\work\chr0.bin > nul
copy tileset2.chr ..\..\work\chrE.bin > nul
cd ..\..\..\
if [%1]==[menu] goto :assemble

:monono
echo Building Monono
cd src\Monono\dev\
call compile.bat > nul
copy monono.nes ..\..\work\rom1.nes > nul
copy tileset.chr ..\..\work\chr1.bin > nul
copy tileset2.chr ..\..\work\chr8.bin > nul
copy tileset3.chr ..\..\work\chrB.bin > nul
cd ..\..\..\
if [%1]==[monono] goto :assemble

:bosque
echo Building Bosque
cd src\Bosque\dev\
call compile.bat > nul
copy bosque.nes ..\..\work\rom2.nes > nul
copy tileset.chr ..\..\work\chr2.bin > nul
copy tsbosque2.chr ..\..\work\chr9.bin > nul
cd ..\..\..\
if [%1]==[bosque] goto :assemble

:pantanow
echo Building Pantanow
cd src\pantanow\dev\
call compile.bat > nul
copy pantanow.nes ..\..\work\rom3.nes > nul
copy tileset1.chr ..\..\work\chr3.bin > nul
copy tileset2.chr ..\..\work\chrF.bin > nul
cd ..\..\..\
if [%1]==[pantanow] goto :assemble

:sonicmal
echo Building Sonic Mal
cd src\SonicMal\dev\
call compile.bat > nul
copy sonic.nes ..\..\work\rom4.nes > nul
copy tileset.chr ..\..\work\chr4.bin > nul
cd ..\..\..\
if [%1]==[sonicmal] goto :assemble

:thenine
echo Building The Nine
cd "src\the nine\dev\"
call compile.bat > nul
copy nine.nes ..\..\work\rom5.nes > nul
copy tileset1.chr ..\..\work\chr5.bin > nul
copy tileset2.chr ..\..\work\chrC.bin > nul
cd ..\..\..\
if [%1]==[thenine] goto :assemble

:tontis
echo Building Tontis
cd src\tontis\dev\
call compile.bat > nul
copy tontis.nes ..\..\work\rom6.nes > nul
copy tileset.chr ..\..\work\chr6.bin > nul
copy tileset2.chr ..\..\work\chrA.bin > nul
copy tileset3.chr ..\..\work\chrD.bin > nul
cd ..\..\..\
if [%1]==[tontis] goto :assemble

:zcp
echo Building Leo vs zcp
cd src\zcp\dev\
call compile.bat > nul
copy zcp.nes ..\..\work\rom7.nes > nul
copy tileset.chr ..\..\work\chr7.bin > nul
cd ..\..\..\
if [%1]==[zcp] goto :assemble

:assemble
echo Extracting prg from roms.
cd work 
..\gnrom-utils\xtrctbin rom0.nes prg0.bin 16 32768
..\gnrom-utils\xtrctbin rom1.nes prg1.bin 16 32768
..\gnrom-utils\xtrctbin rom2.nes prg2.bin 16 32768
..\gnrom-utils\xtrctbin rom3.nes prg3.bin 16 32768
..\gnrom-utils\xtrctbin rom4.nes prg4.bin 16 32768
..\gnrom-utils\xtrctbin rom5.nes prg5.bin 16 32768
..\gnrom-utils\xtrctbin rom6.nes prg6.bin 16 32768
..\gnrom-utils\xtrctbin rom7.nes prg7.bin 16 32768

echo Assembling mapper 113 multicart
..\gnrom-utils\bld113.exe ..\multicart.nes horz 8 16

echo Assembling binaries for the real MojoNES v2.0 cart
copy /b prg0.bin + prg1.bin + prg2.bin + prg3.bin + prg4.bin + prg5.bin + prg6.bin + prg7.bin ..\U2-PRG-GS2.bin >nul
copy /b chr0.bin + chr1.bin + chr2.bin + chr3.bin + chr4.bin + chr5.bin + chr6.bin + chr7.bin + chr8.bin + chr9.bin + chrA.bin + chrB.bin + chrC.bin + chrD.bin + chrE.bin + chrF.bin ..\U3-CHR-GS2.bin >nul

echo Cool
cd ..

echo Done!
