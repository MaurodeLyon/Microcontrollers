/*
* Project name:
Demo4_1 : Free running AD conversion on channel 1, PORTF.1
* Author: Avans-TI, JW
* Revision History:
20101229: - initial release;
* Description:
This program gives an interrupt on each ms
* Test configuration:
MCU:             ATmega128
Dev.Board:       BIGAVR6
Oscillator:      External Clock 08.0000 MHz
Ext. Modules:    -
SW:              AVR-GCC
* NOTES:
- Turn ON the PORT LEDs at SW12.1 - SW12.8
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <math.h>

#define BIT(x)	(1 << (x))

// wait(): busy waiting for 'ms' millisecond
// Used library: util/delay.h
void wait( int ms )
{
	for (int tms=0; tms<ms; tms++)
	{
		_delay_ms( 1 );			// library function (max 30 ms at 8MHz)
	}
}


// Initialize ADC: 10-bits (left justified), free running
void adcInit( void )
{
	ADMUX = 0b01000001;			// AREF=VCC, result left adjusted, channel1 at pin PF1
	ADCSRA = 0b11100110;		// ADC-enable, no interrupt, start, free running, division by 64
}

// Main program: ADC at PF1
int main( void )
{
	DDRF = 0x00;				// set PORTF for input (ADC)
	DDRA = 0xFF;				// set PORTA for output
	DDRB = 0xFF;				// set PORTB for output
	adcInit();					// initialize ADC

	while (1)
	{
		wait(100);				// every 100 ms (busy waiting)
		int number = ADCL;
		if( number < 1)
		{
			PORTB = 0b00000001;
		}
		else if ( number < 5)//0 - 12.5
		{
			PORTB = 0b00000001;
		}
		else if (number < 10)//12.5-25
		{
			PORTB = 0b00000011;
		}else if (number <15)//25-37.5
		{
			PORTB = 0b00000111;
		}
		else if (number < 20)//37.5-50
		{
			PORTB = 0b00001111;
		}
		else if (number < 25)//50-62.5
		{
			PORTB = 0b00011111;
		}
		else if (number < 30)//62.5-75
		{
			PORTB = 0b00111111;
		}
		else if (number < 35)//87.5-100
		{
			PORTB = 0b01111111;
		}
		else if( number > 35)// <100
		{
			PORTB = 0b11111111;
		}
		
	}
}
