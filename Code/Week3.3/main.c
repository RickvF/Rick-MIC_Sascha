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
int t = 0;

int main(void)
{
	DDRC = 0b11111111;
	DDRD = 0b11111111;
	init();
	_delay_ms(1000);
	clear();
	_delay_ms(1000);
	home();
	_delay_ms(1000);

	OCR2 = 15624;
	TCCR2 |= (1 << WGM21);
	// Set to CTC Mode
	TIMSK |= (1 << OCIE2);
	//Set interrupt on compare match
	TCCR2 |= (1<<CS02) | (1<<CS00);
	// set prescaler to 1024 and starts PWM
	sei();
	// enable interrupts
	while (1);
	{
		// we have a working timer
	}
}

ISR (TIMER2_COMP_vect)
{
	if(t = 0)
	{
		PORTD = 0b00000000;
		t= 1;
	}
	else
	{
		PORTD = 0b11111111;
		t= 0;
	}
	clear();
	++i;
	if(i>9)
	{
		i = 0;
	}
	char write = i + '0';
	lcd_writeChar(write);
}

