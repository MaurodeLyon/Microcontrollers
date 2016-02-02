/*
 * B2.c
 *
 * Created: 2-2-2016 14:47:13
 * Author : Arthur
 */ 

#include <avr/io.h>
#include <util/delay.h>

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}

int main(void)
{
    
	

	
	/* Replace with your application code */
	DDRD = 0b11111111;
	
    while (1) 
    {
		
		
		PORTD = 0x80;
		wait(500);
		
		PORTD = 0x40;
		
		wait(500);
    }
}

