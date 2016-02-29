/*
 * B1.c
 *
 * Created: 23-2-2016 12:04:15
 * Author : Arthur
 */ 

#include <avr/io.h>
#include "LCD.h"


int main(void)
{
	//Run the functions as a test.
	init();
	set_cursor(2);
	display_text("Paul4Preside");
    while (1) 
    {
    }
}

