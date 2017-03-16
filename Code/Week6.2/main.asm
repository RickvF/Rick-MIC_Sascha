;
; Week6.2.asm
;
; Created: 16-3-2017 12:00:56
; Author : Rick
;


; Replace with your application code
start:
	ldi R16, 10
	ldi xh, $66
	ldi xl, 00
	ldi yh, $8B
	ldi yl, 00

lus: 
    ld R17, X+
	ST Y+, R17
	dec R16
	brne lus



klaar:
	rjmp klaar
