/*
 * Week3.c
 *
 * Created: 16-2-2017 10:15:29
 * Author : Rick
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"



int main(void)
{
	DDRC = 0b11111111;

	_delay_ms(1000);

	init();
	_delay_ms(1000);
	clear();
	_delay_ms(1000);
	home();
	_delay_ms(1000);

	char text[] = "hallo 1234567890 cool display";

	set_cursor(0);
	display_text(text);
	
    /* Replace with your application code */
    while (1) 
    {
		shiftLeft();
		_delay_ms(250);
    }

	return 1;
}

