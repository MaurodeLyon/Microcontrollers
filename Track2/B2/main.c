/*
 * B2.c
 *
 * Created: 21-2-2016 18:08:41
 * Author : Arthur
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void nextStep();

int index=0;

typedef struct {
	char data;
	int delay ;
} step;


//Array which contains several instances of step which together make a pattern that will be displayed on the board
step steps[] = {
	{0x90,1000},{0x60,1000},{0x50,1000},{0x90,1000}
	
};


void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}


void nextStep()
{
	if((sizeof(steps)/sizeof(steps[0])) >= index)		//This if-statement checks if we have reached the end of the array
	{
		PORTD= steps[index].data;						//Take the next value for PORTD out of the array
		
		index++;										//increment the index with 1
		wait(steps[index].delay);						//"freeze" the program for a given amount of time which is taken from the array
	}
	else{
		index=0;
	}									//Set the index value on zero, therefore restarting the loop}
	
}

ISR( INT1_vect )
{
	nextStep();	 //Show the next step of the animation	
}

ISR( INT3_vect )
{
	nextStep();			
}
ISR( INT2_vect )
{
	nextStep();
}
ISR( INT0_vect )
{
	nextStep();
}


int main( void )

{
	// Init I/O
	DDRD = 0xF0;			// PORTD(7:4) output, PORTD(3:0) input	
	// Init Interrupt hardware
	EICRA |= 0xAA;			// INT0 through INT3 set to falling edge
	EIMSK |= 0xF;			// Enable INT1 through INT3
	
	
	sei();				// Enable global interrupt system

	while (1)
	{
									
	}

	return 1;
}

