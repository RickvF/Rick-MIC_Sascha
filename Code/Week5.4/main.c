/*
 * Week5.4.c
 *
 * Created: 9-3-2017 13:39:47
 * Author : Rick
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define BIT(x) ( 1<<x )
#define DDR_SPI DDRB // spi Data direction register
#define PORT_SPI PORTB// spi Output register
#define SPI_SCK 1 // PB1: spi Pin System Clock
#define SPI_MOSI 2 // PB2: spi Pin MOSI
#define SPI_MISO 3 // PB3: spi Pin MISO
#define SPI_SS 0 // PB0: spi Pin Slave Select

void wait(int ms)
{
	for (int i=0; i<ms; i++)
	_delay_ms(1);
}

void spi_masterInit(void)
{
	DDR_SPI = 0xff;	// All pins output: MOSI, SCK, SS, SS_display
	DDR_SPI &= ~BIT(SPI_MISO);	//	except: MISO input
	PORT_SPI |= BIT(SPI_SS);	//	SS_ADC == 1: deselect slave
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1);	// or: SPCR = 0b11010010;
											// Enable spi, MasterMode, Clock rate fck/64
											//	bitrate=125kHz,	Mode = 0: CPOL=0, CPPH=0
}

void spi_write( unsigned char data )
{
	SPDR = data;	// Load byte--> starts transmission
	while( !(SPSR & BIT(SPIF)) );	// Wait for transmission complete
}

char spi_writeRead( unsigned char data )
{
	SPDR = data;	// Load byte--> starts transmission
	while( !(SPSR & BIT(SPIF)) );	// Wait for transmission complete
	data = SPDR;	// New received data (eventually, MISO) in SPDR
	return data;	// Return received byte
}

void spi_slaveSelect(unsigned char chipNumber)
{
	PORTB &= ~BIT(chipNumber);
}

void spi_slaveDeSelect(unsigned char chipNumber)
{
	PORTB |= BIT(chipNumber);
}

void displayDriverInit()
{
	spi_slaveSelect(0);	// Select display chip (MAX7219)
	spi_write(0x09);	// Register 09: Decode Mode
	spi_write(0xFF);	//	-> 1's = BCD mode for all digits
	spi_slaveDeSelect(0);	// Deselect display chip
	spi_slaveSelect(0);	// Select dispaly chip
	spi_write(0x0A);	// Register 0A: Intensity
	spi_write(0x0F);	//	-> Level 4 (in range [1..F])
	spi_slaveDeSelect(0);	// Deselect display chip
	spi_slaveSelect(0);	// Select display chip
	spi_write(0x0B);	// Register 0B: Scan-limit
	spi_write(0x03);	//-> 1 = Display digits 0..1
	spi_slaveDeSelect(0);	// Deselect display chip
	spi_slaveSelect(0);	// Select display chip
	spi_write(0x0C);	// Register 0B: Shutdown register
	spi_write(0x01);	//	-> 1 = Normal operation
	spi_slaveDeSelect(0);	// Deselect display chip
}

void displayOn()
{
	spi_slaveSelect(0); 	// Select display chip
	spi_write(0x0C);	//	Register 0B: Shutdown register
	spi_write(0x01);	//	-> 1 = Normal operation
	spi_slaveDeSelect(0);	// Deselect display chip
}

void spi_writeWord( unsigned char adress, unsigned char data )
{
	spi_slaveSelect(0);    
	spi_write(adress);		
	spi_write(data);		
	spi_slaveDeSelect(0);		
}

void writeLedDisplay(int value)
{
	// clear display (all zero's)
	for (char i =1; i<=4; i++)
	{
		spi_writeWord(i, 15);
	}

	if(value >0 && value<10000)
	{
		if(value>999)
		{
			spi_writeWord(4,value/1000);
			value = value%1000;
		}
		if(value>99)
		{
			spi_writeWord(3,value/100);
			value = value%100;
		}
		if(value>9)
		{
			spi_writeWord(2,value/10);
			value = value%10;
		}
		if(value>0)
		{
			spi_writeWord(1,value);
		}
	}
	else if(value>-1000)
	{
		int minGezet = 0; 
		value = value*-1;
		if(value>99)
		{
			spi_writeWord(4,10);
			spi_writeWord(3,value/100);
			value = value%100;
			minGezet =1;
		}
		if(value>9)
		{
			if(minGezet == 0)
			{
				spi_writeWord(3,10);
				minGezet =1;
			}
			spi_writeWord(2,value/10);
			value = value%10;
		}
		if(value>0)
		{
			if(minGezet == 0)
			{
				spi_writeWord(2,10);
				minGezet =1;
			}
			spi_writeWord(1,value);
		}
	}
}

int main()
{
	DDRB=0x01;	// Set PB0 pin as output for display select
	spi_masterInit();	// Initialize spi module
	displayDriverInit();            // Initialize display chip
	// clear display (all zero's)
	for (char i =1; i<=4; i++)
	{
		spi_writeWord(i, 0 );
	}
	wait(1000);	// write 4	-	digit data
	int print = 4;
	for (char i =1; i<=4; i++)
	{
		spi_writeWord(i, print );
		print--;
		wait(1000);
	}
	writeLedDisplay(0000);
	writeLedDisplay(9711);
	writeLedDisplay(-71);
	wait(1000);
	return (1);
}