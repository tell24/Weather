EESchema Schematic File Version 4
LIBS:Weather-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 14 15
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4850 2700 0    50   Input ~ 0
J18_P1
Text HLabel 4850 2900 0    50   Input ~ 0
J18_P2
Text HLabel 4850 3100 0    50   Input ~ 0
J18_P3
Text HLabel 4850 3300 0    50   Input ~ 0
J18_P4
$Comp
L MyComponents:HTU21 MOD2
U 1 1 5CB467F0
P 7400 3150
F 0 "MOD2" H 8028 3146 50  0000 L CNN
F 1 "HTU21" H 8028 3055 50  0000 L CNN
F 2 "footprint:HTU21" H 7600 2850 50  0001 C CNN
F 3 "" H 7600 2850 50  0001 C CNN
	1    7400 3150
	1    0    0    1   
$EndComp
$Comp
L MyComponents:4_Way_Wire J18
U 1 1 5CB4EF7C
P 5700 2700
F 0 "J18" H 5700 2850 50  0000 L CNN
F 1 "4_Way_Wire" H 5700 2000 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5600 2750 50  0001 C CNN
F 3 "" H 5600 2750 50  0001 C CNN
	1    5700 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 2700 5600 2700
Wire Wire Line
	4850 2900 5600 2900
Wire Wire Line
	4850 3100 5600 3100
Wire Wire Line
	4850 3300 5600 3300
Wire Wire Line
	7300 3250 7000 3250
Wire Wire Line
	7000 3250 7000 3500
Wire Wire Line
	7000 3500 5600 3500
Wire Wire Line
	5600 3500 5600 3300
Connection ~ 5600 3300
Wire Wire Line
	7300 2800 7000 2800
Wire Wire Line
	7000 2800 7000 2500
Wire Wire Line
	7000 2500 5600 2500
Wire Wire Line
	5600 2500 5600 2700
Connection ~ 5600 2700
Wire Wire Line
	7300 2950 6750 2950
Wire Wire Line
	6750 2950 6750 2800
Wire Wire Line
	6750 2800 5600 2800
Wire Wire Line
	5600 2800 5600 2900
Connection ~ 5600 2900
Wire Wire Line
	7300 3100 6750 3100
Wire Wire Line
	6750 3100 6750 3200
Wire Wire Line
	6750 3200 5600 3200
Wire Wire Line
	5600 3200 5600 3100
Connection ~ 5600 3100
$EndSCHEMATC
