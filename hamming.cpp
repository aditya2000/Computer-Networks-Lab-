#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int data_bit_size;
	cout<<"\n Enter the data bit size: ";
	cin>> data_bit_size;

	int red_bit_size;

// Calculating the size of redundant bits to be added
	for(int i=0; i >=0; i++) {
		if(pow(2, i) > (i + data_bit_size +1)) {
			red_bit_size = i;
			break;
		}
	}

	cout<<"\n Number of redundant bits to be added: "<<red_bit_size<<" total bits: "<<red_bit_size+data_bit_size;

	int data_bits[data_bit_size];
	cout<<"\n Enter data bits: ";
	for(int i=0; i<data_bit_size; i++) {
		cin>>data_bits[i];
	}

	cout<<"\n Entered data bits: ";
	for(int i=0; i<data_bit_size; i++) {
		cout<<data_bits[i]<<" ";
	}

// Inserting redundant bits
	int data[red_bit_size+data_bit_size];
	int index_Red = 0; // index of redundant bits
	int index_Norm = 0; // index of normal bits
	for(int i=1; i<red_bit_size+data_bit_size; i++) {
		if(i == pow(2, index_Red)) {
			data[i] = 0;
			index_Red++;
		} else {
			data[i] = data_bits[index_Norm];
			index_Norm++;
		}
	}

	cout<<"\n Data encoded with redundant bits: ";
	for(int i=1; i<data_bit_size+red_bit_size; i++) {
		cout<<data[i]<<" ";
	}

// Calculating Parity bits
	index_Norm = 0;
	int parity, j, k, min, max;
	for(int i=0; i<red_bit_size+data_bit_size; i=pow(2, index_Norm)) {
		index_Norm++;
		parity = 0;
		j = i;
		k = i;
		min = 1;
		max = i;
		for(j; j<data_bit_size+red_bit_size;) {
			for(k = j; max >= min && k <= red_bit_size+data_bit_size; min++, k++) {
				if(data[k] == 1) {
					parity++;
				}
			}
		}

		if(parity%2 == 0) {
			data[i] = 0;
		} else {
			data[i] = 1;
		}
	}

	cout<<"Data To be sent is: ";
	for(int i=0; i<red_bit_size+data_bit_size; i++) {
		cout<<data[i]<<" ";
	}
}