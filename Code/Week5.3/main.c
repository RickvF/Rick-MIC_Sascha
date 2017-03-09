/*
 * Week5.3.c
 *
 * Created: 9-3-2017 11:58:58
 * Author : Rick
 */ 

#define F_CPU 8000000
#define BIT(x)	(1 << (x))
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"


int main(void)
{
	DDRF = 0b00000000; //PORTF is input;
	DDRA = 0b11111111; //PORTA is output;
	DDRC = 0b11111111;

	//enable ADC(BIT 7), prescaler(BIT 2,1,0 -> 110), free running mode(BIT 5)
	ADCSRA = 0b11100110;

	//Vref waarde aan 2,56V(BIT 7,6 -> 11),result left (BIT 5), Channel1 pinF3(BIT4-0 -> 00011)
	ADMUX = 0b11100011;

	_delay_ms(1000);
	//initLCD
	init();
	_delay_ms(1000);
	clear();
	_delay_ms(1000);
	home();
	_delay_ms(1000);

    /* Replace with your application code */
    while (1) 
    {
		PORTA = ADCH;
		int f = ADCH/10;
		int l = ADCH%10;
		char wf = '0' + f;
		char wl = '0' + l;
		home();
		lcd_writeChar(wf);
		lcd_writeChar(wl);

    }
}

