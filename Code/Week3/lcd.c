/*
 * lcd.c
 *
 * Created: 16-2-2017 11:14:34
 *  Author: Rick
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

 void send_Char()
 {
	//RS en E naar 1
	PORTC = PORTC | 0x0C;

	_delay_ms(1);
	// Rs en E naar 0
	PORTC = 0x00;
 }

 void send_Command()
 {
	 //RS en E naar 1
	 PORTC = PORTC | 0x08;

	 _delay_ms(1);
	 // Rs en E naar 0
	 PORTC = 0x00;
 }

 void lcd_writeChar( unsigned char dat )
 {
	//upper
	PORTC = dat & 0xF0;
	send_Char();

	//Lower
	PORTC = (dat & 0x0F) << 4;
	send_Char();
}

void lcd_writeCommand(unsigned char dat)
{
	//Upper
	PORTC = dat & 0xF0;
	send_Command();

	//Lower
	PORTC = (dat & 0x0F) << 4;
	send_Command();
}

 void init()
 {
	//4 bit mode instellen
	lcd_writeCommand(0x20);

	//4bit mode ON, 2 lines, 5*8 font
	lcd_writeCommand(0x28);

	//return home
	lcd_writeCommand(0x02);

	//display on, cursor off, blinking off
	lcd_writeCommand(0x0C);

	//entry mode cursor to right, no shift
	lcd_writeCommand(0x06);

	//RAM adress: 0, first position, line 1
	lcd_writeCommand(0x80);
 }

 void display_text(char *str)
 {
	int i = 0;

	while(str[i])
	{
		lcd_writeChar(str[i]);
		i++;
	}
 }

 void set_cursor(char position)
 {
	lcd_writeCommand(0x80|position);
 }

 void clear()
 {
	lcd_writeCommand(0x01);
 }

 void home()
 {
	lcd_writeCommand(0x02);
 }

 void shiftRight()
 {
	lcd_writeCommand(0x1C);
 }

 void shiftLeft()
 {
	 lcd_writeCommand(0x18);
 }