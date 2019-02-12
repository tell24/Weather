/* 
 * File:   Globals.h
 * Author: te
 *
 * Created on 12 December 2018, 14:32
 */
#include<xc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <i2c.h>
#include <dsp.h>
//#include "fir.h"
//#include "utils.h"


#ifndef GLOBALS_H
#define	GLOBALS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define NY 32


#define Fosc  80000000 
#define Fcy   (Fosc/2)
#define Fs     500000
#define SAMPPRD    (Fcy/Fs)-1

#define CHUNK 1024

#define ARRAYSIZE 1024
#define USDELAY 2000

#define BAUDRATE    115200
#define BRGVAL      ( (Fcy / BAUDRATE) / 16 ) - 1

#define I2C2_BRG   399

#define true 1
#define false 0


    typedef unsigned char byte;

    typedef struct peakArray {
        double arr[10][2];
        int points;
        char found;
    } peak_vals;

    typedef struct quadratics {
        double a;
        double b;
        double c;
    } abc_val;

    typedef struct remote_data_packet {
        int16_t status;
        int16_t wind_speed;
        int16_t peak_wind_speed;
        int16_t bearing;
        uint8_t checksum;
    } remotedatapacket;

    typedef struct data_packet_2 {
        uint16_t type;
        int16_t temp;
        int16_t hum;
        int16_t pressure;
        uint8_t checksum;
    } request_data;

    typedef struct data_packet_3 {
        double zero[4];
        double gain[4];
    } request_debug;

    extern request_data requestdata;

    extern request_debug requestdebug;

    extern remotedatapacket remote_data;

    extern abc_val Exp_formula_pos, Exp_formula_neg;

    extern peak_vals predicted;

    //DMA ADC Buffer
    extern int bufferA[ARRAYSIZE] __attribute__((space(xmemory)));
    
    // FIR Output Buffer
    extern fractional FSignal[ARRAYSIZE] __attribute__((far));
    extern fractional FSignal_1[ARRAYSIZE] __attribute__((far));
    extern FIRStruct firfilter;
    
    // working Buffers
    extern double signal[ARRAYSIZE] __attribute__((far));
    extern double signal_old[ARRAYSIZE] __attribute__((far));
    extern int int_signal[ARRAYSIZE] __attribute__((far));
    
// Filter Controls
    extern IIRTransposedStruct BPFFilter;
    extern void IIRTransposedInit(IIRTransposedStruct* filter);
    extern fractional* IIRTransposed(int numSamps,
            fractional* dstSamps,
            fractional* srcSamps,
            IIRTransposedStruct* filter
            );
        
    extern byte measurement_type;
    extern byte return_data;
    extern byte start_measurement;
    extern byte measure;

    extern int accumulative_bearing;
    extern int samples;
    extern int direction;
    extern int passes;
    extern int tx_sequence;
    extern int tx_trig;
    extern int direction;
    
    extern int16_t bearing;
    
    extern double ws, ns_zero, sn_zero, ew_zero, we_zero;
    extern double accumulative_ws;

#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALS_H */

