#include <fstream>
#include <iostream>
#include <cstdlib>
/*
Collin Ward
cmw0147@auburn.edu
COMP 2710-002
project3_Ward_cmw0147

Compiled with current g++ and then run with .a/.out in au server

*/
using namespace std;
const int MAX_SIZE = 100;

int readfile(int inputArray[], ifstream& instream);
void writefile(int outputArray[], int outputArray_size, string fileNameIn);
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);


int main() {
	ifstream inStream1;
	int iArray1[MAX_SIZE];
	int iArray1_size;
	int iArray2[MAX_SIZE];
	int iArray2_size;
	string filename;
	cout << "*** Welcome to Collin's sorting program ***" << endl;
	cout << "Enter the first input file name: " ;
	cin >> filename;
	
		inStream1.open(filename);
	
	while (!inStream1) {
		cout << "File Not Found, try again: " << endl;
		cin >> filename;
		inStream1.open(filename);
	}
	

		cout << "The list of 6 numbers in file " << filename << " is:" << endl;
		iArray1_size = readfile(iArray1, inStream1);
		inStream1.close();
	
	ifstream inStream2;

	cout << endl << "Enter the second input file name: ";
	cin >> filename;



	inStream2.open(filename);

	while (!inStream2) {
		cout << "File Not Found, try again: " << endl;
		cin >> filename;
		inStream2.open(filename);
	}


	cout << "The list of 5 numbers in file " << filename << " is:" << endl;
	iArray2_size = readfile(iArray2, inStream2);
	inStream2.close();

	int outArray[MAX_SIZE];
	int outArray_size = sort(iArray1, iArray1_size, iArray2, iArray2_size, outArray);

	cout << "The sorted list of 11 numbers is: ";
	for (int i = 0; i < outArray_size; i++) {
		cout << outArray[i] << " ";
	}
	cout << endl << "Enter the output file name: ";
	cin >> filename;


	writefile(outArray, outArray_size, filename);

	cout << "*** Please check the new file - " << filename << " ***" << endl;
	cout << "*** Goodbye. ***";

	return 0;
}

int readfile(int inputArray[], ifstream& inStream) {
	int index = 0;
	while (!inStream.eof()) {
		inStream >> inputArray[index];
		cout << inputArray[index] << endl;
		index++;
	}
	return index;
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
	
	int total = (inputArray1_size + inputArray2_size);
	int i = 0, j = 0, k = 0;

	while (i < inputArray1_size && j < inputArray2_size) {
		if (inputArray1[i] < inputArray2[j]) {
			outputArray[k] = inputArray1[i];
			i++;
		}
		else {
			outputArray[k] = inputArray2[j];
			j++;
		}
		k++;
	}

	while (i < inputArray1_size) {
		outputArray[k] = inputArray1[i];
		i++;
		k++;
	}

	while (j < inputArray2_size) {
		outputArray[k] = inputArray2[j];
		j++;
		k++;
	}


	return total;
}

void writefile(int outputArray[], int outputArray_size, string filenameIn) {
	ofstream outfile;
	outfile.open(filenameIn);
	for (int i = 0; i < outputArray_size; i++) {
		outfile << outputArray[i] << endl;

	}
	outfile.close();

}