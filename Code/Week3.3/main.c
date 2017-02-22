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

int main(void)
{
	DDRB |= (1 << 0); // Set LED as output

	TIMSK |= (1 << OCIE2);
	//Set interrupt on compare match
	TCCR2 |= (1 << WGM21) | (1 << CS22) | (1 << CS21) | (1 << CS20);
	// Set to CTC Mode
	OCR2 = 98;
	
	sei();
	// enable interrupts
	while (1);
	{
		// we have a working timer
	} 
}

ISR (TIMER2_COMP_vect)
{
	PORTB ^= (1 << 0); // Toggle the LED
}

