#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int flip;
// Interrupt routine timer2 overflow
//
ISR( TIMER2_OVF_vect )
{
	PORTD ^= 0x80;			// toggle portd.7
	if(flip)
	{
		TCNT2 = 255-195;	// 15 ms
		flip = 0;
	}else
	{
		TCNT2 = 255-117;	// 25 ms
		flip = 1;
	}
}
// Initialize timer2
//
void timer2Init( void )
{
	flip = 0;
	TCNT2 = 0;				// Preset value of counter 2
	TIMSK |= (1<<6);		// T2 overflow interrupt enable
	TCCR2 = 0b00000101;		// Initialize T2: ext.counting, rising edge, run
}


// Main program: Counting on T2
int main( void )
{
	DDRD = 0x80;				// set PORTD.7 for input
	DDRA = 0xFF;				// set PORTA for output (shows countregister)
	DDRB = 0xFF;				// set PORTB for output (shows tenthvalue)
	timer2Init();
	SREG |= (1<<7);				// turn_on intr all
	while (1)
	{
		
	}
}
