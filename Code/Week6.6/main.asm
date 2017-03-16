;
; Week6.6.asm
;
; Created: 16-3-2017 13:06:23
; Author : Rick
;


; Replace with your application code
start:
	ldi R16, 0
	ldi R17, 7
    out PORTA, R16

lus: 
    inc R16
	out PORTA, R16
	dec R17
	brne lus

twee:
	ldi R17, 7

lus1: 
    dec R16
	out PORTA, R16
	dec R17
	brne lus1

klaar:
	rjmp start
