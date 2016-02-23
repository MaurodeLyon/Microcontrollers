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
    /* Replace with your application code */
	init();
	set_cursor(2);
	display_text("Paul4President");
    while (1) 
    {
    }
}

