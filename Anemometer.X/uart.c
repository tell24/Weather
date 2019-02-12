#include "uart.h"
#include "compiler.h"
#include <stdio.h>
#include <stdlib.h>
#include <PPS.h>

void CfgUart1(void) {
    //Configuration for UART1
    U1MODEbits.STSEL = 0; // 1-Stop bit
    U1MODEbits.PDSEL = 0; // No Parity, 8-Data bits
    U1MODEbits.ABAUD = 0; // Auto-Baud disabled
    U1MODEbits.BRGH = 0; // Standard-Speed mode
    U1BRG = BRGVAL;
    U1STAbits.UTXISEL0 = 0; // Interrupt after one TX character is transmitted
    U1STAbits.UTXISEL1 = 0;
    IEC0bits.U1TXIE = 0; // Enable UART TX interrupt
    U1MODEbits.UARTEN = 1; // Enable UART
    U1STAbits.UTXEN = 1; // Enable UART TX
    PPSOutput(OUT_FN_PPS_U1TX, OUT_PIN_PPS_RP36);
}

void Uart_PrintChr(unsigned char SendDat) {
    U1TXREG = SendDat;
    while (IFS0bits.U1TXIF == 0);
    IFS0bits.U1TXIF = 0;
}

void Uart_PrintStr(const char *str) {
    while (*str) {
        Uart_PrintChr((unsigned char) *str);
        str++;
    }
}

void Uart_println_double(double val) {
    char str[20];
    sprintf(str, "%0.12f", val);
    Uart_PrintStr(str);
    Uart_PrintStr("\r\n");
}

void Uart_print_double(double val) {
    char str[20];
    sprintf(str, "%0.12f", val);
    Uart_PrintStr(str);
    Uart_PrintStr("  ,  ");
}

void Uart_print_int(int val) {
    char str[10];
    sprintf(str, "%d", val);
    Uart_PrintStr(str);
    Uart_PrintStr("  ,  ");
}

void Uart_println_int(int val) {
    char str[10];
    sprintf(str, "%d", val);
    Uart_PrintStr(str);
    Uart_PrintStr("\r\n");
}