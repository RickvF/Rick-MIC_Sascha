/*
 * Week5.2.c
 *
 * Created: 9-3-2017 11:28:07
 * Author : Rick
 */ 

#define F_CPU 8000000
#define BIT(x)	(1 << (x))
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRF = 0b00000000; //PORTF is input;
	DDRA = 0b11111111; //PORTA is output;

	//enable ADC(BIT 7), prescaler(BIT 2,1,0 -> 110), not free running mode(BIT 5 LOW)
	ADCSRA = 0b11000110;

	//Vref waarde aan 5V(BIT 7,6 -> 01),result left (BIT 5), Channel1 pinF1(BIT4-0 -> 00001)
	ADMUX = 0b01100001;

    /* Replace with your application code */
    while (1) 
    {
		ADCSR |= BIT(6);
		while ( ADCSRA & BIT(6) ) ;
		PORTA = ADCH;
    }
}

