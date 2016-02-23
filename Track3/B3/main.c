/*
 * B3.c
 *
 * Created: 23-2-2016 13:31:51
 * Author : Arthur
 */ 

#include <avr/io.h>
#include "LCD.h"
#include <util/delay.h>

#define BIT(x) (1 <<(x))
int counter;

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}


ISR(TIMER2_OVF_vect )
{
	TCNT2 = -10;	// Preset value
	counter++;			// Increment counter
	

}



int main(void)
{
	counter=0;
	DDRD=	~BIT(7);
	DDRA = 0xFF;				
	DDRB = 0xFF;
	
	
	TCNT2 = -10;				// of  TCNT2=0xf6
	TIMSK |= BIT(6);			// T2 overflow interrupt enable, p. 162
	SREG|= BIT(7);
	TCCR2 = 0x07;		// counter, normal mode, run

    /* Replace with your application code */
    while (1) 
    {
		PORTA = TCNT2;			// show value counter 2
		PORTB = counter;	// show value tenth counter
		wait(10);				// every 10 ms
	

    }
}

