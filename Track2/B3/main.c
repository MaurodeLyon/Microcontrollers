/*
* B3.c
*
* Created: 22-2-2016 09:36:48
* Author : mauro
*/

#include <avr/io.h>
#include <util/delay.h>

static int displayDigit;
static unsigned char HEXNUMBERS[17] =
{
	0b00111111, //0
	0b00000110, //1
	0b01011011, //2
	0b01001111, //3
	0b01100110, //4
	0b01101101, //5
	0b01111101, //6
	0b00000111, //7
	0b01111111, //8
	0b01101111, //9
	0b01110111, //A (10)
	0b01111100, //B (11)
	0b01011000, //C (12)
	0b01011110, //D (13)
	0b01111001, //E (14)
	0b01110001, //F (15)
	0b11111001  //ER(16) 
};

void wait( int ms ){
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

void display(int digit)
{
	displayDigit = digit;						//veranderd globale variabele
	if (0 <= displayDigit && displayDigit <= 15)//als het 0 < getal < 15
	{
		PORTD = HEXNUMBERS[displayDigit];		//display getal
	}
	else if(displayDigit > 15)					//als het getal > 15 
	{
		PORTD = HEXNUMBERS[16];					//display error = E.
	}
}

void increase(void)
{
	displayDigit++;
	display(displayDigit);
}

void decrease(void)
{
	displayDigit--;
	display(displayDigit);
}

int main(void)
{
	/* Replace with your application code */
	displayDigit = 0;
	DDRD = 0b11111111;		// PORTD all output
	
	while (1)
	{
		increase(); // verhoogt de waarde van de globale variabele met 1 en update het 7-segment display
		wait(250);	// wacht 250 ms
	}
}

