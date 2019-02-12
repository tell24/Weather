/* 
 * File:   main.c
 * Author: te
 *
 * Created on 12 December 2018, 14:31
 */


/*
 * 
 * Connections / pin configuration
 * 
 * WIND DIRECTION AND SPEED
 * Signal i/p       - AN0
 * Signal Enable    - RP10
 * Trigger Pulse    - RP11
 * Channel Select A - RP12
 * Channel Select B - RP13
 * 
 * TEMPERATURE AND HUMIDITY
 * DATA             - RB0
 * 
 * COMPASS
 * Clock            - ASCL1
 * Data             - ASDA1
 * 
 * COMUNICATION (nRF24L01)
 * MISO             - SDI / RP9
 * MOSI             - SDO1 / RP8
 * Clock            - SCK1 / RP7
 * Chip Enable      - RP15
 * CSN              = RP14
 * 
 */


#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "Globals.h"
#include "init.h"
#include "my_i2c.h"
#include <i2c.h>
#include "data_gather.h"
//#include "uart.h"
#include "utils.h"

// DSPIC33EP256GP502 Configuration Bit Settings
//

// _FOSCSEL(FNOSC_PRIPLL) // PLL enabled 
// _FOSC(OSCIOFNC_OFF & POSCMD_XT) // XT Osc 
// _FWDT(FWDTEN_OFF) // Disable Watchdog timer 

#pragma config FNOSC = PRIPLL       //Primary Osc w/PLL (XT+,HS+,EC+PLL)
#pragma config POSCMD = XT         //HS osc mode
#pragma config OSCIOFNC = OFF
#pragma config FWDTEN = ON
#pragma config ALTI2C2 = ON

request_data requestdata;
request_debug requestdebug;
remotedatapacket remote_data;

int bufferA[ARRAYSIZE] __attribute__((space(xmemory)));
// FIR Output Buffer
extern fractional FSignal[ARRAYSIZE] __attribute__((far));
extern fractional FSignal_1[ARRAYSIZE] __attribute__((far));
extern FIRStruct firfilter;
double signal[ARRAYSIZE] __attribute__((far));
double signal_old[ARRAYSIZE] __attribute__((far));
int int_signal[ARRAYSIZE] __attribute__((far));

byte measurement_type;
byte return_data;
byte start_measurement;
byte measure;

int samples;
int passes = 0;

double ws = 0, ns_zero = 0, sn_zero = 0, ew_zero = 0, we_zero = 0, ns_ref = 0, sn_ref = 0;

//IIRTransposedStruct BPFFilter;
void IIRTransposedInit(IIRTransposedStruct* filter);

fractional* IIRTransposed(int numSamps,
        fractional* dstSamps,
        fractional* srcSamps,
        IIRTransposedStruct* filter
        );

/*
 * 
 */
int main(int argc, char** argv) {
    init_board();
    i2c_init();
    while (1) {
        if (start_measurement) {
            start_measurement = false;
            get_wind_data();
        }
    };
    return (EXIT_SUCCESS);
}

