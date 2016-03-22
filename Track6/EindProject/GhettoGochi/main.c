/*
* GhettoGochi.c
*
* Created: 22-3-2016 13:06:46
* Author : mauro
*/

#include <avr/io.h>
#include <util/delay.h>

#include "i2c_master.h"

#define BIT(x) ( 1<<x )
#define I2C_SCL_PIN		0			// I2C Serial Clock
#define I2C_SDA_PIN		0			// I2C Serial Data	
#define DEVICE_ADDRES	0b11100000	// device addres
#define SYSTEM_SETUP	0b00100001	// system setup

int smile_bmp[] =
{
	0b00111100,
	0b01000010,
	0b10100101,
	0b10000001,
	0b10100101,
	0b10011001,
	0b01000010,
	0b00111100
};

int neutral_bmp[] =
{
	0b00111100,
	0b01000010,
	0b10100101,
	0b10000001,
	0b10111101,
	0b10000001,
	0b01000010,
	0b00111100
};

int frown_bmp[] =
{
	0b00111100,
	0b01000010,
	0b10100101,
	0b10000001,
	0b10011001,
	0b10100101,
	0b01000010,
	0b00111100
};

void init(void)
{
	i2c_init();
	i2c_start(DEVICE_ADDRES);
	//Internal system clock enable
	i2c_write(SYSTEM_SETUP);
	//ROW/INT output pin set + INT pin output level set
	i2c_write(0b10101111);
	//Dimming set
	i2c_write(0b11101001);
	//Blinking set
	i2c_write(0b10000101);
}

void TWIInit(void)
{
	//set SCL to 400kHz
	TWSR = 0x00;
	TWBR = 0x0C;
	//enable TWI
	TWCR = (1<<TWEN);
}

void TWIStart(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
}
//send stop signal
void TWIStop(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void TWIWrite(uint8_t u8data)
{
	TWDR = u8data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
}

int main(void)
{
	DDRD = 0b11111111;
	TWIInit();
	TWIStart();

	/* Replace with your application code */
	while (1)
	{
		TWIWrite(0b01110000);
		TWIWrite(0b00000000);
		TWIWrite(0b00000000);
		TWIWrite(0b00000000);
		TWIWrite(0b00000000);
		_delay_ms(1000);
	}
}

