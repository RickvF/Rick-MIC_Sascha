;
; AssemblerTest.asm
;
; Created: 16-3-2017 09:45:06
; Author : Rick
;

.org $0200 ; beginpunt zetten op $0200 dus niet $0000

start:
	
	; Laad $5A in register R16 (R0->R15 kan niet)
	ldi R16, $5A

	; Laad inhoud van adres $0100 (data RAM) in register R17
	lds R17, $0100

	; Tel R17 op bij R16
	add R16, R17 

	; Copieer R16 naar R18
	mov R18, R16

	; Laad PORTA in R19
	in R19, PORTA

	; Verhoog R16 met 1
	inc R16

	; Sla R16 op op adres $0100 (in RAM)
	STS $0100, R16

klaar:
	rjmp klaar
