EESchema Schematic File Version 4
LIBS:Weather-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 13
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 2150 2850 0    50   Input ~ 0
J2_P1
Text HLabel 2150 2500 0    50   Input ~ 0
J2_P2
Text HLabel 8350 2950 2    50   Input ~ 0
J3_P1
Text HLabel 8350 2800 2    50   Input ~ 0
J3_P2
Text HLabel 8350 2650 2    50   Input ~ 0
J3_P3
Text HLabel 8350 2500 2    50   Input ~ 0
J3_P4
$Comp
L Weather-rescue:ESP-01v090-ESP8266 U?
U 1 1 5C9306F6
P 5800 2650
AR Path="/5C9306F6" Ref="U?"  Part="1" 
AR Path="/5C9253D5/5C9306F6" Ref="U2"  Part="1" 
F 0 "U2" H 5800 3165 50  0000 C CNN
F 1 "ESP-01v090" H 5800 3074 50  0000 C CNN
F 2 "footprint:ESP-01" H 5800 2650 50  0001 C CNN
F 3 "http://l0l.org.uk/2014/12/esp8266-modules-hardware-guide-gotta-catch-em-all/" H 5800 2650 50  0001 C CNN
	1    5800 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 2500 7850 2950
Wire Wire Line
	7850 2950 8350 2950
Wire Wire Line
	8000 2700 8000 2800
Wire Wire Line
	8000 2800 8350 2800
Wire Wire Line
	8150 2600 8150 2650
Wire Wire Line
	8150 2650 8350 2650
Wire Wire Line
	2150 2850 2500 2850
Wire Wire Line
	2500 2850 2500 3350
Wire Wire Line
	2500 3350 3550 3350
Wire Wire Line
	7850 3350 7850 2950
Connection ~ 7850 2950
$Comp
L MyComponents:AMS1117 U1
U 1 1 5C938BB3
P 3100 1600
F 0 "U1" V 2600 1550 60  0000 L CNN
F 1 "AMS1117" V 3600 1400 60  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 3100 1600 60  0001 C CNN
F 3 "" H 3100 1600 60  0000 C CNN
	1    3100 1600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3550 1850 3550 3350
Wire Wire Line
	3750 2800 3750 2300
Wire Wire Line
	3750 1600 3550 1600
Wire Wire Line
	2500 2500 2500 1000
Wire Wire Line
	2500 1000 3550 1000
Wire Wire Line
	3550 1000 3550 1350
$Comp
L Device:C C2
U 1 1 5C941E83
P 3950 3200
F 0 "C2" H 4065 3246 50  0000 L CNN
F 1 "0.1uF" H 4065 3155 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.8mm_W2.6mm_P2.50mm" H 3988 3050 50  0001 C CNN
F 3 "~" H 3950 3200 50  0001 C CNN
	1    3950 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 2500 2500 2500
$Comp
L Device:CP C1
U 1 1 5C944F87
P 2500 2700
F 0 "C1" H 2618 2746 50  0000 L CNN
F 1 "47uF" H 2618 2655 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_Tantal_D5.0mm_P2.50mm" H 2538 2550 50  0001 C CNN
F 3 "~" H 2500 2700 50  0001 C CNN
	1    2500 2700
	1    0    0    -1  
$EndComp
Connection ~ 2500 2850
$Comp
L Device:CP C3
U 1 1 5C945952
P 4350 3200
F 0 "C3" H 4468 3246 50  0000 L CNN
F 1 "47uF" H 4468 3155 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_Tantal_D5.0mm_P2.50mm" H 4388 3050 50  0001 C CNN
F 3 "~" H 4350 3200 50  0001 C CNN
	1    4350 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 2500 7850 2500
Wire Wire Line
	6750 2700 8000 2700
Wire Wire Line
	6750 2600 8150 2600
Connection ~ 3950 3350
Wire Wire Line
	3950 3350 4350 3350
Wire Wire Line
	3750 2800 3950 2800
Wire Wire Line
	3550 3350 3950 3350
Connection ~ 3550 3350
Wire Wire Line
	4350 3350 7850 3350
Connection ~ 4350 3350
Wire Wire Line
	4350 3050 4350 2800
Connection ~ 4350 2800
Wire Wire Line
	4350 2800 4850 2800
Wire Wire Line
	3950 3050 3950 2800
Connection ~ 3950 2800
Wire Wire Line
	3950 2800 4350 2800
Text Label 3000 1500 0    50   ~ 0
3.3v
$Comp
L Device:R R2
U 1 1 5C9520C8
P 4300 2450
F 0 "R2" H 4370 2496 50  0000 L CNN
F 1 "4.7K" H 4370 2405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4230 2450 50  0001 C CNN
F 3 "~" H 4300 2450 50  0001 C CNN
	1    4300 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5C953C46
P 4050 2450
F 0 "R1" H 4120 2496 50  0000 L CNN
F 1 "10k" H 4120 2405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3980 2450 50  0001 C CNN
F 3 "~" H 4050 2450 50  0001 C CNN
	1    4050 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 2300 4050 2300
Wire Wire Line
	4050 2300 3750 2300
Connection ~ 4050 2300
Connection ~ 3750 2300
Wire Wire Line
	3750 2300 3750 1600
Wire Wire Line
	4300 2600 4850 2600
Wire Wire Line
	4050 2700 4850 2700
Wire Wire Line
	4050 2600 4050 2700
Wire Wire Line
	2500 2550 2500 2500
Connection ~ 2500 2500
Wire Wire Line
	3550 1350 8150 1350
Wire Wire Line
	8150 1350 8150 2500
Wire Wire Line
	8150 2500 8350 2500
Connection ~ 3550 1350
Text Label 8200 2650 0    50   ~ 0
SCL
Text Label 8200 2800 0    50   ~ 0
SDA
Text Label 8200 2500 0    50   ~ 0
5v
Text Label 8200 2950 0    50   ~ 0
GND
$EndSCHEMATC
