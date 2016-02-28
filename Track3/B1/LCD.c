/*
 * LCD.c
 *
 * Created: 23-2-2016 12:04:53
 *  Author: Arthur
 */ 


#include "LCD.h"
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

static void lcd_command(unsigned char dat);
static void lcd_writeChar(unsigned char dat);


void init()
{
	//Initialise LCD
	DDRC = 0b11111111;	//Set PORTD to OUTPUT
	
	// return home
	lcd_command( 0x02 );
	// mode: 4 bits interface data, 2 lines, 5x8 dots
	lcd_command( 0x28 );
	// display: on, cursor off, blinking off
	lcd_command( 0x0C );
	// entry mode: cursor to right, no shift
	lcd_command( 0x06 );
	// RAM adress: 0, first position, line 1
	lcd_command( 0x80 );
	
}


static void lcd_writeChar( unsigned char dat )
{
	//Write a single character to the display
	PORTC = dat & 0xF0;				// high nibble
	PORTC = PORTC | 0x0C;			// data (RS=1),

	_delay_ms(1);					// wait 1 ms
	PORTC = 0x04;					// stop (EN = 0)
	
	PORTC = (dat & 0x0F) << 4;		// low nibble
	PORTC = PORTC | 0x0C;			// data (RS=1),
	// start (EN=1)
	_delay_ms(1);					// wait 1 ms
	PORTC = 0x00;					// stop
	// (EN=0 RS=0)
}

static void lcd_command ( unsigned char dat )
{
	//send a command to the LCD (like positioning the cursor)
	
	PORTC = dat & 0xF0;				// high nibble
	PORTC = PORTC | 0x08;			// data (RS=0),
	// start (EN=1)
	_delay_ms(1);					// wait 1 ms
	PORTC = 0x04;					// stop (EN = 0)
	
	PORTC = (dat & 0x0F) << 4;		// high nibble
	PORTC = PORTC | 0x08;			// data (RS=0),
	// start (EN=1)
	_delay_ms(1);					// wait 1 ms
	PORTC = 0x00;					// stop // (EN=0 RS=0)
}
void display_text(char *str)
{
	//Display an array of chars on the LCD
	
	//lcd_command(0x80);  <-- would clear the screen before writing again
	for (int i=0; i< strlen(str); i++)
	{
		lcd_writeChar( str[i] );
	}
	
}
void set_cursor(int position)
{
	int i;
	for(i=0; i<position ; i++)
	{
		lcd_command(0x14);		//This command tells the LCD to move its to the right by one. 
								//It will be run until the preferred position is reached
		
	}
	//lcd_command(0x14);	
	//lcd_command(0xF);
}