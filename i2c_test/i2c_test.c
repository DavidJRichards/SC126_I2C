/*
 * SC126 I2C test program, conversion to z88dk driver library and C test program
 * D. Richards. August 23rd 2020
 * work in progress
 * library calling needs adjustment
 *
 * i2c driver compile: 
 * z80asm -l i2c_device.asm
 *
 * i2c driver libbrary: 
 * z80asm -xi2c_device.lib i2c_device.o
 *
 * i2c_test application build: 
 * zcc +rc2014 -subtype=cpm -mz180 -vn -create-app -Iinclude -SO3 -clib=new --list -m i2c_test.c -l i2c_device -o i2c_test
 */

#include "i2c_device.h"
#define I2C_ADDR 0x70           //I2C device addess
#define I2C_IO_Ports 0xC0		// 0b11000000 ;SCL and SDA high + LED 1

int main()
{

	int value;
//            LD   A,0b11000000   ;SCL and SDA high + LED 1
//            CALL I2C_WrPort     ;SCL high and SDA high
	I2C_WrPort(I2C_IO_Ports);

//            LD   A,I2C_ADDR     ;I2C address to write to
//            CALL I2C_Open       ;Open I2C device for write
//            RET  NZ
	if(value = I2C_Open(I2C_ADDR)) 
		return value;

//            LD   A,0xAA
//            CALL I2C_Write      ;Write I2C device's output bits
//            RET  NZ
	if(value = I2C_Write(0xAA)) 
		return value;

//            LD   DE,1000
//            CALL API_Delay      ;Delay 1000ms
	API_Delay(1000);

//            LD   A,0x55
//            CALL I2C_Write      ;Write I2C device's output bits
//            RET  NZ
	if(value = I2C_Write(0x55)) 
		return value;

//            LD   DE,1000
//            CALL API_Delay      ;Delay 1000ms
	API_Delay(1000);

//            LD   A,0xFF
//            CALL I2C_Write      ;Set output bits
//            RET  NZ
	if(value = I2C_Write(0xFF)) 
		return value;

//            CALL I2C_Close      ;Close I2C device 
	I2C_Close();


//            LD   A,I2C_ADDR+1   ;I2C address to write to
//            CALL I2C_Open       ;Open I2C device for read
	I2C_Open(I2C_ADDR+1);

//            CALL I2C_Read       ;Read from I2C device
	value = I2C_Read();

//            CALL I2C_Close      ;Close I2C device
	I2C_Close();

	return value;
}

