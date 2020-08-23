INCLUDE	"i2c_device.inc"



I2C_ADDR:   EQU 0x70           ;I2C device addess

;            PROC Z80           ;SCWorkshop select processor

PUBLIC _main

            .CODE
            ORG 0x8000

_main:
            LD   A,0b11000000   ;SCL and SDA high + LED 1
            CALL _I2C_WrPort     ;SCL high and SDA high

            LD   A,I2C_ADDR     ;I2C address to write to
            CALL _I2C_Open       ;Open I2C device for write
            RET  NZ

            LD   A,0xAA
            CALL _I2C_Write      ;Write I2C device's output bits
            RET  NZ

            LD   DE,1000
            CALL _API_Delay      ;Delay 1000ms

            LD   A,0x55
            CALL _I2C_Write      ;Write I2C device's output bits
            RET  NZ

            LD   DE,1000
            CALL _API_Delay      ;Delay 1000ms

            LD   A,0xFF
            CALL _I2C_Write      ;Set output bits
            RET  NZ

            CALL _I2C_Close      ;Close I2C device 


            LD   A,I2C_ADDR+1   ;I2C address to write to
            CALL _I2C_Open       ;Open I2C device for read

            CALL _I2C_Read       ;Read from I2C device

            CALL _I2C_Close      ;Close I2C device


            RET

