/*
* testje.c
*
* Created: 2-2-2017 11:59:30
* Author : Rick
*/

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>



void wachten( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}

void knipperLed(int pin, int delay)
{
	DDRD = pin;
	wachten(delay);
	DDRD = 0x00;
	wachten(delay);
}

//B2
#pragma region B2


//int main(void)
//{
//
//
//DDRD = 0b11111111;
//
//while (1)
//{
////pin 7 hoog zetten, pin 6 laag zetten
//PORTD = 0b10000000;
////500ms wachten
//wachten(500);
////pin 6 hoog zetten, pin 7 laag zetten
//PORTD = 0b01000000;
////500ms wachten
//wachten(500);
//}
//
//return 1;
//}
#pragma endregion B2

//B3
#pragma region B3

//int main(void)
//{
//
////D als output
//DDRD = 0b11111111;
//
////C als input
//DDRC = 0b00000000;
//
//while (1)
//{
////checken of pinc input heeft. het getal achter '&' teken betaald bij welke button ingedrukt moet worden
//if(PINC & 1)
//{
////pin 7 aanzetten
//PORTD = 0b10000000;
//wachten(500);
////pin 7 uitzetten
//PORTD = 0b00000000;
//wachten(500);
//}
//}
//
//return 1;
//}
#pragma endregion B3

//B4
#pragma region B4

//int main(void)
//{
//
////D als output
//DDRD = 0b11111111;
//
////bit initialiseren voor de eerste led
//int bit = 0b00000001;
//
//while (1)
//{
////als bit laatste led heeft bereikt, dan bit weer eerste led
//if(bit > 0xFF)
//{
//bit = 0b00000001;
//}
////bit toewijzen aan portd
//PORTD = bit;
////bitshiften
//bit<<=1;
////wachten
//wachten(50);
//}
//
//return 1;
//}

#pragma endregion B4

//B5
#pragma region B5

//typedef struct
//{
//unsigned char regis;
//unsigned int data;
//unsigned int delay;
//}patroon;
//
//patroon patronen[] = {
//{'C', 0b00000000, 1},
//{'B', 0b00000000, 1},
//{'A', 0b00000000, 1},
//{'C', 0b00000101, 1},
//{'B', 0b00000111, 1},
//{'A', 0b00000101, 1000},
//{'C', 0b00000111, 1},
//{'B', 0b00000011, 1},
//{'A', 0b00000111, 1000},
//{'C', 0b00000001, 1},
//{'B', 0b00000001, 1},
//{'A', 0b00000111, 1000},
//{'C', 0b00000001, 1},
//{'B', 0b00000001, 1},
//{'A', 0b00000111, 1000},
//{'C', 0b00000111, 1},
//{'B', 0b00000101, 1},
//{'A', 0b00000111, 1000}
//
//};
//
//int main(void)
//{
//DDRA = 0b11111111;
//DDRB = 0b11111111;
//DDRC = 0b11111111;
//DDRD = 0b11111111;
//int index = 0;
//
//while(1)
//{
//if(index < (sizeof(patronen)/sizeof(patronen[0])))
//{
//switch(patronen[index].regis)
//{
//case 'B':
//PORTB = patronen[index].data;
//wachten(patronen[index].delay);
//break;
//
//case 'C':
//PORTC = patronen[index].data;
//wachten(patronen[index].delay);
//break;
//
//case 'D':
//PORTD = patronen[index].data;
//wachten(patronen[index].delay);
//break;
//
//case 'A':
//PORTA = patronen[index].data;
//wachten(patronen[index].delay);
//break;
//}
//index++;
//}
//else
//{
//index = 0;
//}
//}
//
//return 1;
//}

#pragma endregion B5

//B6
#pragma region B6

//int main(void)
//{
	//DDRC = 0b00000000;
	//DDRD = 0b11111111;
	//int state = 0;
//
//
//
	//while(1)
	//{
		//if(PINC&1)
		//{
			//if(state == 1)
			//{
				//state = 0;
			//}
			//else
			//{
				//state=1;
			//}
		//}
//
		//switch (state)
		//{
			//case 0:
			//knipperLed(0b10000000,1000);
			//break;
			//case 1:
			//knipperLed(0b10000000,250);
			//break;
			//default:
			//state=0;
			//break;
		//}
	//}
//
	//return 1;
//}



#pragma endregion B6

//keuze 7A
#pragma region keuze7A

//int main(void)
//{
	//DDRC = 0b11111111;
	//DDRA = 0b00000000;
	//int state = 0;
	//PORTC = 0x00;
	//
	//while(1)
	//{
		//
		//int input = PINA;
		//printf("%i input", input);
		//if(PINA > 0)
		//{
			//switch(state)
			//{
				//case 0:
				//PORTC = 0b00000001;
				//if(input == 0b00010000)
				//{
					//state = 2;
				//}
				//else if (input == 0b00100000)
				//{
					//state = 1;
				//}
				//break;
				//case 1:
				//PORTC = 0b00000010;
				//if(input == 0b00010000)
				//{
					//state = 2;
				//}
				//else if (input == 0b01000000)
				//{
					//state = 0;
				//}
				//break;
				//case 2:
				//PORTC = 0b00000100;
				//if(input == 0b00010000)
				//{
					//state = 3;
				//}
				//else if (input == 0b01000000)
				//{
					//state = 0;
				//}
				//else if (input == 0b00100000)
				//{
					//state = 1;
				//}
				//break;
				//case 3:
				//PORTC = 0b00001000;
				//if (input == 0b01000000)
				//{
					//state = 0;
				//}
				//else if (input == 0b00100000 | input == 0b00010000)
				//{
					//state = 4;
				//}
				//break;
				//case 4:
				//PORTC = 0b00010000;
				//if (input == 0b01000000)
				//{
					//state = 0;
				//}
				//break;
				//default:
				//PORTC = 0xFF;
				//break;
			//}
		//}
	//}
//
	//return 1;
//}

#pragma endregion keuze7A
