/*
* B7a.c
*
* Created: 2-2-2016 16:31:42
* Author : mauro
*/

#include <avr/io.h>
#define BIT(x) (1 << (x))

int main(void)
{
	/* Replace with your application code */
	
	
	DDRC = 0b11111111;				// zet C naar output
	DDRD = 0b00000000;				// zet D naar input
	typedef enum {START,S1,S2,S3,END} STATE;
	STATE state = START;

	while (1)
	{
		switch (state)
		{
			case START:
				if(PIND & BIT(6)) state = S1;
				PORTC = 0x1;
			break;
			case S1:
				if(PIND & BIT(7)) state = START;
				if(PIND & BIT(5)) state = S2;
				PORTC = 0x2;
			break;
			case S2:
				if(PIND & BIT(7)) state = START;
				if(PIND & BIT(6)) state = S1;
				if(PIND & BIT(5)) state = S3;
				PORTC = 0x4;
			break;
			case S3:
				if(PIND & BIT(7)) state = START;
				if(PIND & BIT(5) || PIND & BIT(6)) state = END;
				PORTC = 0x8;
			break;
			case END:
				if(PIND & BIT(7)) state = START;
				PORTC = 0x10;
			break;
		}
		PIND = 0;
	}
}

