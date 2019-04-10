EESchema Schematic File Version 4
LIBS:Weather-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 15
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
J0_P1
Text HLabel 2000 1750 0    50   Input ~ 0
J0_P2
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
	2000 2000 2100 2000
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
	2000 1750 2100 1750
Wire Wire Line
	2900 2000 2500 2000
Connection ~ 2500 2000
$Comp
L Mechanical:MountingHole_Pad H?
U 1 1 5CB5C4AF
P 2100 1650
AR Path="/5CAF7F5D/5CB5C4AF" Ref="H?"  Part="1" 
AR Path="/5C9252D8/5CB5C4AF" Ref="H1"  Part="1" 
F 0 "H1" H 2050 1850 50  0000 L CNN
F 1 "MountingHole_Pad" H 1500 1950 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 2100 1650 50  0001 C CNN
F 3 "~" H 2100 1650 50  0001 C CNN
	1    2100 1650
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H?
U 1 1 5CB5D5F2
P 2100 2100
AR Path="/5CAF7F5D/5CB5D5F2" Ref="H?"  Part="1" 
AR Path="/5C9252D8/5CB5D5F2" Ref="H2"  Part="1" 
F 0 "H2" H 2100 2300 50  0000 L CNN
F 1 "MountingHole_Pad" H 2050 2400 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 2100 2100 50  0001 C CNN
F 3 "~" H 2100 2100 50  0001 C CNN
	1    2100 2100
	-1   0    0    1   
$EndComp
Connection ~ 2100 2000
Wire Wire Line
	2100 2000 2500 2000
Connection ~ 2100 1750
Wire Wire Line
	2100 1750 2900 1750
$EndSCHEMATC
