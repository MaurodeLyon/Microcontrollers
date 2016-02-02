/*
 * B4.c
 *
 * Created: 2-2-2016 15:21:33
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
	PORTD= 0x1;
	while (1) 
	{
	
		if(PORTD >= 0x80)
		{
			PORTD=0x1;
			 wait(1000);
		}
		PORTD= PORTD << 1;
		 wait(1000);
		
    }
}

