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

int t = 0;

ISR (TIMER2_COMP_vect)
{
	if(0 == t)
	{
		PORTB = 0b00000000;
		t= 1;
		 OCR2 = 193;
	}
	else
	{
		PORTB = 0b11111111;
		t= 0;
		OCR2 = 117;
	}
}

 void timer2Init()
 {
	 
	 OCR2 = 117;// Compare value of counter 2

	 TIMSK = 0b10000000;// T2 compare match interrupt enable

	 TCCR2 = 0b00011101;
 }

int main(void)
{
	DDRB = 0b11111111; // all output
	timer2Init();
	sei();
	while (1);
	{
		
	}
}


