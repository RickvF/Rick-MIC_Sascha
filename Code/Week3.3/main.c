/*
 * Week3.3.c
 *
 * Created: 22-2-2017 10:37:29
 * Author : Rick
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include "lcd.h"

int i = 0;
int main(void)
{
	DDRC = 0b11111111;
	init();
	_delay_ms(1000);
	clear();
	_delay_ms(1000);
	home();
	_delay_ms(1000);

	OCR2 = 62;
	TCCR2 |= (1 << WGM21);
	// Set to CTC Mode
	TIMSK |= (1 << OCIE2);
	//Set interrupt on compare match
	TCCR2 |= (1 << CS21);
	// set prescaler to 64 and starts PWM
	sei();
	// enable interrupts
	while (1);
	{
		// we have a working timer
	}
}

ISR (TIMER2_COMP_vect)
{
	// action to be done every 250us
	i++;
	char write = i + '0';
	lcd_writeChar(write);
}

