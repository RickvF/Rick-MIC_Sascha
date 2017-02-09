/*
 * Week2.c
 *
 * Created: 9-2-2017 10:26:15
 * Author : Rick
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


//B1
#pragma region B1

///* ---------------------------------------------------------------------------
//** This software is in the public domain, furnished "as is", without technical
//** support, and with no warranty, express or implied, as to its usefulness for
//** any purpose.
//**
//** ioisr.c
//**
//** Beschrijving:	ISR on PORTD demonstrattion  
//** Target:			AVR mcu
//** Build:			avr-gcc -std=c99 -Wall -O3 -mmcu=atmega128 -D F_CPU=8000000UL -c ioisr.c
//**					avr-gcc -g -mmcu=atmega128 -o ioisr.elf ioisr.o
//**					avr-objcopy -O ihex ioisr.elf ioisr.hex 
//**					or type 'make'
//** Author: 			dkroeske@gmail.com
//** -------------------------------------------------------------------------*/
//
//
//
//
//
///******************************************************************/
//void wait( int ms )
///* 
//short:			Busy wait number of millisecs
//inputs:			int ms (Number of millisecs to busy wait)
//outputs:	
//notes:			Busy wait, not very accurate. Make sure (external)
				//clock value is set. This is used by _delay_ms inside
				//util/delay.h
//Version :    	DMK, Initial code
//*******************************************************************/
//{
	//for (int i=0; i<ms; i++)
	//{
		//_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	//}
//}
//
///******************************************************************/
//ISR( INT0_vect )
///* 
//short:			ISR INT0
//inputs:			
//outputs:	
//notes:			Set PORTD.5
//Version :    	DMK, Initial code
//*******************************************************************/
//{
    //PORTD |= (1<<5);		
//}
//
///******************************************************************/
//ISR( INT1_vect )
///* 
//short:			ISR INT1
//inputs:			
//outputs:	
//notes:			Clear PORTD.5
//Version :    	DMK, Initial code
//*******************************************************************/
//{
    //PORTD &= ~(1<<5);		
//}
//
///******************************************************************/
//int main( void )
///* 
//short:			main() loop, entry point of executable
//inputs:			
//outputs:	
//notes:			Slow background task after init ISR
//Version :    	DMK, Initial code
//*******************************************************************/
//{
	//// Init I/O
	//DDRD = 0xF0;			// PORTD(7:4) output, PORTD(3:0) input	
//
	//// Init Interrupt hardware
	//EICRA |= 0x0B;			// INT1 falling edge, INT0 rising edge
	//EIMSK |= 0x03;			// Enable INT1 & INT0
	//
	//// Enable global interrupt system
	////SREG = 0x80;			// Of direct via SREG of via wrapper
	//sei();				
//
	//while (1)
	//{
		//PORTD ^= (1<<7);	// Toggle PORTD.7
		//wait( 500 );								
	//}
//
	//return 1;
//}


#pragma endregion B1

//B2
#pragma region B2

////initialisatie van de bitshift. begint op 1. Dit is te zien als A0 brand
//int bitShift = 0b00000001;
//
////interup fuctie voor knop D0
//ISR( INT0_vect )
//{
	//bitShift<<=1;
//
	////Wanneer aan het einde van de strip is, weer naar het begin van de strip
	//if(bitShift > 0b10000000)
	//{
		//bitShift = 0b0000001;
	//}
//
	////wanneer aan het begin van de strip is, weer naar het einde van de strip
	//else if(bitShift < 0b0000001)
	//{
		//bitShift = 0b10000000;
	//}
//
	////waarde van de bitShift toekennen aan PortA om lampjes te zien branden
	//PORTA = bitShift;
//}
//
////interup fuctie voor knop D1
//ISR( INT1_vect )
//{
	//bitShift >>= 1;
//
	////Wanneer aan het einde van de strip is, weer naar het begin van de strip
	//if(bitShift > 0b10000000)
	//{
		//bitShift = 0b0000001;
	//}
//
	////wanneer aan het begin van de strip is, weer naar het einde van de strip
	//else if(bitShift < 0b0000001)
	//{
		//bitShift = 0b10000000;
	//}
//
	////waarde van de bitShift toekennen aan PortA om lampjes te zien branden
	//PORTA = bitShift;
//}
//
////main functie
//int main()
//{
	////input
	//DDRD = 0b00000000;
//
	////output
	//DDRA = 0b11111111;
//
	////initialisatie van de interup
	//EICRA |= 0x0F;			
	//EIMSK |= 0x03;			
//
	//sei();
	//
	//while (1)
	//{
		//
	//}
//
	//return 1;
//}

#pragma endregion B2

//B3
#pragma region B3

//int digitToDisplay = 0;
//
//void display(int digit)
//{
	////switchcase voor patroon van het display per cijfer
	//switch(digit)
	//{
		//case 0:
			//PORTD = 0b00111111;
			//break;
		//case 1:
			//PORTD = 0b00000110;
			//break;
		//case 2:
			//PORTD = 0b01011011;
			//break;
		//case 3:
			//PORTD = 0b01001111;
			//break;
		//case 4:
			//PORTD = 0b01100110;
			//break;
		//case 5:
			//PORTD = 0b01101101;
			//break;
		//case 6:
			//PORTD = 0b01111101;
			//break;
		//case 7:
			//PORTD = 0b00000111;
			//break;
		//case 8:
			//PORTD = 0b01111111;
			//break;
		//case 9:
			//PORTD = 0b01101111;
			//break;
		//case 10:
			//PORTD = 0b01110111;
			//break;
		//case 11:
			//PORTD = 0b01111100;
			//break;
		//case 12:
			//PORTD = 0b00111001;
			//break;
		//case 13:
			//PORTD = 0b01011110;
			//break;
		//case 14:
			//PORTD = 0b01111001;
			//break;
		//case 15:
			//PORTD = 0b01110001;
			//break;
		//default:
			//PORTD = 0b01111001;
			//break;
	//}
//}
//
//
//int main()
//{
	////output voor het display
	//DDRD = 0b11111111;
	//
	////input voor de buttons
	//DDRA = 0b00000000;
	//
	//while(1)
	//{
		////checken of beide buttons zijn ingedrukt
		//if(PINA == 0b00000011)
		//{
			//digitToDisplay =0;
		//}
		////checken of button A1 is ingedrukt
		//else if(PINA == 0b00000010)
		//{
			//digitToDisplay--;
		//}
		////checken of button A0 is ingedrukt
		//else if(PINA == 0b00000001)
		//{
			//digitToDisplay++;
		//}
		////tonen van het cijfer op het display
		//display(digitToDisplay);
		//wait(250);
	//}
//
	//return 1;
//}
#pragma endregion B3

//b4
#pragma region B4

//#define DELAY_TIME 50
//
//typedef struct
//{
	//int patroon;
	//int delay;
//}effect;
//
//effect lichtpatroon[] = 
//{
	//{0b00000000, DELAY_TIME},
	//{0b00000001, DELAY_TIME},
	//{0b01000000, DELAY_TIME},
	//{0b00001000, DELAY_TIME},
	//{0b01000001, DELAY_TIME},
	//{0b01001001, DELAY_TIME},
	//{0b00000000, DELAY_TIME},
	//{0b00000010, DELAY_TIME},
	//{0b00000100, DELAY_TIME},
	//{0b00000110, DELAY_TIME},
	//{0b00010000, DELAY_TIME},
	//{0b00100000, DELAY_TIME},
	//{0b00110000, DELAY_TIME},
	//{0b00110110, DELAY_TIME},
	//{0b01000000, DELAY_TIME},
	//{0b00111111, DELAY_TIME},
	//{0b00111111, DELAY_TIME},
	//{0b00000000, DELAY_TIME},
	//{0b00000010, DELAY_TIME},
	//{0b00010000, DELAY_TIME},
	//{0b00000100, DELAY_TIME},
	//{0b00100000, DELAY_TIME},
	//{0b00000001, DELAY_TIME},
	//{0b00001000, DELAY_TIME},
	//{0b00100000, DELAY_TIME},
	//{0b00000000, DELAY_TIME},
	//{0b01010010, DELAY_TIME},
	//{0b01100100, DELAY_TIME},
//};
//
//int main()
//{
	//DDRD = 0b11111111;
	//int indexArray = 0;
//
	//while(1)
	//{
		//if(indexArray < (sizeof(lichtpatroon)/sizeof(lichtpatroon[0])))
		//{
			//PORTD = lichtpatroon[indexArray].patroon;
			//wait(lichtpatroon[indexArray].delay);
			//indexArray++;
		//}
		//else
		//{
			//indexArray =0;
		//}
	//}
	//return 1;
//}

#pragma endregion B4

