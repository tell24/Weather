
#include "data_gather.h"
#include "signal_processing.h"
#include <xc.h>
#include "utils.h"
#include <dsp.h>
#include <math.h>
#include <p33EP256GP502.h>

void get_wind_data() {
    passes = 0;
    tx_sequence = 0;
    accumulative_ws = 0;
    accumulative_bearing = 0;
    remote_data.peak_wind_speed = 0;
    remote_data.status = 0;
    tx_trig = 0;
    ws = 0;
    ns_zero = 0;
    sn_zero = 0;
    ew_zero = 0;
    we_zero = 0;
    requestdebug.gain[0] = 0;
    requestdebug.gain[1] = 0;
    requestdebug.gain[2] = 0;
    requestdebug.gain[3] = 0;

    requestdebug.zero[0] = 0;
    requestdebug.zero[1] = 0;
    requestdebug.zero[2] = 0;
    requestdebug.zero[3] = 0;

    //Start Timer 2
    LATBbits.LATB10 = 0;
    LATBbits.LATB11 = 0;
    //Start Timer 2
    TMR2 = 0;
    IFS0bits.T2IF = 0;
    IEC0bits.T2IE = 1; // Enable Timer 2 interrupt
    T2CONbits.TON = 1;
}

void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void) {
    ClrWdt(); // reset the watch dog counter to 0
    TMR2 = 0x0000;
    IFS0bits.T2IF = 0; // Reset Timer1 interrupt flag
    IFS0bits.DMA0IF = 0; //Clear the DMA interrupt flag bit
    IEC0bits.DMA0IE = 1; //Set the DMA interrupt enable bit
    switch (direction) {
        case 0:
            LATBbits.LATB14 = 0;
            LATBbits.LATB15 = 1;
            break;
        case 1:
            LATBbits.LATB14 = 1;
            LATBbits.LATB15 = 1;
            break;
        case 2:
            LATBbits.LATB14 = 0;
            LATBbits.LATB15 = 1;
            break;
        case 3:
            LATBbits.LATB14 = 1;
            LATBbits.LATB15 = 1;
            break;
    }
    LATBbits.LATB10 = 0;
    LATBbits.LATB11 = 0;
    LATBbits.LATB12 = 0;
    LATBbits.LATB13 = 0;
    delay_uS(500);
    IFS1bits.T4IF = 0;
    IEC1bits.T4IE = 1; // Enable Timer4 interrupt  
    T3CONbits.TON = 0;
    TMR2 = 0;
    TMR3 = 0;
    TMR4 = 0;
    int len_h = 0x3;
    int len_l = 0x11;

    switch (direction) {
        case 0:
            T4CONbits.TON = 1;
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            delay_uS(len_l);
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            delay_uS(len_l);
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            delay_uS(len_l);
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            delay_uS(len_l);
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            delay_uS(len_l);
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            delay_uS(len_l);
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            delay_uS(len_l);
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            break;
        case 1:
            T4CONbits.TON = 1;
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            delay_uS(len_l);
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            delay_uS(len_l);
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            delay_uS(len_l);
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            delay_uS(len_l);
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            delay_uS(len_l);
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            delay_uS(len_l);
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            delay_uS(len_l);
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            break;
        case 2:
            T4CONbits.TON = 1;
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            delay_uS(len_l);
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            delay_uS(len_l);
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            delay_uS(len_l);
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            delay_uS(len_l);
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            delay_uS(len_l);
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            delay_uS(len_l);
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            delay_uS(len_l);
            LATBbits.LATB10 = 1;
            delay_uS(len_h);
            LATBbits.LATB10 = 0;
            break;
        case 3:
            T4CONbits.TON = 1;
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            delay_uS(len_l);
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            delay_uS(len_l);
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            delay_uS(len_l);
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            delay_uS(len_l);
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            delay_uS(len_l);
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            delay_uS(len_l);
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            delay_uS(len_l);
            LATBbits.LATB12 = 1;
            delay_uS(len_h);
            LATBbits.LATB12 = 0;
            break;
    }

    IEC0bits.T2IE = 0; // Enable Timer1 interrupt 
    LATBbits.LATB7 = 0;
}

void __attribute__((interrupt, no_auto_psv)) _T4Interrupt(void) {
    T3CONbits.TON = 1;
    T4CONbits.TON = 0;
    IEC1bits.T4IE = 0; // Disable Timer4 interrupt
    IFS1bits.T4IF = 0;
}

void __attribute__((interrupt, no_auto_psv)) _DMA0Interrupt(void) {
    add_data(&bufferA[0]);

    _DMA0IF = 0; //Clear the DMA0 Interrupt Flag
}
