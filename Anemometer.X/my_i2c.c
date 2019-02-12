
#include<xc.h>
#include <string.h>
#include <i2c.h>
#include "Globals.h"
#include "utils.h"


void i2c_init();

void __attribute__((interrupt, no_auto_psv)) _SI2C2Interrupt(void);

int data_byte = 0;
unsigned char data_in[10]; //data written to master
int out_byte = 0;
unsigned char dataout[40];

void i2c_init() {
    I2C2BRG = 3999; // SCLK = 100kHz for FCY = 4 MHz
    I2C2CONbits.I2CEN = 1;
    I2C2ADD = 0x20; // 7-bit I2C slave address must be initialised here.
    IFS2 = 0;
    _SI2C2IE = 1;
};

void __attribute__((interrupt, no_auto_psv)) _SI2C2Interrupt(void) {

    unsigned char temp = 0; //dummy data
    if ((I2C2STATbits.R_W == 0) && (I2C2STATbits.D_A == 0)) // Device address matched (write)
    {
        data_byte = 0;
        temp = I2C2RCV; //dummy read to clear RCV buffer

    } else if ((I2C2STATbits.R_W == 0) && (I2C2STATbits.D_A == 1)) //check for data (write)
    {
        data_in[data_byte++] = I2C2RCV; //transfer data from RCV buffer
        if (data_byte == 9)
            if (data_in[0] == 6) {
                memcpy(&requestdata, data_in, 9);
                start_measurement = true;
                out_byte = 0;
                memcpy(dataout, &remote_data, 8);
                dataout[8] = Sum(dataout, 8);
            }
    } else if ((I2C2STATbits.R_W == 1) && (I2C2STATbits.D_A == 0)) // Device address matched (read)
    {
        data_in[data_byte++] = I2C2RCV; //transfer data from RCV buffer
        I2C2TRN = dataout[out_byte++ ];

    } else if ((I2C2STATbits.R_W == 1) && (I2C2STATbits.D_A == 1) && (I2C2STATbits.ACKSTAT == 0)) {
        temp = I2C2RCV;
        I2C2TRN = dataout[out_byte++ ];
    }

    I2C2CONbits.SCLREL = 1;
    _SI2C2IF = 0; //clear I2C1 Slave interrupt flag 

}
