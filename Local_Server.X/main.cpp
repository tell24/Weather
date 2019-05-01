/* 
 * File:   main.cpp
 * Author: te
 *
 * Created on 22 December 2018, 15:15
 */

#include <cstdlib>
#include <stdint.h>
#include <xc.h>
#include <stdio.h>
#include <string.h>
#include "Globals.h"
#include "EthernetClass.h"
#include "my_uart.h"
#include "eeprom.h"
#include "RTCC.h"

using namespace std;

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

/*
 * 
 */
const char html_0[] =
"<!DOCTYPEhtml>"
"<!-- saved from url=(0016)http://localhost -->\r"
"<html>"
"<head>"
"<meta charset='utf-8'>"
"<title>Weather</title>"
"<meta name='generator'content='GoogleWebDesigner5.0.4.0226'>"
"<style type='text/css'id='gwd-text-style'>"
".sidenav{"
"height:100%;"
"width:130px;"
"position:fixed;"
"z-index:1;"
"top:0px;"
"left:0px;"
"background-color:rgb(80,0,80);"
"overflow-x:hidden;"
"padding-top:40px;"
"}\r"
".sidenav a{"
"padding:5px 5px 5px 32px;"
"text-decoration:none;"
"font-size:25px;"
"color:rgb(192,192,192);"
"display:block;"
"}\r"
".sidenav a:hover{""\r"
"color:rgb(241,241,241);""\r"
"}\r"
".data{"
"position:absolute;"
"margin:auto;"
"text-align:center;"
"overflow:auto;"
"top:0px;"
"height:750px;"
"width:100%;"
"}\r"
".about{"
"top:0px;"
"text-align:left;"
"position:absolute;"
"margin-left:430px;"
"width:1100px;"
"}\r"
".graph{\r"
"top:0px;\r"
"text-align: left;\r"
"position: absolute;\r"
"margin-left: 130px;\r"
"width:1100px;\r"
"}\r"
".cent{"
"text-align:left;"
"position:relative;"
"margin:auto;"
"width:1160px;"
"}\r"
".cent_c{"
"text-align:left;"
"position:relative;"
"margin:auto;"
"width:1000px;"
"}\r"
".column{"
"float:left;"
"height:680px;"
"width:370px;"
"text-align:center;"
"}\r"
".column_1{"
"width:780px;"
"height:680px;"
"float:right;"
"text-align:center;"
"}"
".row{"
"height:170px;"
"content:'';"
"clear:both;"
"}\r"
;

const char html_1[] =
"@media (max-height:450px){\r"
".sidenav{"
"padding-top:10px;"
"}\r"
".sidenav a{"
"font-size:18px;"
"}\r"
"}\r"
"</style>"
"<style type='text/css'>"
"html, body{"
"width:100%;"
"height:100%;"
"margin:0px;"
"}"
"body{"
"background-color:transparent;"
"transform:perspective(1400px)matrix3d(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);"
"transform-style:preserve-3d;"
"}/r"
"</style>"
"<script type='text/javascript'>"
"var sel;"
"var sort_update;"
"var handleSelect;"
"window.onload=function(){"
"handleSelect = function(){""\r"
"sel=document.getElementById('duration').value;""\r"
"WaitDownload();\r"
"active_window=1;""\r"
"sort_update();""\r"
"};"
"var L1=130;"
"var L2=350;"
"var L3=570;"
"var xhr;"
"var H_offset=0;"
"var active_window=1;"
"var p_col='#5050f8';"
"var peak_col='#ff0000';"
"var col1='#cc1c5e';"
"var col2='#e730e7';"
"var col3='#2c57eb';"
"var col4='#39dddd';"
"var r_col='#8cc8e8';"
"var PI=3.1416;"
"var rad=57.2958;"
"var rain_scale=137;"
"var marker=0;"
"var mark=true;"
"var c=document.getElementById('canvas');"
"var dia=80;"
"var dia_small=70;"
"var myMsg;"
"var m_len=30;"
"var len=30;"
"var chart=[document.getElementById('canvas_a').getContext('2d'),"
"document.getElementById('canvas_b').getContext('2d'),"
"document.getElementById('canvas_c').getContext('2d'),"
"\r"
;

const char html_2[] =
"document.getElementById('canvas_d').getContext('2d'),"
"document.getElementById('canvas_e').getContext('2d')"
"];"
"var titles=['Temperature','','Humidity','','Pressure','WindSpeed','','RainFall'];"
"var plot=['OutHigh','InHigh','OutHigh','InHigh','High','Gust','Mean','Total','OutLow','InLow','OutLow','InLow','Low'];"
"var axis_x_label=['Minutes','Hours','January','Febuary','March','April','May','June','July','August','September','October','November','December'];"
"var axis_y_label=['C','','%','','mB','mph','','mm'];"
"var myarr;"
"var m_m_arr;"
"document.getElementById('canvas_b').addEventListener('click',canvas_b_click);"
"document.getElementById('canvas_c').addEventListener('click',canvas_c_click);"
"document.getElementById('canvas_d').addEventListener('click',canvas_d_click);"
"document.getElementById('canvas_e').addEventListener('click',canvas_e_click);"
"//StartCurrentPage\r"
"function draw_dial(loc,win){"
"var x1,y1;"
"var ident;"
"var scale=5,"
"start=-20;"
"var text='';"
"win.textAlign='center';"
"win.fillStyle='Black';"
"win.font='14px Arial';"
"switch(loc){"
"case 0:"
"x1=166;"
"y1=L1;"
"ident=13;"
"\r"
;

const char html_3[] =
"scale=5;"
"\r"
"start=-20;"
"\r"
"text='InsideTemperature(C)';"
"break;"
"\r"
"case 1:"
"x1=832;"
"y1=L1;"
"ident=13;"
"scale=5;"
"start=-20;"
"text='OutsideTemperature(C)';"
"break;"
"\r"
"case 2:"
"x1=166;"
"y1=L2;"
"ident=11;"
"scale=10;"
"start=0;"
"text='InsideHumidity(%)';"
"break;"
"\r"
"case 3:"
"x1=832;"
"y1=L2;"
"ident=11;"
"scale=10;"
"start=0;"
"text='OutsideHumidity(%)';"
"break;"
"\r"
"case 4:"
"x1=500;"
"y1=L1;"
"ident=11;"
"scale=20;"
"start=860;"
"text='AirPressure(mb)';"
"break;"
"\r"
"case 5:"
"x1=166;"
"y1=L3;"
"ident=11;"
"scale=5;"
"start=0;"
"text='WindSpeed(mph)';"
"break;"
"}"
"\r"
"var step=240/(ident-1);"
"var offset=dia*0.707;"
"win.beginPath();"
"win.arc(x1,y1,dia,0.75*PI,0.25*PI);"
"win.stroke();"
"win.beginPath();"
"win.moveTo(x1-offset,y1+offset);"
"win.lineTo(x1+offset,y1+offset);"
"win.stroke();"
"var val;"
"for(var i=0;i<ident;i++){"
"var x2,y2,x3,y3;"
"var ang=(-30+(step*i))/rad;"
"y2=y1-((dia+2)*Math.sin(ang));"
"y3=y1-((dia+10)*Math.sin(ang));"
"x2=x1-((dia+2)*Math.cos(ang));"
"x3=x1-((dia+10)*Math.cos(ang));"
"win.beginPath();"
"win.moveTo(x2,y2);"
"win.lineTo(x3,y3);"
"win.stroke();"
"val=(i*scale)+start;"
"y2=y1+5-((dia+25)*Math.sin(ang));"
"x2=x1-((dia+25)*Math.cos(ang));"
"win.fillText(val.toString(),x2,y2);"
"}"
"\r"
;

const char html_4[] =
"win.fillText(text,x1,y1+80);"
"};"
"function draw_bearing(win){"
"var x=833;"
"var y=L3-20;"
"var ident=8;"
"var direction=['N','NE','E','SE','S','SW','W','NW'];"
"win.beginPath();"
"win.arc(x,y,dia_small,0,2*PI);"
"win.stroke();"
"win.beginPath();"
"win.textAlign='center';"
"win.fillStyle='Black';"
"win.font='14px Arial';"
"var step=360/ident;"
"for(var i=0;i<ident;i++){"
"var x2,y2,x3,y3;"
"var ang=(90+(step*i))/rad;"
"y2=y-((dia_small+2)*Math.sin(ang));"
"y3=y-((dia_small+10)*Math.sin(ang));"
"x2=((dia_small+2)*Math.cos(ang))+x;"
"x3=((dia_small+10)*Math.cos(ang))+x;"
"win.beginPath();"
"win.moveTo(x2,y2);"
"win.lineTo(x3,y3);"
"win.stroke();"
"val=(i*30);"
"y2=y+5-((dia_small+25)*Math.sin(ang));"
"x2=x-((dia_small+25)*Math.cos(ang));"
"win.fillText(direction[i],x2,y2);"
"}"
"text='WindBearing(mph)';"
"win.fillText(text,x,y+120);"
"};"
"function data_plot(x,y,win){"
"var delta;"
"var dia1=80;"
"var x1,y1;"
"var peak=false;"
"switch(x){"
"case 0:"
"delta=(1.1667-(((20+y)/90)*2))*PI;"
"x1=166;"
"y1=L1;"
"break;"
"case 1:"
"delta=(1.1667-(((20+y)/90)*2))*PI;"
"x1=832;"
"y1=L1;"
"break;"
"case 2:"
"delta=(1.1667-((y/150)*2))*PI;"
"x1=166;"
"y1=L2;"
"break;"
"case 3:"
"delta=(1.1667-((y/150)*2))*PI;"
"\r"
;

const char html_5[] =
"x1=832;"
"y1=L2;"
"break;"
"case 4:"
"delta=(1.1667-(((y-860)/300)*2))*PI;"
"x1=500;"
"y1=L1;"
"break;"
"case 5:"
"delta=(1.1667-((y/75)*2))*PI;"
"x1=166;"
"y1=L3;"
"break;"
"case 6:"
"delta=(0.5-((y/360)*2))*PI;"
"x1=832;"
"y1=L3-20;"
"dia1=70;"
"break;"
"case 7:"
"delta=(1.1667-((y/75)*2))*PI;"
"x1=166;"
"y1=L3;"
"peak=true;"
"break;"
"}"
"var x2,y2,x3,y3,x4,y4;"
"if(peak){"
"y2=y1-((dia1-15)*Math.sin(delta+0.075));"
"y3=y1-(dia1*Math.sin(delta));"
"y4=y1-((dia1-15)*Math.sin(delta-0.075));"
"x2=((dia1-15)*Math.cos(delta+0.075))+x1;"
"x3=(dia1*Math.cos(delta))+x1;"
"x4=((dia1-15)*Math.cos(delta-0.075))+x1;"
"win.beginPath();"
"win.fillStyle=peak_col;"
"win.moveTo(x2,y2);"
"win.lineTo(x3,y3);"
"win.lineTo(x4,y4);"
"win.lineTo(x2,y2);"
"win.fill();"
"win.font='16px Arial';"
"win.fillText(y,x1,y1+20);"
"} else {"
"y2=y1-((dia1-15)*Math.sin(delta+0.075));"
"y3=y1-(dia1*Math.sin(delta));"
"y4=y1-((dia1-15)*Math.sin(delta-0.075));"
"x2=((dia1-15)*Math.cos(delta+0.075))+x1;"
"x3=(dia1*Math.cos(delta))+x1;"
"x4=((dia1-15)*Math.cos(delta-0.075))+x1;"
"win.beginPath();"
"win.fillStyle=p_col;"
"win.moveTo(x2,y2);"
"win.lineTo(x3,y3);"
"win.lineTo(x4,y4);"
"win.lineTo(x2,y2);"
"\r"
;

const char html_6[] =
"win.fill();"
"win.font='16px Arial';"
"if(x!=6)win.fillText(y,x1,y1);"
"}"
"win.font='14px Arial';"
"};"
"function draw_rain(win){"
"win.rect(449,250,52,152);"
"win.rect(501,250,52,152);"
"win.stroke();"
"win.beginPath();"
"win.textAlign='center';"
"win.fillStyle='Black';"
"win.font='14px Arial';"
"win.fillText('rate',370,310);"
"win.fillText('of',370,325);"
"win.fillText('fall',370,340);"
"win.fillText('/hr',370,355);"
"win.fillText('total',620,320);"
"win.fillText('this',620,335);"
"win.fillText('hr',620,350);"
"win.fillText('RainFall(mm)',500,L2+80);"
"};"
"function rain_plot(now,total,win){"
"now/=(rain_scale/60);"
"total/=rain_scale;"
"var n_scale=Math.ceil(now+0.5);"
"var t_scale=Math.ceil(total+0.5);"
"var n_ticks=Math.ceil(n_scale/5);"
"var ticks=152/5;"
"var s=0;"
"var num=s.toFixed(1);"
"var y=402;"
"var count=5;"
"do{"
"win.fillStyle='black';"
"win.beginPath();"
"win.moveTo(444,y);"
"win.lineTo(449,y);"
"win.stroke();"
"win.fillText(num,415,y+5);"
"y-=ticks;"
"s+=n_ticks;"
"num=s.toFixed(1);"
"count--;"
"}while(count>=0);"
"s-=n_ticks;"
"num=s.toFixed(1);"
"var n_s=152*(now/num);"
"var t_ticks=Math.ceil(t_scale/5);"
"ticks=152/5;"
"s=0;"
"num=s.toFixed(1);"
"\r"
;

const char html_7[] =
"var y=402;"
"count=5;"
"do{"
"win.beginPath();"
"win.moveTo(553,y);"
"win.lineTo(558,y);"
"win.stroke();"
"win.fillText(num,580,y+5);"
"y-=ticks;"
"s+=t_ticks;"
"num=s.toFixed(1);"
"count--;"
"}while(count>=0);"
"s-=t_ticks;"
"num=s.toFixed(1);"
"var n_t=152*(total/num);"
"win.beginPath();"
"win.fillStyle=r_col;"
"win.rect(450,402-n_s,50,n_s);"
"win.fill();"
"win.beginPath();"
"win.fillStyle='Blue';"
"win.rect(502,402-n_t,50,n_t);"
"win.fill();"
"};"
"function drawHand(win,pos,length,width){"
"win.beginPath();"
"win.lineWidth=width;"
"win.lineCap='round';"
"win.moveTo(500,L3);"
"var x=Math.sin(pos/rad)*length;"
"var y=Math.cos(pos/rad)*length;"
"win.lineTo(500+x,L3-y);"
"win.stroke();"
"};"
"function clock(win){"
"var step=30;"
"var cc=L3;"
"win.beginPath();"
"win.arc(500,cc,dia,0,2*PI);"
"win.stroke();"
"for(var i=1;i<=12;i++){"
"var x2,y2,x3,y3;"
"var ang=(90+(step*i))/rad;"
"y2=cc-((dia)*Math.sin(ang));"
"y3=cc-((dia-5)*Math.sin(ang));"
"x2=((dia)*Math.cos(ang))+500;"
"x3=((dia-5)*Math.cos(ang))+500;"
"win.beginPath();"
"win.moveTo(x2,y2);"
"win.lineTo(x3,y3);"
"win.stroke();"
"val=(i*30);"
"y2=cc+5-((dia+10)*Math.sin(ang));"
"x2=500-((dia+10)*Math.cos(ang));"
"\r"
;

const char html_8[] =
"win.fillText(i,x2,y2);"
"}"
"var d,h,m;"
"d=new Date();"
"h=d.getHours();"
"m=d.getMinutes();"
"h=h%12;"
"//hour\r"
"h=((h/12)*360)+((m/60)*30);"
"drawHand(win,h,dia*0.5,4);"
"//minute\r"
"m=(m/60)*360;"
"drawHand(win,m,dia*0.8,2);"
"win.lineWidth=1;"
"};"
"function update_fields(){"
"xhr=new XMLHttpRequest();"
"var a='0';"
"var url='https://script.google.com/macros/s/AKfycbzep_6TONHLbfjt1H23_iCb0DMc126LPo3smsun/exec?read=current';"
"xhr.onreadystatechange=function(){"
"if(xhr.readyState==4){"
"var t_r=xhr.responseText;"
"var dat=t_r.split(',');"
"var x=document.getElementById('cent_c');"
"x.style.display='block';"
"x=document.getElementById('canvas_area_1');"
"x.style.display='none';"
"x=document.getElementById('about');"
"x.style.display='none';"
"var ctx=c.getContext('2d');"
"ctx.fillStyle='white';"
"ctx.fillRect(0,0,1000,750);"
"draw_dial(0,ctx);"
"draw_dial(1,ctx);"
"draw_dial(2,ctx);"
"draw_dial(3,ctx);"
"draw_dial(4,ctx);"
"draw_dial(5,ctx);"
"draw_bearing(ctx);"
"draw_rain(ctx);"
"clock(ctx);"
"ctx.fillStyle='Black';"
"data_plot(0,parseFloat(dat[19]),ctx);"
"data_plot(1,parseFloat(dat[1]),ctx);"
"if(parseFloat(dat[22])>100)"
"data_plot(2,parseFloat('100'),ctx);"
"\r"
;

const char html_9[] =
" else "
"data_plot(2,parseFloat(dat[22]),ctx);"
"if(parseFloat(dat[4])>100)"
"data_plot(3,parseFloat('100'),ctx);"
" else "
"data_plot(3,parseFloat(dat[4]),ctx);"
"data_plot(4,parseFloat(dat[25]),ctx);"
"data_plot(5,parseFloat(dat[7]),ctx);"
"data_plot(6,parseFloat(dat[10]),ctx);"
"data_plot(7,parseFloat(dat[13]),ctx);"
"rain_plot(parseFloat(dat[16]),parseFloat(dat[17]),ctx);"
"var x=document.getElementById('cent_c');"
"x.style.display='block';"
"}"
"};"
"xhr.open('GET',url);"
"xhr.send(null);"
"};"
"//StartHistoryPage\r""\r"
"function update_history(){""\r"
"sel=document.getElementById('duration').value;""\r"
"var url1='https://script.google.com/macros/s/AKfycbzep_6TONHLbfjt1H23_iCb0DMc126LPo3smsun/exec?read='+sel;""\r"
"xhr=new XMLHttpRequest();""\r"
"xhr.onreadystatechange=function(){""\r"
"if(xhr.readyState==4){""\r"
"var t_r=xhr.responseText;""\r"
"var all_dat=t_r.split(',');""\r"
"len=30;""\r"
"var index=0;""\r"
"var cell=2;""\r"
"var type=0;""\r"
"switch(sel){""\r"
"case 'hour':""\r"
"type=1;""\r"
"mark=true;""\r"
"len=59;""\r"
"m_len=15;""\r"
"do{""\r"
"myarr[0][index]=all_dat[cell];//intemp\r"
"myarr[1][index]=all_dat[cell+18];//outtemp\r"
"myarr[2][index]=all_dat[cell+3];//outhum\r"
"myarr[3][index]=all_dat[cell+21];//inhum\r"
;

const char html_10[] = 
"myarr[4][index]=all_dat[cell+24];//pres\r"
"myarr[5][index]=all_dat[cell+9];//wind\r"
"myarr[6][index]=all_dat[cell+6];//gust\r"
"myarr[7][index]=all_dat[cell+15]/rain_scale;//rainmm\r"
"myarr[8][index]=all_dat[cell+1];//inlowtemp\r"
"myarr[9][index]=all_dat[cell+19];//outlowtemp\r"
"myarr[10][index]=all_dat[cell+4];//outlowhum\r"
"myarr[11][index]=all_dat[cell+22];//inlowhum\r"
"index++;""\r"
"cell+=29;""\r"
"}while(index<=len);""\r"
"marker=all_dat[1770];""\r"
"if(parseFloat(all_dat[2+(61*29)])<parseFloat(all_dat[20+(61*29)]))//templow\r""\r"
"m_m_arr[0][0]=Math.floor(all_dat[2+(61*29)]);""\r"
" else ""\r"
"m_m_arr[0][0]=Math.floor(all_dat[20+(61*29)]);""\r"
"if(parseFloat(all_dat[3+(61*29)])>parseFloat(all_dat[21+(61*29)]))//temphigh\r""\r"
"m_m_arr[1][0]=Math.ceil(all_dat[3+(61*29)]);""\r"
" else ""\r"
"m_m_arr[1][0]=Math.ceil(all_dat[21+(61*29)]);""\r"
"if(m_m_arr[1][0]>100)m_m_arr[1][0]=50;""\r"
"m_m_arr[0][1]=m_m_arr[0][0];""\r"
"m_m_arr[1][1]=m_m_arr[1][0];""\r"
"if(parseFloat(all_dat[5+(61*29)])<parseFloat(all_dat[23+(61*29)]))//humlow\r"
"m_m_arr[0][2]=Math.floor(all_dat[5+(61*29)]);""\r"
" else ""\r"
"m_m_arr[0][2]=Math.floor(all_dat[23+(61*29)]);""\r"
"if(m_m_arr[0][2]<0)m_m_arr[0][2]=0;""\r"
"\r"
;

const char html_11[] = 
"if(parseFloat(all_dat[6+(61*29)])>parseFloat(all_dat[24+(61*29)]))//humhigh\r"
"m_m_arr[1][2]=Math.ceil(all_dat[6+(61*29)]);""\r"
" else ""\r"
"m_m_arr[1][2]=Math.ceil(all_dat[24+(61*29)]);""\r"
"if(m_m_arr[1][2]>100)m_m_arr[1][2]=100;""\r"
"m_m_arr[0][3]=m_m_arr[0][2];""\r"
"m_m_arr[1][3]=m_m_arr[1][2];""\r"
"m_m_arr[0][4]=Math.floor(all_dat[26+(61*29)]);//peslow\r"
"m_m_arr[1][4]=Math.ceil(all_dat[27+(61*29)]);//preshigh\r"
"m_m_arr[0][5]=0;//windlow\r"
"if(parseFloat(all_dat[12+(61*29)])>parseFloat(all_dat[15+(61*29)]))//windhigh\r"
"m_m_arr[1][5]=Math.ceil(all_dat[12+(61*29)]);""\r"
" else ""\r"
"m_m_arr[1][5]=Math.ceil(all_dat[15+(61*29)]);""\r"
"if(m_m_arr[1][5]<2)m_m_arr[1][5]=2;""\r"
"m_m_arr[0][6]=m_m_arr[0][5];""\r"
"m_m_arr[1][6]=m_m_arr[1][5];""\r"
"m_m_arr[0][7]=0;//rain\r"
"m_m_arr[1][7]=Math.ceil(all_dat[17+(62*29)]/rain_scale);""\r"
"break;""\r"
"case 'day':""\r"
"type=2;""\r"
"mark=true;""\r"
"len=24;""\r"
"m_len=12;""\r"
"do{""\r"
"myarr[0][index]=all_dat[cell];//outhightemp\r"
"myarr[1][index]=all_dat[cell+18];//inhightemp\r"
"myarr[2][index]=all_dat[cell+3];//outhighhum\r"
"myarr[3][index]=all_dat[cell+21];//inhighhum\r"
"myarr[4][index]=all_dat[cell+24];//pres\r"
"myarr[5][index]=all_dat[cell+6];//wind\r"
"myarr[6][index]=all_dat[cell+9];//gust\r"
"\r"
;

const char html_12[] =
"myarr[7][index]=all_dat[cell+16]/rain_scale;//rainmm\r"
"myarr[8][index]=all_dat[cell+1];//inlowtemp\r"
"myarr[9][index]=all_dat[cell+19];//outlowtemp\r"
"myarr[10][index]=all_dat[cell+4];//outlowhum\r"
"myarr[11][index]=all_dat[cell+22];//inlowhum\r"
"myarr[12][index]=all_dat[cell+25];//lowpres\r"
"index++;""\r"
"cell+=29;""\r"
"}while(index<=len);""\r"
"marker=all_dat[784];""\r"
"if(parseFloat(all_dat[2+(27*29)])<parseFloat(all_dat[20+(27*29)]))//templow\r"
"m_m_arr[0][0]=Math.floor(all_dat[2+(27*29)]);""\r"
" else ""\r"
"m_m_arr[0][0]=Math.floor(all_dat[20+(27*29)]);""\r"
"if(parseFloat(all_dat[3+(27*29)])>parseFloat(all_dat[21+(27*29)]))//temphigh\r"
"m_m_arr[1][0]=Math.ceil(all_dat[3+(27*29)]);""\r"
" else ""\r"
"m_m_arr[1][0]=Math.ceil(all_dat[21+(27*29)]);""\r"
"if(m_m_arr[1][0]>100)m_m_arr[1][0]=50;""\r"
"m_m_arr[0][1]=m_m_arr[0][0];""\r"
"m_m_arr[1][1]=m_m_arr[1][0];""\r"
"if(parseFloat(all_dat[5+(27*29)])<parseFloat(all_dat[23+(27*29)]))//humlow\r"
"m_m_arr[0][2]=Math.floor(all_dat[5+(27*29)]);""\r"
" else ""\r"
"m_m_arr[0][2]=Math.floor(all_dat[23+(27*29)]);""\r"
"if(m_m_arr[0][2]<0)m_m_arr[0][2]=0;""\r"
"if(parseFloat(all_dat[6+(27*29)])>parseFloat(all_dat[24+(27*29)]))//humhigh\r"
"m_m_arr[1][2]=Math.ceil(all_dat[6+(27*29)]);""\r"
" else "
"\r"
;


const char html_13[] =
"m_m_arr[1][2]=Math.ceil(all_dat[24+(27*29)]);""\r"
"if(m_m_arr[1][2]>100)m_m_arr[1][2]=100;""\r"
"m_m_arr[0][3]=m_m_arr[0][2];""\r"
"m_m_arr[1][3]=m_m_arr[1][2];""\r"
"m_m_arr[0][4]=Math.floor(all_dat[26+(27*29)]);//peslow\r"
"m_m_arr[1][4]=Math.ceil(all_dat[27+(27*29)]);//preshigh\r"
"m_m_arr[0][5]=0;//windlow\r"
"if(parseFloat(all_dat[12+(27*29)])>parseFloat(all_dat[15+(27*29)]))//windhigh\r"
"m_m_arr[1][5]=Math.ceil(all_dat[12+(27*29)]);""\r"
" else ""\r"
"m_m_arr[1][5]=Math.ceil(all_dat[15+(27*29)]);""\r"
"if(m_m_arr[1][5]<2)m_m_arr[1][5]=2;""\r"
"m_m_arr[0][6]=m_m_arr[0][5];""\r"
"m_m_arr[1][6]=m_m_arr[1][5];""\r"
"m_m_arr[0][7]=0;//rain\r"
"m_m_arr[1][7]=Math.ceil(all_dat[18+(28*29)]/rain_scale);""\r"
"break;""\r"
"default:""\r"
"type=2;""\r"
"mark=false;""\r"
"var d=new Date();""\r"
"m=parseInt(d.getMonth());""\r"
"var sm=parseInt(document.getElementById('duration').selectedIndex)-2;""\r"
"if(sm===m)""\r"
"len=parseInt(d.getDate())-2;""\r"
" else {""\r"
"if((sm===3)||(sm===5)||(sm===8)||(sm===10))len=29;""\r"
" else len=30;""\r"
"if(sm===1)""\r"
"if(d.getFullYear()%4===0)len=28;""\r"
" else len=27;""\r"
"}""\r"
"do{""\r"
"myarr[0][index]=all_dat[cell];//outhightemp\r"
"myarr[1][index]=all_dat[cell+18];//inhightemp\r"
"\r"
;

const char html_14[] =
"myarr[2][index]=all_dat[cell+3];//outhighhum\r"
"myarr[3][index]=all_dat[cell+21];//inhighhum\r"
"myarr[4][index]=all_dat[cell+24];//pres\r"
"myarr[5][index]=all_dat[cell+6];//wind\r"
"myarr[6][index]=all_dat[cell+9];//gust\r"
"myarr[7][index]=all_dat[cell+16]/rain_scale;//rain\r"
"myarr[8][index]=all_dat[cell+1];//inlowtemp\r"
"myarr[9][index]=all_dat[cell+19];//outlowtemp\r"
"myarr[10][index]=all_dat[cell+4];//outlowhum\r"
"myarr[11][index]=all_dat[cell+22];//inlowhum\r"
"myarr[12][index]=all_dat[cell+25];//lowpres\r"
"index++;""\r"
"cell+=29;""\r"
"}while(index<=len);""\r"
"if(parseFloat(all_dat[2+(33*29)])<parseFloat(all_dat[20+(33*29)]))//templow\r"
"m_m_arr[0][0]=Math.floor(all_dat[2+(33*29)]);""\r"
" else ""\r"
"m_m_arr[0][0]=Math.floor(all_dat[20+(33*29)]);""\r"
"if(parseFloat(all_dat[3+(33*29)])>parseFloat(all_dat[21+(33*29)]))//temphigh\r"
"m_m_arr[1][0]=Math.ceil(all_dat[3+(33*29)]);""\r"
" else ""\r"
"m_m_arr[1][0]=Math.ceil(all_dat[21+(33*29)]);""\r"
"if(m_m_arr[1][0]>100)m_m_arr[1][0]=50;""\r"
"m_m_arr[0][1]=m_m_arr[0][0];""\r"
"m_m_arr[1][1]=m_m_arr[1][0];""\r"
"if(parseFloat(all_dat[5+(33*29)])<parseFloat(all_dat[23+(33*29)]))//humlow\r"
"\r"
;

const char html_15[] =

"m_m_arr[0][2]=Math.floor(all_dat[5+(33*29)]);""\r"
" else ""\r"
"m_m_arr[0][2]=Math.floor(all_dat[23+(33*29)]);""\r"
"if(m_m_arr[0][2]<0)m_m_arr[0][2]=0;""\r"
"if(parseFloat(all_dat[6+(33*29)])>parseFloat(all_dat[24+(33*29)]))//humhigh\r"
"m_m_arr[1][2]=Math.ceil(all_dat[6+(33*29)]);""\r"
" else ""\r"
"m_m_arr[1][2]=Math.ceil(all_dat[24+(33*29)]);""\r"
"if(m_m_arr[1][2]>100)m_m_arr[1][2]=100;""\r"
"m_m_arr[0][3]=m_m_arr[0][2];""\r"
"m_m_arr[1][3]=m_m_arr[1][2];""\r"
"m_m_arr[0][4]=Math.floor(all_dat[26+(33*29)]);//peslow\r"
"m_m_arr[1][4]=Math.ceil(all_dat[27+(33*29)]);//preshigh\r"
"m_m_arr[0][5]=0;//windlow\r"
"if(parseFloat(all_dat[12+(33*29)])>parseFloat(all_dat[15+(33*29)]))//windhigh\r"
"m_m_arr[1][5]=Math.ceil(all_dat[12+(33*29)]);""\r"
" else ""\r"
"m_m_arr[1][5]=Math.ceil(all_dat[15+(33*29)]);""\r"
"if(m_m_arr[1][5]<2)m_m_arr[1][5]=2;""\r"
"m_m_arr[0][6]=m_m_arr[0][5];""\r"
"m_m_arr[1][6]=m_m_arr[1][5];""\r"
"m_m_arr[0][7]=0;//rain\r"
"m_m_arr[1][7]=Math.ceil(all_dat[18+(33*29)]/rain_scale);""\r"
"m_len=Math.ceil((len+1)/2);""\r"
"break;""\r"
"};""\r"
"var count=7;""\r"
"do{\r"
"if(m_m_arr[1][count]-m_m_arr[0][count]<1)m_m_arr[1][count]=m_m_arr[0][count]+1;""\r"
"count--;""\r"
"}while(count>0);""\r"
"\r"
;

const char html_16[] =
"build_history(type,len);"
"}"
"};"
"xhr.open('GET',url1);"
"xhr.send(null);"
"};\r"
"function build_history(data_valid,len){""\r"
"var temp=new Array();""\r"
"var min=0;""\r"
"var max=1;""\r"
"var ticks=30;""\r"
"var points=60;""\r"
"var first=1;""\r"
"if(data_valid>0){""\r"
"switch(sel){""\r"
"case 'hour':""\r"
"ticks=15;""\r"
"points=60;""\r"
"first=0;""\r"
"break;""\r"
"case 'day':""\r"
"ticks=12;""\r"
"points=23;""\r"
"break;""\r"
"default:""\r"
"ticks=m_len;""\r"
"points=len;""\r"
"break;""\r"
"}""\r"
"}""\r"
"var plots=0;""\r"
"var range=0;""\r"
"var d_set;""\r"

"switch(H_offset){\r""\r"
"case 0:\r"
"d_set=0;""\r"
"break;""\r"
"case 1:\r"
"d_set=2;""\r"
"break;""\r"
"case 2:""\r"
"d_set=4;""\r"
"break;""\r"
"case 3:""\r"
"d_set=5;""\r"
"break;""\r"
"case 4:\r"
"d_set=7;""\r"
"break;""\r"
"};""\r"
"switch(data_valid){\r"
"case 0:\r"
"do{\r"
"min=0;""\r"
"max=2;""\r"
"range=2;""\r"
"draw_graph(plots,range,min,ticks,points,0,0);""\r"
"plots++;""\r"
"}while(plots<5);""\r"
"break;""\r"
"case 1:\r"
"do{""\r"
"min=m_m_arr[0][d_set];""\r"
"max=m_m_arr[1][d_set];""\r"
"range=max-min;""\r"
"if(plots===0){""\r"
"range=Math.ceil(range/8)*8;""\r"
"if(max<(range/2))""\r"
"range=Math.ceil(range/2);""\r"
"if(max<(range/2))""\r"
"range=Math.ceil(range/2);""\r"
"} else {""\r"
"range=Math.ceil(range/4)*4;""\r"
"if(max<(range/2))""\r"
"range=Math.ceil(range/2);""\r"
"};""\r"
"if((d_set===2)||(d_set===3)){""\r"
"if(range+min>100)min=100-range;""\r"
"};\r"
"draw_graph(plots,range,min,ticks,points,d_set,first);""\r"
"temp=new Array();""\r"
"temp=myarr[d_set];""\r"
"fill_chart(0,plots,temp,range,min,points,d_set);""\r"
"\r"
;

const char html_17[] =
"if((d_set===0)||(d_set===2)||(d_set===5)){""\r"
"d_set++;""\r"
"temp=new Array();""\r"
"temp=myarr[d_set];""\r"
"fill_chart(1,plots,temp,range,min,points,d_set);""\r"
"};""\r"
"d_set++;""\r"
"if(d_set===8)d_set=0;""\r"
"plots++;""\r"
"}while(plots<5);""\r"
"break;""\r"
"case 2:\r"
"do{""\r"
"min=m_m_arr[0][d_set];""\r"
"max=m_m_arr[1][d_set];""\r"
"range=max-min;""\r"
"if(plots===0){\r"
"range=Math.ceil(range/8)*8;""\r"
"if(max<(range/2))\r"
"range=Math.ceil(range/2);""\r"
"if(max<(range/2))\r"
"range=Math.ceil(range/2);""\r"
"} else {\r"
"range=Math.ceil(range/4)*4;""\r"
"if(max<(range/2))\r"
"range=Math.ceil(range/2);""\r"
"};\r"
"if((d_set===2)||(d_set===3)){\r"
"if(range+min>100)min=100-range;""\r"
"};\r"
"draw_graph(plots,range,min,ticks,points,d_set,first);""\r"
"temp=new Array();""\r"
"temp=myarr[d_set];""\r"
"if((d_set===4)||(d_set===7)){""\r"
"fill_chart(0,plots,temp,range,min,points,d_set);"
"};\r"
"if(d_set===5){\r"
"fill_chart(0,plots,temp,range,min,points,d_set);""\r"
"d_set++;""\r"
"temp=new Array();""\r"
"temp=myarr[d_set];""\r"
"fill_chart(1,plots,temp,range,min,points,d_set);""\r"
"};""\r"
"if((d_set===0)||(d_set===2)){\r"
"fill_chart(2,plots,temp,range,min,points,d_set);""\r"
"temp=new Array();""\r"
"temp=myarr[d_set+8];""\r"
"fill_chart(4,plots,temp,range,min,points,d_set+8);""\r"
"}"
"\r"
;

const char html_18[] =
"if((d_set===0)||(d_set===2)){\r""\r"
"d_set++;""\r"
"temp=new Array();""\r"
"temp=myarr[d_set];""\r"
"fill_chart(3,plots,temp,range,min,points,d_set);""\r"
"if((d_set===1)||(d_set===3)){\r""\r"
"temp=new Array();""\r"
"temp=myarr[d_set+8];""\r"
"fill_chart(5,plots,temp,range,min,points,d_set+8);""\r"
"};""\r"
"};""\r"
"d_set++;""\r"
"if(d_set===8)d_set=0;""\r"
"plots++;""\r"
"}while(plots<5);""\r"
"break;""\r"
"};"
"myMsg.close();""\r"
"var x=document.getElementById('cent_c');""\r"
"x.style.display='none';""\r"
"x=document.getElementById('canvas_area_1');""\r"
"x.style.display='block';""\r"
"x=document.getElementById('about');""\r"
"x.style.display='none';"
"};""\r"
"function draw_graph(num,range,min,ticks,points,t_index,first){\r"
"var sm=parseInt(document.getElementById('duration').selectedIndex);""\r"
"var ctx=chart[num];""\r"
"ctx.font='10px Arial';""\r"
"var y_inc=range/4;""\r"
"var x=60;""\r"
"var y=30;""\r"
"var w=300;""\r"
"var h=100;""\r"
"var ys=100/4;""\r"
"var steps=4;""\r"
"var x_step=Math.round(points/ticks);""\r"
"ctx.fillStyle='White';""\r"
"if(num===0){""\r"
"w=700;""\r"
"h=600;""\r"
"steps=8;""\r"
"y_inc=range/8;""\r"
"ys=h/8;""\r"
"ctx.fillRect(0,0,800,780);""\r"
"} else ""\r"
"ctx.fillRect(0,0,400,170);""\r"
"ctx.fillStyle='black';""\r"
"ctx.beginPath();""\r"
"ctx.lineWidth=1;""\r"
"ctx.strokeStyle='grey';""\r"
"ctx.rect(x,y,w,h);""\r"
"ctx.stroke();""\r"
"\r"
;

const char html_19[] =
"ctx.textAlign='center';""\r"
"var xl=x;""\r"
"var xs=(w/(points))*x_step;""\r"
"var c_b=y+h;""\r"
"var i=first;""\r"
"ctx.font='11px Arial';""\r"
"ctx.beginPath();""\r"
"ctx.fillText(i,xl,y+h+14);""\r"
"while(xl<=(w+x)){""\r"
"xl+=xs;""\r"
"if(w+x-10<=xl)break;""\r"
"ctx.moveTo(xl,y);""\r"
"ctx.lineTo(xl,c_b);""\r"
"i+=x_step;""\r"
"ctx.fillText(i,xl,y+h+14);""\r"
"};"
"ctx.fillText(points+first,w+x,y+h+14);""\r"
"ctx.stroke();""\r"
"var yl=y;""\r"
"c_b=x+w;""\r"
"ctx.beginPath();""\r"
"i=min+range;""\r"
"var step=range/steps;""\r"
"while(yl<=(h+y)-1){""\r"
"ctx.fillText(i,45,yl+5);""\r"
"yl+=ys;""\r"
"ctx.moveTo(x,yl);""\r"
"ctx.lineTo(c_b,yl);""\r"
"i-=step;""\r"
"};"
"ctx.fillText(i,45,yl+5);""\r"
"ctx.stroke();""\r"
"ctx.font='13px Arial';""\r"
"if(num===0)""\r"
"ctx.fillText(axis_y_label[t_index],25,y+(h/2)-20);""\r"
" else ""\r"
"ctx.fillText(axis_y_label[t_index],18,y+(h/2));""\r"
"ctx.fillText(titles[t_index],x+(w/2),17);""\r"
"ctx.fillText(axis_x_label[sm],x+(w/2),yl+28);""\r"
"ctx.font='11px Arial';""\r"
"ctx.strokeStyle='black';""\r"
"ctx.fillStyle='black';""\r"
"};""\r"
"function fill_chart(col,c_num,p_data,range,min,p,type){""\r"
"var ctx=chart[c_num];""\r"
"var x=60;""\r"
"var y=30;""\r"
"var w=300;""\r"
"var h=100;""\r"
"if(c_num===0){""\r"
"w=700;""\r"
"h=600;""\r"
"};""\r"
"var r_label=x+w-170;""\r"
"if(col===0){""\r"
"ctx.fillText(plot[type],130,17);""\r"
"ctx.strokeStyle=col1;""\r"
"ctx.fillStyle=col1;""\r"
"\r"
;

const char html_20[] =
"ctx.fillRect(90,7,15,10);""\r"
"};""\r"
"if(col===1){""\r"
"ctx.fillText(plot[type],r_label+130,17);""\r"
"ctx.strokeStyle=col2;""\r"
"ctx.fillStyle=col2;""\r"
"ctx.fillRect(r_label+90,7,15,10);""\r"
"//ctx.fillRect(110,7,15,10);""\r"
"};""\r"
"if(col===2){""\r"
"ctx.fillText(plot[type],80,17);""\r"
"ctx.strokeStyle=col3;""\r"
"ctx.fillStyle=col3;""\r"
"ctx.fillRect(110,7,15,10);""\r"
"};""\r"
"if(col===3){""\r"
"ctx.fillText(plot[type],r_label+95,17);""\r"
"ctx.strokeStyle=col4;""\r"
"ctx.fillStyle=col4;""\r"
"ctx.fillRect(r_label+120,7,15,10);""\r"
"};""\r"
"if(col===4){""\r"
"ctx.fillText(plot[type],150,17);""\r"
"ctx.strokeStyle=col1;""\r"
"ctx.fillStyle=col1;""\r"
"ctx.fillRect(40,7,15,10);""\r"
"};""\r"
"if(col===5){""\r"
"ctx.fillText(plot[type],r_label+155,17);""\r"
"ctx.strokeStyle=col2;""\r"
"ctx.fillStyle=col2;""\r"
"ctx.fillRect(r_label+60,7,15,10);""\r"
"};""\r"
"var y_inc=h/range;""\r"
"var i=min+range;""\r"
"var s=0;""\r"
"var y1=0;""\r"
"var xs=w/p;""\r"
"var xm=x+(xs*marker);""\r"
"var hm=y+h;""\r"
"if(i<p_data[0])p_data[0]=i;""\r"
"y1=y+(y_inc*(i-p_data[0]));""\r"
"ctx.lineWidth=2;""\r"
"ctx.beginPath();""\r"
"ctx.moveTo(x,y1);""\r"
"do{""\r"
"s++;""\r"
"x+=xs;""\r"
"if(i<p_data[s])p_data[s]=i;""\r"
"y1=y+(y_inc*(i-p_data[s]));""\r"
"if(y1>(y+h))""\r"
"ctx.moveTo(x,y+h);""\r"
" else ""\r"
"ctx.lineTo(x,y1);""\r"
"}while(s<p);""\r"
"ctx.stroke();""\r"
"if(mark){""\r"
"ctx.beginPath();""\r"
"ctx.fillStyle='black';""\r"
"ctx.moveTo(xm-5,hm);""\r"
"\r"
;

const char html_21[] =
"ctx.lineTo(xm,hm-7);""\r"
"ctx.lineTo(xm+5,hm);""\r"
"ctx.lineTo(xm-5,hm);""\r"
"ctx.fill();""\r"
"};""\r"
"ctx.strokeStyle='black';""\r"
"ctx.fillStyle='black';""\r"
"};""\r"
"function move_history(){"
"var min;"
"var max;"
"var temp;"
"var points;"
"var range;"
"var h_c=0;"
"var first=1;"
"var fun=0;"
"switch(sel){"
"case 'hour':"
"points=60;"
"ticks=15;"
"first=0;"
"fun=1;"
"break;"
"case 'day':"
"points=23;"
"ticks=12;"
"break;"
"default:"
"points=len;"
"ticks=m_len;"
"break;"
"}"
"switch(H_offset){"
"case 0:"
"h_c=0;"
"break;"
"case 1:"
"h_c=2;"
"break;"
"case 2:"
"h_c=4;"
"break;"
"case 3:"
"h_c=5;"
"break;"
"case 4:"
"h_c=7;"
"break;"
"}"
"var plots=0;"
"if(fun===1){"
"do{"
"min=m_m_arr[0][h_c];"
"max=m_m_arr[1][h_c];"
"range=max-min;"
"if(plots===0){"
"range=Math.ceil(range/8)*8;"
"if(max<(range/2))"
"range=Math.ceil(range/2);"
"if(max<(range/2))"
"range=Math.ceil(range/2);"
"} else {"
"range=Math.ceil(range/4)*4;"
"if(max<(range/2))"
"range=Math.ceil(range/2);"
"}"
"if((h_c===2)||(h_c===3)){"
"if(range+min>100)min=100-range;"
"}"
"draw_graph(plots,range,min,ticks,points,h_c,first);"
"temp=new Array();"
"temp=myarr[h_c];"
"if(h_c===4){"
"fill_chart(0,plots,temp,range,min,points,h_c);"
"}"
"if(h_c===7){"
"fill_chart(0,plots,temp,range,min,points,h_c);"
"}"
"\r"
;

const char html_22[] =
"if((h_c===0)||(h_c===2)||(h_c===5)){"
"h_c++;"
"temp=new Array();"
"temp=myarr[h_c];"
"fill_chart(1,plots,temp,range,min,points,h_c);"
"}"
"h_c++;"
"if(h_c===8)h_c=0;"
"plots++;"
"}while(plots<5)"
"} else {"
"do{"
"min=m_m_arr[0][h_c];"
"max=m_m_arr[1][h_c];"
"range=max-min;"
"if(plots===0){"
"range=Math.ceil(range/8)*8;"
"if(max<(range/2))"
"range=Math.ceil(range/2);"
"if(max<(range/2))"
"range=Math.ceil(range/2);"
"} else {"
"range=Math.ceil(range/4)*4;"
"if(max<(range/2))"
"range=Math.ceil(range/2);"
"}"
"if((h_c===2)||(h_c===3)){"
"if(range+min>100)min=100-range;"
"}"
"draw_graph(plots,range,min,ticks,points,h_c,first);"
"temp=new Array();"
"temp=myarr[h_c];"
"if(h_c===4){"
"fill_chart(0,plots,temp,range,min,points,h_c);"
"}"
"if(h_c===7){"
"fill_chart(0,plots,temp,range,min,points,h_c);"
"}"
"if(h_c===5){"
"fill_chart(0,plots,temp,range,min,points,h_c);"
"h_c++;"
"temp=new Array();"
"temp=myarr[h_c];"
"fill_chart(1,plots,temp,range,min,points,h_c);"
"}"
"if((h_c===0)||(h_c===2)){"
"fill_chart(2,plots,temp,range,min,points,h_c);"
"temp=new Array();"
"temp=myarr[h_c+8];"
"fill_chart(4,plots,temp,range,min,points,h_c+8);"
"}"
"if((h_c===0)||(h_c===2)){"
"\r"
;

const char html_23[] =
"h_c++;"
"temp=new Array();"
"temp=myarr[h_c];"
"fill_chart(3,plots,temp,range,min,points,h_c);"
"if((h_c===1)||(h_c===3)){"
"temp=new Array();"
"temp=myarr[h_c+8];"
"fill_chart(5,plots,temp,range,min,points,h_c+8);"
"}"
"}"
"h_c++;"
"if(h_c===8)h_c=0;"
"plots++;"
"}while(plots<5)"
"}\r"
"};\r"
"function WaitDownload(){"
"wLeft=window.screenLeft?window.screenLeft:window.screenX;""\r"
"wTop=window.screenTop?window.screenTop:window.screenY;""\r"
"var left=wLeft+(window.innerWidth/2)-(100);""\r"
"var top=wTop+(window.innerHeight/2)-(50);""\r"
"myMsg=window.open('','MsgWindow','toolbar=no,personalbar=no,directories=no,status=no,menubar=no,scrollbars=no,resizable=no,copyhistory=no,width=350,height=180,top='+top+',left='+left);"
"myMsg.document.write('<h1>Downloading Data</h1>');""\r"
"myMsg.document.write('<h1>Please Wait</h1>');""\r"
"};\r"

"function make_array(){\r"
"myarr=new Array();"
"myarr.push([]);"
"myarr.push([]);"
"myarr.push([]);"
"myarr.push([]);"
"myarr.push([]);"
"myarr.push([]);"
"myarr.push([]);"
"myarr.push([]);"
"myarr.push([]);"
"myarr.push([]);"
"myarr.push([]);"
"myarr.push([]);"
"myarr.push([]);"
"m_m_arr=new Array();"
"m_m_arr.push([]);"
"m_m_arr.push([]);"
"};\r"
"\r"
;

const char html_24[] =
"sort_update=function(){\r"
"if(active_window==0)\r"
"update_fields();"
"if(active_window==1){\r"
"update_history();"
"}\r"
"}\r"
"document.getElementById('current').onclick=function myFunction(){\r"
"document.getElementById('duration').style.visibility='hidden';"
"document.getElementById('ld').style.visibility='hidden';"
"var x=document.getElementById('cent_c');"
"x.style.display='block';"
"x=document.getElementById('canvas_area_1');"
"x.style.display='none';"
"x=document.getElementById('about');"
"x.style.display='none';"
"active_window=0;"
"sort_update();"
"return false;"
"};\r"
"document.getElementById('history').onclick=function myFunction(){\r"
"document.getElementById('duration').style.visibility='visible';"
"document.getElementById('ld').style.visibility='visible';"
"var x=document.getElementById('cent_c');"
"x.style.display='none';"
"x=document.getElementById('canvas_area_1');"
"x.style.display='block';"
"x=document.getElementById('about');"
"x.style.display='none';"
"WaitDownload();"
"active_window=1;"
"sort_update();"
"return false;"
"};\r"
"document.getElementById('about1').onclick=function myFunction(){\r"
;

const char html_25[] =
"document.getElementById('duration').style.visibility='hidden';"
"document.getElementById('ld').style.visibility='hidden';"
"var x=document.getElementById('cent_c');"
"x.style.display='none';"
"x=document.getElementById('canvas_area_1');"
"x.style.display='none';"
"x=document.getElementById('about');"
"x.style.display='block';"
"return false;"
"};"
"function canvas_b_click(){"
"H_offset+=1;"
"H_offset=H_offset%5;"
"move_history();"
"};"
"function canvas_c_click(){"
"H_offset+=2;"
"H_offset=H_offset%5;"
"move_history();"
"};"
"function canvas_d_click(){"
"H_offset+=3;"
"H_offset=H_offset%5;"
"move_history();"
"};"
"function canvas_e_click(){"
"H_offset+=4;"
"H_offset=H_offset%5;"
"move_history();"
"};"
"var x=document.getElementById('cent_c');"
"x.style.display='block';"
"x=document.getElementById('canvas_area_1');"
"x.style.display='none';"
"x=document.getElementById('about');"
"x.style.display='none';"
"document.getElementById('duration').style.visibility='hidden';"
"document.getElementById('ld').style.visibility='hidden';"
"var myVar=setInterval(sort_update,30000);"
"active_window=0;"
"make_array();"
"sort_update();"
"\r"
;

const char html_26[] =
"}"
"</script>"
"</head>"

"<body class='htmlNoPages'>"
"\r"
"<div class='sidenav'>""\r"
"<a href='#'id='current'>Current</a>""\r"
"<a href='#'id='history'>History</a>""\r"
"<a href='#'id='about1' >About</a>""\r"
"<div>""\r"
"<p id='ld' left='20px'><font color='#818181'>History</font>""\r"
"</p>""\r"
"</div>""\r"
"<select name='optionList' id='duration' height='30' width='100' margin='auto' onchange='handleSelect()'>""\r"
"<option value='hour'>Hour</option>""\r"
"<option value='day'>Day</option>""\r"
"<option value='Jan'>January</option>""\r"
"<option value='Feb'>Febuary</option>""\r"
"<option value='Mar'>March</option>""\r"
"<option value='Apr'>April</option>""\r"
"<option value='May'>May</option>""\r"
"<option value='Jun'>June</option>""\r"
"<option value='Jul'>July</option>""\r"
"<option value='Aug'>August</option>""\r"
"<option value='Sep'>September</option>""\r"
"<option value='Oct'>October</option>""\r"
"<option value='Nov'>November</option>""\r"
"<option value='Dec'>December</option>""\r"
"</select>""\r"
"</div>""\r"
"<div class='data' id='Data'>""\r"
"<div class= 'graph'>""\r"
"<div class= 'cent_c' id='cent_c'>""\r"
"<canvas id= 'canvas'height='780'width='1000'></canvas>""\r"
"</div>""\r"
"<div class='cent' id='canvas_area_1' height='750' width='1180'>""\r"
"<div class='column'>""\r"
;

const char html_27[] =
"<div class='row'>""\r"
"<canvas id='canvas_b' width='400' height='170'></canvas>""\r"
"</div>""\r"
"<div class='row'>""\r"
"<canvas id='canvas_c' width='400' height='170'></canvas>""\r"
"</div>""\r"
"<div class='row'>""\r"
"<canvas id='canvas_d' width='400' height='170'></canvas>""\r"
"</div>""\r"
"<div class='row'>""\r"
"<canvas id='canvas_e' width='400' height='170'></canvas>""\r"
"</div>""\r"
"</div>""\r"
"<div class='column_1'>""\r"
"<canvas id='canvas_a' width='780' height='680'></canvas>""\r"
"</div>""\r"
"</div>""\r"
"</div>""\r"
"<div class='about' id='about'>""\r"
"<div class='cent'>""\r"
"<h3>Weather Station Operation</h3>""\r"
"<h4>Temperature</h4>""\r"
"<p>Sensor AM2320</p>""\r"
"<h4>Humidity</h4>""\r"
"<p>Sensor AM2320</p>""\r"
"<p></p>""\r"
"<h4>Air Pressure</h4>""\r"
"<p>Sensor BMP180</p>""\r"
"<p></p>""\r"
"<h4>RainFall</h4>""\r"
"<p>Count number of drips from calibrated Tube</p>""\r"
"<p></p>""\r"
"<h4>Wind Speed and Direction</h4>""\r"
"<p>Utrasonic Sensors @ N, S, E&amp; W</p>""\r"
"<p>Pulse Sensors N-S , S-N </p>""\r"
"<p>Measure Time of Flight each way to calculate N-S vector</p>""\r"
"<p>Pulse Sensors E-W, W-E</p>""\r"
"<p>Measure Time of Flight each way to calculate E-W vector</p>""\r"
"<p>Calculate Speed of Sound using Temperature and Humidity</p>""\r"
"<p>From above calculate Wind Speed and Bearing using Trig</p>""\r"
"</div>""\r"
"</div>""\r"
"</div>""\r"
"</body>""\r"
"</html>""\r";
// test_data_location
#define NVR_DAY_ADDRESS  0xBD035000 
#define NVR_WEEK_ADDRESS  0xBD039000
#define NVR_MONTH_ADDRESS  0xBD03B000
#define NVR_YEAR_ADDRESS  0xBD03C000

#define NVR_DATA_ADDRESS_0 0xBD03F000 // 

//
EthernetClass ether;

// ethernet interface mac address
 uint8_t mymac[] = {0x74, 0x69, 0x69, 0x2D, 0x30, 0x31};
// ethernet interface ip address
 uint8_t myip[] = {192, 168, 0, 23};
// gateway ip address
 uint8_t gwip[] = {192, 168, 0, 1};

uint16_t serial_baud = 9600;


uint16_t HTTP_start = 0;
char data[10];
data_all min_data[60];
data_all current;
data_h history_data;
my_uart Serial;
//const char script[] = "https://script.google.com/macros/s/AKfycbznD66uT9RcicnAhSnAuAherAwO9iQ7hssPCfJfrQW3auBDEJ0/exec?value=33,45,67"


unsigned int NVMUnlock(unsigned int nvmop) {
    // Enable Flash Write/Erase Operations and Select
    // Flash operation to perform
    NVMCON = nvmop;
    // Write Keys
    NVMKEY = 0xAA996655;
    NVMKEY = 0x556699AA;
    // Start the operation using the Set Register
    NVMCONSET = 0x8000;
    // Wait for operation to complete
    while (NVMCON & 0x8000);

    // Disable NVM write enable
    NVMCON &= ~0x0004000;
    // Return WRERR and LVDERR Error Status Bits
    return (NVMCON & 0x3000);
}

unsigned int NVMWriteWord(void* address, unsigned int data) {
    unsigned int res;
    asm volatile("di");
    // Load data into NVMDATA register
    NVMDATA = data;
    // Load address to program into NVMADDR register
    NVMADDR = (unsigned int) address;
    // Unlock and Write Word
    res = NVMUnlock(0x4001);
    asm volatile("ei");
    // Return Result
    return res;
}

unsigned int NVMErasePage(void* address) {
    unsigned int res;
    asm volatile("di");
    // Set NVMADDR to the Start Address of page to erase
    NVMADDR = (unsigned int) address;
    // Unlock and Erase Page
    res = NVMUnlock(0x4004);
    // Return Result;
    asm volatile("ei");
    return res;
}

unsigned int ReadNVM(unsigned int base, unsigned int offset) {
    return (*(unsigned int *) (base + (4 * offset)));
}

void read_history(uint32_t record_address, uint16_t samples, uint8_t *data) {
    uint32_t res[5];
    uint32_t offset_word = 0;
    uint16_t i = 0;
    do {
        offset_word = 0;
        do {
            res[offset_word] = ReadNVM(record_address + (i * 20), offset_word);
            offset_word++;
        } while (offset_word < 5);
        memcpy(&data, &res, 20);
        i++;
    } while (i < samples);
}

void write_history(uint32_t record_address, data_h data) {
    uint32_t offset_word = 0;
    uint32_t word_to_store[5];
    memcpy(&word_to_store, &data, 20);
    do {
        NVMWriteWord((void*) (record_address + (offset_word * 4)), word_to_store[offset_word]);
        offset_word++;
    } while (offset_word < 5);
}

Date_Time convert_timestamp( uint32_t unix)
{
      //// 1546105776
            //// Saturday, 29 December 2018 17:49:36
            ///
    Date_Time ts;
    unix -= 1262304000;
            
            uint32_t seconds, minutes, hours, days, year, month;
            seconds = unix;
            /* calculate minutes */
            minutes = seconds / 60;
            seconds -= minutes * 60;
            /* calculate hours */
            hours = minutes / 60;
            minutes -= hours * 60;
            /* calculate days */
            days = hours / 24;
            hours -= days * 24;
            ts.sec = seconds;
            ts.min = minutes;
            ts.hr = hours;
            
            /* Unix time starts in 1970 on a Thursday */
            year = 2010;
       //     dayOfWeek = 4;
            month = 0;
            uint32_t iterations = 0;
            while (true)
            {
                iterations++;
                bool leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
                uint32_t daysInYear = leapYear ? (uint32_t)366 : (uint32_t)365;
                if (days >= daysInYear)
                {
                    days -= daysInYear;
                    ++year;
                }
                else
                {
                    /* calculate the month and day */
                    uint32_t daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
                    for (month = 0; month < 12; ++month)
                    {
                        uint32_t dim = daysInMonth[month];

                        /* add a day to feburary if this is a leap year */
                        if (month == 1 && leapYear)
                            ++dim;

                        if (days >= dim)
                            days -= dim;
                        else
                            break;
                    }
                    break;
                }
            }
            days += 1;
            month += 1;
            ts.day = days;
            ts.month = month;
            ts.year = year;
            return ts;
}

uint8_t get_data(int8_t type, uint16_t data_len) {
    uint16_t HTTP_start = 0x36;
    do {
        if ((char) ether.buffer[HTTP_start] == '\r')
            if (((char) ether.buffer[HTTP_start + 1] == '\n')&((char) ether.buffer[HTTP_start + 2] == '\r')&((char) ether.buffer[HTTP_start + 3] == '\n')) break;
        HTTP_start++;
    } while (HTTP_start < (600));
    if (HTTP_start >= 600) 
        return (uint16_t) 0;
HTTP_start += 4;
    memcpy(&current, ether.buffer + HTTP_start, 20);

    return (uint8_t) 1;
}

int data_in(uint16_t data_len) {
    uint8_t good = get_data((int8_t) 0, data_len);
    ether.httpServerReplyAck();
    char buf1[] = "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n Content-Length: 3\r\n\r\n OK";
    int len = sizeof (buf1) - 1;
    memcpy(ether.buffer + 54, buf1, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V + TCP_FLAGS_FIN_V);
    return good;
}

void update() {
    uint8_t good = get_data((int8_t) 1, 0);
    uint8_t chart[2];
    memcpy(&chart, data, 1);
    ether.httpServerReplyAck();
    char buf1[] = "HTTP/1.0 200 OK\r\nContent-Type: multipart/form-data\r\n Content-Length: ";
    char buf2[] = "\r\n\r\n";
    uint16_t len = sizeof (buf1) + sizeof (buf2) + 6 - 2;
    char buf[256];
    uint8_t data_buf[1200];
    uint16_t length = 0;
    uint8_t d_type = chart[0];
    uint32_t record_address = 0;
    switch (d_type) {
        case '0':
            length = 60 * 14; // for all one hour data
            sprintf(buf, "%s%6d%s", buf1, length, buf2); // header with data size
            memcpy(ether.buffer + 54, buf, len);
            ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
            memcpy(ether.buffer + 54, &min_data, length);
            ether.httpServerReply_with_flags(length, TCP_FLAGS_ACK_V + TCP_FLAGS_FIN_V);
            break;
        case '1':
            length = 24 * 20; // for all one hour data  
            record_address = NVR_DAY_ADDRESS;
            sprintf(buf, "%s%6d%s", buf1, length, buf2); // header with data size
            memcpy(ether.buffer + 54, buf, len);
            ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
            read_history(record_address, 24, data_buf);
            memcpy(ether.buffer + 54, &data_buf, length);
            ether.httpServerReply_with_flags(length, TCP_FLAGS_ACK_V + TCP_FLAGS_FIN_V);
            break;
        case '2':
            length = 7 * 20; // for all one hour data
            record_address = NVR_WEEK_ADDRESS;
            sprintf(buf, "%s%6d%s", buf1, length, buf2); // header with data size
            memcpy(ether.buffer + 54, buf, len);
            ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
            read_history(record_address, 7, data_buf);
            memcpy(ether.buffer + 54, &data_buf, length);
            ether.httpServerReply_with_flags(length, TCP_FLAGS_ACK_V + TCP_FLAGS_FIN_V);
            break;
        case '3':
            length = 31 * 20; // for all one hour data
            record_address = NVR_MONTH_ADDRESS;
            sprintf(buf, "%s%6d%s", buf1, length, buf2); // header with data size
            memcpy(ether.buffer + 54, buf, len);
            ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
            read_history(record_address, 31, data_buf);
            memcpy(ether.buffer + 54, &buf, length);
            ether.httpServerReply_with_flags(length, TCP_FLAGS_ACK_V + TCP_FLAGS_FIN_V);
            break;
        case '4':
            length = 52 * 20; // for all one hour data
            record_address = NVR_YEAR_ADDRESS;
            sprintf(buf, "%s%6d%s", buf1, length, buf2); // header with data size
            memcpy(ether.buffer + 54, buf, len);
            ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
            read_history(record_address, 52, data_buf);
            memcpy(ether.buffer + 54, &data_buf, length);
            ether.httpServerReply_with_flags(length, TCP_FLAGS_ACK_V + TCP_FLAGS_FIN_V);
            break;
    }
}

void refresh() {
    ether.httpServerReplyAck();
    char buf1[] = "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n Content-Length: ";
    char buf2[] = "\r\n\r\n";
    char buf3[50];
    int length = sizeof (current);

    char buf[256];

    uint16_t len = sizeof (buf1) + sizeof (buf2) + 6 - 2;
    sprintf(buf, "%s%6d%s", buf1, length, buf2); // header with data size
    memcpy(ether.buffer + 54, buf, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    memcpy(ether.buffer + 54, &current, length);
    ether.httpServerReply_with_flags(length, TCP_FLAGS_ACK_V + TCP_FLAGS_FIN_V);
}

void homePage() {
    ether.httpServerReplyAck();
    char buf1[] = "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n Content-Length: ";
    char buf2[] = "\r\n\r\n";
    int length = sizeof (html_0) - 1 + sizeof (html_1) - 1 + sizeof (html_2) - 1 + sizeof (html_3) - 1
            + sizeof (html_4) - 1 + sizeof (html_5) - 1
            + sizeof (html_6) - 1 + sizeof (html_7) - 1 + sizeof (html_8) - 1 + sizeof (html_9) - 1 + sizeof (html_10) - 1 + sizeof (html_11) - 1
            + sizeof (html_12) - 1 + sizeof (html_13) - 1 + sizeof (html_14) - 1 + sizeof (html_15) - 1 + sizeof (html_16) - 1 + sizeof (html_17) - 1
            + sizeof (html_18) - 1 + sizeof (html_19) - 1 + sizeof (html_20) - 1 + sizeof (html_21) - 1 + sizeof (html_22) - 1 + sizeof (html_23) - 1 
            + sizeof (html_24) - 1 + sizeof (html_25) - 1 + sizeof (html_26) - 1 + sizeof (html_27) - 1;
    uint16_t len = sizeof (buf1) + sizeof (buf2) + 6 - 2;
    char buf[2048];
    sprintf(buf, "%s%6d%s", buf1, length, buf2); // header with data size
    memcpy(ether.buffer + 54, buf, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_0) - 1;
    memcpy(ether.buffer + 54, html_0, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_1) - 1;
    memcpy(ether.buffer + 54, html_1, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_2) - 1;
    memcpy(ether.buffer + 54, html_2, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_3) - 1;
    memcpy(ether.buffer + 54, html_3, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_4) - 1;
    memcpy(ether.buffer + 54, html_4, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_5) - 1;
    memcpy(ether.buffer + 54, html_5, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_6) - 1;
    memcpy(ether.buffer + 54, html_6, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_7) - 1;
    memcpy(ether.buffer + 54, html_7, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_8) - 1;
    memcpy(ether.buffer + 54, html_8, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_9) - 1;
    memcpy(ether.buffer + 54, html_9, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_10) - 1;
    memcpy(ether.buffer + 54, html_10, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_11) - 1;
    memcpy(ether.buffer + 54, html_11, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_12) - 1;
    memcpy(ether.buffer + 54, html_12, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_13) - 1;
    memcpy(ether.buffer + 54, html_13, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_14) - 1;
    memcpy(ether.buffer + 54, html_14, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_15) - 1;
    memcpy(ether.buffer + 54, html_15, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_16) - 1;
    memcpy(ether.buffer + 54, html_16, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_17) - 1;
    memcpy(ether.buffer + 54, html_17, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_18) - 1;
    memcpy(ether.buffer + 54, html_18, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_19) - 1;
    memcpy(ether.buffer + 54, html_19, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_20) - 1;
    memcpy(ether.buffer + 54, html_20, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_21) - 1;
    memcpy(ether.buffer + 54, html_21, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_22) - 1;
    memcpy(ether.buffer + 54, html_22, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_23) - 1;
    memcpy(ether.buffer + 54, html_23, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_24) - 1;
    memcpy(ether.buffer + 54, html_24, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_25) - 1;
    memcpy(ether.buffer + 54, html_25, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_26) - 1;
    memcpy(ether.buffer + 54, html_26, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V);
    len = sizeof (html_27) - 1;
    memcpy(ether.buffer + 54, html_27, len);
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V + TCP_FLAGS_FIN_V);
    len = 0;
}

int main(int argc, char** argv) {
  //  Serial.begin(serial_baud);
   ether.delay(1000);
  //  Serial.print("testing\r\n");
   RTCC rtc;
   //  0x09000000 = set time to 09 hr, 0 min, 0 sec
  //0x04050119 =  set date to Wednesday 1 May 2019
   rtc.init_RTCC();
   rtc.set_RTCC_time_date(0x09000000 , 0x19050103);
   
    eeprom eprom;
   
    eprom.init_EEPROM(100000);
//    uint16_t eeAddress = 64;
//    uint8_t data[] = {'n','b','w',' ','o','n'};
//    uint8_t data1[6];
//    uint8_t numBytes = 6;
//    eprom.write_EEPROM( eeAddress, &data[0],  numBytes);
//    ether.delay(10);
//    eprom.read_EEPROM( eeAddress +1,  &data1[0],  numBytes-1);
 //   };
//    int h_s = 0;
//    int sss[28] = {0};// = new int[35]; 
//         sss[0] = sizeof(html_0);
//         sss[1] = sizeof(html_1);
//         sss[2] = sizeof(html_2);
//         sss[3] = sizeof(html_3);
//         sss[4] = sizeof(html_4);
//         sss[5] = sizeof(html_5);
//         sss[6] = sizeof(html_6);
//         sss[7] = sizeof(html_7);
//         sss[8] = sizeof(html_8);
//         sss[9] = sizeof(html_9);
//         sss[10] = sizeof(html_10);
//         sss[11] = sizeof(html_11);
//         sss[12] = sizeof(html_12);
//         sss[13] = sizeof(html_13);
//         sss[14] = sizeof(html_14);
//         sss[15] = sizeof(html_15);
//         sss[16] = sizeof(html_16);
//         sss[17] = sizeof(html_17);
//         sss[18] = sizeof(html_18);
//         sss[19] = sizeof(html_19);
//         sss[20] = sizeof(html_20);
//         sss[21] = sizeof(html_21);
//         sss[22] = sizeof(html_22);
//         sss[23] = sizeof(html_23);
//         sss[24] = sizeof(html_24);
//         sss[25] = sizeof(html_25);
//         sss[26] = sizeof(html_26);
//         sss[27] = sizeof(html_27);
    
    
    
    
    
    if (ether.begin(mymac, 10) == 0) {
    }
    ether.delay(1000);
    bool connected = ether.staticSetup(myip, gwip);
    if (connected)ether.delay(1000);


    int loop = 1;
    while (loop) {
        uint8_t proc = 0;
        int i = 10;
        uint16_t len = ether.packetReceive();
        uint16_t pos = ether.packetLoop(len);
        if (pos) {
            proc = ether.GET_OR_POST(pos, len);
            switch (proc) {
                case 0:
                    ether.httpServerReplyAck();                    
                    break;
                case 1:
                    homePage();
                    break;
                case 2:
                    refresh();
                    break;
                case 3:
                    update();
                    break;
                case 4:
                    if (data_in(len) == 1) {
                        Serial.println(current.timestamp);
                        if(current.timestamp > 1500000000){
                        Date_Time ts = convert_timestamp(current.timestamp);
                        Serial.print(ts.hr);Serial.print(":");
                        Serial.print(ts.min);Serial.print(":");
                        Serial.print(ts.sec);Serial.print("   ");
                        Serial.print(ts.day);Serial.print("-");
                        Serial.print(ts.month);Serial.print("-");
                        Serial.println(ts.year);}
                        else Serial.println("no date");
                    } else Serial.println("false date");;
                    break;
               }
        }
    }
    return 0;

}

