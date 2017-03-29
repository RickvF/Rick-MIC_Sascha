#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define MARGE 200
int servoh = 46;
int servov = 46;

void servo_init( void )
{
	OCR1A = 46;					// RED, default, off
	OCR1B = 46;					// GREEN, default, off
	OCR1C = 46;					// BLUE, default, off
	TCCR1A = 0b10101001;		// compare output OC1A,OC1B,OC1C
	TCCR1B = 0b00001100;		// fast PWM 8 bit, prescaler=64, RUN
}

void setServo( unsigned char servoV, unsigned char servoH )
{
	OCR1A = servoV;
	OCR1B = servoH;
}

int main(void)
{
	DDRB	= 0xFF; //servo
	DDRA	= 0xFF;
	DDRC	= 0xFF;
	DDRD	= 0xFF;
	DDRE	= 0xFF;
	DDRF	= 0x00;
	ADCSRA	= 0b11100110;
	servo_init();
	_delay_ms(250);
	int pos = 30;

	//setRed(46);//30 links //46 midden //62 meest recht
	while (1)
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

		PORTA=sensors[0];
		PORTC=sensors[1];
		PORTD=sensors[2];
		PORTE=sensors[3];

		int up = sensors[0] + sensors[3];
		int down = sensors[1] + sensors[2];
		int left = sensors[0] + sensors[1];
		int right = sensors[2] + sensors[3];

		if(up > down)
		{
			if(up-down>MARGE)
			{
				servov = servov+1;
				if(servov > 61)
				{
					servov = 61;
				}
			}
		}
		else if(up < down)
		{
			if(down-up>MARGE)
			{
				servov = servov-1;
				if(servov < 30)
				{
					servov = 30;
				}
			}
		}

		if(left > right)
		{
			if(left-right>MARGE)
			{
				servoh = servoh+1;
				if(servoh > 62)
				{
					servoh = 62;
				}
			}
		}
		else if(left < right)
		{
			if(right-left>MARGE)
			{
				servoh = servoh-1;
				if(servoh < 30)
				{
					servoh = 30;
				}
			}
		}

		setServo(servov, servoh);
	}
}
