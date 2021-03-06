/*
 * Week3.2.c
 *
 * Created: 16-2-2017 12:44:50
 * Author : Rick
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include "lcd.h"

int aantalKeerPress = 0;

ISR(TIMER2_COMP_vect)
{
	aantalKeerPress++;
}


int main(void)
{
    DDRC = 0b11111111;
	DDRD = 0b00000000;
	DDRB = 0b11111111;

	TCCR2 = 0b00011111;
	OCR2 = 1;
	TIMSK |= 0x80;
	sei();
	
	
    _delay_ms(1000);

    init();
    _delay_ms(1000);
    clear();
    _delay_ms(1000);
    home();
    _delay_ms(1000);
	lcd_writeChar('5');

    /* Replace with your application code */
    while (1)
    {
		home();
		char write = '0' + aantalKeerPress;
		lcd_writeChar(write);
    }

    return 1;
}

