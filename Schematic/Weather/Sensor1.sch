EESchema Schematic File Version 4
LIBS:Weather-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 15
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 3050 2650 0    50   Input ~ 0
J4_P1
Text HLabel 3050 2800 0    50   Input ~ 0
J4_P2
Text HLabel 3050 2950 0    50   Input ~ 0
J4_P3
Text HLabel 3050 3100 0    50   Input ~ 0
J4_P4
$Comp
L Connector:Conn_01x05_Male J2
U 1 1 5CAF34CD
P 7000 4050
F 0 "J2" H 7150 4400 50  0000 R CNN
F 1 "Conn_01x05_Male" H 7650 4650 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 7000 4050 50  0001 C CNN
F 3 "~" H 7000 4050 50  0001 C CNN
	1    7000 4050
	1    0    0    1   
$EndComp
$Comp
L MyComponents:HTU21 MOD1
U 1 1 5CB25268
P 7900 4050
F 0 "MOD1" H 8528 4046 50  0000 L CNN
F 1 "HTU21" H 8528 3955 50  0000 L CNN
F 2 "footprint:HTU21" H 8100 3750 50  0001 C CNN
F 3 "" H 8100 3750 50  0001 C CNN
	1    7900 4050
	1    0    0    -1  
$EndComp
$EndSCHEMATC
