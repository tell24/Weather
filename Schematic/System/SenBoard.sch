EESchema Schematic File Version 4
LIBS:System-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 9
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
L Amplifier_Operational:LM321 U?
U 1 1 5C8D3D43
P 2300 1500
F 0 "U?" H 2644 1546 50  0000 L CNN
F 1 "LM321" H 2644 1455 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 2300 1500 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm321.pdf" H 2300 1500 50  0001 C CNN
	1    2300 1500
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_FET:AO3401 Q?
U 1 1 5C8E6572
P 3300 3050
F 0 "Q?" H 3506 3096 50  0000 L CNN
F 1 "AO3401" H 3506 3005 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3500 2975 50  0001 L CIN
F 3 "" H 3300 3050 50  0001 L CNN
	1    3300 3050
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:BSS138 Q?
U 1 1 5C8ED196
P 2200 2500
F 0 "Q?" H 2406 2546 50  0000 L CNN
F 1 "BSS138" H 2406 2455 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2400 2425 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/BS/BSS138.pdf" H 2200 2500 50  0001 L CNN
	1    2200 2500
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:AO3401 Q?
U 1 1 5C8F1C4F
P 3250 4000
F 0 "Q?" H 3456 4046 50  0000 L CNN
F 1 "AO3401" H 3456 3955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3450 3925 50  0001 L CIN
F 3 "" H 3250 4000 50  0001 L CNN
	1    3250 4000
	1    0    0    -1  
$EndComp
Text GLabel 1500 2500 0    50   Input ~ 0
N_Pulse
Text GLabel 1500 4000 0    50   Input ~ 0
S_Pulse
Text GLabel 1500 5000 0    50   Input ~ 0
W_Pulse
Text GLabel 1500 6000 0    50   Input ~ 0
E_Pulse
$EndSCHEMATC
