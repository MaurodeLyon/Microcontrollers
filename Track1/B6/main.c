/*
* B6.c
*
* Created: 2-2-2016 16:01:45
* Author : mauro
*/

#include <avr/io.h>
#include <util/delay.h>
void wait(int ms);

int main(void)
{
	DDRD = 0b11111111;				// zet D naar output
	DDRC = 0b00000000;				// zet C naar input
	PORTD = 0x0;					// zet port D op 0
	int toggle = 0;					// maak toggle
	int T2W = 1000;					// time to wait
	while (1)
	{
		if (PINC & 0x1)		{				// registreer button press
			if(toggle == 0)
			{
				toggle = 1;
				T2W = 500;				// 1 keer per seconden knipperen
			}
			else
			{
				toggle = 0;
				T2W = 250;				// 2 keer per seconden knipperen
			}
		}
		wait(T2W);
		PORTD ^= 0x40;						// toggle portD bit7
		
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

