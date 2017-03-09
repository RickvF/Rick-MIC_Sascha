/*
 * Week5.1.c
 *
 * Created: 9-3-2017 10:48:05
 * Author : Rick
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{

	DDRF = 0b00000000; //PORTF is input;
	DDRA = 0b11111111; //PORTA is output;
	DDRB = 0b11111111; //PORTB is output;

	//enable ADC(BIT 7), prescaler(BIT 2,1,0 -> 110), free running mode(BIT 5)
	ADCSRA = 0b11100110;

	//Vref waarde aan 5V(BIT 7,6 -> 01),result left (BIT 5), Channel1 pinF1(BIT4-0 -> 00001)
	ADMUX = 0b01100001;

	
	
    /* Replace with your application code */
    while (1) 
    {
		PORTA = ADCL;
		PORTB = ADCH;
    }
}

