#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define MARGE 200					//Verschil voordat meetwaardes serieeus genomen worden.
int servoh = 46;
int servov = 46;

void servo_init( void )
{
	OCR1A = 46;					// Vertical Servo
	OCR1B = 46;					// Horizontal Servo
	TCCR1A = 0b10101001;				// compare output OC1A,OC1B
	TCCR1B = 0b00001100;				// fast PWM 8 bit, prescaler=64, RUN
}

void setServo( unsigned char servoV, unsigned char servoH ) //30 links //46 midden //62 meest recht
{
	OCR1A = servoV;
	OCR1B = servoH;
}

int main(void)
{
	DDRB	= 0xFF; //servo
	DDRA	= 0xFF;	//PIR 0	output
	DDRC	= 0xFF;	//PIR 1	output
	DDRD	= 0xFF;	//PIR 2	output
	DDRE	= 0xFF; //PIR 3	output
	DDRF	= 0x00;	//READING ALL PIR's
	ADCSRA	= 0b11100110;			//SETTING ADC A in FREE RUNNING with PRE SCALER 64
	servo_init();	//Initilialiseren van Servo's
	_delay_ms(250); //Tijd voor Servo's om op de juiste start posistie te staan.
	
	
	while (1)
	{
		int sensors[4];		//array with PIR's
		ADMUX = 0b01100000;	//Setting the register to read first PIR
		_delay_ms(50);		//waiting for the register to be set
		sensors[0] = ADCL+ADCH;	//Retrieving sensor data
		
		ADMUX = 0b01100001;	//Setting the register to read second PIR
		_delay_ms(50);		//waiting for the register to be set
		sensors[1] = ADCL+ADCH; //Retrieving sensor data

		ADMUX = 0b01100010;	//Setting the register to read third PIR
		_delay_ms(50);		//waiting for the register to be set
		sensors[2] = ADCL+ADCH; //Retrieving sensor data
		
		ADMUX = 0b01100011;	//Setting the register to read f PIR
		_delay_ms(50);		//waiting for the register to be set
		sensors[3] = ADCL+ADCH; //Retrieving sensor data

		PORTA=sensors[0];	//Displaying Sensors on LED's
		PORTC=sensors[1];
		PORTD=sensors[2];
		PORTE=sensors[3];

		int up = sensors[0] + sensors[3];
		int down = sensors[1] + sensors[2];
		int left = sensors[0] + sensors[1];
		int right = sensors[2] + sensors[3];

		
			if(up-down>MARGE)		//Checking of MARGE is overschreden
			{
				servov = servov+1;	//servo waarde aanpassen
				if(servov > 61)
				{
					servov = 61;
				}
			}
	
		
			else if(down-up>MARGE)		//Checking of Marge is overschreven 
			{
				servov = servov-1;	//Servo waarde aanpassen
				if(servov < 30)		
				{
					servov = 30;
				}
			}
		

					if(left-right>MARGE)
			{
				servoh++;
				if(servoh > 62)
				{
					servoh = 62;
				}
			}
		
				else if(right-left>MARGE)
			{
				servoh = --
				if(servoh < 30)
				{
					servoh = 30;
				}
			}
		

		setServo(servov, servoh);		//Servo's bewegen
	}
}
