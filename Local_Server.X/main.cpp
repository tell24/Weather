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
#pragma config FSOSCEN  = OFF           // Secondary Oscillator Enable (KLO was off)
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
"<html>"
"<head>"
"<metacharset='utf-8'>"
"<title>Weather</title>"
"<metaname='generator'content='GoogleWebDesigner5.0.4.0226'>"
"<styletype='text/css'id='gwd-text-style'>"
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
"}"
".sidenava{"
"padding:5px5px5px32px;"
"text-decoration:none;"
"font-size:25px;"
"color:rgb(192,192,192);"
"display:block;"
"}"
".sidenava:hover{"
"color:rgb(241,241,241);"
"}"
".data{"
"position:absolute;"
"margin:auto;"
"text-align:center;"
"overflow:auto;"
"top:0px;"
"height:750px;"
"width:100%;"
"}"
".about{"
"top:0px;"
"text-align:left;"
"position:absolute;"
"margin-left:430px;"
"width:1100px;"
"}"
".graph{"
"top:0px;"
"text-align:left;"
"position:absolute;"
"margin-left:130px;"
"width:1100px;"
"}"
".cent{"
"text-align:left;"
"position:relative;"
"margin:auto;"
"width:1160px;"
"}"
".cent_c{"
"text-align:left;"
"position:relative;"
"margin:auto;"
"width:1000px;"
"}"
".column{"
"float:left;"
"height:680px;"
"width:370px;"
"text-align:center;"
"}"
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
"}";

const char html_1[] =
"@media(max-height:450px){"
".sidenav{"
"padding-top:10px;"
"}"
".sidenava{"
"font-size:18px;"
"}"
"}"
"</style>"
"<styletype='text/css'>"
"html,body{"
"width:100%;"
"height:100%;"
"margin:0px;"
"}"
"body{"
"background-color:transparent;"
"transform:perspective(1400px)matrix3d(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);"
"transform-style:preserve-3d;"
"}"
"</style>"
"<scripttype='text/javascript'>"
"varsel;"
"varsort_update;"
"functionhandleSelect(){"
"sel=document.getElementById('duration').value;"
"//WaitDownload();"
"active_window=1;"
"sort_update();"
"}"
"window.onload=function(){"
"varL1=130;"
"varL2=350;"
"varL3=570;"
"varxhr;"
"varH_offset=0;"
"varactive_window=1;"
"varp_col='#5050f8';"
"varpeak_col='#ff0000';"
"varcol1='#cc1c5e';"
"varcol2='#e730e7';"
"varcol3='#2c57eb';"
"varcol4='#39dddd';"
"varr_col='#8cc8e8';"
"varPI=3.1416;"
"varrad=57.2958;"
"varrain_scale=137;"
"varmarker=0;"
"varmark=true;"
"varc=document.getElementById('canvas');"
"vardia=80;"
"vardia_small=70;"
"varmyMsg;"
"varm_len=30;"
"varlen=30;"
"varchart=[document.getElementById('canvas_a').getContext('2d'),"
"document.getElementById('canvas_b').getContext('2d'),"
"document.getElementById('canvas_c').getContext('2d'),";

const char html_2[] =
"document.getElementById('canvas_d').getContext('2d'),"
"document.getElementById('canvas_e').getContext('2d')"
"];"
"vartitles=['Temperature','','Humidity','','Pressure','WindSpeed','','RainFall'];"
"varplot=['OutHigh','InHigh','OutHigh','InHigh','High','Gust','Mean','Total','OutLow','InLow','OutLow','InLow','Low'];"
"varaxis_x_label=['Minutes','Hours','January','Febuary','March','April','May','June','July','August','September','October','November','December'];"
"varaxis_y_label=['C','','%','','mB','mph','','mm'];"
"varmyarr;"
"varm_m_arr;"
"document.getElementById('canvas_b').addEventListener('click',canvas_b_click);"
"document.getElementById('canvas_c').addEventListener('click',canvas_c_click);"
"document.getElementById('canvas_d').addEventListener('click',canvas_d_click);"
"document.getElementById('canvas_e').addEventListener('click',canvas_e_click);"
"//StartCurrentPage"
"functiondraw_dial(loc,win){"
"varx1,y1;"
"varident;"
"varscale=5,"
"start=-20;"
"vartext='';"
"win.textAlign='center';"
"win.fillStyle='Black';"
"win.font='14pxArial';"
"switch(loc){"
"case0:"
"x1=166;"
"y1=L1;"
"ident=13;"
;

const char html_3[] =

"scale=5;"
"start=-20;"
"text='InsideTemperature(C)';"
"break;"
"case1:"
"x1=832;"
"y1=L1;"
"ident=13;"
"scale=5;"
"start=-20;"
"text='OutsideTemperature(C)';"
"break;"
"case2:"
"x1=166;"
"y1=L2;"
"ident=11;"
"scale=10;"
"start=0;"
"text='InsideHumidity(%)';"
"break;"
"case3:"
"x1=832;"
"y1=L2;"
"ident=11;"
"scale=10;"
"start=0;"
"text='OutsideHumidity(%)';"
"break;"
"case4:"
"x1=500;"
"y1=L1;"
"ident=11;"
"scale=20;"
"start=860;"
"text='AirPressure(mb)';"
"break;"
"case5:"
"x1=166;"
"y1=L3;"
"ident=11;"
"scale=5;"
"start=0;"
"text='WindSpeed(mph)';"
"break;"
"}"
"varstep=240/(ident-1);"
"varoffset=dia*0.707;"
"win.beginPath();"
"win.arc(x1,y1,dia,0.75*PI,0.25*PI);"
"win.stroke();"
"win.beginPath();"
"win.moveTo(x1-offset,y1+offset);"
"win.lineTo(x1+offset,y1+offset);"
"win.stroke();"
"varval;"
"for(vari=0;i<ident;i++){"
"varx2,y2,x3,y3;"
"varang=(-30+(step*i))/rad;"
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
"}";

const char html_4[] =
"win.fillText(text,x1,y1+80);"
"}"
"functiondraw_bearing(win){"
"varx=833;"
"vary=L3-20;"
"varident=8;"
"vardirection=['N','NE','E','SE','S','SW','W','NW'];"
"win.beginPath();"
"win.arc(x,y,dia_small,0,2*PI);"
"win.stroke();"
"win.beginPath();"
"win.textAlign='center';"
"win.fillStyle='Black';"
"win.font='14pxArial';"
"varstep=360/ident;"
"for(vari=0;i<ident;i++){"
"varx2,y2,x3,y3;"
"varang=(90+(step*i))/rad;"
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
"}"
"functiondata_plot(x,y,win){"
"vardelta;"
"vardia1=80;"
"varx1,y1;"
"varpeak=false;"
"switch(x){"
"case0:"
"delta=(1.1667-(((20+y)/90)*2))*PI;"
"x1=166;"
"y1=L1;"
"break;"
"case1:"
"delta=(1.1667-(((20+y)/90)*2))*PI;"
"x1=832;"
"y1=L1;"
"break;"
"case2:"
"delta=(1.1667-((y/150)*2))*PI;"
"x1=166;"
"y1=L2;"
"break;"
"case3:"
"delta=(1.1667-((y/150)*2))*PI;"
;

const char html_5[] =
"x1=832;"
"y1=L2;"
"break;"
"case4:"
"delta=(1.1667-(((y-860)/300)*2))*PI;"
"x1=500;"
"y1=L1;"
"break;"
"case5:"
"delta=(1.1667-((y/75)*2))*PI;"
"x1=166;"
"y1=L3;"
"break;"
"case6:"
"delta=(0.5-((y/360)*2))*PI;"
"x1=832;"
"y1=L3-20;"
"dia1=70;"
"break;"
"case7:"
"delta=(1.1667-((y/75)*2))*PI;"
"x1=166;"
"y1=L3;"
"peak=true;"
"break;"
"}"
"varx2,y2,x3,y3,x4,y4;"
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
"win.font='16pxArial';"
"win.fillText(y,x1,y1+20);"
"}else{"
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
;

const char html_6[] =
"win.fill();"
"win.font='16pxArial';"
"if(x!=6)win.fillText(y,x1,y1);"
"}"
"win.font='14pxArial';"
"}"
"functiondraw_rain(win){"
"win.rect(449,250,52,152);"
"win.rect(501,250,52,152);"
"win.stroke();"
"win.beginPath();"
"win.textAlign='center';"
"win.fillStyle='Black';"
"win.font='14pxArial';"
"win.fillText('rate',370,310);"
"win.fillText('of',370,325);"
"win.fillText('fall',370,340);"
"win.fillText('/hr',370,355);"
"win.fillText('total',620,320);"
"win.fillText('this',620,335);"
"win.fillText('hr',620,350);"
"win.fillText('RainFall(mm)',500,L2+80);"
"}"
"functionrain_plot(now,total,win){"
"now/=(rain_scale/60);"
"total/=rain_scale;"
"varn_scale=Math.ceil(now+0.5);"
"vart_scale=Math.ceil(total+0.5);"
"varn_ticks=Math.ceil(n_scale/5);"
"varticks=152/5;"
"vars=0;"
"varnum=s.toFixed(1);"
"vary=402;"
"varcount=5;"
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
"varn_s=152*(now/num);"
"vart_ticks=Math.ceil(t_scale/5);"
"ticks=152/5;"
"s=0;"
"num=s.toFixed(1);";

const char html_7[] =

"vary=402;"
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
"varn_t=152*(total/num);"
"win.beginPath();"
"win.fillStyle=r_col;"
"win.rect(450,402-n_s,50,n_s);"
"win.fill();"
"win.beginPath();"
"win.fillStyle='Blue';"
"win.rect(502,402-n_t,50,n_t);"
"win.fill();"
"}"
"functiondrawHand(win,pos,length,width){"
"win.beginPath();"
"win.lineWidth=width;"
"win.lineCap='round';"
"win.moveTo(500,L3);"
"varx=Math.sin(pos/rad)*length;"
"vary=Math.cos(pos/rad)*length;"
"win.lineTo(500+x,L3-y);"
"win.stroke();"
"}"
"functionclock(win){"
"varstep=30;"
"varcc=L3;"
"win.beginPath();"
"win.arc(500,cc,dia,0,2*PI);"
"win.stroke();"
"for(vari=1;i<=12;i++){"
"varx2,y2,x3,y3;"
"varang=(90+(step*i))/rad;"
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
;

const char html_8[] =
"win.fillText(i,x2,y2);"
"}"
"vard,h,m;"
"d=newDate();"
"h=d.getHours();"
"m=d.getMinutes();"
"h=h%12;"
"//hour"
"h=((h/12)*360)+((m/60)*30);"
"drawHand(win,h,dia*0.5,4);"
"//minute"
"m=(m/60)*360;"
"drawHand(win,m,dia*0.8,2);"
"win.lineWidth=1;"
"}"
"functionupdate_fields(){"
"xhr=newXMLHttpRequest();"
"vara='0';"
"varurl='https://script.google.com/macros/s/AKfycbzep_6TONHLbfjt1H23_iCb0DMc126LPo3smsun/exec?read=current';"
"xhr.onreadystatechange=function(){"
"if(xhr.readyState==4){"
"vart_r=xhr.responseText;"
"vardat=t_r.split(',');"
"varx=document.getElementById('cent_c');"
"x.style.display='block';"
"x=document.getElementById('canvas_area_1');"
"x.style.display='none';"
"x=document.getElementById('about');"
"x.style.display='none';"
"varctx=c.getContext('2d');"
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
;

const char html_9[] =
"else"
"data_plot(2,parseFloat(dat[22]),ctx);"
"if(parseFloat(dat[4])>100)"
"data_plot(3,parseFloat('100'),ctx);"
"else"
"data_plot(3,parseFloat(dat[4]),ctx);"
"data_plot(4,parseFloat(dat[25]),ctx);"
"data_plot(5,parseFloat(dat[7]),ctx);"
"data_plot(6,parseFloat(dat[10]),ctx);"
"data_plot(7,parseFloat(dat[13]),ctx);"
"rain_plot(parseFloat(dat[16]),parseFloat(dat[17]),ctx);"
"varx=document.getElementById('cent_c');"
"x.style.display='block';"
"}"
"};"
"xhr.open('GET',url);"
"xhr.send(null);"
"}"
"//StartHistoryPage"
"functionupdate_history(){"
"sel=document.getElementById('duration').value;"
"varurl1='https://script.google.com/macros/s/AKfycbzep_6TONHLbfjt1H23_iCb0DMc126LPo3smsun/exec?read='+sel;"
"xhr=newXMLHttpRequest();"
"xhr.onreadystatechange=function(){"
"if(xhr.readyState==4){"
"vart_r=xhr.responseText;"
"varall_dat=t_r.split(',');"
"len=30;"
"varindex=0;"
"varcell=2;"
"vartype=0;"
"switch(sel){"
"case'hour':"
"type=1;"
"mark=true;"
"len=59;"
"m_len=15;"
"do{"
"myarr[0][index]=all_dat[cell];//intemp"
"myarr[1][index]=all_dat[cell+18];//outtemp"
"myarr[2][index]=all_dat[cell+3];//outhum"
"myarr[3][index]=all_dat[cell+21];//inhum"
;

const char html_10[] = 
"myarr[4][index]=all_dat[cell+24];//pres"
"myarr[5][index]=all_dat[cell+9];//wind"
"myarr[6][index]=all_dat[cell+6];//gust"
"myarr[7][index]=all_dat[cell+15]/rain_scale;//rainmm"
"myarr[8][index]=all_dat[cell+1];//inlowtemp"
"myarr[9][index]=all_dat[cell+19];//outlowtemp"
"myarr[10][index]=all_dat[cell+4];//outlowhum"
"myarr[11][index]=all_dat[cell+22];//inlowhum"
"index++;"
"cell+=29;"
"}while(index<=len);"
"marker=all_dat[1770];"
"if(parseFloat(all_dat[2+(61*29)])<parseFloat(all_dat[20+(61*29)]))//templow"
"m_m_arr[0][0]=Math.floor(all_dat[2+(61*29)]);"
"else"
"m_m_arr[0][0]=Math.floor(all_dat[20+(61*29)]);"
"if(parseFloat(all_dat[3+(61*29)])>parseFloat(all_dat[21+(61*29)]))//temphigh"
"m_m_arr[1][0]=Math.ceil(all_dat[3+(61*29)]);"
"else"
"m_m_arr[1][0]=Math.ceil(all_dat[21+(61*29)]);"
"if(m_m_arr[1][0]>100)m_m_arr[1][0]=50;"
"m_m_arr[0][1]=m_m_arr[0][0];"
"m_m_arr[1][1]=m_m_arr[1][0];"
"if(parseFloat(all_dat[5+(61*29)])<parseFloat(all_dat[23+(61*29)]))//humlow"
"m_m_arr[0][2]=Math.floor(all_dat[5+(61*29)]);"
"else"
"m_m_arr[0][2]=Math.floor(all_dat[23+(61*29)]);"
"if(m_m_arr[0][2]<0)m_m_arr[0][2]=0;"
;

const char html_11[] = 
"if(parseFloat(all_dat[6+(61*29)])>parseFloat(all_dat[24+(61*29)]))//humhigh"
"m_m_arr[1][2]=Math.ceil(all_dat[6+(61*29)]);"
"else"
"m_m_arr[1][2]=Math.ceil(all_dat[24+(61*29)]);"
"if(m_m_arr[1][2]>100)m_m_arr[1][2]=100;"
"m_m_arr[0][3]=m_m_arr[0][2];"
"m_m_arr[1][3]=m_m_arr[1][2];"
"m_m_arr[0][4]=Math.floor(all_dat[26+(61*29)]);//peslow"
"m_m_arr[1][4]=Math.ceil(all_dat[27+(61*29)]);//preshigh"
"m_m_arr[0][5]=0;//windlow"
"if(parseFloat(all_dat[12+(61*29)])>parseFloat(all_dat[15+(61*29)]))//windhigh"
"m_m_arr[1][5]=Math.ceil(all_dat[12+(61*29)]);"
"else"
"m_m_arr[1][5]=Math.ceil(all_dat[15+(61*29)]);"
"if(m_m_arr[1][5]<2)m_m_arr[1][5]=2;"
"m_m_arr[0][6]=m_m_arr[0][5];"
"m_m_arr[1][6]=m_m_arr[1][5];"
"m_m_arr[0][7]=0;//rain"
"m_m_arr[1][7]=Math.ceil(all_dat[17+(62*29)]/rain_scale);"
"break;"
"case'day':"
"type=2;"
"mark=true;"
"len=24;"
"m_len=12;"
;

const char html_12[] = "";

const char html_13[] =
""
;

const char html_14[] =
""
;

const char html_15[] =

"do{"
"myarr[0][index]=all_dat[cell];//outhightemp"
"myarr[1][index]=all_dat[cell+18];//inhightemp"
"myarr[2][index]=all_dat[cell+3];//outhighhum"
"myarr[3][index]=all_dat[cell+21];//inhighhum"
"myarr[4][index]=all_dat[cell+24];//pres"
"myarr[5][index]=all_dat[cell+6];//wind"
"myarr[6][index]=all_dat[cell+9];//gust"
"myarr[7][index]=all_dat[cell+16]/rain_scale;//rainmm"
"myarr[8][index]=all_dat[cell+1];//inlowtemp"
"myarr[9][index]=all_dat[cell+19];//outlowtemp"
"myarr[10][index]=all_dat[cell+4];//outlowhum"
"myarr[11][index]=all_dat[cell+22];//inlowhum"
"myarr[12][index]=all_dat[cell+25];//lowpres"
"index++;"
"cell+=29;"
"}while(index<=len);"
"marker=all_dat[784];";

const char html_16[] =
"if(parseFloat(all_dat[2+(27*29)])<parseFloat(all_dat[20+(27*29)]))//templow"
"m_m_arr[0][0]=Math.floor(all_dat[2+(27*29)]);"
"else"
"m_m_arr[0][0]=Math.floor(all_dat[20+(27*29)]);"
"if(parseFloat(all_dat[3+(27*29)])>parseFloat(all_dat[21+(27*29)]))//temphigh"
"m_m_arr[1][0]=Math.ceil(all_dat[3+(27*29)]);"
"else"
"m_m_arr[1][0]=Math.ceil(all_dat[21+(27*29)]);"
"if(m_m_arr[1][0]>100)m_m_arr[1][0]=50;"
"m_m_arr[0][1]=m_m_arr[0][0];"
"m_m_arr[1][1]=m_m_arr[1][0];"
"if(parseFloat(all_dat[5+(27*29)])<parseFloat(all_dat[23+(27*29)]))//humlow"
"m_m_arr[0][2]=Math.floor(all_dat[5+(27*29)]);"
"else"
"m_m_arr[0][2]=Math.floor(all_dat[23+(27*29)]);"
"if(m_m_arr[0][2]<0)m_m_arr[0][2]=0;"
"if(parseFloat(all_dat[6+(27*29)])>parseFloat(all_dat[24+(27*29)]))//humhigh"
"m_m_arr[1][2]=Math.ceil(all_dat[6+(27*29)]);"
"else"
"m_m_arr[1][2]=Math.ceil(all_dat[24+(27*29)]);"
"if(m_m_arr[1][2]>100)m_m_arr[1][2]=100;"
"m_m_arr[0][3]=m_m_arr[0][2];"
"m_m_arr[1][3]=m_m_arr[1][2];";

const char html_17[] =
"m_m_arr[0][4]=Math.floor(all_dat[26+(27*29)]);//peslow"
"m_m_arr[1][4]=Math.ceil(all_dat[27+(27*29)]);//preshigh"
"m_m_arr[0][5]=0;//windlow"
"if(parseFloat(all_dat[12+(27*29)])>parseFloat(all_dat[15+(27*29)]))//windhigh"
"m_m_arr[1][5]=Math.ceil(all_dat[12+(27*29)]);"
"else"
"m_m_arr[1][5]=Math.ceil(all_dat[15+(27*29)]);"
"if(m_m_arr[1][5]<2)m_m_arr[1][5]=2;"
"m_m_arr[0][6]=m_m_arr[0][5];"
"m_m_arr[1][6]=m_m_arr[1][5];"
"m_m_arr[0][7]=0;//rain"
"m_m_arr[1][7]=Math.ceil(all_dat[18+(28*29)]/rain_scale);"
"break;"
"default:"
"type=2;"
"mark=false;"
"vard=newDate();"
"m=parseInt(d.getMonth());"
"varsm=parseInt(document.getElementById('duration').selectedIndex)-2;"
"if(sm===m)"
"len=parseInt(d.getDate())-2;"
"else{"
"if((sm===3)||(sm===5)||(sm===8)||(sm===10))len=29;"
"elselen=30;"
"if(sm===1)"
"if(d.getFullYear()%4===0)len=28;"
"elselen=27;"
"}";

const char html_18[] =
"do{"
"myarr[0][index]=all_dat[cell];//outhightemp"
"myarr[1][index]=all_dat[cell+18];//inhightemp"
"myarr[2][index]=all_dat[cell+3];//outhighhum"
"myarr[3][index]=all_dat[cell+21];//inhighhum"
"myarr[4][index]=all_dat[cell+24];//pres"
"myarr[5][index]=all_dat[cell+6];//wind"
"myarr[6][index]=all_dat[cell+9];//gust"
"myarr[7][index]=all_dat[cell+16]/rain_scale;//rain"
"myarr[8][index]=all_dat[cell+1];//inlowtemp"
"myarr[9][index]=all_dat[cell+19];//outlowtemp"
"myarr[10][index]=all_dat[cell+4];//outlowhum"
"myarr[11][index]=all_dat[cell+22];//inlowhum"
"myarr[12][index]=all_dat[cell+25];//lowpres"
"index++;"
"cell+=29;"
"}while(index<=len);"
"if(parseFloat(all_dat[2+(33*29)])<parseFloat(all_dat[20+(33*29)]))//templow"
"m_m_arr[0][0]=Math.floor(all_dat[2+(33*29)]);"
"else"
"m_m_arr[0][0]=Math.floor(all_dat[20+(33*29)]);"
"if(parseFloat(all_dat[3+(33*29)])>parseFloat(all_dat[21+(33*29)]))//temphigh"
"m_m_arr[1][0]=Math.ceil(all_dat[3+(33*29)]);"
"else";

const char html_19[] =
"m_m_arr[1][0]=Math.ceil(all_dat[21+(33*29)]);"
"if(m_m_arr[1][0]>100)m_m_arr[1][0]=50;"
"m_m_arr[0][1]=m_m_arr[0][0];"
"m_m_arr[1][1]=m_m_arr[1][0];"
"if(parseFloat(all_dat[5+(33*29)])<parseFloat(all_dat[23+(33*29)]))//humlow"
"m_m_arr[0][2]=Math.floor(all_dat[5+(33*29)]);"
"else"
"m_m_arr[0][2]=Math.floor(all_dat[23+(33*29)]);"
"if(m_m_arr[0][2]<0)m_m_arr[0][2]=0;"
"if(parseFloat(all_dat[6+(33*29)])>parseFloat(all_dat[24+(33*29)]))//humhigh"
"m_m_arr[1][2]=Math.ceil(all_dat[6+(33*29)]);"
"else"
"m_m_arr[1][2]=Math.ceil(all_dat[24+(33*29)]);"
"if(m_m_arr[1][2]>100)m_m_arr[1][2]=100;"
"m_m_arr[0][3]=m_m_arr[0][2];"
"m_m_arr[1][3]=m_m_arr[1][2];"
"m_m_arr[0][4]=Math.floor(all_dat[26+(33*29)]);//peslow"
"m_m_arr[1][4]=Math.ceil(all_dat[27+(33*29)]);//preshigh"
"m_m_arr[0][5]=0;//windlow"
"if(parseFloat(all_dat[12+(33*29)])>parseFloat(all_dat[15+(33*29)]))//windhigh"
"m_m_arr[1][5]=Math.ceil(all_dat[12+(33*29)]);"
"else";

const char html_20[] =
"m_m_arr[1][5]=Math.ceil(all_dat[15+(33*29)]);"
"if(m_m_arr[1][5]<2)m_m_arr[1][5]=2;"
"m_m_arr[0][6]=m_m_arr[0][5];"
"m_m_arr[1][6]=m_m_arr[1][5];"
"m_m_arr[0][7]=0;//rain"
"m_m_arr[1][7]=Math.ceil(all_dat[18+(33*29)]/rain_scale);"
"m_len=Math.ceil((len+1)/2);"
"break;"
"}"
"varcount=7;"
"do{"
"if(m_m_arr[1][count]-m_m_arr[0][count]<1)m_m_arr[1][count]=m_m_arr[0][count]+1;"
"count--;"
"}while(count>0);"
"build_history(type,len);"
"}"
"};"
"xhr.open('GET',url1);"
"xhr.send(null);"
"}"
"functionbuild_history(data_valid,len){"
"vartemp=newArray();"
"varmin=0;"
"varmax=1;"
"varticks=30;"
"varpoints=60;"
"varfirst=1;"
"if(data_valid>0){"
"switch(sel){"
"case'hour':"
"ticks=15;"
"points=60;"
"first=0;"
"break;"
"case'day':"
"ticks=12;"
"points=23;"
"break;"
"default:"
"ticks=m_len;"
"points=len;"
"break;"
"}"
"}"
"varplots=0;"
"varrange=0;"
"vard_set;";

const char html_21[] =
"switch(H_offset){"
"case0:"
"d_set=0;"
"break;"
"case1:"
"d_set=2;"
"break;"
"case2:"
"d_set=4;"
"break;"
"case3:"
"d_set=5;"
"break;"
"case4:"
"d_set=7;"
"break;"
"}"
"switch(data_valid){"
"case0:"
"do{"
"min=0;"
"max=2;"
"range=2"
"draw_graph(plots,range,min,ticks,points,0,0);"
"plots++;"
"}while(plots<5);"
"break;"
"case1:"
"do{"
"min=m_m_arr[0][d_set];"
"max=m_m_arr[1][d_set];"
"range=max-min;"
"if(plots===0){"
"range=Math.ceil(range/8)*8;"
"if(max<(range/2))"
"range=Math.ceil(range/2);"
"if(max<(range/2))"
"range=Math.ceil(range/2);"
"}else{"
"range=Math.ceil(range/4)*4;"
"if(max<(range/2))"
"range=Math.ceil(range/2);"
"}"
"if((d_set===2)||(d_set===3)){"
"if(range+min>100)min=100-range;"
"}"
"draw_graph(plots,range,min,ticks,points,d_set,first);"
"temp=newArray();"
"temp=myarr[d_set];"
"fill_chart(0,plots,temp,range,min,points,d_set);"
"if((d_set===0)||(d_set===2)||(d_set===5)){"
"d_set++;"
"temp=newArray();"
"temp=myarr[d_set];"
"fill_chart(1,plots,temp,range,min,points,d_set);"
"}";

const char html_22[] =
"d_set++;"
"if(d_set===8)d_set=0;"
"plots++;"
"}while(plots<5);"
"break;"
"case2:"
"do{"
"min=m_m_arr[0][d_set];"
"max=m_m_arr[1][d_set];"
"range=max-min;"
"if(plots===0){"
"range=Math.ceil(range/8)*8;"
"if(max<(range/2))"
"range=Math.ceil(range/2);"
"if(max<(range/2))"
"range=Math.ceil(range/2);"
"}else{"
"range=Math.ceil(range/4)*4;"
"if(max<(range/2))"
"range=Math.ceil(range/2);"
"}"
"if((d_set===2)||(d_set===3)){"
"if(range+min>100)min=100-range;"
"}"
"draw_graph(plots,range,min,ticks,points,d_set,first);"
"temp=newArray();"
"temp=myarr[d_set];"
"if((d_set===4)||(d_set===7)){"
"fill_chart(0,plots,temp,range,min,points,d_set);"
"}"
"if(d_set===5){"
"fill_chart(0,plots,temp,range,min,points,d_set);"
"d_set++;"
"temp=newArray();"
"temp=myarr[d_set];"
"fill_chart(1,plots,temp,range,min,points,d_set);"
"}"
"if((d_set===0)||(d_set===2)){"
"fill_chart(2,plots,temp,range,min,points,d_set);"
"temp=newArray();"
"temp=myarr[d_set+8];"
"fill_chart(4,plots,temp,range,min,points,d_set+8);"
"}";

const char html_23[] =
"if((d_set===0)||(d_set===2)){"
"d_set++;"
"temp=newArray();"
"temp=myarr[d_set];"
"fill_chart(3,plots,temp,range,min,points,d_set);"
"if((d_set===1)||(d_set===3)){"
"temp=newArray();"
"temp=myarr[d_set+8];"
"fill_chart(5,plots,temp,range,min,points,d_set+8);"
"}"
"}"
"d_set++;"
"if(d_set===8)d_set=0;"
"plots++;"
"}while(plots<5);"
"break;"
"}"
"myMsg.close();"
"varx=document.getElementById('cent_c');"
"x.style.display='none';"
"x=document.getElementById('canvas_area_1');"
"x.style.display='block';"
"x=document.getElementById('about');"
"x.style.display='none';"
"}"
"functiondraw_graph(num,range,min,ticks,points,t_index,first){"
"varsm=parseInt(document.getElementById('duration').selectedIndex);"
"varctx=chart[num];"
"ctx.font='10pxArial';"
"vary_inc=range/4;"
"varx=60;"
"vary=30;"
"varw=300;"
"varh=100;"
"varys=100/4;"
"varsteps=4;"
"varx_step=Math.round(points/ticks);"
"ctx.fillStyle='White';";

const char html_24[] =
"if(num===0){"
"w=700;"
"h=600;"
"steps=8;"
"y_inc=range/8;"
"ys=h/8;"
"ctx.fillRect(0,0,800,780);"
"}else"
"ctx.fillRect(0,0,400,170);"
"ctx.fillStyle='black';"
"ctx.beginPath();"
"ctx.lineWidth=1;"
"ctx.strokeStyle='grey';"
"ctx.rect(x,y,w,h);"
"ctx.stroke();"
"ctx.textAlign='center';"
"varxl=x;"
"varxs=(w/(points))*x_step;"
"varc_b=y+h;"
"vari=first;"
"ctx.font='11pxArial';"
"ctx.beginPath();"
"ctx.fillText(i,xl,y+h+14);"
"while(xl<=(w+x)){"
"xl+=xs;"
"if(w+x-10<=xl)break;"
"ctx.moveTo(xl,y);"
"ctx.lineTo(xl,c_b);"
"i+=x_step;"
"ctx.fillText(i,xl,y+h+14);"
"};"
"ctx.fillText(points+first,w+x,y+h+14);"
"ctx.stroke();"
"varyl=y;"
"c_b=x+w;"
"ctx.beginPath();"
"i=min+range;"
"varstep=range/steps;"
"while(yl<=(h+y)-1){"
"ctx.fillText(i,45,yl+5);"
"yl+=ys;"
"ctx.moveTo(x,yl);"
"ctx.lineTo(c_b,yl);"
"i-=step;"
"};"
"ctx.fillText(i,45,yl+5);"
"ctx.stroke();"
"ctx.font='13pxArial';"
"if(num===0)"
"ctx.fillText(axis_y_label[t_index],25,y+(h/2)-20);"
"else"
"ctx.fillText(axis_y_label[t_index],18,y+(h/2));"
"ctx.fillText(titles[t_index],x+(w/2),17);"
"ctx.fillText(axis_x_label[sm],x+(w/2),yl+28);"
"ctx.font='11pxArial';"
"ctx.strokeStyle='black';"
"ctx.fillStyle='black';"
"}";

const char html_25[] =
"functionfill_chart(col,c_num,p_data,range,min,p,type){"
"varctx=chart[c_num];"
"varx=60;"
"vary=30;"
"varw=300;"
"varh=100;"
"if(c_num===0){"
"w=700;"
"h=600;"
"};"
"varr_label=x+w-170;"
"if(col===0){"
"ctx.fillText(plot[type],130,17);"
"ctx.strokeStyle=col1;"
"ctx.fillStyle=col1;"
"ctx.fillRect(90,7,15,10);"
"}"
"if(col===1){"
"ctx.fillText(plot[type],r_label+130,17);"
"ctx.strokeStyle=col2;"
"ctx.fillStyle=col2;"
"ctx.fillRect(r_label+90,7,15,10);"
"//ctx.fillRect(110,7,15,10);"
"}"
"if(col===2){"
"ctx.fillText(plot[type],80,17);"
"ctx.strokeStyle=col3;"
"ctx.fillStyle=col3;"
"ctx.fillRect(110,7,15,10);"
"}"
"if(col===3){"
"ctx.fillText(plot[type],r_label+95,17);"
"ctx.strokeStyle=col4;"
"ctx.fillStyle=col4;"
"ctx.fillRect(r_label+120,7,15,10);"
"}"
"if(col===4){"
"ctx.fillText(plot[type],150,17);"
"ctx.strokeStyle=col1;"
"ctx.fillStyle=col1;"
"ctx.fillRect(40,7,15,10);"
"}"
"if(col===5){"
"ctx.fillText(plot[type],r_label+155,17);"
"ctx.strokeStyle=col2;"
"ctx.fillStyle=col2;"
"ctx.fillRect(r_label+60,7,15,10);"
"}";

const char html_26[] =
"vary_inc=h/range;"
"vari=min+range;"
"vars=0;"
"vary1=0;"
"varxs=w/p;"
"varxm=x+(xs*marker);"
"varhm=y+h;"
"if(i<p_data[0])p_data[0]=i;"
"y1=y+(y_inc*(i-p_data[0]));"
"ctx.lineWidth=2;"
"ctx.beginPath();"
"ctx.moveTo(x,y1);"
"do{"
"s++;"
"x+=xs;"
"if(i<p_data[s])p_data[s]=i;"
"y1=y+(y_inc*(i-p_data[s]));"
"if(y1>(y+h))"
"ctx.moveTo(x,y+h);"
"else"
"ctx.lineTo(x,y1);"
"}while(s<p);"
"ctx.stroke();"
"if(mark){"
"ctx.beginPath();"
"ctx.fillStyle='black';"
"ctx.moveTo(xm-5,hm);"
"ctx.lineTo(xm,hm-7);"
"ctx.lineTo(xm+5,hm);"
"ctx.lineTo(xm-5,hm);"
"ctx.fill();"
"}"
"ctx.strokeStyle='black';"
"ctx.fillStyle='black';"
"}";

const char html_27[] =
"functionmove_history(){"
"varmin;"
"varmax;"
"vartemp;"
"varpoints;"
"varrange;"
"varh_c=0;"
"varfirst=1;"
"varfun=0;"
"switch(sel){"
"case'hour':"
"points=60;"
"ticks=15;"
"first=0;"
"fun=1;"
"break;"
"case'day':"
"points=23;"
"ticks=12;"
"break;"
"default:"
"points=len;"
"ticks=m_len;"
"break;"
"}"
"switch(H_offset){"
"case0:"
"h_c=0;"
"break;"
"case1:"
"h_c=2;"
"break;"
"case2:"
"h_c=4;"
"break;"
"case3:"
"h_c=5;"
"break;"
"case4:"
"h_c=7;"
"break;"
"}"
"varplots=0;"
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
"}else{"
"range=Math.ceil(range/4)*4;"
"if(max<(range/2))"
"range=Math.ceil(range/2);"
"}"
"if((h_c===2)||(h_c===3)){"
"if(range+min>100)min=100-range;"
"}"
"draw_graph(plots,range,min,ticks,points,h_c,first);"
"temp=newArray();"
"temp=myarr[h_c];"
"if(h_c===4){"
"fill_chart(0,plots,temp,range,min,points,h_c);"
"}";

const char html_28[] =
"if(h_c===7){"
"fill_chart(0,plots,temp,range,min,points,h_c);"
"}"
"if((h_c===0)||(h_c===2)||(h_c===5)){"
"h_c++;"
"temp=newArray();"
"temp=myarr[h_c];"
"fill_chart(1,plots,temp,range,min,points,h_c);"
"}"
"h_c++;"
"if(h_c===8)h_c=0;"
"plots++;"
"}while(plots<5)"
"}else{"
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
"}else{"
"range=Math.ceil(range/4)*4;"
"if(max<(range/2))"
"range=Math.ceil(range/2);"
"}"
"if((h_c===2)||(h_c===3)){"
"if(range+min>100)min=100-range;"
"}"
"draw_graph(plots,range,min,ticks,points,h_c,first);"
"temp=newArray();"
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
"temp=newArray();"
"temp=myarr[h_c];"
"fill_chart(1,plots,temp,range,min,points,h_c);"
"}";

const char html_29[] =
"if((h_c===0)||(h_c===2)){"
"fill_chart(2,plots,temp,range,min,points,h_c);"
"temp=newArray();"
"temp=myarr[h_c+8];"
"fill_chart(4,plots,temp,range,min,points,h_c+8);"
"}"
"if((h_c===0)||(h_c===2)){"
"h_c++;"
"temp=newArray();"
"temp=myarr[h_c];"
"fill_chart(3,plots,temp,range,min,points,h_c);"
"if((h_c===1)||(h_c===3)){"
"temp=newArray();"
"temp=myarr[h_c+8];"
"fill_chart(5,plots,temp,range,min,points,h_c+8);"
"}"
"}"
"h_c++;"
"if(h_c===8)h_c=0;"
"plots++;"
"}while(plots<5)"
"}"
"}"
"functionWaitDownload(){"
"wLeft=window.screenLeft?window.screenLeft:window.screenX;"
"wTop=window.screenTop?window.screenTop:window.screenY;"
"varleft=wLeft+(window.innerWidth/2)-(100);"
"vartop=wTop+(window.innerHeight/2)-(50);"
"myMsg=window.open('','MsgWindow','toolbar=no,personalbar=no,directories=no,status=no,menubar=no,scrollbars=no,resizable=no,copyhistory=no,width=350,height=180,top='+top+',left='+left);"
"myMsg.document.write('<h1>DownloadingData</h1>');"
"myMsg.document.write('<h1>PleaseWait</h1>');"
"}";

const char html_30[] =
"functionmake_array(){"
"myarr=newArray();"
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
"m_m_arr=newArray();"
"m_m_arr.push([]);"
"m_m_arr.push([]);"
"}"
"sort_update=function(){"
"if(active_window==0)"
"update_fields();"
"if(active_window==1){"
"update_history();"
"}"
"}"
"document.getElementById('current').onclick=functionmyFunction(){"
"document.getElementById('duration').style.visibility='hidden';"
"document.getElementById('ld').style.visibility='hidden';"
"varx=document.getElementById('cent_c');"
"x.style.display='block';"
"x=document.getElementById('canvas_area_1');"
"x.style.display='none';"
"x=document.getElementById('about');"
"x.style.display='none';"
"active_window=0;"
"sort_update();"
"returnfalse;"
"}";

const char html_31[] =
"document.getElementById('history').onclick=functionmyFunction(){"
"document.getElementById('duration').style.visibility='visible';"
"document.getElementById('ld').style.visibility='visible';"
"varx=document.getElementById('cent_c');"
"x.style.display='none';"
"x=document.getElementById('canvas_area_1');"
"x.style.display='block';"
"x=document.getElementById('about');"
"x.style.display='none';"
"WaitDownload();"
"active_window=1;"
"sort_update();"
"returnfalse;"
"}"
"document.getElementById('about1').onclick=functionmyFunction(){"
"document.getElementById('duration').style.visibility='hidden';"
"document.getElementById('ld').style.visibility='hidden';"
"varx=document.getElementById('cent_c');"
"x.style.display='none';"
"x=document.getElementById('canvas_area_1');"
"x.style.display='none';"
"x=document.getElementById('about');"
"x.style.display='block';"
"returnfalse;"
"}"
"functioncanvas_b_click(){"
"H_offset+=1;"
"H_offset=H_offset%5;"
"move_history();"
"}";

const char html_32[] =
"functioncanvas_c_click(){"
"H_offset+=2;"
"H_offset=H_offset%5;"
"move_history();"
"}"
"functioncanvas_d_click(){"
"H_offset+=3;"
"H_offset=H_offset%5;"
"move_history();"
"}"
"functioncanvas_e_click(){"
"H_offset+=4;"
"H_offset=H_offset%5;"
"move_history();"
"}"
"varx=document.getElementById('cent_c');"
"x.style.display='block';"
"x=document.getElementById('canvas_area_1');"
"x.style.display='none';"
"x=document.getElementById('about');"
"x.style.display='none';"
"document.getElementById('duration').style.visibility='hidden';"
"document.getElementById('ld').style.visibility='hidden';"
"varmyVar=setInterval(sort_update,30000);"
"active_window=0;"
"make_array();"
"sort_update();"
"}"
"</script>"
"</head>"
"<bodyclass='htmlNoPages'>"
"<divclass='sidenav'>"
"<ahref='#'id='current'>Current</a>"
"<ahref='#'id='history'>History</a>"
"<ahref='#'id='about1'>About</a>"
"<div>"
"<pid='ld'left='20px'><fontcolor='#818181'>History</font>"
"</p>"
"</div>";

const char html_33[] =
"<selectname='optionList'id='duration'height='30'width='100'margin='auto'onchange='handleSelect()'>"
"<optionvalue='hour'>Hour</option>"
"<optionvalue='day'>Day</option>"
"<optionvalue='Jan'>January</option>"
"<optionvalue='Feb'>Febuary</option>"
"<optionvalue='Mar'>March</option>"
"<optionvalue='Apr'>April</option>"
"<optionvalue='May'>May</option>"
"<optionvalue='Jun'>June</option>"
"<optionvalue='Jul'>July</option>"
"<optionvalue='Aug'>August</option>"
"<optionvalue='Sep'>September</option>"
"<optionvalue='Oct'>October</option>"
"<optionvalue='Nov'>November</option>"
"<optionvalue='Dec'>December</option>"
"</select>"
"</div>"
"<divclass='data'id='Data'>"
"<divclass='graph'>"
"<divclass='cent_c'id='cent_c'>"
"<canvasid='canvas'height='780'width='1000'></canvas>"
"</div>"
"<divclass='cent'id='canvas_area_1'height='750'width='1180'>"
"<divclass='column'>"
"<divclass='row'>"
"<canvasid='canvas_b'width='400'height='170'></canvas>"
"</div>";

const char html_34[] =
"<divclass='row'>"
"<canvasid='canvas_c'width='400'height='170'></canvas>"
"</div>"
"<divclass='row'>"
"<canvasid='canvas_d'width='400'height='170'></canvas>"
"</div>"
"<divclass='row'>"
"<canvasid='canvas_e'width='400'height='170'></canvas>"
"</div>"
"</div>"
"<divclass='column_1'>"
"<canvasid='canvas_a'width='780'height='680'></canvas>"
"</div>"
"</div>"
"</div>"
"<divclass='about'id='about'>"
"<divclass='cent'>"
"<h3>WeatherStationOperation</h3>"
"<h4>Temperature</h4>"
"<p>SensorAM2320</p>"
"<h4>Humidity</h4>"
"<p>SensorAM2320</p>"
"<p></p>"
"<h4>AirPressure</h4>"
"<p>SensorBMP180</p>"
"<p></p>"
"<h4>RainFall</h4>"
"<p>CountnumberofdripsfromcalibratedTube</p>"
"<p></p>"
"<h4>WindSpeedandDirection</h4>"
"<p>UtrasonicSensors@N,S,E&amp;W</p>"
"<p>PulseSensorsN-S,S-N</p>"
"<p>MeasureTimeofFlighteachwaytocalculteN-Svector</p>"
"<p>PulseSensorsE-W,W-E</p>"
"<p>MeasureTimeofFlighteachwaytocalculteE-Wvector</p>"
"<p>CalculateSpeedofSoundusingTemperatureandHumidity</p>"
"<p>FromabovecalculateWindSpeedandBearingusingTrig</p>"
"</div>"
"</div>"
"</div>"
"</body>"
"</html>";
//
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
            + sizeof (html_18) - 1 + sizeof (html_19) - 1
            + sizeof (html_20) - 1 + sizeof (html_21) - 1;
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
    ether.httpServerReply_with_flags(len, TCP_FLAGS_ACK_V + TCP_FLAGS_FIN_V);
    len = 0;
}

int main(int argc, char** argv) {
 //   Serial.begin(serial_baud);
//   ether.delay(1000);
 //   Serial.print("testing\r\n");
 //   ether.delay(1000);
    int h_s = 0;
    int sss[35] = {0};// = new int[35]; 
         sss[0] = sizeof(html_0);
         sss[1] = sizeof(html_1);
         sss[2] = sizeof(html_2);
         sss[3] = sizeof(html_3);
         sss[4] = sizeof(html_4);
         sss[5] = sizeof(html_5);
         sss[6] = sizeof(html_6);
         sss[7] = sizeof(html_7);
         sss[8] = sizeof(html_8);
         sss[9] = sizeof(html_9);
         sss[10] = sizeof(html_10);
         sss[11] = sizeof(html_11);
         sss[12] = sizeof(html_12);
         sss[13] = sizeof(html_13);
         sss[14] = sizeof(html_14);
         sss[15] = sizeof(html_15);
         sss[16] = sizeof(html_16);
         sss[17] = sizeof(html_17);
         sss[18] = sizeof(html_18);
         sss[19] = sizeof(html_19);
         sss[20] = sizeof(html_20);
         sss[21] = sizeof(html_21);
         sss[22] = sizeof(html_22);
         sss[23] = sizeof(html_23);
         sss[24] = sizeof(html_24);
         sss[25] = sizeof(html_25);
         sss[26] = sizeof(html_26);
         sss[27] = sizeof(html_27);
         sss[28] = sizeof(html_28);
         sss[29] = sizeof(html_29);
         sss[30] = sizeof(html_30);
         sss[31] = sizeof(html_31);
         sss[32] = sizeof(html_32);
         sss[33] = sizeof(html_33);
         sss[34] = sizeof(html_34);
    
    
   int loop = 1;
    while (loop) {}
    
    
    
    
    if (ether.begin(mymac, 10) == 0) {
    }
    ether.delay(1000);
    bool connected = ether.staticSetup(myip, gwip);
    if (connected)ether.delay(1000);


 //   int loop = 1;
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

