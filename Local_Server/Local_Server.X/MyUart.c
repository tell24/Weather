// MyUart Source



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "TCPIP Stack/TCPIP.h"

void my_uart_begin() {
    U1MODEbits.BRGH = 0; // Baud Rate = 9600
    //  U1BRG = 259;
    U1BRG = (uint8_t) (((GetSystemClock() / 4) / 19200) / 16) - 1; // baud 9600
    U1MODEbits.SIDL = 0; // Continue operation in SLEEP mode
    U1MODEbits.IREN = 0; // IrDA is disabled
    U1MODEbits.RTSMD = 0; // U1RTS pin is in Flow Control mode
    U1MODEbits.UEN = 0b00; // U1TX, U1RX are enabled
    U1MODEbits.WAKE = 1; // Wake-up enabled
    U1MODEbits.LPBACK = 0; // Loopback mode is disabled
    U1MODEbits.RXINV = 0; // U1RX IDLE state is '1'
    U1MODEbits.PDSEL = 0b00; // 8-bit data, no parity
    U1MODEbits.STSEL = 0; // 1 stop bit
    U1STAbits.UTXINV = 0; // U1TX IDLE state is '1'
    U1MODEbits.ON = 1; // UART1 is enabled
    U1STAbits.URXEN = 0; // UART1 receiver is enabled
    U1STAbits.UTXEN = 1; // UART1 transmitter is enabled
}

void my_uart_print_str(char *str) {
    while (*str) {
        my_uart_print(*str); // Transmit one character
        str++; // Go to next character in string
    }
}


void my_uart_println_str(char *str) {
    while (*str) {
        my_uart_print(*str); // Transmit one character
        str++; // Go to next character in string
    }
    my_uart_print('\r');
    my_uart_print('\n');
}

void my_uart_println_int(int i) {
    char buf[10];
    sprintf(buf, " = %d",i);
my_uart_println_str(buf); // Transmit one character
}

void my_uart_print(char data) {
    U1STAbits.UTXEN = 1; // Make sure transmitter is enabled
    // while(CTS)    

    while (U1STAbits.UTXBF); // Wait while buffer is full

    U1TXREG = data; // Transmit character// Optional CTS use

}

