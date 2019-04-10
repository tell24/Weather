EESchema Schematic File Version 4
LIBS:Weather-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 14
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 2000 2000 0    50   Input ~ 0
J1_P1
Text HLabel 2000 1750 0    50   Input ~ 0
J1_P2
$Comp
L power:GND #PWR01
U 1 1 5C92A263
P 2500 2450
F 0 "#PWR01" H 2500 2200 50  0001 C CNN
F 1 "GND" H 2505 2277 50  0000 C CNN
F 2 "" H 2500 2450 50  0001 C CNN
F 3 "" H 2500 2450 50  0001 C CNN
	1    2500 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 2000 2500 2000
Wire Wire Line
	2500 2000 2500 2450
Text Label 2500 2250 0    50   ~ 0
0v
$Comp
L MyComponents:PowerBrick PSU1
U 1 1 5C92F4FB
P 3000 1850
F 0 "PSU1" H 3628 1871 50  0000 L CNN
F 1 "PowerBrick" H 3628 1780 50  0000 L CNN
F 2 "footprint:PowerBrick" H 3200 1550 50  0001 C CNN
F 3 "" H 3200 1550 50  0001 C CNN
	1    3000 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 1750 2900 1750
Wire Wire Line
	2900 2000 2500 2000
Connection ~ 2500 2000
$EndSCHEMATC
