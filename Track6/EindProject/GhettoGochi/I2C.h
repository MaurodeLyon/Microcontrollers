/*
 * I2C.h
 *
 * Created: 6-4-2016 12:11:56
 *  Author: mauro
 */ 


#ifndef I2C_H_
#define I2C_H_

void twi_init(void);
void transmit(unsigned char data);
void draw(int data[]);
void wait(int ms);

#endif /* I2C_H_ */