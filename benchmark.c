#include <stdio.h>
#include<stdlib.h>

#define SIZE 50000 //define variables
int A[SIZE];
int B[SIZE];
long long C[SIZE];

int main()
{
	long long checksum = 0; //initialize final sum
	const long long expected_checksum = 41667916675000; //expected value for final sum

	for (int i = 0; i < SIZE; i++) { //initialize A,B and C arrays
		A[i] = i;
		B[i] = SIZE-i;
		C[i] = 0;
	}

	for (int i = 0; i < SIZE; i++) { //for each element in C
		long long sum = 0; //new sum for each C
		for (int j = 0; j <= A[i]; j++) { //sum B from 0 to A[i]
			sum += B[j];
		}
		C[i] = sum; //C[i] is the sum of B from 0 to A[i]
	}

	for (int i = 0; i < SIZE; i++) { //compute final sum of all C components
		checksum += C[i];
	}

	printf("Computed checksum: %lld\n", checksum); //print final sum

	if(checksum != expected_checksum) { //compare final sum to expected sum, exit with return value of 1 if wrong
		fprintf(stderr, "Error: checksum is incorrect. Expected %lld, got %lld\n", expected_checksum, checksum);
		return 1;
	}

	return 0; //return 0 if no error
}
