EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 7
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
L TS3A475:TS3A4751PWR U?
U 1 1 5F378E97
P 4350 3250
AR Path="/5F378E97" Ref="U?"  Part="1" 
AR Path="/5F373590/5F378E97" Ref="U2"  Part="1" 
F 0 "U2" H 5550 3637 60  0000 C CNN
F 1 "TS3A4751PWR" H 5550 3531 60  0000 C CNN
F 2 "PW14" H 5550 3490 60  0001 C CNN
F 3 "" H 4350 3250 60  0000 C CNN
	1    4350 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5F378E9D
P 6750 3150
AR Path="/5F378E9D" Ref="#PWR?"  Part="1" 
AR Path="/5F373590/5F378E9D" Ref="#PWR0114"  Part="1" 
F 0 "#PWR0114" H 6750 3000 50  0001 C CNN
F 1 "+3.3V" H 6765 3323 50  0000 C CNN
F 2 "" H 6750 3150 50  0001 C CNN
F 3 "" H 6750 3150 50  0001 C CNN
	1    6750 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 3150 6750 3250
$Comp
L power:GND #PWR?
U 1 1 5F378EA4
P 4350 3900
AR Path="/5F378EA4" Ref="#PWR?"  Part="1" 
AR Path="/5F373590/5F378EA4" Ref="#PWR0115"  Part="1" 
F 0 "#PWR0115" H 4350 3650 50  0001 C CNN
F 1 "GND" H 4355 3727 50  0000 C CNN
F 2 "" H 4350 3900 50  0001 C CNN
F 3 "" H 4350 3900 50  0001 C CNN
	1    4350 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 3850 4350 3900
Wire Wire Line
	6750 3750 7250 3750
Wire Wire Line
	6750 3850 7250 3850
Wire Wire Line
	6750 3350 7250 3350
Wire Wire Line
	4350 3250 3800 3250
Wire Wire Line
	4350 3350 3800 3350
Wire Wire Line
	4350 3450 3800 3450
Wire Wire Line
	4350 3550 3800 3550
Wire Wire Line
	4350 3650 3800 3650
Wire Wire Line
	4350 3750 3800 3750
Text GLabel 3800 3250 0    50   Input ~ 0
PORT1_IO
Text GLabel 3800 3350 0    50   Input ~ 0
IO_COM
Text GLabel 3800 3450 0    50   Input ~ 0
PORT2_IO
Text GLabel 3800 3550 0    50   Input ~ 0
IO_COM
Text GLabel 3800 3650 0    50   Input ~ 0
PORT2_SEL
Text GLabel 3800 3750 0    50   Input ~ 0
PORT3_SEL
Text GLabel 7250 3350 2    50   Input ~ 0
PORT1_SEL
Text GLabel 7250 3750 2    50   Input ~ 0
IO_COM
Text GLabel 7250 3850 2    50   Input ~ 0
PORT3_IO
$EndSCHEMATC
