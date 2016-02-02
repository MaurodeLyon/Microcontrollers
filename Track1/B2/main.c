/*
 * B2.c
 *
 * Created: 2-2-2016 14:47:13
 * Author : Arthur
 */ 

#include <avr/io.h>
#include <util/delay.h>

//wait method to temporarily "freeze" the program
void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}


int main(void)
{	
	
	DDRD = 0b11111111;	//Set PORTD to OUTPUT
	
    while (1) 
    {
		
		
		PORTD = 0x80;	//Turn on only PORTD7
		wait(500);		//Wait for 500ms
		
		PORTD = 0x40;	//Turn on only PORTD7
		
		wait(500);		//Wait for 500ms
    }
}

