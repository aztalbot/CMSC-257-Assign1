#ifndef CMSC257_A1SUPPORT_INCLUDED
#define CMSC257_A1SUPPORT_INCLUDED

////////////////////////////////////////////////////////////////////////////////
//
//  File          : cmsc257-s17-assign1-support.h
//  Description   : This is a set of general-purpose utility functions we use
//                  for the 257 assignment #1.
//
//   Author        : Andrew Talbot
//   Last Modified : 1/17/2018
//

//
// Constants
#define MAX_FLOATS 20
#define MAX_INTS 25

//
// Functional Prototypes

int float_display_array(float *values, int arrLength);
	// Function     : float_display_array
	// Description  : This function prints out the array of floating point values
	// Inputs       : values - pointer reference to array of floats
	//                arrLength - integer length of array
	// Outputs      : 0 if successful test, -1 if failure

int integer_display_array(int *values, int arrLength);
	// Function     : integer_display_array
	// Description  : This function prints out the array of integer values
	// Inputs       : values - pointer reference to array of integers
	//                arrLength - integer length of array
	// Outputs      : 0 if successful test, -1 if failure

int float_evens(float *numbers, int arrLength);
	// Function     : float_evens
	// Description  : Return the number of even numbers in the array (float version)
	// Inputs       : numbers - pointer reference to array of floats
	//                arrLength - integer length of array
	// Outputs      : integer number of even numbers in the array

int integer_evens(int numbers[], int arrLength);
	// Function     : integer_evens
	// Description  : Return the number of even numbers in the array (int version)
	// Inputs       : numbers - pointer reference to array of integers
	//                arrLength - integer length of array
	// Outputs      : integer number of even numbers in the array

int countBits(int number);
	// Function     : countBits
	// Description  : Count the number of '1' bits in the binary representation
	// Inputs       : number - integer to count bits from
	// Outputs      : integer number of nonzero bits in the number

int most_values(int *values, int numElements, int maxValue);
	// Function     : float_display_array
	// Description  : Print out the values with the most occurences in array
	// Inputs       : values - pointer reference to integer array
	//                numElements - the number of elements in the array
	//                maxValue - the maximum possible value
        // Outputs      : integer 1 indicating success -- prints value(s) occuring most often

unsigned short int reverseBits(unsigned short int number);
	// Function     : reverseBits
	// Description  : Reverse the binary bit string
	// Inputs       : number - the unsigned short int number to reverse
	// Outputs      : the number, as an unsigned short int, 
	//                represented by the reverse of the input's bits

void binaryString(char *strPointer, int length, int number);
	// Function     : binaryString
	// Description  : Print the binary equivalent of the number passed
	// Inputs       : strPointer - pointer reference to string
	//                length - the length of the string
	//                number - integer number to convert to binary
	// Outputs      : None. Side-effect -- fills string with binary
	//                binary represenation of the number.

void integerQuickSort(int *numbers, int left, int right);
	// Function     : integerQuickSort
	// Description  : Sort the integer array using QuickSort algorithm
	// Inputs       : number - pointer reference to integer array to sort
	//                left - integer left index
	//                right - integer right index
	// Outputs      : None. Side-effect -- sorts the values in the array
	//                from lowest to highest.

// ADDED HELPER FUNCTIONS -- A. TALBOT (3/1/18)
void swap(int *a, int *b);
	// Function     : swap
	// Description  : Swap the values of two different array integers
	// Inputs       : a - pointer to the value to swap with b
	//                b - pointer to the value to swap with a
	// Outputs      : None. Side-effect -- swaps the values at a and b

int partition(int *ptr, int lo, int hi);
	// Function     : partition
	// Description  : Parition an array for quicksort
	// Inputs       : ptr - pointer to the array or partition
	//                lo - integer lowest index of the partition
	//                hi - integer highest index of the partition
	// Outputs      : The integer index of the new pivot
        

#endif // CMSC257_A1SUPPORT_INCLUDED
