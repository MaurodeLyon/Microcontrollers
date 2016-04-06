/*
* GhettoGochi.c
*
* Created: 22-3-2016 13:06:46
* Author : mauro
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "I2C.h"
#include "Tama.h"

#define BIT(x) ( 1<<x );
int overflow;
void check()
{
	switch (status)
	{
		case 0:
		smile = frown_bmp;
		case 1:
		smile = frown_bmp;
		transmit(0b11100000);	//Display Dimming 8/16 duty cycle
		break;
		case 2:
		smile = frown_bmp;
		transmit(0b11100001);
		break;
		case 3:
		smile = frown_bmp;
		transmit(0b11100010);
		break;
		case 4:
		smile = frown_bmp;
		transmit(0b11100011);
		break;
		case 5:
		smile = neutral_bmp;
		transmit(0b11100100);
		break;
		case 6:
		smile = neutral_bmp;
		transmit(0b11100101);
		break;
		case 7:
		smile = neutral_bmp;
		transmit(0b11100110);
		break;
		case 8:
		smile = neutral_bmp;
		transmit(0b11100111);
		break;
		case 9:
		smile = neutral_bmp;
		transmit(0b11101000);
		break;
		case 10:
		smile = smile_bmp;
		transmit(0b11101001);
		break;
		case 11:
		smile = smile_bmp;
		transmit(0b11101010);
		break;
		case 12:
		smile = smile_bmp;
		transmit(0b11101011);
		break;
		case 13:
		smile = smile_bmp;
		transmit(0b11101100);
		break;
		case 14:
		smile = smile_bmp;
		transmit(0b11101101);
		break;
		case 15:
		smile = smile_bmp;
		transmit(0b11101110);
		break;
		case 16:
		smile = smile_bmp;
		transmit(0b11101111);
		break;
		default:
		if(status > 16)
		{
			status = 16;
		}
		if(status < 0){
			status = 0;
		}
		break;
	}
}
ISR( INT4_vect )
{
	status++;
	PORTA ^= (1<<6);	// Toggle PORTA.7
}
ISR( INT5_vect )
{

}
ISR( INT6_vect )
{

}

ISR( TIMER2_OVF_vect)
{
	TCNT2 = 0;
	if(overflow > 4){
		status--;
		overflow = 0;
	}
	PORTA ^= (1<<7);	// Toggle PORTA.7
	overflow++;
}
int main( void )
{
	DDRA = 0b11111111;
	//enable interrupts op port E4 5 6
	EICRB |= 0b00111111;	// Interrupt 4,5 en 6 op rising edge
	EIMSK |= 0b01110000;	// Enable INT4, INT5, INT6
	
	TCNT2 = 0;				// Preset value of counter 2
	TIMSK |= (1<<6);		// T2 overflow interrupt enable
	TCCR2 = 0b00000101;		// Initialize T2: ext.counting, rising edge, run


	twi_init();				// Init TWI interface
	// Init HT16K22. Page 32 datasheet
	transmit(0x21);			// Internal osc on (page 10 HT16K33)
	transmit(0xA0);			// HT16K33 pins all output
	transmit(0b11101010);	//Display Dimming 8/16 duty cycle
	transmit(0x81);			// Display OFF - Blink On
	
	status = 0;
	sei();
	while (1)
	{
		draw(smile);
		check();
	}

	return 1;
}

