/*
 * B5.c
 *
 * Created: 2-2-2016 16:03:23
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

//a custom struct that holds the data (defines which leds should be on) and the delay (waiting period before initiating) of ONE step
typedef struct {
	char data;
	int delay ;
} step;


//Array which contains several instances of step which together make a pattern that will be displayed on the board
step steps[] = {
	{0x81,1000},{0x42,1000},{0x24,1000},{0x18,1000},
	{0x81,500},{0x42,500},{0x24,500},{0x18,500},
	{0x81,250},{0x42,250},{0x24,250},{0x18,250}
		
	

};

int main(void)
{
   
	int index=0;											//initiates index value which is used to navigate through the earlier mentioned array
	DDRD = 0b11111111;										//Set PORTD to OUTPUT
    while (1) 
    {
		if((sizeof(steps)/sizeof(steps[0])) >= index)		//This if-statement checks if we have reached the end of the array
		{
			PORTD= steps[index].data;						//Take the next value for PORTD out of the array
			
			index++;										//increment the index with 1
			wait(steps[index].delay);						//"freeze" the program for a given amount of time which is taken from the array
		}
		else
		{
			index=0;										//Set the index value on zero, therefore restarting the loop
		}
		
    }
}

