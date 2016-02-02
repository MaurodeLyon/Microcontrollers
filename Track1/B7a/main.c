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
	
	typedef enum {START,S1,S2,S3,END} STATE;
	STATE state = STATE.START;

	while (1)
	{
		switch (state)
		{
			case START:
			if(PIND & BIT(6)) state = STATE.S1;
			break;
			case S1:
			if(PIND & BIT(7) state = STATE.START;
			if(PIND & BIT(5)) state = STATE.S2;
			break;
			case S2:
			/* Your code here */
			break;
			case S3:
			/* Your code here */
			break;
			case END:
			/* Your code here */
			break;
		}
	}
}

