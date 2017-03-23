
#define F_CPU 8000000UL // 8 MHz clock speed

#include <avr/io.h>
#include <util/delay.h>

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
	_delay_us(600);
	PORTC = 0x00;
 }

 /*
 * tick one step right for the horizontal servo
 */
 void servoH_tick_right()
 {
	PORTC = 0x01;
	_delay_us(2250);
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
	servo_init();
	while(1)
	{
		////Rotate Motor to 0 degree
		//PORTC = 0x01;
		//_delay_us(1000);
		//PORTC = 0x00;
//
		//_delay_ms(2000);

		////Rotate Motor helemaal naar links
		//PORTC = 0x03;
		//_delay_us(600);
		//PORTC = 0x00;
//
		//_delay_ms(2000);
//
		////Rotate Motor helemaal naar rechts
		//PORTC = 0x03;
		//_delay_us(2250);
		//PORTC = 0x00;

		for(int i =0; i<10; i++)
		{
			servoV_tick_down();
			servoH_tick_left();
			_delay_ms(10);
		}
		
		_delay_ms(2000);

		for(int i=0; i<10; i++)
		{		
			servoV_tick_up();
			servoH_tick_right();
			_delay_ms(10);
		}
		_delay_ms(2000);
	}
}