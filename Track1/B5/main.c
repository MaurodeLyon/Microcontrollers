/*
 * B5.c
 *
 * Created: 2-2-2016 16:03:23
 * Author : Arthur
 */ 

#include <avr/io.h>
#include <util/delay.h>

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}


typedef struct {
	char data;
	int delay ;
} step;


//step steps[] = {
	//{0x00, 100}, {0x01, 100}, {0x02, 100}, {0x04, 100}, {0x10, 100}, {0x20, 100}, {0x40, 100}, {0x80, 100},
	//{0x00, 100},
	//{0xAA,  50}, {0x55,  50},
	//{0xAA,  50}, {0x55,  50},
	//{0xAA,  50}, {0x55,  50},
	//{0x00, 100},
	//{0x81, 100}, {0x42, 100}, {0x24, 100}, {0x18, 100}, {0x0F, 200}, {0xF0, 200}, {0x0F, 200}, {0xF0, 200},
	//{0x00, 0x00}
//
//};

step steps[] = {
	{0x81,1000},{0x42,1000},{0x24,1000},{0x18,1000},
	{0x81,500},{0x42,500},{0x24,500},{0x18,500},
	{0x81,250},{0x42,250},{0x24,250},{0x18,250}
		
	

};

int main(void)
{
    /* Replace with your application code */
	int index=0;
	DDRD = 0b11111111;
    while (1) 
    {
		if((sizeof(steps)/sizeof(steps[0])) >= index)
		{
			PORTD= steps[index].data;
			
			index++;
			wait(steps[index].delay);
		}
		else
		{
			index=0;
		}
		
    }
}

