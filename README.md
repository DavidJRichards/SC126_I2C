# SC126_I2C
Developmet of I2C library for Z180 SC126 SBC

i2c driver compile: 
z80asm -l i2c_device.asm
 
i2c driver libbrary: 
z80asm -xi2c_device.lib i2c_device.o

i2c_test application build: 
zcc +rc2014 -subtype=cpm -mz180 -vn -create-app -Iinclude -SO3 -clib=new --list -m i2c_test.c -l i2c_device -o i2c_test

