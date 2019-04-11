EESchema Schematic File Version 4
LIBS:Weather-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 12 15
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MyComponents:BMP180 MOD3
U 1 1 5CB3BC30
P 5900 3650
F 0 "MOD3" H 6528 3571 50  0000 L CNN
F 1 "BMP180" H 6528 3480 50  0000 L CNN
F 2 "footprint:BMP180" H 6100 3150 50  0001 C CNN
F 3 "" H 6100 3150 50  0001 C CNN
	1    5900 3650
	1    0    0    1   
$EndComp
Text HLabel 4300 3150 0    50   Input ~ 0
J5_P1
Text HLabel 4300 3350 0    50   Input ~ 0
J5_P2
Text HLabel 4300 3550 0    50   Input ~ 0
J5_P3
Text HLabel 4300 3750 0    50   Input ~ 0
J5_P4
Text HLabel 4300 3950 0    50   Input ~ 0
J5_P5
Wire Wire Line
	4300 3150 4800 3150
Wire Wire Line
	4300 3350 4800 3350
Wire Wire Line
	4300 3550 4800 3550
Wire Wire Line
	4300 3750 4800 3750
Wire Wire Line
	4300 3950 4800 3950
$Comp
L MyComponents:5_Way_Wire J5
U 1 1 5CAF5E59
P 4900 3150
F 0 "J5" H 4800 2250 50  0000 L CNN
F 1 "5_Way_Wire" H 4800 3400 50  0000 L CNN
F 2 "" H 4900 3150 50  0001 C CNN
F 3 "" H 4900 3150 50  0001 C CNN
	1    4900 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 3750 5250 3750
Wire Wire Line
	5250 3750 5250 3600
Wire Wire Line
	5250 3600 4800 3600
Wire Wire Line
	4800 3600 4800 3550
Connection ~ 4800 3550
Wire Wire Line
	5800 3600 5350 3600
Wire Wire Line
	5350 3600 5350 3400
Wire Wire Line
	5350 3400 4800 3400
Wire Wire Line
	4800 3400 4800 3350
Connection ~ 4800 3350
Wire Wire Line
	5800 3450 5450 3450
Wire Wire Line
	5450 3450 5450 3200
Wire Wire Line
	5450 3200 4800 3200
Wire Wire Line
	4800 3200 4800 3150
Connection ~ 4800 3150
Wire Wire Line
	5800 3300 5550 3300
Wire Wire Line
	5550 3300 5550 3800
Wire Wire Line
	5550 3800 4800 3800
Wire Wire Line
	4800 3800 4800 3750
Connection ~ 4800 3750
$EndSCHEMATC
