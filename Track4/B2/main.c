/*
 * B2.c
 *
 * Created: 1-3-2016 12:02:27
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
	OCR1A = 255;					// BLUE, default, off
	OCR1B = 255;					// RED, default, off
	OCR1C = 255;					// GREEN, default, off
	TCCR1A = 0b10101001;		// compare output OC1A,OC1B,OC1C
	TCCR1B = 0b00001011;		// fast PWM 8 bit, prescaler=64, RUN
}

// Set pulse width for RED on pin PB5, 0=max, 255=off
void setRed( unsigned char red )
{
	OCR1B = red;
}
// Set pulse width for GREEN on pin PB5, 0=max, 255=off
void setGreen( unsigned char green)
{
	OCR1C=green;	
	
}
// Set pulse width for BLUE on pin PB5, 0=max, 255=off
void setBlue( unsigned char blue)
{
	OCR1A=blue;	
	
}

void fadeRed()
{
	//SLowly turn on the red LED
	for(int red = 255 ; red >=0 ; red-=2)
	{
		setRed(red);
		wait(250);
	}
	//Slowly turn off the red LED
	for(int red = 0 ; red <=255 ; red+=2)
	{
		setRed(red);
		wait(500);
	}
	//Turn of
	setRed(255);
	
}
void fadeGreen()
{
	//Slowly turn on the green LED
	for(int green = 255 ; green >=0 ; green-=2)
	{
		setGreen(green);
		wait(250);
	}
	//Slowly turn off the green LED
	for(int green = 0 ; green <=255 ; green+=2)
	{
		setGreen(green);
		wait(500);
	}
	//Turn off the green LED
	setGreen(255);
}

void fadeBlue()
{
	//Slowly turn on the blue LED
	for(int blue = 255 ; blue >=0 ; blue-=2)
	{
		setBlue(blue);
		wait(250);
	}
	//Slowly turn off the blue LED
	for(int blue = 0 ; blue <=255 ; blue+=2)
	{
		setBlue(blue);
		wait(500);
	}
	//Turn off the blue LED
	setBlue(255);
}

// Main program: Counting on T1
int main( void )
{
	DDRB = 0xFF;					// set PORTB for compare output
	timer1Init()					//Initialise the timer
	wait(100);

	while (1)
	{
		
		//Turn off LED's
		setRed( 255 );		
		setBlue( 255 );
		setGreen( 255 );
		
		fadeRed();
		fadeGreen();
		fadeBlue();
		
		//Turn off LED's
		setRed( 255 );
		setBlue( 255 );
		setGreen( 255 );

		wait(100);

	}
}
