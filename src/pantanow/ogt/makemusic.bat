@echo off
..\..\utils\text2data music.txt -ca65
copy *.s ..\dev > nul
