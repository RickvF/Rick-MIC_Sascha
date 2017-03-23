#define F_CPU 8000000UL // 8 MHz clock speed
#include <avr/io.h>
#include <util/delay.h>
#define MARGE	15
/*
* init servo at the right output port
*/
void servo_init()
{
	DDRC = 0x03; //Makes RC0&1 output pin
	PORTC = 0x00;
}
/*
*	tick one step left for the horizontal servo
*/
void servoH_tick_left()
{
	PORTC = 0x01;
	_delay_us(500);
	PORTC = 0x00;
}
/*
* tick one step right for the horizontal servo
*/
void servoH_tick_right()
{
	PORTC = 0x01;
	_delay_us(2400);
	PORTC = 0x00;
}
/*
*tick one step up for the vertical servo
*/
void servoV_tick_up()
{
	PORTC = 0x02;
	_delay_us(2250);
	PORTC = 0x00;
}
/*
*
*/
void servoV_tick_down()
{
	PORTC = 0x02;
	_delay_us(600);
	PORTC = 0x00;
}


int main(void)
{
	DDRA	= 0xFF;
	DDRB	= 0xFF;
	DDRD	= 0xFF;
	DDRE	= 0xFF;
	DDRF	= 0x00;
	ADCSRA	= 0b11100110;

	
	servo_init();
	while(1)
	{
		int sensors[4];
		ADMUX = 0b01100000;
		_delay_ms(50);
		sensors[0] = ADCL+ADCH;
		
		ADMUX = 0b01100001;
		_delay_ms(50);
		sensors[1] = ADCL+ADCH;

		ADMUX = 0b01100010;
		_delay_ms(50);
		sensors[2] = ADCL+ADCH;
		
		ADMUX = 0b01100011;
		_delay_ms(50);
		sensors[3] = ADCL+ADCH;
		
		if((sensors[0]+sensors[1])>(sensors[2]+sensors[3]+MARGE))
		{
			PORTA=sensors[0];
			PORTB=sensors[1];
			PORTD=sensors[2];
			PORTE=sensors[3];
			servoH_tick_right();
			_delay_ms(10);
		}
		else if((sensors[2]+sensors[3])>(sensors[0]+sensors[1]+MARGE))
		{
			PORTA=sensors[0];
			PORTB=sensors[1];
			PORTD=sensors[2];
			PORTE=sensors[3];
			servoH_tick_left();
			_delay_ms(100);
		}

		if((sensors[0]+sensors[3])>(sensors[1]+sensors[2]+MARGE))
		{
			PORTA=sensors[0];
			PORTB=sensors[1];
			PORTD=sensors[2];
			PORTE=sensors[3];
			servoV_tick_up();
			_delay_ms(10);
		}
		else if((sensors[1]+sensors[2])>(sensors[0]+sensors[3]+MARGE))
		{
			PORTA=sensors[0];
			PORTB=sensors[1];
			PORTD=sensors[2];
			PORTE=sensors[3];
			servoV_tick_down();
			_delay_ms(100);
		}
		
		_delay_ms(500);
	}
}
