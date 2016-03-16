/*
 * B2bV2.c
 *
 * Created: 15-3-2016 12:49:35
 * Author : Arthur
 */ 

#include <avr/io.h>
#include "LCD.h"
#define F_CPU 8000000UL

#include "uart0.h"

void wait( int ms )
{
	for (int tms=0; tms<ms; tms++)
	{
		_delay_ms( 1 );						// library function (max 30 ms at 8MHz)
	}
}


int main(void)
{
    
    char buffer[16];						// declare string buffer

    init();								// initialize LCD-display
    usart0_init();							// initialize USART0
    usart0_start();

    wait(100);

    while (1)
    {
	    wait(150);							// every 50 ms (busy waiting)

	    uart0_receiveString( buffer );		// receive string from uart
	    
	    // write string to LCD display
		buffer[0]=' ';
	   display_text(buffer); 
	   
    }
}

