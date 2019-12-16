EESchema Schematic File Version 4
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
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
L Diode:1N4001 D?
U 1 1 5D7E49C9
P 2600 1950
F 0 "D?" H 2600 1734 50  0000 C CNN
F 1 "1N4001" H 2600 1825 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 2600 1775 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 2600 1950 50  0001 C CNN
	1    2600 1950
	-1   0    0    1   
$EndComp
$Comp
L Diode:1N4001 D?
U 1 1 5D7E61B4
P 3300 1950
F 0 "D?" H 3300 1734 50  0000 C CNN
F 1 "1N4001" H 3300 1825 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 3300 1775 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 3300 1950 50  0001 C CNN
	1    3300 1950
	-1   0    0    1   
$EndComp
$Comp
L Diode:1N4001 D?
U 1 1 5D7E6E42
P 2600 2350
F 0 "D?" H 2600 2134 50  0000 C CNN
F 1 "1N4001" H 2600 2225 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 2600 2175 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 2600 2350 50  0001 C CNN
	1    2600 2350
	-1   0    0    1   
$EndComp
$Comp
L Diode:1N4001 D?
U 1 1 5D7E7C6A
P 3300 2350
F 0 "D?" H 3300 2134 50  0000 C CNN
F 1 "1N4001" H 3300 2225 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 3300 2175 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 3300 2350 50  0001 C CNN
	1    3300 2350
	-1   0    0    1   
$EndComp
Wire Wire Line
	2450 1950 2300 1950
Wire Wire Line
	2300 1950 2300 2350
Wire Wire Line
	2300 2350 2450 2350
Wire Wire Line
	3450 1950 3650 1950
Wire Wire Line
	3650 1950 3650 2350
Wire Wire Line
	3650 2350 3450 2350
Wire Wire Line
	3650 1950 3650 1450
Connection ~ 3650 1950
Wire Wire Line
	2750 1950 2950 1950
Wire Wire Line
	2750 2350 2950 2350
Wire Wire Line
	2950 1950 2950 1450
Connection ~ 2950 1950
Wire Wire Line
	2950 1950 3150 1950
Wire Wire Line
	2950 2350 2950 2850
Connection ~ 2950 2350
Wire Wire Line
	2950 2350 3150 2350
Text Label 2950 1650 1    50   ~ 0
Vin_A
Text Label 2950 2650 3    50   ~ 0
Vin_B
Wire Wire Line
	2300 2350 2300 2850
Connection ~ 2300 2350
$Comp
L SparkFun-PowerSymbols:GND #GND?
U 1 1 5D7EAD94
P 2300 2850
F 0 "#GND?" H 2350 2800 45  0001 L BNN
F 1 "GND" H 2300 2680 45  0000 C CNN
F 2 "" H 2300 2750 60  0001 C CNN
F 3 "" H 2300 2750 60  0001 C CNN
	1    2300 2850
	1    0    0    -1  
$EndComp
$Comp
L SparkFun-PowerSymbols:VOUT #SUPPLY?
U 1 1 5D7EB20D
P 3650 1450
F 0 "#SUPPLY?" H 3700 1450 45  0001 L BNN
F 1 "VOUT" H 3650 1726 45  0000 C CNN
F 2 "XXX-00000" H 3650 1631 60  0000 C CNN
F 3 "" H 3650 1450 60  0001 C CNN
	1    3650 1450
	1    0    0    -1  
$EndComp
$EndSCHEMATC
