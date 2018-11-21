#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main () {
	int databit_size, b, data_bits[30], d, red_size = 0, d1; //Max bits here i kept is 30

	cout << " Enter the No of Data Bits you want to Enter : ";
	cin >>databit_size;

	while (databit_size + red_size + 1 > pow (2, red_size)) {
	    red_size++;
	}

	cout << "No of data bits to be added " << red_size << " : Total Bits :" << databit_size + red_size << endl;
	
	cout << " Enter the Data Bits One by One :" << endl;
	for (int i = 1; i <= databit_size; ++i) { 
	    cin >> data_bits[i];
	}

	cout << endl << " Data bits entered : ";
	for (int i = 1; i <= databit_size; ++i) {
	    cout << data_bits[i] << " ";
	}
	cout << endl;

	int data[databit_size + red_size];
	d = 0;
	d1 = 1;
	for (int i = 1; i <= databit_size + red_size; ++i) {
	    if (i == pow (2, d)) {
		   data[i] = 0;
		   ++d;
	 	} else {
		   data[i] = data_bits[d1];
		   ++d1;
	 	}
	}

	cout << " Data Bits are Encoded with Parity bits(0): ";
	for (int i = 1; i <= databit_size + red_size; ++i) {
	    cout << data[i] << " ";
	}

	d1 = 0;
	int min, max = 0, parity, s, j;
	/*Parity Bit Calculation */
	for (int i = 1; i <= databit_size + red_size; i = pow (2, d1)) {
	    ++d1;
	    parity = 0;
	    j = i;
	    s = i;
	    min = 1;
	    max = i;
	    for (j; j <= databit_size + red_size;) {
	   		for (s = j; max >= min && s <= databit_size + red_size; ++min, ++s) {
	      		if (data[s] == 1) {
					parity++;
				}
	     	}
	   		j = s + i;
	   		min = 1;
	 	}

	    if (parity % 2 == 0) {
	   		data[i] = 0;
	 	}  else {
	   		data[i] = 1;
	 	}
	}
	cout << endl << " Hamming codeword bits for even parity are : ";
	for (int i = 1; i <= databit_size + red_size; ++i) {
	    cout << data[i] << " ";
	}
	cout << endl << endl;
}
