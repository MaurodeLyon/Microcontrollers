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

#include "LCD.h"

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

int binary_decimal(int n) /* Function to convert binary to decimal.*/

{
	int decimal=0, i=0, rem;
	while (n!=0)
	{
		rem = n%10;
		n/=10;
		decimal += rem*pow(2,i);
		++i;
	}
	return decimal;
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
	init();
	set_cursor(1);
	char str[40];
	while (1)
	{	
		sprintf(str, "Temperatuur: %d",	binary_decimal(ADCL));
		display_text(str);
		PORTB = ADCL;			// Show MSB/LSB (bit 10:0) of ADC
		PORTA = ADCH;
		wait(250);				// every 100 ms (busy waiting)
		sprintf(str, "Temperatuur:    ");
		display_text(str);
	}
}
