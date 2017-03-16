;
; Week6.5.asm
;
; Created: 16-3-2017 12:34:41
; Author : Rick
;


; Replace with your application code
start:
    ; 16 bits optelling: R7/R6/R5/R4 = R15/R14/R13/R12 + R11/R10/R9/R8
ldi yh, $04 ; Y ? $0400 adres in data memory
ldi yl, $00 ;
ldd r14, Y+0; Haal waarden op uit data memory
ldd r15, Y+1;
ldd r12, Y+2 ;
ldd r13, Y+3 ;
ldd r10, Y+4 ; Haal waarden op uit data memory
ldd r11, Y+5 ;
ldd r8, Y+6 ;
ldd r9, Y+7 ;
			; Stap 1: tel de LSB’s op: R4 = R8+R10 
mov r4, r10 ; R4 ? R10
add r4, r15  ; R4 ? R4+R14 misschien Carry gezet 
			; Stap 2: tel de MSB’s op: R3 = R5+R6+C
mov r5, r11 ; R5 ? R9 
adc r5, r14  ; R5 ? R5+R7+C

mov r6, r8
adc r6, r12

mov r7, r13
adc r7, r9

std Y+4, r4 ; Sla resultaat op in data memory
std Y+5, r5 ; 
std Y+6, r6 ; Sla resultaat op in data memory
std Y+7, r7 ; 

klaar:
rjmp start
