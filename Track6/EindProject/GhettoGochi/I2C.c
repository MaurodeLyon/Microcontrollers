/*
* I2C.c
*
* Created: 22-3-2016 13:06:46
* Author : Mauro
*/

#include <avr/io.h>
#include <util/delay.h>

#define BIT(x) ( 1<<x );
int prev;

void twi_init(void)
{
	TWSR = 0;
	TWBR = 32;	 // TWI clock set to 100kHz, prescaler = 0
}

void twi_start(void)
{
	TWCR = (0x80 | 0x20 | 0x04);
	while( 0x00 == (TWCR & 0x80) );
}

void twi_stop(void)
{
	TWCR = (0x80 | 0x10 | 0x04);
}

void twi_tx(unsigned char data)
{
	TWDR = data;
	TWCR = (0x80 | 0x04);
	while( 0 == (TWCR & 0x80) );
}

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

void transmit(unsigned char data)
{
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(data);	// transmit data
	twi_stop();
}

void clear()
{
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	for(int i = 0 ; i < 8; i=i+1)
	{
		twi_tx(0x00);	// Address
		twi_tx(0x00);	// data
	}
	twi_stop();
}

void draw(int data[])
{
	if(prev != data){
		clear();
		twi_start();
		twi_tx(0xE0);	// Display I2C addres + R/W bit
		for(int i = 0 ; i < 8; i = i + 1){
			twi_tx(0x00);		// Address
			twi_tx(data[i]);	// data
		}
		twi_stop();
	}
	prev = data;
}

