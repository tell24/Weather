/*********************************************************************
 *
 *  Main Application Entry Point and TCP/IP Stack Demo
 *  Module for Microchip TCP/IP Stack
 *   -Demonstrates how to call and use the Microchip TCP/IP stack
 *   -Reference: Microchip TCP/IP Stack Help (TCPIP Stack Help.chm)1150

 *
 *********************************************************************
 * FileName:        Main.c
 * Dependencies:    TCPIP.h
 * Processor:       PIC18, PIC24F, PIC24H, dsPIC30F, dsPIC33F, PIC32
 * Compiler:        Microchip C32 v1.11b or higher
 *                  Microchip C30 v3.24 or higher
 *                  Microchip C18 v3.36 or higher
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
 *      ENCX24J600.c and ENCX24J600.h ported to a non-Microchip device
 *      used in conjunction with a Microchip ethernet controller for
 *      the sole purpose of interfacing with the ethernet controller.
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
 * File Description:
 * Change History:
 * Rev   Description
 * ----  -----------------------------------------
 * 1.0   Initial release
 * V5.36 ---- STACK_USE_MPFS support has been removed 
 ********************************************************************/
/*
 * This macro uniquely defines this file as the main entry point.
 * There should only be one such definition in the entire project,
 * and this file must define the AppConfig variable as described below.
 */
#define THIS_IS_STACK_APPLICATION


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>
#include <plib.h>
#include <math.h>
#include <peripheral/rtcc.h>
#include "../Include/TCPIP Stack/UART.h"
#include "BMP180.h"
#include "HTU21D.h"
#include "ST7735.h"
#include "eeprom.h"
// Include all headers for any enabled TCPIP Stack functions
#include "TCPIP Stack/TCPIP.h"

#if defined(STACK_USE_MY_UART)
//#include "MyUart.h"
#undef STACK_USE_UART
#endif

// Include functions specific to this stack application
#include "main.h"

// Used for Wi-Fi assertions
#define WF_MODULE_NUMBER   WF_MODULE_MAIN_DEMO

#define SERVER_PORT	80

#pragma config FPLLMUL  = MUL_20        // PLL Multiplier
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider
#pragma config FPLLODIV = DIV_1         // PLL Output Divider
#pragma config FPBDIV   = DIV_4         // Peripheral Clock divisor
#pragma config FWDTEN   = OFF           // Watchdog Timer
#pragma config WDTPS    = PS1           // Watchdog Timer Postscale
#pragma config FCKSM    = CSDCMD        // Clock Switching & Fail Safe Clock Monitor
#pragma config OSCIOFNC = OFF           // CLKO Enable
#pragma config POSCMOD  = XT            // Primary Oscillator
#pragma config IESO     = OFF           // Internal/External Switch-over
#pragma config FSOSCEN  = ON           // Secondary Oscillator Enable (KLO was off)
#pragma config FNOSC    = PRIPLL        // Oscillator Selection
#pragma config CP       = OFF           // Code Protect
#pragma config BWP      = OFF           // Boot Flash Write Protect
#pragma config PWP      = OFF           // Program Flash Write Protect
#pragma config ICESEL   = ICS_PGx1      // ICE/ICD Comm Channel Select
#pragma config DEBUG    = OFF            // Background Debugger Enable


//#define NO_DATA = 0

// Declare AppConfig structure and some other supporting stack variables
APP_CONFIG AppConfig;
static unsigned short wOriginalAppConfigChecksum; // Checksum of the ROM defaults for AppConfig
BYTE AN0String[8];


static ROM BYTE SerializedMACAddress[6] = {MY_DEFAULT_MAC_BYTE1, MY_DEFAULT_MAC_BYTE2, MY_DEFAULT_MAC_BYTE3, MY_DEFAULT_MAC_BYTE4, MY_DEFAULT_MAC_BYTE5, MY_DEFAULT_MAC_BYTE6};

const char * Day_array[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
const char * Month_array[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", "Jan"};
uint8_t month[] = {0, 30, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
remotedata outsidedata;
current WEB_data_0;
//RTCCDateTime DataTime;
current ThisHour[60];
history_packet History;

int TCP_status;
DWORD post_data_size;
TempHum inside, outside;
unsigned short pressure;
BYTE process_item;
uint8_t old_min;
volatile uint8_t ref_day;
bool reset_clock = false;


// Private helper functions.
// These may or may not be present in all applications.
static void InitAppConfig(void);
static void InitializeBoard(void);
static void ProcessIO(void);

static void DisplayIPValue(IP_ADDR IPVal);
void TCPServer(int *TCP_status, DWORD *post_data_size, MPFS_HANDLE *f);
BYTE TCPClient(BYTE type);
static DateTime Set_RTCC();
//static void SetAlarm(DateTime alarm);
static void read_inside_data();
static TempHum get_Humidity_Temperature();
static double i2c_Pressure_read();
static _Bool save_data(RTCCDateTime tim);
RTCCDateTime now;

#if defined(__C32__)

void _general_exception_handler(unsigned cause, unsigned status) {
    Nop();
    Nop();
}
#endif

double i2c_Pressure_read() {
    // pressure BMP180
    char status;
    double T = 0, P = 0;
    status = BMP180_startTemperature();
    if (status != 0) {
        DelayMs(status);
        status = BMP180_getTemperature(&T);

        if (status != 0) {
            status = BMP180_startPressure(3);
            if (status != 0) {
                DelayMs(status);
                status = BMP180_getPressure(&P, &T);
                if (status != 0)
                    return BMP180_sealevel(P, ALTITUDE);
            }
        }
    }
    return 0;
}

TempHum get_Humidity_Temperature() {
    TempHum res;
    res.t = HTU21DF_readTemperature();
    res.h = HTU21DF_readHumidity();
    if(res.h > 95){
    if(res.h <97) res.h =  95;
    else if(res.h<98) res.h =  96;
    else if(res.h<103) res.h =  97;
    else if(res.h<111) res.h =  98;
    else res.h =  99;
    }
    return res;
}

static void read_inside_data() {

    inside = get_Humidity_Temperature();
    pressure = (unsigned short) i2c_Pressure_read();
}

static _Bool save_data(RTCCDateTime tim) {

    /*     
    Sample to read / write data to eeprom 
    uint16_t eeAddress = 0;
    uint8_t data[32] ;
    uint8_t numBytes = 8;
    memcpy(data1, &STRUCTURE, numBytes);
    write_EEPROM( eeAddress, data,  numBytes);
    read_EEPROM(eeAddress, &data1, numBytes);
     */

#if defined(SAVE_DATA)
    uint16_t eeAddress = 0;
    uint8_t data[32];
    uint8_t data1[32];
    uint8_t numBytes = 0;
    uint8_t min = mRTCCBCD2Dec(tim.t.min);
    WEB_data_0.timestamp = unixtime(tim);
    // Save min data to eeprom
    if (min != 0) {
        numBytes = 24;
        eeAddress = min * 32;
        memcpy(data, &WEB_data_0, numBytes);
        write_EEPROM(min * 32, data, numBytes);
        ThisHour[min] = WEB_data_0;

    } else {
        int i = 0;
        current av;
        int itl = 100, ith = -100, otl = 100, oth = -100, ihl = 100, ihh = 0, ohl = 100, ohh = 0, pl = 1100, ph = 100, w = 0, pw = 0, b = 0, r = 0;
        for (i = 0; i < 60; i++) {
            av = ThisHour[i];
            if (av.in_temp > ith)ith = av.in_temp;
            if (av.in_temp < itl)itl = av.in_temp;
            if (av.in_hum > ihh)ihh = av.in_hum;
            if (av.in_hum < ihl)ihl = av.in_hum;
            if (av.out_temp > oth)oth = av.out_temp;
            if (av.out_temp < otl)otl = av.out_temp;
            if (av.out_hum > ohh)ohh = av.out_hum;
            if (av.out_hum < ohl)ohl = av.out_hum;
            if (av.pressure > ph)ph = av.pressure;
            if (av.pressure < pl)pl = av.pressure;
            if (av.peak_wind_speed > pw)pw = av.peak_wind_speed;
            w += av.wind_speed;
            b += av.bearing;
            r += av.rainfall;
        }
        History.in_temp_H = ith;
        History.in_temp_L = itl;
        History.out_temp_H = oth;
        History.out_temp_L = otl;
        History.in_hum_H = ihh;
        History.in_hum_L = ihl;
        History.out_hum_H = ohh;
        History.out_hum_L = ohl;
        History.pressure_H = ph;
        History.pressure_L = pl;
        History.wind_speed = pw;
        History.peak_wind_speed = (signed short) (w / 60);
        History.bearing = (signed short) (b / 60);
        History.rainfall = (signed short) (r / 60);
        History.timestamp = WEB_data_0.timestamp;

        numBytes = 24;
        eeAddress = min * 32;
        memcpy(data, &WEB_data_0, numBytes);
        write_EEPROM(eeAddress, data, numBytes);
        MIN_WRITE_DELAY;
        ThisHour[min] = WEB_data_0;
        numBytes = 32;
        eeAddress = HOUR_OFFSET + (mRTCCBCD2Dec(tim.d.mday) * 32 * 24) +(mRTCCBCD2Dec(tim.t.hour) * 32);
        memcpy(data, &History, numBytes);
        write_EEPROM(eeAddress, data, numBytes);
        MIN_WRITE_DELAY;
        //        read_EEPROM(min * 32, &data, 24) ;
        //        MIN_WRITE_DELAY;
        //        read_EEPROM(eeAddress, &data1, 32) ;
        //        MIN_WRITE_DELAY;
    }

#endif
    return true;
}

DateTime Set_RTCC() {
    DateTime d_t;
    rtccTime tim;
    rtccDate dt;
    struct tm *mytime;
    DWORD time = SNTPGetUTCSeconds();
    if (time > 100) {
        char buf[128];
        mytime = localtime(&time);
        strftime(buf, 128, "%H:%M:%S on the %d-%m-%Y\n", mytime);
        int cc = 0;

#if defined(STACK_USE_MY_UART)     
        my_uart_print_str("Clock time  ");
        do {
            my_uart_print((char) buf[cc]);
            if (buf[cc] == '\n') break;
            cc++;
        } while (cc < 128);
#endif

        uint32_t ts = (mRTCCDec2BCD(mytime->tm_hour));
        ts = ts << 8 | (mRTCCDec2BCD(mytime->tm_min));
        ts = ts << 8 | (mRTCCDec2BCD(mytime->tm_sec));
        ts = ts << 8;
        uint32_t ds = (mRTCCDec2BCD(mytime->tm_year));
        ds = ds << 8 | (mRTCCDec2BCD(mytime->tm_mon));
        ds = ds << 8 | (mRTCCDec2BCD(mytime->tm_mday));
        ds = ds << 8 | (mRTCCDec2BCD(mytime->tm_wday));

        SYSKEY = 0xaa996655; // write first unlock key to SYSKEY
        SYSKEY = 0x556699aa; // write second unlock key to SYSKEY
        RTCCONSET = 0x8; // set RTCWREN in RTCCONSET
        RTCTIME = ts; // safe to update time to 16 hr, 15 min, 33 sec
        RTCDATE = ds; // update the date to Friday 27 Oct 2006
        IEC1CLR = 0x00008000; // disable RTCC interrupts
        RTCCONSET = 0x8000; // turn on the RTCC
        RTCCONCLR = 0x8; // set RTCWREN in RTCCONSET  
        while (!(RTCCON & 0x40)); // wait for clock to be turned on  

        tim.l = RtccGetTime();
        dt.l = RtccGetDate();
        mytime->tm_hour = mRTCCBCD2Dec(tim.hour);
        mytime->tm_min = mRTCCBCD2Dec(tim.min);
        mytime->tm_sec = mRTCCBCD2Dec(tim.sec);
        mytime->tm_mday = mRTCCBCD2Dec(dt.mday);
        mytime->tm_mon = mRTCCBCD2Dec(dt.mon);
        mytime->tm_year = mRTCCBCD2Dec(dt.year);
        mytime->tm_wday = mRTCCBCD2Dec(dt.wday);

        d_t.t = tim.l;
        d_t.d = dt.l;

        return d_t;

    }
    d_t.d = 0;
    d_t.t = 0;
    now.t = tim;
    now.d = dt;
    return d_t;
}

_Bool Is_DST(struct tm newtime) {
    if ((newtime.tm_mon > 3) && (newtime.tm_mon < 10)) {
        return true;
    }
    if (newtime.tm_mon == 3) {
        if (newtime.tm_wday == 0) {
            if ((newtime.tm_mday + (6 - newtime.tm_wday)) >= 31) {
                if (newtime.tm_hour >= 1) {
                    return true;
                } else
                    return false;
            } else {
                return false;
            }
        } else {
            if ((newtime.tm_mday + (6 - newtime.tm_wday)) < 31)
                return false;
        }
    }

    if (newtime.tm_mon == 10) {
        if (newtime.tm_wday == 0) {
            if ((newtime.tm_mday + (6 - newtime.tm_wday)) >= 31) {
                if (newtime.tm_hour > 1) {
                    return false;
                } else
                    return true;
            } else
                return true;
        } else {
            if ((newtime.tm_mday + (6 - newtime.tm_wday)) < 31) {
                return true;
            } else
                return false;
        }
    }
    return false;
}

_Bool Is_It_Time() {
    uint8_t new_min;
    rtccTime tm;
    tm.l = RtccGetTime();
    new_min = mRTCCBCD2Dec(tm.min);
    if (old_min != new_min) {

        old_min = new_min;
        return true;
    }
    return false;
}

RTCCDateTime update_clock() {
    RTCCDateTime clockTime;
    uint8_t min, hour, day, mon, wday;
    struct tm t;
    rtccTime tm;
    rtccDate dt;
    tm.l = RtccGetTime();
    dt.l = RtccGetDate();
    hour = mRTCCBCD2Dec(tm.hour);
    min = mRTCCBCD2Dec(tm.min);
    day = mRTCCBCD2Dec(dt.mday);
    mon = mRTCCBCD2Dec(dt.mon) + 1;
    wday = mRTCCBCD2Dec(dt.wday);

    if (ref_day != day) {
#if defined(STACK_USE_MY_UART)
        my_uart_println_str("reset ");
#endif
        reset_clock = true;
        ref_day = day;
    }

    t.tm_hour = hour;
    t.tm_min = min;
    t.tm_sec = 0;
    t.tm_mday = day;
    t.tm_mon = mon;
    t.tm_wday = wday;

    if (Is_DST(t)) {
        hour++;
        if (hour == 24) {
            day++;
            wday++;
            hour = 0;
            if (day > month[mon]) {
                mon++;
                day = 1;
            }
        }
    }
    DWORD ST7735_COLOUR;
    if ((hour < 8) || (hour > 22)) {
        ST7735_COLOUR = ST7735_NIGHT_TIME;
    } else {
        ST7735_COLOUR = ST7735_DAY_TIME;

    }
    char buf[10];
    if (hour > 12) hour -= 12;
    if (hour == 0) hour = 12;
    if (hour < 10)
        sprintf(buf, " %1d:%02d", hour, min);
    else
        sprintf(buf, "%2d:%02d", hour, min);

    drawtext(4, 0, buf, ST7735_COLOUR, ST7735_BLACK, 4);

    if (day < 10)
        sprintf(buf, "%s  %1d %s", Day_array[wday], day, Month_array[mon]);
    else
        sprintf(buf, "%s %2d %s", Day_array[wday], day, Month_array[mon]);

    drawtext(0, 40, buf, ST7735_COLOUR, ST7735_BLACK, 2);
    outside.t = (double) outsidedata.temp / 100;
    outside.h = (double) outsidedata.hum / 100;

    drawtext(40, 72, "Inside", ST7735_COLOUR, ST7735_BLACK, 1);
    if (inside.t <= -10) sprintf(buf, "%3.1f%s", inside.t, "C ");
    else if (inside.t < 0)
        sprintf(buf, "%s%3.1f%s", " ", inside.t, "C ");
    else if (inside.t < 10)
        sprintf(buf, "%s%3.1f%s", "  ", inside.t, "C ");
    else
        sprintf(buf, "%s%3.1f%s", " ", inside.t, "C ");
    drawtext(0, 88, buf, ST7735_COLOUR, ST7735_BLACK, 2);
    if (inside.h > 99)inside.h = 99;
    sprintf(buf, "%2.0f%s", inside.h, "%");
    drawtext(88, 88, buf, ST7735_COLOUR, ST7735_BLACK, 2);
    drawtext(40, 144, "Outside", ST7735_COLOUR, ST7735_BLACK, 1);

    if (outside.t <= -10) sprintf(buf, "%3.1f%s", outside.t, "C ");
    else if (outside.t < 0)
        sprintf(buf, "%s%3.1f%s", " ", outside.t, "C ");
    else if (outside.t < 10)
        sprintf(buf, "%s%3.1f%s", "  ", outside.t, "C ");
    else
        sprintf(buf, "%s%3.1f%s", " ", outside.t, "C ");

    drawtext(0, 120, buf, ST7735_COLOUR, ST7735_BLACK, 2);
    if (outside.h > 99)outside.h = 99;
    sprintf(buf, "%2.0f%s", outside.h, "%");
    drawtext(88, 120, buf, ST7735_COLOUR, ST7735_BLACK, 2);

    if (outsidedata.rssi == 0) {
        drawFastVLine(120, 150, 3, ST7735_BLACK);
        drawFastVLine(123, 147, 6, ST7735_BLACK);
        drawFastVLine(126, 144, 9, ST7735_BLACK);
    } else if (outsidedata.rssi < -80) {
        drawFastVLine(120, 150, 3, ST7735_COLOUR);
        drawFastVLine(123, 147, 6, ST7735_BLACK);
        drawFastVLine(126, 144, 9, ST7735_BLACK);
    } else if (outsidedata.rssi < -70) {
        drawFastVLine(120, 150, 3, ST7735_COLOUR);
        drawFastVLine(123, 147, 6, ST7735_COLOUR);
        drawFastVLine(126, 144, 9, ST7735_BLACK);
    } else {
        drawFastVLine(120, 150, 3, ST7735_COLOUR);
        drawFastVLine(123, 147, 6, ST7735_COLOUR);
        drawFastVLine(126, 144, 9, ST7735_COLOUR);
    }


    clockTime.d = dt;
    clockTime.t = tm;
    return clockTime;
}



//
// Main application entry point.
//

int main(void) {
    static DWORD t = 0;
    static DWORD dwLastIP = 0;

    DateTime t_d;
    //   process_item = GET_INCOMMING;
    //    process_item  = DO_NOTHING;
    //process_item = STARTUP;

    process_item = SET_TIME;

    // Initialize application specific hardware
    InitializeBoard();


#if defined(STACK_USE_MY_UART)
    my_uart_println_str("InitializeBoard()");
#endif

    if (!BMP180_begin()) {

#if defined(STACK_USE_MY_UART)
        my_uart_println_str("Couldn't find BMP180!");
#endif
        while (1);
    }

    DelayMs(100);

    if (!HTU21DF_begin()) {

#if defined(STACK_USE_MY_UART)
        my_uart_println_str("Couldn't find HTU21DF!");
#endif
        while (1);
    }

    read_inside_data();

#if defined(STACK_USE_MY_UART)
    my_uart_println_int(pressure);
    my_uart_println_double(inside.t);
    my_uart_println_double(inside.h);
#endif

    // Initialize stack-related hardware components that may be 
    // required by the UART configuration routines
    TickInit();
#if defined(STACK_USE_MPFS2)
    MPFSInit();
#endif

    // Initialize Stack and application related NV variables into AppConfig.
    InitAppConfig();

    // Initialize core stack layers (MAC, ARP, TCP, UDP) and
    // application modules (HTTP, SNMP, etc.)
    StackInit();

    post_data_size = 0;
    TCP_status = 0;
    int ret;
    int nl = 0;
    MPFS_HANDLE f;
    DWORD hFatID;
    DWORD reg;
    BYTE status = 0;


    while (1) {

        //        if ((IFS1bits.RTCCIF == 1)&&(TCP_status < 2)) {
        //            process_item = READ_DATA;
        //            IFS1CLR = 0x00008000; // clear RTCC existing event
        //        }
        // This task performs normal stack task including checking
        // for incoming packet, type of packet and calling
        // appropriate stack entity to process it.
        StackTask();

        // This tasks invokes each of the core stack application tasks
        StackApplications();

        switch (process_item) {
            case GET_INCOMMING:
                TCPServer(&TCP_status, &post_data_size, &f);
                break;
            case SET_TIME:
                t_d = Set_RTCC();
                if (t_d.d != 0) {

                    DelayMs(2000);
                    process_item = STARTUP;
                    reset_clock = false;
                }
                break;
            case READ_INSIDE_DATA:
                now = update_clock();
                inside.t = 0;
                inside.h = 0;
                outside.t = 0;
                outside.h = 0;
                read_inside_data();
#ifndef TESTING
                process_item = READ_OUTSIDE_DATA;
#else   
#ifndef NO_DATA
                process_item = READ_OUTSIDE_DATA;
#else
                process_item = GET_INCOMMING;
#endif
#endif
                break;

            case READ_OUTSIDE_DATA:
                status = TCPClient(GET_REMOTE);
                switch (status) {
                    case 0:
                        break;
                    case 1:
                        process_item = GET_INCOMMING;
                        
#if defined(SEND_DATA)  
                            process_item = UPLOAD_CURRENT;
#if defined(STACK_USE_MY_UART)
                            my_uart_println_str("UPLOAD_CURRENT");
#endif
#else
#if defined(SAVE_DATA)                
                        if (save_data(now)) {
                            process_item = UPLOAD_CURRENT;
#if defined(STACK_USE_MY_UART)
                            my_uart_println_str("UPLOAD_CURRENT");
#endif
                        }
#endif                            
#endif
                        break;
                }
                break;

            case UPDATE_RTCC:
#if defined(STACK_USE_MY_UART)
                my_uart_println_str("UPDATE_RTCC");
#endif
                t_d = Set_RTCC();
                if (t_d.d != 0) {
                    DelayMs(2000);
                    process_item = GET_INCOMMING;
                    reset_clock = false;
                }
                break;
            case UPLOAD_CURRENT:
#if defined(SEND_DATA)    
                if (TCPClient(CURRENT_DATA) == 1) {

#if defined(STACK_USE_MY_UART)
                    my_uart_println_str("CURRENT SENT");
#endif
                    if (reset_clock)
                        process_item = UPDATE_RTCC;
                    else
                        process_item = GET_INCOMMING;
                }
#else
                process_item = GET_INCOMMING;
#endif
                break;

            case UPLOAD_HISTORY:
#if defined(SEND_DATA)    
                if (TCPClient(HISTORY_DATA) == 1) {

#if defined(STACK_USE_MY_UART)
                    my_uart_println_str("HISTORY SENT");
#endif
                    if (reset_clock)
                        process_item = UPDATE_RTCC;
                    else
                        process_item = GET_INCOMMING;
                }
#else
                process_item = GET_INCOMMING;
#endif
                break;

            case STOP_SERVER:
                TCP_status = 10;
                TCPServer(&TCP_status, &post_data_size, &f);
                if (TCP_status == 0)process_item = READ_INSIDE_DATA;
                break;

            case STARTUP:
#if defined(FILL_HOUR_DATA)
                fill_hour_data();
#endif
                process_item = GET_INCOMMING;
                break;
        }

        ProcessIO();
    }
}

// Writes an IP address to the LCD display and the UART as available

void DisplayIPValue(IP_ADDR IPVal) {

    BYTE IPDigit[4];

    BYTE i;


    for (i = 0; i < sizeof (IP_ADDR); i++) {
        uitoa((WORD) IPVal.v[i], IPDigit);

#if defined(STACK_USE_MY_UART)
        putrsUART((char *) IPDigit);
#endif


        if (i == sizeof (IP_ADDR) - 1)
            break;

#if defined(STACK_USE_UART)
        while (BusyUART());
        WriteUART('.');
#endif
    }


}

// Processes A/D data from the potentiometer

static void ProcessIO(void) {
#if defined(__C30__) || defined(__C32__)
    // Convert potentiometer result into ASCII string
    //  uitoa((WORD) ADC1BUF0, AN0String);
#endif
    if (TCP_status == 1)
        if (Is_It_Time())
            process_item = STOP_SERVER;
}

/****************************************************************************
  Function:
    static void InitializeBoard(void)

  Description:
    This routine initializes the hardware.  It is a generic initialization
    routine for many of the Microchip development boards, using definitions
    in HardwareProfile.h to determine specific initialization.

  Precondition:
    None

  Parameters:
    None - None

  Returns:
    None

  Remarks:
    None
 ***************************************************************************/
static void InitializeBoard(void) {
    // LEDs
    LED0_TRIS = 0;
    LED1_TRIS = 0;
    LED2_TRIS = 0;
    LED3_TRIS = 0;
    LED4_TRIS = 0;
    LED5_TRIS = 0;
    LED6_TRIS = 0;
    LED7_TRIS = 0;
    LED_PUT(0x00);

    ST7735_TFT_Init();
    DelayMs(10);
    TRISEbits.TRISE5 = 0;
    DelayMs(1);
    LATEbits.LATE5 = 0;
    DelayMs(1000);

#if defined(ANALIZER_ON)    
    TRIGGER_CONTROL = 0; // Ref LED1
    TRIGGER_IO = 0;
#endif

#if defined(STACK_USE_MY_UART)
    my_uart_begin();
#endif
    init_I2C(100000);

#if defined(__PIC32MX__)
    {
        // Enable multi-vectored interrupts
        INTEnableSystemMultiVectoredInt();

        // Enable optimal performance
        SYSTEMConfigPerformance(GetSystemClock());
        mOSCSetPBDIV(OSC_PB_DIV_1); // Use 1:1 CPU Core:Peripheral clocks

        // Disable JTAG port so we get our I/O pins back, but first
        // wait 50ms so if you want to reprogram the part with 
        // JTAG, you'll still have a tiny window before JTAG goes away.
        // The PIC32 Starter Kit debuggers use JTAG and therefore must not 
        // disable JTAG.
        DelayMs(50);
#if !defined(__MPLAB_DEBUGGER_PIC32MXSK) && !defined(__MPLAB_DEBUGGER_FS2)
        DDPCONbits.JTAGEN = 0;
#endif
        LED_PUT(0x00); // Turn the LEDs off

        CNPUESET = 0x00098000; // Turn on weak pull ups on CN15, CN16, CN19 (RD5, RD7, RD13), which is connected to buttons on PIC32 Starter Kit boards
    }
#endif


    AD1CHS = 0; // Input to AN0 (potentiometer)
    AD1PCFGbits.PCFG4 = 0; // Disable digital input on AN4 (TC1047A temp sensor)

    AD1PCFGbits.PCFG5 = 0; // Disable digital input on AN5 (potentiometer)


    // ADC
    AD1CON1 = 0x84E4; // Turn on, auto sample start, auto-convert, 12 bit mode (on parts with a 12bit A/D)
    AD1CON2 = 0x0404; // AVdd, AVss, int every 2 conversions, MUXA only, scan
    AD1CON3 = 0x1003; // 16 Tad auto-sample, Tad = 3*Tcy

    AD1CSSL = 1 << 5; // Scan pot


    // UART
#if defined(STACK_USE_UART)

    UARTTX_TRIS = 0;
    UARTRX_TRIS = 1;
    UMODE = 0x8000; // Set UARTEN.  Note: this must be done before setting UTXEN


    USTA = 0x00001400; // RXEN set, TXEN set
#define CLOSEST_UBRG_VALUE ((GetPeripheralClock()+8ul*BAUD_RATE)/16/BAUD_RATE-1)
#define BAUD_ACTUAL (GetPeripheralClock()/16/(CLOSEST_UBRG_VALUE+1))


#define BAUD_ERROR ((BAUD_ACTUAL > BAUD_RATE) ? BAUD_ACTUAL-BAUD_RATE : BAUD_RATE-BAUD_ACTUAL)
#define BAUD_ERROR_PRECENT    ((BAUD_ERROR*100+BAUD_RATE/2)/BAUD_RATE)
#if (BAUD_ERROR_PRECENT > 3)
#warning UART frequency error is worse than 3%
#elif (BAUD_ERROR_PRECENT > 2)
#warning UART frequency error is worse than 2%
#endif

    UBRG = CLOSEST_UBRG_VALUE;
#endif


    // Deassert all chip select lines so there isn't any problem with 
    // initialization order.  Ex: When ENC28J60 is on SPI2 with Explorer 16, 
    // MAX3232 ROUT2 pin will drive RF12/U2CTS ENC28J60 CS line asserted, 
    // preventing proper 25LC256 EEPROM operation.
#if defined(ENC_CS_TRIS)
    ENC_CS_IO = 1;
    ENC_CS_TRIS = 0;
#endif


}

/*********************************************************************
 * Function:        void InitAppConfig(void)
 *
 * PreCondition:    MPFSInit() is already called.
 *
 * Input:           None
 *
 * Output:          Write/Read non-volatile config variables.
 *
 * Side Effects:    None
 *
 * Overview:        None
 *
 * Note:            None
 ********************************************************************/
// MAC Address Serialization using a MPLAB PM3 Programmer and 
// Serialized Quick Turn Programming (SQTP). 
// The advantage of using SQTP for programming the MAC Address is it
// allows you to auto-increment the MAC address without recompiling 
// the code for each unit.  To use SQTP, the MAC address must be fixed
// at a specific location in program memory.  Uncomment these two pragmas
// that locate the MAC address at 0x1FFF0.  Syntax below is for MPLAB C 
// Compiler for PIC18 MCUs. Syntax will vary for other compilers.
//#pragma romdata MACROM=0x1FFF0
//static ROM BYTE SerializedMACAddress[6] = {MY_DEFAULT_MAC_BYTE1, MY_DEFAULT_MAC_BYTE2, MY_DEFAULT_MAC_BYTE3, MY_DEFAULT_MAC_BYTE4, MY_DEFAULT_MAC_BYTE5, MY_DEFAULT_MAC_BYTE6};
//#pragma romdata

static void InitAppConfig(void) {

    while (1) {
        // Start out zeroing all AppConfig bytes to ensure all fields are 
        // deterministic for checksum generation
        memset((void*) &AppConfig, 0x00, sizeof (AppConfig));

        AppConfig.Flags.bIsDHCPEnabled = TRUE;
        AppConfig.Flags.bInConfigMode = TRUE;
        memcpypgm2ram((void*) &AppConfig.MyMACAddr, (ROM void*) SerializedMACAddress, sizeof (AppConfig.MyMACAddr));
        //        {
        //            _prog_addressT MACAddressAddress;
        //            MACAddressAddress.next = 0x157F8;
        //            _memcpy_p2d24((char*)&AppConfig.MyMACAddr, MACAddressAddress, sizeof(AppConfig.MyMACAddr));
        //        }
        AppConfig.MyIPAddr.Val = MY_DEFAULT_IP_ADDR_BYTE1 | MY_DEFAULT_IP_ADDR_BYTE2 << 8ul | MY_DEFAULT_IP_ADDR_BYTE3 << 16ul | MY_DEFAULT_IP_ADDR_BYTE4 << 24ul;
        AppConfig.DefaultIPAddr.Val = AppConfig.MyIPAddr.Val;
        AppConfig.MyMask.Val = MY_DEFAULT_MASK_BYTE1 | MY_DEFAULT_MASK_BYTE2 << 8ul | MY_DEFAULT_MASK_BYTE3 << 16ul | MY_DEFAULT_MASK_BYTE4 << 24ul;
        AppConfig.DefaultMask.Val = AppConfig.MyMask.Val;
        AppConfig.MyGateway.Val = MY_DEFAULT_GATE_BYTE1 | MY_DEFAULT_GATE_BYTE2 << 8ul | MY_DEFAULT_GATE_BYTE3 << 16ul | MY_DEFAULT_GATE_BYTE4 << 24ul;
        AppConfig.PrimaryDNSServer.Val = MY_DEFAULT_PRIMARY_DNS_BYTE1 | MY_DEFAULT_PRIMARY_DNS_BYTE2 << 8ul | MY_DEFAULT_PRIMARY_DNS_BYTE3 << 16ul | MY_DEFAULT_PRIMARY_DNS_BYTE4 << 24ul;
        AppConfig.SecondaryDNSServer.Val = MY_DEFAULT_SECONDARY_DNS_BYTE1 | MY_DEFAULT_SECONDARY_DNS_BYTE2 << 8ul | MY_DEFAULT_SECONDARY_DNS_BYTE3 << 16ul | MY_DEFAULT_SECONDARY_DNS_BYTE4 << 24ul;




        // Load the default NetBIOS Host Name
        memcpypgm2ram(AppConfig.NetBIOSName, (ROM void*) MY_DEFAULT_HOST_NAME, 16);
        FormatNetBIOSName(AppConfig.NetBIOSName);



        // Compute the checksum of the AppConfig defaults as loaded from ROM
        wOriginalAppConfigChecksum = CalcIPChecksum((BYTE*) & AppConfig, sizeof (AppConfig));


        break;
    }
}


//UART

#if (defined STACK_USE_MY_UART) || (defined UART_DATA)

void my_uart_begin() {
    U1MODEbits.BRGH = 0; // Baud Rate = 9600
    U1BRG = 259; // baud 19200
    //   U1BRG = (uint8_t) ((GetSystemClock()  / 4800) / 16) - 1; // baud 19200
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

void my_uart_print(char data) {
    U1STAbits.UTXEN = 1; // Make sure transmitter is enabled
    // while(CTS)    

    while (U1STAbits.UTXBF); // Wait while buffer is full

    U1TXREG = (BYTE) data; // Transmit character// Optional CTS use

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
    sprintf(buf, "%d", i);
    my_uart_println_str(buf); // Transmit one character
}


void my_uart_print_int(int i) {
    char buf[10];
    sprintf(buf, "%d", i);
    my_uart_print_str(buf); // Transmit one character
}

void my_uart_println_double(double i) {
    char buf[20];
    sprintf(buf, " = %.8f", i);
    my_uart_println_str(buf); // Transmit one character
}

void my_uart_print_HEX(uint32_t hex) {
    char HEX_Char[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    my_uart_print('0');
    my_uart_print('x');
    int b = 28;
    do {
        uint32_t c = hex>>b;
        my_uart_print(HEX_Char[hex >> b & 0x0f]);
        b -= 4;
    } while (b >= 0);
    my_uart_print('\r');
    my_uart_print('\n');

}

void my_uart_print_byte_HEX(uint8_t hex) {
    char HEX_Char[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    my_uart_print('0');
    my_uart_print('x');
    int b = 4;
    do {
        uint32_t c = hex>>b;
        my_uart_print(HEX_Char[hex >> b & 0x0f]);
        b -= 4;
    } while (b >= 0);
    my_uart_print('\r');
    my_uart_print('\n');

}
#endif

uint16_t date2days(uint16_t y, uint8_t m, uint8_t d) {
    if (y >= 2000)
        y -= 2000;
    uint16_t days = 1;
    uint8_t i = 0;
    for (i = 1; i < m; ++i){
        days += month[i];
     
    #if (defined UART_DATA)
 my_uart_print_int(i);
    my_uart_print_str("  ");
 my_uart_print_int(month[i]);
    my_uart_print_str("  ");
 my_uart_println_int(days);
#endif
}
    days += d;
       
    #if (defined UART_DATA)
 my_uart_println_int(days);
#endif
    if (m > 2 && y % 4 == 0){
        ++days;
           
    #if (defined UART_DATA)
 my_uart_println_int(days);
#endif
    }
    return days + 365 * y + (y + 3) / 4 - 1;
}

uint32_t time2long(uint16_t days, uint8_t h, uint8_t m, uint8_t s) {
    return ((((((uint32_t)days * 24L) + (uint32_t)h) * 60) + (uint32_t)m) * 60) + (uint32_t)s;
}

uint32_t unixtime(RTCCDateTime dt) {
    uint32_t t;
    int y = mRTCCBCD2Dec(dt.d.year) - 100;
    int m = mRTCCBCD2Dec(dt.d.mon) + 1;
    int d = mRTCCBCD2Dec(dt.d.mday);
    int hh = mRTCCBCD2Dec(dt.t.hour);
    int mm = mRTCCBCD2Dec(dt.t.min);
    int ss = 0;
    
    #if (defined UART_DATA)
my_uart_print_HEX(dt.d.l);
 my_uart_println_int(y);
 my_uart_println_int(m);
 my_uart_println_int(d);
my_uart_print_HEX(dt.t.l);
 my_uart_println_int(hh);
 my_uart_println_int(mm);

#endif

    uint16_t days = date2days(y, m, d);
    
    #if (defined UART_DATA)
 my_uart_println_int(days);
#endif
    t = time2long(days, hh, mm, ss);
   
    #if (defined UART_DATA)
 my_uart_println_int(t);
#endif   
    t += SECONDS_FROM_1970_TO_2000; // seconds from 1970 to 2000
    #if (defined UART_DATA)
 my_uart_println_int(t);
#endif   

    return t;
}


#if defined(FILL_HOUR_DATA)

void fill_hour_data() {

    uint16_t numBytes = 24;
    uint16_t eeAddress = 0;
    uint8_t data[32];

    uint32_t timestamp = unixtime(now);
    int location = 0;
    do {
        WEB_data_0.in_temp = 2112;
        WEB_data_0.in_hum = 5900;
        WEB_data_0.out_temp = 1534;
        WEB_data_0.out_hum = 7612;
        WEB_data_0.pressure = 1007;
        WEB_data_0.wind_speed = 1167;
        WEB_data_0.peak_wind_speed = 1543;
        WEB_data_0.bearing = 232;
        WEB_data_0.rainfall = 89;
        WEB_data_0.rainfall_rate = 345;
        WEB_data_0.timestamp = timestamp;
        timestamp += 60;
        memcpy(data, &WEB_data_0, numBytes);
        my_uart_print_str("write current ");
        my_uart_println_int(timestamp);
        eeAddress = location * 32;
        write_EEPROM(eeAddress, data, numBytes);
        location++;
    } while (location < 60);

    numBytes = 32;
    timestamp = 1570964400;

    History.in_temp_H = 2189;
    History.in_temp_L = 1612;
    History.in_hum_H = 7560;
    History.in_hum_L = 5060;
    History.out_temp_H = 1740;
    History.out_temp_L = 1034;
    History.out_hum_H = 8712;
    History.out_hum_L = 7012;
    History.pressure_H = 1020;
    History.pressure_L = 990;
    History.wind_speed = 1167;
    History.peak_wind_speed = 1543;
    History.bearing = 232;
    History.rainfall = 360;
    History.timestamp = timestamp;
    location = 0;
    do {
        memcpy(data, &WEB_data_0, numBytes);
        my_uart_print_str("write current ");
        my_uart_println_int(timestamp);
        eeAddress = HOUR_OFFSET + (location * 32);
        write_EEPROM(eeAddress, data, numBytes);
        timestamp += (60 * 60);
        location++;
    } while (location < 24);

    while (true);

}
#endif