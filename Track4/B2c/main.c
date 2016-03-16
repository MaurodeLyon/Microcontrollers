/*
 * B2c.c
 *
 * Created: 1-3-2016 13:23:01
 * Author : Arthur
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BIT(x)			(1 << (x))

unsigned int sCount=0, minutes=0, hours=0;

// wait(): busy waiting for 'ms' millisecond
// Used library: util/delay.h
void wait( int ms )
{
	for (int tms=0; tms<ms; tms++)
	{
		_delay_ms( 1 );			// library function (max 30 ms at 8MHz)
	}
}

// Initialize timer 1: fast PWM at pin PORTB.6 (hundredth ms)
void timer1Init( void )
{
	OCR1A = 255;					// RED, default, off
	OCR1B = 255;					// GREEN, default, off
	OCR1C = 255;					// BLUE, default, off
	TCCR1A = 0b10101001;		// compare output OC1A,OC1B,OC1C
	TCCR1B = 0b00001011;		// fast PWM 8 bit, prescaler=64, RUN
}

// Set pulse width for RED on pin PB5, 0=off, 255=max
void setRed( unsigned char red )
{
	OCR1B = red;
}

void setGreen( unsigned char green)
{
	OCR1C=green;
	
}
void setBlue( unsigned char blue)
{
	OCR1A=blue;
	
}



// Main program: Counting on T1
int main( void )
{
	DDRB = 0xFF;					// set PORTB for compare output
	timer1Init();
	wait(100);

	while (1)
	{
		
		//Turn off all LED's but red
		setRed( 0 );
		setBlue( 255 );
		setGreen( 255 );
		
		////Turn on the green LED		
		//for(int green=255; green >=0; green-=2)
		//{
			//setGreen(green);
			////wait(10);
			//
		//}
		////Turn off red
		//for(int red=0; red <=255; red+=2)
		//{
			//setRed(red);
			//wait(10);
			//
		//}
		//
		////Turn on the blue LED
		//for(int blue=255 ; blue >=0; blue-=2)
		//{
			//
			//setBlue(blue);
			//wait(10);
		//}
		////Turn off green led
		//for(int green=0; green<=255; green+=2)
		//{
			//
			//setGreen(green);
			//wait(10);
		//}
		//
		////turn on red
		//for(int red=255; red <=0; red-=2)
		//{
			//setRed(red);
			//wait(10);
			//
		//}
		
		
		
		//Turn off the blue LED
		//for(int blue=0 ; blue <=255; blue+=2)
		//{
			//
			//setBlue(blue);
			//wait(10);
		//}
		////Turn off the green LED
		//
		////Turn off all LED'
		//setRed( 255 );
		//setBlue( 255 );
		//setGreen( 255 );

		wait(100);

	}
}


