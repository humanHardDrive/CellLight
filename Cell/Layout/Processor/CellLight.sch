EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 2100 1300 2050 1300
U 5F354543
F0 "Processor" 50
F1 "Processor.sch" 50
$EndSheet
$Sheet
S 4350 1300 2050 1300
U 5F3717FF
F0 "Connectors" 50
F1 "Connectors.sch" 50
$EndSheet
$Sheet
S 4300 3450 2050 1250
U 5F373590
F0 "CommSelect" 50
F1 "CommSelect.sch" 50
$EndSheet
$Sheet
S 2150 3400 1950 1300
U 5F395CF0
F0 "Memory" 50
F1 "Memory.sch" 50
$EndSheet
$Sheet
S 6600 1300 2150 1300
U 5F395F1A
F0 "Power" 50
F1 "Power.sch" 50
$EndSheet
Wire Wire Line
	3800 6100 3800 6200
$Comp
L SparkFun-PowerSymbols:GND #GND0104
U 1 1 5FA89469
P 3000 6200
F 0 "#GND0104" H 3050 6150 45  0001 L BNN
F 1 "GND" H 3000 6030 45  0000 C CNN
F 2 "" H 3000 6100 60  0001 C CNN
F 3 "" H 3000 6100 60  0001 C CNN
	1    3000 6200
	1    0    0    -1  
$EndComp
$Comp
L SparkFun-PowerSymbols:GND #GND0105
U 1 1 5FA895DD
P 3800 6200
F 0 "#GND0105" H 3850 6150 45  0001 L BNN
F 1 "GND" H 3800 6030 45  0000 C CNN
F 2 "" H 3800 6100 60  0001 C CNN
F 3 "" H 3800 6100 60  0001 C CNN
	1    3800 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 6100 3000 6200
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 5FA68397
P 3000 6000
F 0 "H1" H 3100 6049 50  0000 L CNN
F 1 "MountingHole_Pad" H 3100 5958 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5_Pad" H 3000 6000 50  0001 C CNN
F 3 "~" H 3000 6000 50  0001 C CNN
	1    3000 6000
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 5FA68840
P 3800 6000
F 0 "H2" H 3900 6049 50  0000 L CNN
F 1 "MountingHole_Pad" H 3900 5958 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5_Pad" H 3800 6000 50  0001 C CNN
F 3 "~" H 3800 6000 50  0001 C CNN
	1    3800 6000
	1    0    0    -1  
$EndComp
$EndSCHEMATC
