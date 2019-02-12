
#include <xc.h>
#include "Globals.h"
//#include "uart.h"
#include "signal_processing.h"


void init_board();
void InitAdc1(); // Initialize the A/D converter to convert Channel 5
void InitDma0(); // Initialise the DMA controller to buffer ADC data in conversion order
void InitTmr3(); // Initialise the Timer to generate sampling event to ADC @ 250Khz rate
void InitTmr2();
void InitTmr4();
int Get_TOF(double tof);

void init_board() {
    // Configure FRC to operate the device at 80MIPS
    // Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
    // Fosc= 8M*40/(2*2)=80Mhz for 10MHz input clock
    PLLFBD = 38; // M=40
    CLKDIVbits.PLLPOST = 0; // N1=2
    CLKDIVbits.PLLPRE = 0; // N2=2
    OSCTUN = 0; // Tune FRC oscillator, if FRC is used

    // Disable Watch Dog Timer
    RCONbits.SWDTEN = 0;

    // Disable Watch Dog Timer
    RCONbits.SWDTEN = 0;

    // Clock switching to incorporate PLL
    __builtin_write_OSCCONH(0x03); // Initiate Clock Switch to Primary
    // Oscillator with PLL (NOSC=0b011)
    __builtin_write_OSCCONL(0x01); // Start clock switching
    while (OSCCONbits.COSC != 0b011); // Wait for Clock switch to occur	

    // Wait for PLL to lock
    while (OSCCONbits.LOCK != 1) {
    };

    TRISBbits.TRISB6 = 0;
    TRISBbits.TRISB7 = 0;
    TRISBbits.TRISB10 = 0;
    TRISBbits.TRISB11 = 0;
    TRISBbits.TRISB12 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB15 = 0;
    LATBbits.LATB6 = 1;
    LATBbits.LATB10 = 0;
    LATBbits.LATB11 = 0;
    LATBbits.LATB12 = 0;
    LATBbits.LATB13 = 0;
    LATBbits.LATB14 = 0;
    LATBbits.LATB15 = 0;
    LATBbits.LATB7 = 0;

    ANSELBbits.ANSB0 = 0;
    TRISBbits.TRISB0 = 1;

    //   CfgUart1();
    Init_Filter();
    InitAdc1(); // Initialize the A/D converter to convert Channel 5
    InitDma0(); // Initialise the DMA controller to buffer ADC data in conversion order
    InitTmr3(); // Initialise the Timer to generate sampling event to ADC @ 250Khz rate
    InitTmr2();
    InitTmr4();

}

void InitAdc1() {
    AD1CON1bits.FORM = 1; // Data Output Format: Signed Fraction (Q15 format)
    AD1CON1bits.SSRC = 2; // Sample Clock Source: GP Timer starts conversion
    AD1CON1bits.ASAM = 1; // ADC Sample Control: Sampling begins immediately after conversion
    AD1CON1bits.AD12B = 1; // 12-bit ADC operation

    AD1CON2bits.CHPS = 0; // Converts CH0

    AD1CON3bits.ADRC = 0; // ADC Clock is derived from Systems Clock
    AD1CON3bits.ADCS = 3; // ADC Conversion Clock Tad=Tcy*(ADCS+1)= (1/40M)*4 = 100ns
    // ADC Conversion Time for 10-bit Tc=12*Tad = 1.2us 

    AD1CON1bits.ADDMABM = 1; // DMA buffers are built in conversion order mode
    AD1CON2bits.SMPI = 0; // SMPI must be 0
    AD1CON4bits.ADDMAEN = 1; // all results written in ADC1BUF0

    //AD1CHS0: A/D Input Select Register
    AD1CHS0bits.CH0SA = 0; // MUXA +ve input selection (AN0) for CH0
    AD1CHS0bits.CH0NA = 0; // MUXA -ve input selection (Vref-) for CH0

    IFS0bits.AD1IF = 0; // Clear the A/D interrupt flag bit
    IEC0bits.AD1IE = 0; // Do Not Enable A/D interrupt 
    AD1CON1bits.ADON = 1; // Turn on the A/D converter 


};

void InitDma0() {
    DMA0CONbits.AMODE = 0; // Configure DMA for Register indirect with post increment
    DMA0CONbits.MODE = 0; // Configure DMA for Continuous Ping-Pong mode

    DMA0PAD = (int) &ADC1BUF0;
    DMA0CNT = (ARRAYSIZE - 1);

    DMA0REQ = 13;

    DMA0STAL = (unsigned int) &bufferA;
    DMA0STAH = (unsigned int) &bufferA;

    IFS0bits.DMA0IF = 0; //Clear the DMA interrupt flag bit

    DMA0CONbits.CHEN = 1;

}; // Initialise the DMA controller to buffer ADC data in conversion order

void InitTmr2() {
    //trigger data gater interval
    T2CON = 0; // Timer reset
    IFS0bits.T2IF = 0; // Reset Timer1 interrupt flag
    IEC0bits.T2IE = 0; // Enable Timer1 interrupt
    TMR2 = 0x0000;
    T2CON |= 0b000000000110000;
    PR2 = 0x1800; // Timer1 period register = ?????
};

void InitTmr3() {
    //trigger  interval
    PR3 = SAMPPRD;
    IFS0bits.T3IF = 0;
    IEC0bits.T3IE = 0;
    IPC2bits.T3IP = 4;
};

void InitTmr4() {
    //wait mS to start of sampling
    T4CON = 0; // Timer reset
    IFS1bits.T4IF = 0; // Reset Timer4 interrupt flag
    IEC1bits.T4IE = 0; // Disable Timer4 interrupt
    IPC6bits.T4IP = 5;
    T4CON |= 0b000000000100000;
    PR4 = Get_TOF(775); // Timer4 period register = 800 uS
    TMR4 = 0x0000;
};

int Get_TOF(double tof) {
    // calculate delay to start sampling
    double FOSC = 40 * 1e6;
    double de = (tof * 1e-6);
    double clk = 1 / (FOSC / 64);
    double TOF_real = de / clk;
    int TOF = (int) TOF_real;
    return TOF;
}
