/*
* GhettoGochi.c
*
* Created: 22-3-2016 13:06:46
* Author : mauro
*/

#include <avr/io.h>
#include <util/delay.h>

#define BIT(x) ( 1<<x )
#define DDR_SPI DDRB	// spi Data direction register
#define PORT_SPI PORTB	// spi Output register
#define SPI_SCK 1		// PB1: spi Pin System Clock
#define SPI_MOSI 2		// PB2: spi Pin MOSI
#define SPI_MISO 3		// PB3: spi Pin MISO
#define SPI_SS 0		// PB0: spi Pin Slave Select
#define F_CPU 1000000UL

int smile_bmp[] =
{
	0b00111100,
	0b01000010,
	0b10100101,
	0b10000001,
	0b10100101,
	0b10011001,
	0b01000010,
	0b00111100
};

int neutral_bmp[] =
{
	0b00111100,
	0b01000010,
	0b10100101,
	0b10000001,
	0b10111101,
	0b10000001,
	0b01000010,
	0b00111100
};

int frown_bmp[] =
{
	0b00111100,
	0b01000010,
	0b10100101,
	0b10000001,
	0b10011001,
	0b10100101,
	0b01000010,
	0b00111100
};

int main(void)
{
	DDRD = 0b11111111;
	PORTD = 0b11111111;
	/* Replace with your application code */
	while (1)
	{
	
	}
}

