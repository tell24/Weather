/* 
 * File:   HardwareProfile.h
 * Author: terry
 *
 * Created on 03 July 2019, 15:28
 */

#ifndef HARDWAREPROFILE_H
#define	HARDWAREPROFILE_H

#ifdef	__cplusplus
extern "C" {
#endif


#include "Compiler.h"

    
// Clock frequency values
// These directly influence timed events using the Tick module.  They also are used for UART and SPI baud rate generation.
#define GetSystemClock()		(80000000ul)			// Hz
#define GetInstructionClock()	(GetSystemClock()/1)	// Normally GetSystemClock()/4 for PIC18, GetSystemClock()/2 for PIC24/dsPIC, and GetSystemClock()/1 for PIC32.  Might need changing if using Doze modes.
#define GetPeripheralClock()	(GetSystemClock()/1)	// Normally GetSystemClock()/4 for PIC18, GetSystemClock()/2 for PIC24/dsPIC, and GetSystemClock()/1 for PIC32.  Divisor may be different if using a PIC32 since it's configurable.

    
#define ENC_IN_SPI2

// UART configuration (not too important since we don't have a UART 
// connector attached normally, but needed to compile if the STACK_USE_UART 
// or STACK_USE_UART2TCP_BRIDGE features are enabled.
#define UARTTX_TRIS			(TRISFbits.TRISF3)
#define UARTRX_TRIS			(TRISFbits.TRISF2)
    
    
// ENC28J60 I/O pins
#if defined ENC_IN_SPI1
	#define ENC_CS_TRIS			(TRISDbits.TRISD14)
	#define ENC_CS_IO			(PORTDbits.RD14)
	//#define ENC_RST_TRIS		(TRISDbits.TRISD15)	// Not connected by default.  It is okay to leave this pin completely unconnected, in which case this macro should simply be left undefined.
	//#define ENC_RST_IO		(PORTDbits.RD15)

	// SPI SCK, SDI, SDO pins are automatically controlled by the 
	#define ENC_SPI_IF			(IFS0bits.SPI1RXIF)
	#define ENC_SSPBUF			(SPI1BUF)
	#define ENC_SPICON1			(SPI1CON)
	#define ENC_SPICON1bits		(SPI1CONbits)
	#define ENC_SPIBRG			(SPI1BRG)
	#define ENC_SPISTATbits		(SPI1STATbits)
#elif defined ENC_IN_SPI2
	#define ENC_CS_TRIS			(TRISGbits.TRISG9)
	#define ENC_CS_IO			(PORTGbits.RG9)
	//#define ENC_RST_TRIS		(TRISFbits.TRISF13)	// Not connected by default.  It is okay to leave this pin completely unconnected, in which case this macro should simply be left undefined.
	//#define ENC_RST_IO		(PORTFbits.RF13)

	// SPI SCK, SDI, SDO pins are automatically controlled by the 
	// PIC32 SPI module 
	#define ENC_SPI_IF			(IFS1bits.SPI2RXIF)
	#define ENC_SSPBUF			(SPI2BUF)
	#define ENC_SPICON1			(SPI2CON)
	#define ENC_SPISTATbits		(SPI2STATbits)
	#define ENC_SPICON1bits		(SPI2CONbits)
	#define ENC_SPIBRG			(SPI2BRG)
#endif

    
    
// LEDs
#define LED0_TRIS			(TRISDbits.TRISD5)	// Ref LED1
#define LED0_IO				(LATDbits.LATD5)
#define LED1_TRIS			(LED0_TRIS)	// Ref LED2
#define LED1_IO				(LED0_IO)
#define LED2_TRIS			(LED0_TRIS)	// Ref LED3
#define LED2_IO				(LED0_IO)
#define LED3_TRIS			(LED0_TRIS)			// No such LED
#define LED3_IO				(LED0_IO)
#define LED4_TRIS			(LED0_TRIS)			// No such LED
#define LED4_IO				(LED0_IO)
#define LED5_TRIS			(LED0_TRIS)			// No such LED
#define LED5_IO				(LED0_IO)
#define LED6_TRIS			(LED0_TRIS)			// No such LED
#define LED6_IO				(LED0_IO)
#define LED7_TRIS			(LED0_TRIS)			// No such LED
#define LED7_IO				(LED0_IO)
#define LED_GET()			((unsigned char)LATD & 0x07)
#define LED_PUT(a)			do{LATD = (LATD & 0xFFF8) | ((a)&0x07);}while(0)

    
// Momentary push buttons
#define BUTTON0_TRIS		(TRISDbits.TRISD6)	// Ref SW1
#define BUTTON0_IO			(PORTDbits.RD6)
#define BUTTON1_TRIS		(TRISDbits.TRISD6)	// Ref SW2
#define BUTTON1_IO			(PORTDbits.RD6)
#define BUTTON2_TRIS		(TRISDbits.TRISD6)	// Ref SW3
#define BUTTON2_IO			(PORTDbits.RD6)
#define BUTTON3_TRIS		(TRISDbits.TRISD6)	// No BUTTON3 on this board
#define BUTTON3_IO			(1)
    
    
// Select which UART the STACK_USE_UART and STACK_USE_UART2TCP_BRIDGE 
// options will use.  You can change these to U1BRG, U1MODE, etc. if you 
// want to use the UART1 module instead of UART2.
    
#define UBRG				U1BRG
#define UMODE				U1MODE
#define USTA				U1STA
#define BusyUART()			BusyUART1()
#define CloseUART()			CloseUART1()
#define ConfigIntUART(a)	ConfigIntUART1(a)
#define DataRdyUART()		DataRdyUART1()
#define OpenUART(a,b,c)		OpenUART1(a,b,c)
#define ReadUART()			ReadUART1()
#define WriteUART(a)		WriteUART1(a)
#define getsUART(a,b,c)		getsUART1(a,b,c)
#define putsUART(a)			putrsUART1(a)
#define getcUART()			getcUART1()
#define putcUART(a)			do{while(BusyUART()); WriteUART(a); while(BusyUART()); }while(0)
#define putrsUART(a)		putrsUART1(a)

    
    
/*****************************************************************************
 * Section:  RTCC default time and date
 *****************************************************************************/
#define RTCC_DEFAULT_DAY        11      // 11th
#define RTCC_DEFAULT_MONTH      11      // November
#define RTCC_DEFAULT_YEAR       11      // 2011
#define RTCC_DEFAULT_WEEKDAY    01      // Monday
#define RTCC_DEFAULT_HOUR       10      // 10:10:01
#define RTCC_DEFAULT_MINUTE     10
#define RTCC_DEFAULT_SECOND     01

#ifdef	__cplusplus
}
#endif

#endif	/* HARDWAREPROFILE_H */

