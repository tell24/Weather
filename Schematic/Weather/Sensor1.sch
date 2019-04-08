EESchema Schematic File Version 4
LIBS:Weather-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 13
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 2650 1750 0    50   Input ~ 0
J4_P1
Text HLabel 2650 1900 0    50   Input ~ 0
J4_P2
Text HLabel 2650 2050 0    50   Input ~ 0
J4_P3
Text HLabel 2650 2200 0    50   Input ~ 0
J4_P4
$Comp
L Weather-rescue:HTU21-MyComponents MOD?
U 1 1 5C959FE9
P 5000 2850
AR Path="/5C959FE9" Ref="MOD?"  Part="1" 
AR Path="/5C9254A0/5C959FE9" Ref="MOD1"  Part="1" 
F 0 "MOD1" H 5628 2846 50  0000 L CNN
F 1 "HTU21" H 5628 2755 50  0000 L CNN
F 2 "footprint:HTU21" H 5200 2550 50  0001 C CNN
F 3 "" H 5200 2550 50  0001 C CNN
	1    5000 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 1750 2650 1750
Wire Wire Line
	2650 2200 3700 2200
Wire Wire Line
	4900 3200 3700 3200
Wire Wire Line
	4650 2750 4900 2750
Wire Wire Line
	2650 2050 3000 2050
Wire Wire Line
	3000 2050 3000 2400
Wire Wire Line
	3000 2400 4550 2400
Wire Wire Line
	2650 1900 3300 1900
Wire Wire Line
	3300 1900 3300 2300
Wire Wire Line
	3300 2300 4650 2300
Wire Wire Line
	4650 2300 4650 2750
$Comp
L MyComponents:BMP180 MOD2
U 1 1 5C958DD2
P 5050 1850
F 0 "MOD2" H 5678 1771 50  0000 L CNN
F 1 "BMP180" H 5678 1680 50  0000 L CNN
F 2 "footprint:BMP180" H 5250 1350 50  0001 C CNN
F 3 "" H 5250 1350 50  0001 C CNN
	1    5050 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 3200 3700 2200
Wire Wire Line
	4950 2200 3700 2200
Connection ~ 3700 2200
Wire Wire Line
	4000 2050 4000 1750
Wire Wire Line
	4950 2050 4000 2050
Wire Wire Line
	4950 1900 4800 1900
Wire Wire Line
	4800 1900 4800 2400
Wire Wire Line
	4950 1750 4650 1750
Wire Wire Line
	4650 1750 4650 2300
Connection ~ 4650 2300
Wire Wire Line
	4900 2900 4550 2900
Wire Wire Line
	4550 2900 4550 2400
Connection ~ 4550 2400
Wire Wire Line
	4550 2400 4800 2400
Wire Wire Line
	4900 3050 4000 3050
Wire Wire Line
	4000 3050 4000 2050
Connection ~ 4000 2050
$EndSCHEMATC
