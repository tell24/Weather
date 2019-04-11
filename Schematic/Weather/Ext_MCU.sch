EESchema Schematic File Version 4
LIBS:Weather-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 15
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 2650 3100 0    50   Input ~ 0
J14_P1
Text HLabel 2650 3300 0    50   Input ~ 0
J14_P2
Text HLabel 2650 3500 0    50   Input ~ 0
J14_P3
Text HLabel 2650 3700 0    50   Input ~ 0
J14_P4
Text HLabel 2600 4400 0    50   Input ~ 0
J15_P1
Text HLabel 2600 4600 0    50   Input ~ 0
J15_P2
Text HLabel 2600 4800 0    50   Input ~ 0
J15_P3
Text HLabel 2600 5000 0    50   Input ~ 0
J15_P4
Text HLabel 2600 5700 0    50   Input ~ 0
J16_P1
Text HLabel 2600 5900 0    50   Input ~ 0
J16_p2
Text HLabel 2600 6100 0    50   Input ~ 0
J16_P3
Text HLabel 2600 6300 0    50   Input ~ 0
J16_P4
$Comp
L MyComponents:4_Way_Wire J14
U 1 1 5C964519
P 3100 3100
F 0 "J14" H 3050 2350 50  0000 L CNN
F 1 "4_Way_Wire" H 2850 2200 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 3000 3150 50  0001 C CNN
F 3 "" H 3000 3150 50  0001 C CNN
	1    3100 3100
	1    0    0    -1  
$EndComp
$Comp
L MyComponents:AMS1117 U2
U 1 1 5C951D08
P 3200 1950
F 0 "U2" V 2700 2000 60  0000 R CNN
F 1 "AMS1117" V 2600 2200 60  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 3200 1950 60  0001 C CNN
F 3 "" H 3200 1950 60  0000 C CNN
	1    3200 1950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3650 2200 3650 2850
Wire Wire Line
	3650 1700 4000 1700
Wire Wire Line
	4000 1700 4000 3600
Wire Wire Line
	3650 1950 4300 1950
$Comp
L MyComponents:4_Way_Wire J15
U 1 1 5CB477D0
P 3150 4400
F 0 "J15" H 3000 3650 50  0000 L CNN
F 1 "4_Way_Wire" H 2900 3500 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 3050 4450 50  0001 C CNN
F 3 "" H 3050 4450 50  0001 C CNN
	1    3150 4400
	1    0    0    -1  
$EndComp
$Comp
L MyComponents:4_Way_Wire J16
U 1 1 5CB50010
P 3150 5700
F 0 "J16" H 3000 4950 50  0000 L CNN
F 1 "4_Way_Wire" H 2900 4850 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 3050 5750 50  0001 C CNN
F 3 "" H 3050 5750 50  0001 C CNN
	1    3150 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 3100 3000 2850
Wire Wire Line
	3000 2850 3650 2850
Wire Wire Line
	3000 3700 3000 3600
Wire Wire Line
	3000 3600 4000 3600
$Comp
L ESP8266:ESP-12 U3
U 1 1 5CB467A8
P 5950 2650
F 0 "U3" H 5950 3731 50  0000 C CNN
F 1 "ESP-12" H 5950 3640 50  0000 C CNN
F 2 "" H 5950 2650 50  0001 C CNN
F 3 "http://l0l.org.uk/2014/12/esp8266-modules-hardware-guide-gotta-catch-em-all/" H 5950 2650 50  0001 C CNN
	1    5950 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 1950 4300 1750
Wire Wire Line
	4300 1750 5950 1750
Wire Wire Line
	4000 3600 5950 3600
Wire Wire Line
	5950 3600 5950 3550
Connection ~ 4000 3600
Wire Wire Line
	5050 2850 4250 2850
Wire Wire Line
	4250 2850 4250 3200
Wire Wire Line
	4250 3200 3000 3200
Wire Wire Line
	3000 3200 3000 3300
Wire Wire Line
	3000 3500 3000 3400
Wire Wire Line
	3000 3400 4400 3400
Wire Wire Line
	4400 3400 4400 2950
Wire Wire Line
	4400 2950 5050 2950
Wire Wire Line
	3650 2850 3650 4250
Wire Wire Line
	3650 4250 3050 4250
Wire Wire Line
	3050 4250 3050 4400
Connection ~ 3650 2850
Wire Wire Line
	3650 4250 3650 5550
Wire Wire Line
	3650 5550 3050 5550
Wire Wire Line
	3050 5550 3050 5700
Connection ~ 3650 4250
Wire Wire Line
	4000 3600 4000 4900
Wire Wire Line
	4000 4900 3050 4900
Wire Wire Line
	3050 4900 3050 5000
Wire Wire Line
	4000 4900 4000 6200
Wire Wire Line
	4000 6200 3050 6200
Wire Wire Line
	3050 6200 3050 6300
Connection ~ 4000 4900
Wire Wire Line
	4250 3200 4250 4500
Wire Wire Line
	4250 4500 3050 4500
Wire Wire Line
	3050 4500 3050 4600
Connection ~ 4250 3200
Wire Wire Line
	4400 3400 4400 4700
Wire Wire Line
	4400 4700 3050 4700
Wire Wire Line
	3050 4700 3050 4800
Connection ~ 4400 3400
Wire Wire Line
	4250 4500 4250 5800
Wire Wire Line
	4250 5800 3050 5800
Wire Wire Line
	3050 5800 3050 5900
Connection ~ 4250 4500
Wire Wire Line
	4400 4700 4400 6000
Wire Wire Line
	4400 6000 3050 6000
Wire Wire Line
	3050 6000 3050 6100
Connection ~ 4400 4700
Wire Wire Line
	2600 6300 3050 6300
Connection ~ 3050 6300
Wire Wire Line
	2600 6100 3050 6100
Connection ~ 3050 6100
Wire Wire Line
	2600 5900 3050 5900
Connection ~ 3050 5900
Wire Wire Line
	2600 5700 3050 5700
Connection ~ 3050 5700
Wire Wire Line
	2600 5000 3050 5000
Connection ~ 3050 5000
Wire Wire Line
	2600 4800 3050 4800
Connection ~ 3050 4800
Wire Wire Line
	2600 4600 3050 4600
Connection ~ 3050 4600
Wire Wire Line
	2600 4400 3050 4400
Connection ~ 3050 4400
Wire Wire Line
	2650 3100 3000 3100
Connection ~ 3000 3100
Wire Wire Line
	2650 3300 3000 3300
Connection ~ 3000 3300
Wire Wire Line
	2650 3500 3000 3500
Connection ~ 3000 3500
Wire Wire Line
	2650 3700 3000 3700
Connection ~ 3000 3700
$EndSCHEMATC
