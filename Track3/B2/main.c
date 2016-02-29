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
	DDRD=	~BIT(7); //Put PORTD.7 on INPUT
	DDRA = 0xFF;	//Set PORTA on OUTPUT.			
	DDRB = 0xFF;	//Set PORTB on OUTPUT.	
	
	
	TCNT2 = -10;				// Initialise the value the counter should hold
	TIMSK |= BIT(6);			// Enable the T2 overflow interrupt. This interrupt will launch when the counter reaches 0.
	SREG|= BIT(7);				//Turn on the interrupt for PORTD
	TCCR2 = 0x07;				// Enable the counter in normal mode and start it

    while (1) 
    {
		PORTA = TCNT2;			// show value counter 2 on PORTA LED's
		PORTB = counter;		// show value tenth counter on PORTB LED's
		wait(10);				// every 10 ms	

    }
}

