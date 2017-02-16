/*
 * lcd.h
 *
 * Created: 16-2-2017 11:15:24
 *  Author: Rick
 */ 

#include <avr/io.h>

#ifndef LCD_H_
#define LCD_H_

void init();
void lcd_writeChar( unsigned char dat );
void lcd_writeCommand(unsigned char dat);
void display_text(char *str);
void set_cursor(char position);
void clear();
void home();
void shiftRight();
void shiftLeft();



#endif /* LCD_H_ */