/*
 * B4.c
 *
 * Created: 2-2-2016 15:21:33
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
	
    DDRD = 0b11111111;		//Set PORTD to OUTPUT
	PORTD= 0x1;				//Give PORTD a default value to bit-shift
	while (1) 
	{
	
		if(PORTD >= 0x80)	//If statement checks if the current value of PORTD has reached the end of the strip of LEDs
		{
			PORTD=0x1;		//Reset to the begin of the strip of LEDs
			wait(50);		//Wait for 50 ms
		}
		PORTD= PORTD << 1;	//Change the value of PORTD with bit-shifting so that the LED thats next in line goes on
		 wait(50);		//wait for 50 ms
		
    }
}

