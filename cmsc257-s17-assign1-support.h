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
// Functional Prototypes

int float_display_array(float values[], int arr_length);
	// This function prints out the array of floating point values

int integer_display_array(int values[], int arr_length);
	// This function prints out the array of integer values

int float_evens(float numbers[], int arr_length);
	// Return the number of even numbers in the array (float version)

int integer_evens(int numbers[], int arr_length);
	// Return the number of even numbers in the array (int version)

int countBits(int number);  // what type parameter should I use?
	// Count the number of '1' bits in the binary representation

int most_values(int values[], int num_elements, int max_value);
	// Print out the values with the most occurences in array

unsigned short reverseBits(int number);
        // Reverse the binary bit string

void binaryString(char *str_pointer, int length, int number);
        // Print the binary equivalent of the number passed

void integerQuickSort(int numbers[], int left, int right);
        // Sort the integer array using QuickSort algorithm
        

#endif // CMSC257_A1SUPPORT_INCLUDED
