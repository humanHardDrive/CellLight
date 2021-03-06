EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 6
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
L Memory_NVRAM:FM24C64B U9
U 1 1 5F398A90
P 5550 3550
F 0 "U9" H 5550 4131 50  0000 C CNN
F 1 "MB85RC256" H 5550 4040 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 5550 3550 50  0001 C CNN
F 3 "https://www.fujitsu.com/us/Images/MB85RC256V-DS501-00017-3v0-E.pdf" H 5350 3900 50  0001 C CNN
	1    5550 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 3350 5150 3450
Wire Wire Line
	5150 3450 5150 3550
Connection ~ 5150 3450
Wire Wire Line
	5950 3450 6350 3450
Wire Wire Line
	5950 3650 6350 3650
Text GLabel 6350 3450 2    50   Input ~ 0
SDA
Text GLabel 6350 3650 2    50   Input ~ 0
SCL
$Comp
L power:GND #PWR03
U 1 1 5F3990BA
P 5550 4050
F 0 "#PWR03" H 5550 3800 50  0001 C CNN
F 1 "GND" H 5555 3877 50  0000 C CNN
F 2 "" H 5550 4050 50  0001 C CNN
F 3 "" H 5550 4050 50  0001 C CNN
	1    5550 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 4050 5550 3950
Wire Wire Line
	5550 2900 5550 3100
Wire Wire Line
	5550 3100 5150 3100
Wire Wire Line
	5150 3100 5150 3350
Connection ~ 5550 3100
Wire Wire Line
	5550 3100 5550 3150
Connection ~ 5150 3350
Wire Wire Line
	5150 3750 5150 3950
Wire Wire Line
	5150 3950 5550 3950
Connection ~ 5550 3950
$Comp
L SparkFun-PowerSymbols:3.3V #SUPPLY09
U 1 1 5FA7A40B
P 5550 2900
F 0 "#SUPPLY09" H 5600 2900 45  0001 L BNN
F 1 "3.3V" H 5550 3176 45  0000 C CNN
F 2 "XXX-00000" H 5550 3081 60  0000 C CNN
F 3 "" H 5550 2900 60  0001 C CNN
	1    5550 2900
	1    0    0    -1  
$EndComp
$EndSCHEMATC
