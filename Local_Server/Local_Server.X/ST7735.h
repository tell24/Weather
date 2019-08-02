/* 
 * File:   ST7735.h
 * Author: terry
 *
 * Created on 29 July 2019, 17:26
 */

//#include "SPI.h"


#ifndef ST7735_H
#define	ST7735_H

#ifdef	__cplusplus
extern "C" {
#endif

    
    // Color definitions
#define   ST7735_BLACK   0x0000
#define   ST7735_BLUE    0x001F
#define   ST7735_RED     0xF800
#define   ST7735_GREEN   0x07E0
#define   ST7735_CYAN    0x07FF
#define   ST7735_MAGENTA 0xF81F
#define   ST7735_YELLOW  0xFFE0
#define   ST7735_WHITE   0xFFFF
    
    // SPI

#define TFT_CS_LOW  LATBbits.LATB4 = 0
#define TFT_CS_HIGH  LATBbits.LATB4 =1
#define TFT_DC_LOW  LATBbits.LATB3 = 0
#define TFT_DC_HIGH  LATBbits.LATB3 = 1
#define TFT_RESET_LOW  LATBbits.LATB5 = 0
#define TFT_RESET_HIGH  LATBbits.LATB5 = 1
#define TFT_CS_Direction  TRISBbits.TRISB4 = 0;
#define TFT_DC_Direction  TRISBbits.TRISB3 = 0
#define TFT_RESET_Direction  TRISBbits.TRISB5 = 0 
#define TFT_SPI_DO  TRISEbits.TRISE6 = 0  
#define TFT_DATA_LOW LATEbits.LATE6 = 0  
#define TFT_DATA_HIGH LATEbits.LATE6 = 1 
    
#define TFT_SPI_CLK  TRISEbits.TRISE7 = 0  
    
#define TFT_CLK_HIGH LATEbits.LATE7= 1;
#define TFT_CLK_LOW LATEbits.LATE7= 0;
    
 
    
    
void SPI2_Init();
void SPI2_Write(char data_);
void write_command(unsigned short cmd_);
void write_data(unsigned short cmd_);


// ST7735 commands

    void Rcmd1();
    void Rcmd2red();
    void Rcmd3();
    void setAddrWindow(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1);
    void drawPixel(unsigned short x, unsigned short y, unsigned int color);
    void fillRectangle(unsigned short x, unsigned short y, unsigned short w, unsigned short h, unsigned int color);
    void fillScreen(unsigned int color);
    void drawFastVLine(unsigned short x, unsigned short y, unsigned short h, unsigned int color);
    void drawFastHLine(unsigned short x, unsigned short y, unsigned short w, unsigned int color);
    void drawCircle(signed int x0, signed int y0, signed int r, unsigned int color);
    void drawCircleHelper(signed int x0, signed int y0, signed int r, unsigned short cornername, unsigned int color);
    void fillCircleHelper(signed int x0, signed int y0, signed int r, unsigned short cornername, signed int delta, unsigned int color);
    void fillCircle(signed int x0, signed int y0, signed int r, unsigned int color);
    void drawRect(unsigned short x, unsigned short y, unsigned short w, unsigned short h, unsigned int color);
    void drawLine(signed int x0, signed int y0, signed int x1, signed int y1, unsigned int color);
    void fillRect(unsigned short x, unsigned short y, unsigned short w, unsigned short h, unsigned int color);
    void drawRoundRect(unsigned short x, unsigned short y, unsigned short w, unsigned short h, unsigned short r, unsigned int color);
    void fillRoundRect(unsigned short x, unsigned short y, unsigned short w, unsigned short h, unsigned short r, unsigned int color);
    void drawTriangle(signed int x0, signed int y0, signed int x1, signed int y1, signed int x2, signed int y2, unsigned int color);
    void fillTriangle(signed int x0, signed int y0, signed int x1, signed int y1, signed int x2, signed int y2, unsigned int color);
    void drawChar(unsigned short x, unsigned short y, unsigned short c, unsigned int color, unsigned int bg, unsigned short size);
    void setTextWrap(unsigned short w);
    void drawtext(unsigned short x, unsigned short y, char *_text, unsigned int color, unsigned int bg, unsigned short size);
    void invertDisplay(unsigned short i);
    void setScrollDefinition(unsigned short top_fix_height, unsigned short bottom_fix_height, unsigned short _scroll_direction);
    void VerticalScroll(unsigned short _vsp);
    void NormalDisplay();
    unsigned int Color565(unsigned int r, unsigned int g, unsigned int b);
    void pushColor(unsigned int color);
    void ST7735_TFT_Init();


#ifdef	__cplusplus
}
#endif

#endif	/* ST7735_H */

