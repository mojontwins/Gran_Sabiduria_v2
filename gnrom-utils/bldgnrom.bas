' Make GNROM
' Pastes together 4 32K PRG-ROMs and 4 8K CHR-ROMs
' adds a suitable iNES header
' and the boils a couple of eggs.

' Copyleft 2015 the Mojon Twins

Sub usage
	Print "bldgnrom out.nes horz|vert #prg #chr"
	Print "will read prg0-7.bin and chr0-f.bin"
End Sub

Dim As Integer i, j, prg, chrn
Dim As uByte d, mapper
Dim s As String * 16

If Len (Command (1)) = 0 Then usage: System
'If Command (9) <> "horz" And Command (9) <> "vert" Then usage: System

prg = Val (Command (3)): If prg = 0 Then prg = 4
chrn = Val (Command (4)): If chrn = 0 Then chrn = 4

Kill Command (1)
Open Command (1) For Binary as #1

' Write iNES header.
mapper = 66

' 0-3: Constant $4E $45 $53 $1A ("NES" followed by MS-DOS end-of-file)
Mid (s, 1, 3) = "NES"
Mid (s, 4, 1) = Chr (&H1A)

' 4: Size of PRG ROM in 16 KB units 
Mid (s, 5, 1) = Chr (2 * prg)

' 5: Size of CHR ROM in 8 KB units (Value 0 means the board uses CHR RAM)
Mid (s, 6, 1) = Chr (chrn)

' 6: Flags 6
' 76543210
' ||||||||
' ||||+||+- 0xx0: vertical arrangement/horizontal mirroring (CIRAM A10 = PPU A11)
' |||| ||   0xx1: horizontal arrangement/vertical mirroring (CIRAM A10 = PPU A10)
' |||| ||   1xxx: four-screen VRAM
' |||| |+-- 1: SRAM in CPU $6000-$7FFF, if present, is battery backed
' |||| +--- 1: 512-byte trainer at $7000-$71FF (stored before PRG data)
' ++++----- Lower nybble of mapper number

d = (mapper And &H0F) Shl 4
If Command (2) = "horz" Then d = d Or 1
Mid (s, 7, 1) = Chr (d)

' 7: Flags 7
' 76543210
' ||||||||
' |||||||+- VS Unisystem
' ||||||+-- PlayChoice-10 (8KB of Hint Screen data stored after CHR data)
' ||||++--- If equal to 2, flags 8-15 are in NES 2.0 format
' ++++----- Upper nybble of mapper number

d = (mapper And &HF0)
Mid (s, 8, 1) = Chr (d)

'' Plus 8 zeros
For i = 9 To 16: Mid (s, i, 1) = Chr (0): Next i
'NES 2.0 header

' 8: Mapper variant: SSSS MMMM - Proposed mapper 113, submapper 1.
'Mid (s, 9, 1) = Chr (&H10)

' 9: Upper bits rom size
'Mid (s, 10, 1) = Chr (0)

' 10: RAM Size
'Mid (s, 11, 1) = Chr (0)

' 11: Video RAM Size
'Mid (s, 12, 1) = Chr (0)

' 12: TV System xxxx xxBP
'Mid (s, 13, 1) = Chr (&H03)

' 13: VS. Hardware
'Mid (s, 14, 1) = Chr (0)

' 14 & 15: reserved
'Mid (s, 15, 1) = Chr (0)
'Mid (s, 16, 1) = Chr (0)

' Write
Put #1, , s

' Write PRG-ROMs
For j = 1 To prg
	Open "prg" & Hex(j-1,1) & ".bin" For Binary as #2
	If Lof (2) = 32768 Then
		While Not Eof (2)
			Get #2, , d
			Put #1, , d
		Wend
		Close #2
	Else
		Print "PRG" & Hex(j-1,1) & " missing or not 32K. Zero-filling."
		If Lof (2) = 0 Then
			Close #2
			Kill "prg" & j & ".bin"
		Else
			Close #2
		End If
		For i = 1 To 32768
			d = 0
			Put #1, , d
		Next i
	End If
Next j

' Write CHR-ROMs
For j = 1 To chrn
	Open "chr" & Hex(j-1,1) & ".bin" For Binary as #2
	If Lof (2) = 8192 Then
		While Not Eof (2)
			Get #2, , d
			Put #1, , d
		Wend
		Close #2
	Else
		Print "CHR" & Hex(j-1,1) & " missing or not 8K. Zero-filling."
		If Lof (2) = 0 Then
			Close #2
			Kill "chr" & j & ".bin"
		Else
			Close #2
		End If
		For i = 1 To 8192
			d = 0
			Put #1, , d
		Next i
	End If
Next j

' Done!

Close 
