;
; Week6.1.asm
;
; Created: 16-3-2017 11:48:11
; Author : Rick
;


; schrijf een stukje assembler programma om de geheugenplaatsen in het datageheugen met adres 540H tot en met 548H de waarde 55H te geven

start:
	ldi R17, $55
	STS $540, R17
	STS $541, R17
	STS $542, R17
	STS $543, R17
	STS $544, R17
	STS $545, R17
	STS $546, R17
	STS $547, R17
	STS $548, R17

klaar:
	rjmp klaar