EESchema Schematic File Version 4
LIBS:Weather-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 15
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 2500 2000 0    50   Input ~ 0
J5_P1
Text HLabel 2500 2250 0    50   Input ~ 0
J5_P2
Text HLabel 2500 2500 0    50   Input ~ 0
J5_P3
$Comp
L MyComponents:PowerBrick PSU2
U 1 1 5C96411B
P 4050 2100
F 0 "PSU2" H 4678 2121 50  0000 L CNN
F 1 "PowerBrick" H 4678 2030 50  0000 L CNN
F 2 "footprint:PowerBrick" H 4250 1800 50  0001 C CNN
F 3 "" H 4250 1800 50  0001 C CNN
	1    4050 2100
	1    0    0    -1  
$EndComp
$Comp
L MyComponents:PowerBrick PSU3
U 1 1 5C9656A9
P 4050 2600
F 0 "PSU3" H 4678 2621 50  0000 L CNN
F 1 "PowerBrick" H 4678 2530 50  0000 L CNN
F 2 "footprint:PowerBrick" H 4250 2300 50  0001 C CNN
F 3 "" H 4250 2300 50  0001 C CNN
	1    4050 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 2250 3500 2250
Wire Wire Line
	3500 2250 3500 2000
Wire Wire Line
	3500 2000 3950 2000
Wire Wire Line
	2500 2000 3000 2000
Wire Wire Line
	3000 2000 3000 2750
Wire Wire Line
	3000 2750 3750 2750
Wire Wire Line
	3950 2250 3750 2250
Wire Wire Line
	3750 2250 3750 2750
Connection ~ 3750 2750
Wire Wire Line
	3750 2750 3950 2750
Wire Wire Line
	3950 2500 2500 2500
$Comp
L MyComponents:3_Way_Wire J7
U 1 1 5CB57954
P 3300 1350
F 0 "J7" H 3469 1311 50  0000 L CNN
F 1 "3_Way_Wire" H 3469 1220 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3300 1350 50  0001 C CNN
F 3 "" H 3300 1350 50  0001 C CNN
	1    3300 1350
	1    0    0    -1  
$EndComp
$EndSCHEMATC
