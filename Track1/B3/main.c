/*
* B3.c
*
* Created: 2-2-2016 14:43:43
* Author : Mauro
*/

#include <avr/io.h>
#include <util/delay.h>
void wait(int ms);

int main(void)
{
	DDRD = 0b11111111;				// zet D naar output
	DDRC = 0b00000000;				// zet C naar input
	PORTD = 0x0;					// zet port D op 0
	while (1)						// 
	{								//
		wait(250);					// wacht 250 ms
		if(PINC & 0x1)PORTD ^= 0x40;// als pinc bit 1 aan is toggle portD bit7
		else PORTD = 0x0;			// anders zet je port D bit 1 uit
		
	}
	return 1;
}

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}