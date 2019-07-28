/* 
 * File:   main.c
 * Author: terry
 *
 * Created on 03 July 2019, 15:14
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>
#include <plib.h>
#include "../Include/TCPIP Stack/UART.h"
#include "BMP180.h"
#include "HTU21D.h"

#define THIS_IS_STACK_APPLICATION

// Include all headers for any enabled TCPIP Stack functions
#include "TCPIP Stack/TCPIP.h"
#include "main.h"

#if defined(STACK_USE_MY_UART)
#include "MyUart.h"
#endif

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


// Declare AppConfig structure and some other supporting stack variables
APP_CONFIG AppConfig;
static unsigned short wOriginalAppConfigChecksum; // Checksum of the ROM defaults for AppConfig
BYTE AN0String[8];

remotedata outsidedata;


TempHum internal;
BYTE process_item;

// Private helper functions.
// These may or may not be present in all applications.
static void InitAppConfig(void);
static void InitializeBoard(void);
static void ProcessIO(void);

static DateTime Set_RTCC();
static void SetAlarm(DateTime alarm);
static void read_inside_data();
static TempHum get_Humidity_Temperature();

/*
 * 
 */

void _general_exception_handler(unsigned cause, unsigned status) {
    Nop();
    Nop();
}

int i2c_Pressure_read() {
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
                if (status != 0) {
                    //      sensor_data.inside_temp = (int)(T * 10);
                    //            my_uart_println_double(T);
                    //            my_uart_println_double(P);
                    //            my_uart_println_double(BMP180_sealevel(P, ALTITUDE));

                    return (int) BMP180_sealevel(P, ALTITUDE);
                }
            }
        }
    }
    return 0;
}

TempHum get_Humidity_Temperature() {
    TempHum res;
    res.t = HTU21DF_readTemperature();
    res.h = HTU21DF_readHumidity();
    return res;
}

static void read_inside_data() {



    //    uint16_t eeAddress = 64;
    //    uint8_t data[] = {'n','b','w',' ','o','n'};
    //    uint8_t data1[6];
    //    uint8_t numBytes = 6;
    //    eprom.write_EEPROM( eeAddress, &data[0],  numBytes);
}


#define SERVER_PORT	80

int main(int argc, char** argv) {

    static DWORD t = 0;
    static DWORD dwLastIP = 0;
    DateTime t_d;
    int pressure;
    //    process_item  = DO_NOTHING;
    process_item = GET_TIME;
    //   process_item =SET_ALARM;
    
    InitializeBoard();

#if defined(STACK_USE_MY_UART)
//    my_uart_begin();
//    DelayMs(100);
//    my_uart_println_str("test");
#endif
    my_uart_begin();
    DelayMs(100);
    my_uart_println_str("test");
    DelayMs(100);

    DelayMs(500);

my_uart_println_str("bmp180!");
    if (!BMP180_begin()) {
        my_uart_println_str("Couldn't find BMP180!");
        while (1);
    }

my_uart_println_str("start pres");
    pressure = i2c_Pressure_read();

    my_uart_println_int(pressure);
    
my_uart_println_str("HTU21DF_begin");
    DelayMs(100);
    
if (!HTU21DF_begin()) {
        my_uart_println_str("Couldn't find HTU21DF!");
        while (1);
    }
    
    DelayMs(100);
    
my_uart_println_str("start t/h");
    internal = get_Humidity_Temperature();
    my_uart_println_double(internal.t);
    my_uart_println_double(internal.h);

    // TickInit();

#if defined(STACK_USE_MPFS2)
    MPFSInit();
#endif

    putrsUART2("MPFSInit\r\n");
    InitAppConfig();


    putrsUART2("InitAppConfig\r\n");

    // Initialize core stack layers (MAC, ARP, TCP, UDP) and
    // application modules (HTTP, SNMP, etc.)
    StackInit();


    putrsUART2("StackInit\r\n");

#if defined(STACK_USE_UART)
    DoUARTConfig();
#endif
    int post_data_size = 0;

    while (1) {

        if ((IFS1bits.RTCCIF == 1)&&(process_item == DO_NOTHING)) {
            read_inside_data();
            uint32_t mt = RTCTIME;
            my_uart_println_str("int Flag");
            my_uart_print_HEX(mt);
            IFS1CLR = 0x00008000; // clear RTCC existing event
        }

        // This task performs normal stack task including checking
        // for incoming packet, type of packet and calling
        // appropriate stack entity to process it.
        StackTask();

        // This tasks invokes each of the core stack application tasks
        StackApplications();

        switch (process_item) {
            case 1: post_data_size = GenericTCPServer(post_data_size);
                break;
            case 2: t_d = Set_RTCC();
                if (t_d.d != 0)
                    process_item = SET_ALARM;
                break;
            case 3:
                SetAlarm(t_d);
                process_item = DO_NOTHING;
                break;
            case 4:
                putrsUART2("Init\r\n");
                process_item = DO_NOTHING;
                break;
        }
        ProcessIO();


        // If the local IP address has changed (ex: due to DHCP lease change)
        // write the new IP address to the LCD display, UART, and Announce 
        // service
        if (dwLastIP != AppConfig.MyIPAddr.Val) {
            dwLastIP = AppConfig.MyIPAddr.Val;
            DisplayIPValue(AppConfig.MyIPAddr);
        }

    }

    return (EXIT_SUCCESS);
}

DateTime Set_RTCC() {

    DateTime d_t;

    rtccTime tm;
    rtccDate dt;
    DWORD time = SNTPGetUTCSeconds();
    struct tm *mytime;
    if (time > 100) {
        char buf[128];
        mytime = localtime(&time);

        strftime(buf, 128, "%H:%M:%S on the %d-%m-%Y\n", mytime);
        int cc = 0;

        do {
            my_uart_print((char) buf[cc]);
            if (buf[cc] == '\n') break;
            cc++;
        } while (cc < 128);

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
        RTCCONCLR = 0x8; // set RTCWREN in RTCCONSET

        process_item = DO_NOTHING;
        tm.l = RtccGetTime();
        dt.l = RtccGetDate();
        mytime->tm_hour = mRTCCBCD2Dec(tm.hour);
        mytime->tm_min = mRTCCBCD2Dec(tm.min);
        mytime->tm_sec = mRTCCBCD2Dec(tm.sec);
        mytime->tm_mday = mRTCCBCD2Dec(dt.mday);
        mytime->tm_mon = mRTCCBCD2Dec(dt.mon);
        mytime->tm_year = mRTCCBCD2Dec(dt.year);
        mytime->tm_wday = mRTCCBCD2Dec(dt.wday);

        strftime(buf, 128, "%H:%M:%S on the %d-%m-%Y\n", mytime);
        cc = 0;

        do {
            my_uart_print((char) buf[cc]);
            if (buf[cc] == '\n') break;
            cc++;
        } while (cc < 128);

        time += 90;

        mytime = localtime(&time);

        d_t.t = (mRTCCDec2BCD(mytime->tm_hour));
        d_t.t = d_t.t << 8 | (mRTCCDec2BCD(mytime->tm_min));
        d_t.t = d_t.t << 8 | 0;
        d_t.t = d_t.t << 8;
        d_t.d = d_t.d << 8 | (mRTCCDec2BCD(mytime->tm_mon));
        d_t.d = d_t.d << 8 | (mRTCCDec2BCD(mytime->tm_mday));
        d_t.d = d_t.d << 8 | (mRTCCDec2BCD(mytime->tm_wday));

        strftime(buf, 128, "%H:%M:%S on the %d-%m-%Y\n", mytime);
        cc = 0;

        do {
            my_uart_print((char) buf[cc]);
            if (buf[cc] == '\n') break;
            cc++;
        } while (cc < 128);

        //starting critical sequence
        SYSKEY = 0xaa996655; // write first unlock key to SYSKEY
        SYSKEY = 0x556699aa; // write second unlock key to SYSKEY
        RTCCONSET = 0x8; // set RTCWREN in RTCCONSET


        RTCCONCLR = 0x8; // set RTCWREN in RTCCONSET
        my_uart_println_str("alarm set");
        IFS1CLR = 0x00008000; // clear RTCC existing event

        return d_t;

    }
    d_t.d = 0;
    d_t.t = 0;
    return d_t;
}

void SetAlarm(DateTime alarm) {

    SYSKEY = 0xaa996655; // write first unlock key to SYSKEY
    SYSKEY = 0x556699aa; // write second unlock key to SYSKEY
    RTCCONSET = 0x8; // set RTCWREN in RTCCONSET
    IEC1CLR = 0x00008000; // disable RTCC interrupts
    RTCCONCLR = 0x8000; // turn off the RTCC
    while (RTCCON & 0x40); // wait for clock to be turned off
    IFS1CLR = 0x00008000; // clear RTCC existing event
    IPC8CLR = 0x1f000000; // clear the priority
    IPC8SET = 0x0d000000; // Set IPL=3, subpriority 1
    IEC1SET = 0x00008000; // Enable RTCC interrupts
    RTCALRMCLR = 0xCFFF; // clear ALRMEN, CHIME, AMASK and ARPT;
    ALRMTIME = alarm.t & 0xffff0000; // set alarm time to 16 hr, 15 min, 43 sec
    ALRMDATE = alarm.d; // set alarm date to Friday 27 Oct 2006
    RTCALRMSET = 0x8000 | 0x00004300; // re-enable the alarm, set alarm mask at once per day
    RTCCONSET = 0x8000; // turn on the RTCC
    RTCCONCLR = 0x8; // set RTCWREN in RTCCONSET
    while (!(RTCCON & 0x40)); // wait for clock to be turned on
}

_Bool Set_DST(DWORD time) {
    struct tm *newtime = localtime(&time);
    if ((newtime->tm_mon > 1)&&(newtime->tm_mon < 10)) {
        if (newtime->tm_mon == 2) {
            if (newtime->tm_wday == 0) {
                if ((newtime->tm_mday + (6 - newtime->tm_wday)) >= 31) {
                    if (newtime->tm_hour >= 1) return true;
                    else return false;
                } else return false;
            } else {
                if ((newtime->tm_mday + (6 - newtime->tm_wday)) < 31) {
                    return false;
                }
            }
        }
        if (newtime->tm_mon == 9) {
            if (newtime->tm_wday == 0) {
                if ((newtime->tm_mday + (6 - newtime->tm_wday)) >= 31) {
                    if (newtime->tm_hour >= 1) return false;
                    else return true;
                } else
                    return true;
            } else {
                if ((newtime->tm_mday + (6 - newtime->tm_wday)) < 31) return true;
                else
                    return false;
            }
        }
    }
    return true;
}

void DisplayIPValue(IP_ADDR IPVal) {
    // printf("%u.%u.%u.%u", IPVal.v[0], IPVal.v[1], IPVal.v[2], IPVal.v[3]);
#if defined (__dsPIC33E__) || defined (__PIC24E__)
    static BYTE IPDigit[4]; /* Needs to be declared as static to avoid the array getting optimized by C30 v3.30 compiler for dsPIC33E/PIC24E. 
                                                   Otherwise the LCD displays corrupted IP address on Explorer 16. To be fixed in the future compiler release*/
#else
    BYTE IPDigit[4];
#endif
    BYTE i;
#ifdef USE_LCD
    BYTE j;
    BYTE LCDPos = 16;
#endif

    for (i = 0; i < sizeof (IP_ADDR); i++) {
        uitoa((WORD) IPVal.v[i], IPDigit);

#if defined(STACK_USE_MY_UART)
        putrsUART2(IPDigit);
        putrsUART2(".");
#endif

#ifdef USE_LCD
        for (j = 0; j < strlen((char*) IPDigit); j++) {
            LCDText[LCDPos++] = IPDigit[j];
        }
        if (i == sizeof (IP_ADDR) - 1)
            break;
        LCDText[LCDPos++] = '.';
#else
        if (i == sizeof (IP_ADDR) - 1) {
            my_uart_print('\r');
            my_uart_print('\n');
            break;
        }
#endif

#if defined(STACK_USE_UART)
        while (BusyUART());
        WriteUART('.');
#endif
    }

#ifdef USE_LCD
    if (LCDPos < 32u)
        LCDText[LCDPos] = 0;
    LCDUpdate();
#endif
}

// Processes A/D data from the potentiometer

static void ProcessIO(void) {
}

static void InitializeBoard(void) {
    // LEDs

    TRISEbits.TRISE5 = 0;
    DelayMs(100);
    LATEbits.LATE5 = 0;
    DelayMs(1000);

    LED0_TRIS = 0;
    LED1_TRIS = 0;
    LED2_TRIS = 0;
    LED3_TRIS = 0;
    LED4_TRIS = 0;
    LED5_TRIS = 0;
    LED6_TRIS = 0;
    LED7_TRIS = 0;
    LED_PUT(0x00);

    init_I2C(100000);
}

static ROM BYTE SerializedMACAddress[6] = {MY_DEFAULT_MAC_BYTE1, MY_DEFAULT_MAC_BYTE2, MY_DEFAULT_MAC_BYTE3, MY_DEFAULT_MAC_BYTE4, MY_DEFAULT_MAC_BYTE5, MY_DEFAULT_MAC_BYTE6};

static void InitAppConfig(void) {

#if defined(EEPROM_CS_TRIS) || defined(SPIFLASH_CS_TRIS)
    unsigned char vNeedToSaveDefaults = 0;
#endif

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


        // SNMP Community String configuration
#if defined(STACK_USE_SNMP_SERVER)
        {
            BYTE i;
            static ROM char * ROM cReadCommunities[] = SNMP_READ_COMMUNITIES;
            static ROM char * ROM cWriteCommunities[] = SNMP_WRITE_COMMUNITIES;
            ROM char * strCommunity;

            for (i = 0; i < SNMP_MAX_COMMUNITY_SUPPORT; i++) {
                // Get a pointer to the next community string
                strCommunity = cReadCommunities[i];
                if (i >= sizeof (cReadCommunities) / sizeof (cReadCommunities[0]))
                    strCommunity = "";

                // Ensure we don't buffer overflow.  If your code gets stuck here, 
                // it means your SNMP_COMMUNITY_MAX_LEN definition in TCPIPConfig.h 
                // is either too small or one of your community string lengths 
                // (SNMP_READ_COMMUNITIES) are too large.  Fix either.
                if (strlenpgm(strCommunity) >= sizeof (AppConfig.readCommunity[0]))
                    while (1);

                // Copy string into AppConfig
                strcpypgm2ram((char*) AppConfig.readCommunity[i], strCommunity);

                // Get a pointer to the next community string
                strCommunity = cWriteCommunities[i];
                if (i >= sizeof (cWriteCommunities) / sizeof (cWriteCommunities[0]))
                    strCommunity = "";

                // Ensure we don't buffer overflow.  If your code gets stuck here, 
                // it means your SNMP_COMMUNITY_MAX_LEN definition in TCPIPConfig.h 
                // is either too small or one of your community string lengths 
                // (SNMP_WRITE_COMMUNITIES) are too large.  Fix either.
                if (strlenpgm(strCommunity) >= sizeof (AppConfig.writeCommunity[0]))
                    while (1);

                // Copy string into AppConfig
                strcpypgm2ram((char*) AppConfig.writeCommunity[i], strCommunity);
            }
        }
#endif

        // Load the default NetBIOS Host Name
        memcpypgm2ram(AppConfig.NetBIOSName, (ROM void*) MY_DEFAULT_HOST_NAME, 16);
        FormatNetBIOSName(AppConfig.NetBIOSName);

#if defined(WF_CS_TRIS)
        // Load the default SSID Name
        WF_ASSERT(sizeof (MY_DEFAULT_SSID_NAME) - 1 <= sizeof (AppConfig.MySSID));
        memcpypgm2ram(AppConfig.MySSID, (ROM void*) MY_DEFAULT_SSID_NAME, sizeof (MY_DEFAULT_SSID_NAME));
        AppConfig.SsidLength = sizeof (MY_DEFAULT_SSID_NAME) - 1;

        AppConfig.SecurityMode = MY_DEFAULT_WIFI_SECURITY_MODE;

#if (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_OPEN)
        memset(AppConfig.SecurityKey, 0x00, sizeof (AppConfig.SecurityKey));
        AppConfig.SecurityKeyLength = 0;

#elif MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WEP_40
        AppConfig.WepKeyIndex = MY_DEFAULT_WEP_KEY_INDEX;
        memcpypgm2ram(AppConfig.SecurityKey, (ROM void*) MY_DEFAULT_WEP_KEYS_40, sizeof (MY_DEFAULT_WEP_KEYS_40) - 1);
        AppConfig.SecurityKeyLength = sizeof (MY_DEFAULT_WEP_KEYS_40) - 1;

#elif MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WEP_104
        AppConfig.WepKeyIndex = MY_DEFAULT_WEP_KEY_INDEX;
        memcpypgm2ram(AppConfig.SecurityKey, (ROM void*) MY_DEFAULT_WEP_KEYS_104, sizeof (MY_DEFAULT_WEP_KEYS_104) - 1);
        AppConfig.SecurityKeyLength = sizeof (MY_DEFAULT_WEP_KEYS_104) - 1;

#elif (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA_WITH_KEY)       || \
                  (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA2_WITH_KEY)      || \
                  (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA_AUTO_WITH_KEY)
        memcpypgm2ram(AppConfig.SecurityKey, (ROM void*) MY_DEFAULT_PSK, sizeof (MY_DEFAULT_PSK) - 1);
        AppConfig.SecurityKeyLength = sizeof (MY_DEFAULT_PSK) - 1;

#elif (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA_WITH_PASS_PHRASE)     || \
                  (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA2_WITH_PASS_PHRASE)    || \
                  (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA_AUTO_WITH_PASS_PHRASE)
        memcpypgm2ram(AppConfig.SecurityKey, (ROM void*) MY_DEFAULT_PSK_PHRASE, sizeof (MY_DEFAULT_PSK_PHRASE) - 1);
        AppConfig.SecurityKeyLength = sizeof (MY_DEFAULT_PSK_PHRASE) - 1;
#elif (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPS_PUSH_BUTTON)
        memset(AppConfig.SecurityKey, 0x00, sizeof (AppConfig.SecurityKey));
        AppConfig.SecurityKeyLength = 0;
#elif (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPS_PIN)
        memcpypgm2ram(AppConfig.SecurityKey, (ROM void*) MY_DEFAULT_WPS_PIN, sizeof (MY_DEFAULT_WPS_PIN) - 1);
        AppConfig.SecurityKeyLength = sizeof (MY_DEFAULT_WPS_PIN) - 1;
#else 
#error "No security defined"
#endif /* MY_DEFAULT_WIFI_SECURITY_MODE */

#endif

        // Compute the checksum of the AppConfig defaults as loaded from ROM
        wOriginalAppConfigChecksum = CalcIPChecksum((BYTE*) & AppConfig, sizeof (AppConfig));

#if defined(EEPROM_CS_TRIS) || defined(SPIFLASH_CS_TRIS)
        {
            NVM_VALIDATION_STRUCT NVMValidationStruct;

            // Check to see if we have a flag set indicating that we need to 
            // save the ROM default AppConfig values.
            if (vNeedToSaveDefaults)
                SaveAppConfig(&AppConfig);

            // Read the NVMValidation record and AppConfig struct out of EEPROM/Flash
#if defined(EEPROM_CS_TRIS)
            {
                XEEReadArray(0x0000, (BYTE*) & NVMValidationStruct, sizeof (NVMValidationStruct));
                XEEReadArray(sizeof (NVMValidationStruct), (BYTE*) & AppConfig, sizeof (AppConfig));
            }
#elif defined(SPIFLASH_CS_TRIS)
            {
                SPIFlashReadArray(0x0000, (BYTE*) & NVMValidationStruct, sizeof (NVMValidationStruct));
                SPIFlashReadArray(sizeof (NVMValidationStruct), (BYTE*) & AppConfig, sizeof (AppConfig));
            }
#endif

            // Check EEPROM/Flash validitity.  If it isn't valid, set a flag so 
            // that we will save the ROM default values on the next loop 
            // iteration.
            if ((NVMValidationStruct.wConfigurationLength != sizeof (AppConfig)) ||
                    (NVMValidationStruct.wOriginalChecksum != wOriginalAppConfigChecksum) ||
                    (NVMValidationStruct.wCurrentChecksum != CalcIPChecksum((BYTE*) & AppConfig, sizeof (AppConfig)))) {
                // Check to ensure that the vNeedToSaveDefaults flag is zero, 
                // indicating that this is the first iteration through the do 
                // loop.  If we have already saved the defaults once and the 
                // EEPROM/Flash still doesn't pass the validity check, then it 
                // means we aren't successfully reading or writing to the 
                // EEPROM/Flash.  This means you have a hardware error and/or 
                // SPI configuration error.
                if (vNeedToSaveDefaults) {
                    while (1);
                }

                // Set flag and restart loop to load ROM defaults and save them
                vNeedToSaveDefaults = 1;
                continue;
            }

            // If we get down here, it means the EEPROM/Flash has valid contents 
            // and either matches the ROM defaults or previously matched and 
            // was run-time reconfigured by the user.  In this case, we shall 
            // use the contents loaded from EEPROM/Flash.
            break;
        }
#endif
        break;
    }
}


