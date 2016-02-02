#include <avr/io.h>
#include <util/delay.h>

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}

int main( void )
{
	// All pins PORTD are set to output
	DDRA = 0b11111111;
	DDRB = 0b11111111;
	DDRC = 0b11111111;
	DDRD = 0b11111111;
	DDRE = 0b11111111;
	DDRF = 0b11111111;
	DDRG = 0b11111111;

	while (1)
	{// Write 01010101b
		PORTA = 0xAA;
		PORTB = 0xAA;
		PORTC = 0xAA;
		PORTD = 0xAA;
		PORTE = 0xAA;
		PORTF = 0xAA;
		PORTG = 0xAA;
		wait( 1000 );
		// Write 01010101b
		PORTA = 0x55;
		PORTB = 0x55;
		PORTC = 0x55;
		PORTD = 0x55;
		PORTE = 0x55;
		PORTF = 0x55;
		PORTG = 0x55;
		wait( 1000 );
		// Write 01010101b
		PORTA = 0xFF;
		PORTB = 0xFF;
		PORTC = 0xFF;
		PORTD = 0xFF;
		PORTE = 0xFF;
		PORTF = 0xFF;
		PORTG = 0xFF;
		wait( 1000 );
	}
	return 1;
}
