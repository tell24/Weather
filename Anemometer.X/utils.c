#include "utils.h"
#include "Globals.h" 


void delay_uS( int delay) {
    int i;
    for (i = 0; i < delay; i++) {
        __asm__ volatile ("repeat #39");
        __asm__ volatile ("nop");
    }
}


void delay_mS( int delay) {
    int i;
    for (i = 0; i < delay; i++) {
        delay_uS( 1000);
    }
}

uint8_t Sum(uint8_t *message, int nBytes) {
    uint8_t sum = 0;
    while (nBytes-- > 0) {
        sum += *(message++);
    }
    return (sum);
} /* Sum() */
