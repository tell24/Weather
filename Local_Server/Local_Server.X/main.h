/*********************************************************************
 *
 *                  Headers for TCPIP Demo App
 *
 *********************************************************************
 * FileName:        MainDemo.h
 * Dependencies:    Compiler.h
 * Processor:       PIC18, PIC24F, PIC24H, dsPIC30F, dsPIC33F, PIC32
 * Compiler:        Microchip C32 v1.05 or higher
 *					Microchip C30 v3.12 or higher
 *					Microchip C18 v3.30 or higher
 *					HI-TECH PICC-18 PRO 9.63PL2 or higher
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright (C) 2002-2010 Microchip Technology Inc.  All rights
 * reserved.
 *
 * Microchip licenses to you the right to use, modify, copy, and
 * distribute:
 * (i)  the Software when embedded on a Microchip microcontroller or
 *      digital signal controller product ("Device") which is
 *      integrated into Licensee's product; or
 * (ii) ONLY the Software driver source files ENC28J60.c, ENC28J60.h,
 *		ENCX24J600.c and ENCX24J600.h ported to a non-Microchip device
 *		used in conjunction with a Microchip ethernet controller for
 *		the sole purpose of interfacing with the ethernet controller.
 *
 * You should refer to the license agreement accompanying this
 * Software for additional information regarding your rights and
 * obligations.
 *
 * THE SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT
 * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 * LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * MICROCHIP BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF
 * PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
 * BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE
 * THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER
 * SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF CONTRACT, TORT
 * (INCLUDING NEGLIGENCE), BREACH OF WARRANTY, OR OTHERWISE.
 *
 *
 * Author               Date    Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * E. Wood				4/26/08 Copied from MainDemo.c
 ********************************************************************/
#ifndef _MAIN_H
#define _MAIN_H

#define BAUD_RATE       (19200)		// bps
#define SaveAppConfig(a)
#define RAD 57.296

#define DO_NOTHING              0 
#define GET_INCOMMING           1
#define GET_TIME                2
#define SET_ALARM               3
#define SET_TIME                4
#define READ_INSIDE_DATA        5
#define READ_OUTSIDE_DATA       6
#define UPLOAD_CURRENT          7
#define UPLOAD_HISTORY          8
#define STOP_SERVER             9
#define STARTUP                 10
#define UPDATE_RTCC             11 

#define CURRENT_DATA   1
#define HISTORY_DATA   2
#define GET_REMOTE     3

#define mRTCCBCD2Dec(BCD)   (((BCD>>4)*10)+(BCD & 0x0f))    
#define mRTCCDec2BCD(Dec)  ((Dec/10)<<4)|(Dec % 10)

#define HOUR_OFFSET  1920
// Define a header structure for validating the AppConfig data structure in EEPROM/Flash

typedef struct {
    unsigned short wConfigurationLength; // Number of bytes saved in EEPROM/Flash (sizeof(APP_CONFIG))
    unsigned short wOriginalChecksum; // Checksum of the original AppConfig defaults as loaded from ROM (to detect when to wipe the EEPROM/Flash record of AppConfig due to a stack change, such as when switching from Ethernet to Wi-Fi)
    unsigned short wCurrentChecksum; // Checksum of the current EEPROM/Flash data.  This protects against using corrupt values if power failure occurs while writing them and helps detect coding errors in which some other task writes to the EEPROM in the AppConfig area.
} NVM_VALIDATION_STRUCT;

typedef struct Date_Time {
    DWORD d;
    DWORD t;
} DateTime;

typedef struct RTCC_Date_Time {
    rtccTime t;
    rtccDate d;
} RTCCDateTime;

typedef struct Temp_Hum {
    double t;
    double h;
} TempHum;

typedef struct data_packet {
    signed short temp;
    signed short hum;
    unsigned short wind_speed;
    unsigned short peak_wind_speed;
    unsigned short bearing;
    signed short rain;
    int32_t      rssi;
    signed short status;
} remotedata;

typedef struct data_packet1 {
    signed short out_temp;
    signed short in_temp;
    signed short out_hum;
    signed short in_hum;
    signed short wind_speed;
    signed short peak_wind_speed;
    signed short bearing;
    signed short pressure;
    signed short rainfall;
    signed short rainfall_rate;
    DWORD timestamp;
} current;


typedef struct data_packet2 {
    signed short out_temp_H;
    signed short out_temp_L;
    signed short in_temp_H;
    signed short in_temp_L;
    signed short out_hum_H;
    signed short out_hum_L;
    signed short in_hum_H;
    signed short in_hum_L;
    signed short wind_speed;
    signed short peak_wind_speed;
    signed short bearing;
    signed short pressure_H;
    signed short pressure_L;
    signed short rainfall;
    DWORD timestamp;
} history_packet;

extern RTCCDateTime DataTime;
extern remotedata outsidedata __attribute__((far));
extern current WEB_data_0 __attribute__((far));
extern current ThisHour[60] __attribute__((far));
extern history_packet History __attribute__((far));


extern TempHum inside, outside;
extern unsigned short pressure;

extern BYTE AN0String[8];
extern BYTE process_item;
extern 
RTCCDateTime now;


_Bool Is_DST(DWORD time);
RTCCDateTime update_clock();
uint32_t unixtime(RTCCDateTime dt);

#if defined(FILL_HOUR_DATA)
   void fill_hour_data();
#endif
#if defined(STACK_USE_MY_UART)
//
void my_uart_begin();
void my_uart_print(char data);
void my_uart_print_str(char *str);
void my_uart_println_str(char *str);
void my_uart_println_int(int i);
void my_uart_print_int(int i);
void my_uart_println_double(double i);
void my_uart_print_HEX(uint32_t hex);

#endif

void DoUARTConfig(void);
 


#define SECONDS_FROM_1970_TO_2000 946684800
    uint16_t date2days(uint16_t y, uint8_t m, uint8_t d);
    uint32_t time2long(uint16_t days, uint8_t h, uint8_t m, uint8_t s);
    uint32_t unixtime(RTCCDateTime tim);


#endif // _MAIN_H
