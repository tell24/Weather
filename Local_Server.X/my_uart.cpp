/* 
 * File:   my_uart.cpp
 * Author: te
 * 
 * Created on 22 December 2018, 15:34
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <xc.h>
#include "my_uart.h"

my_uart::my_uart() {
}

my_uart::my_uart(const my_uart& orig) {
}

my_uart::~my_uart() {
}

void my_uart::begin(uint16_t baud) {
 //  U2BRG = ((4000000 / 9600) / 16) - 1; // baud 9600
   U1MODEbits.BRGH = 0;                // Baud Rate = 9600
    U1BRG = 259;
     
    U1MODEbits.SIDL = 0;                // Continue operation in SLEEP mode
     
    U1MODEbits.IREN = 0;                // IrDA is disabled
     
    U1MODEbits.RTSMD = 0;               // U1RTS pin is in Flow Control mode
     
    U1MODEbits.UEN = 0b00;              // U1TX, U1RX are enabled
     
    U1MODEbits.WAKE = 1;                // Wake-up enabled
     
    U1MODEbits.LPBACK = 0;              // Loopback mode is disabled
     
    U1MODEbits.RXINV = 0;               // U1RX IDLE state is '1'
     
    U1MODEbits.PDSEL = 0b00;            // 8-bit data, no parity
     
    U1MODEbits.STSEL = 0;               // 1 stop bit
     
    U1STAbits.UTXINV = 0;               // U1TX IDLE state is '1'
     
    U1MODEbits.ON = 1;                  // UART1 is enabled
     
    U1STAbits.URXEN = 1;                // UART1 receiver is enabled
     
    U1STAbits.UTXEN = 1;                // UART1 transmitter is enabled
}

void my_uart::print(char data) {     
     U1STAbits.UTXEN = 1;                // Make sure transmitter is enabled
    // while(CTS)                       // Optional CTS use
    while(U1STAbits.UTXBF);             // Wait while buffer is full
    U1TXREG = data;                        // Transmit character

}

void my_uart::print(char *str) {        
   while(*str)
    {
       print(*str);           // Transmit one character
        str++;                       // Go to next character in string
    }
}

void my_uart::println(char *str) {    
    print(str);
    print('\r');
    print('\n');
}

void my_uart::print(int num) {
    char str[10];
    sprintf(str, "%d", num);   
    print(str);
}

void my_uart::println(int num) {    
   char str[10];
    sprintf(str, "%d", num);   
    print(str);
    print('\r');
    print('\n');
}

extern my_uart Serial;