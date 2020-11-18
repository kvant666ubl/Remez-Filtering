# Remez-Filtering
Contains example of Remez filtering algorithm for band-pass and low-pass filter in C.

## Briefly Theory
The procedure is based on the reformulation of the filter design task into a task for polynomial approximation.

We using an iteration procedure, a polynomial function ```Pn(x)``` is approximated. The polynomial oscillates within the error band in the local extrema by ```±h```. You can choose the polynomial degree ```n``` and the error band ```±h```.


## Description
From the file ```FIR-1.c``` we can get the number of koeficients, bandwidth deviation and stopband  deviation in dB. 
Program prompts user to enter the ***filter type***, ***bandwidth*** and ***stopband*** value,  and ***normalized transition bandwidth***.

In this figure, you can see  exactly all these characteristics:
![alt text](https://github.com/kvant666ubl/Remez-Filtering/blob/main/img/2.png?raw=true)

## Example
Let's go to the root of the project repository, compiling and run ```FIR.c``` file:

```$ gcc -o filter FIR-1.c -lm```

```$ ./filter```

For instance, our task is:
```
Calculate the length of the bandpass filter with the next specification:
Bandpass | 1.8 - 2.2 kHz
Stoppass | 0.0 - 1.3 and 3.7 - 5.0 kHz

Sampling frequency  | 10 kHz
Bandwidth deviation | 1 dB
Stopband  deviation | 40 dB
```
So, normalized bandwidth is ```0.04```, bandwidth and stopband are ```0.122``` and ```0.01```, according to basics formulas for FIR filter.

Input our values and get results:
```
Filter type: type <1> to define LP or type <2> to define BP: 2
Enter Bandwidth & Stopband from 0.0 to 1.0.
From | 0.122
To   | 0.01

Less normalized transition bandwidth: 0.04
Bandpass filter calculating...
    1.  The number of koeficients: 	31.261084
    2.  Bandwidth deviation in dB: 	0.999857
    3.  Stopband  deviation in dB: 	40.000000

```

## Matlab
Design the BP-filter to see phase response in Filter-Design App:

![alt text](https://github.com/kvant666ubl/Remez-Filtering/blob/main/img/FD-Matlab.png?raw=true)
