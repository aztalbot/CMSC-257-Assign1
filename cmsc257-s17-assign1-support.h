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

int float_display_array(float values[]);
	// This function prints out the array of floating point values

int integer_display_array(int values[]);
	// This function prints out the array of integer values

int float_evens(float numbers[]);
	// Return the number of even numbers in the array (float version)

int integer_evens(int numbers[]);
	// Return the number of even numbers in the array (int version)

int countBits(????);  // what type parameter should I use?
	// Count the number of '1' bits in the binary representation

int most_values(????);  // what type parameter should I use, and do I return the mode?
	// Print out the values with the most occurences in array

unsigned short reverseBits(????);
        // Reverse the binary bit string

void binaryString(????);  // does this take int?
        // Print the binary equivalent of the number passed

void integerQuickSort(int numbers[]);
        // Sort the integer array using QuickSort algorithm
        

#endif // CMSC257_A1SUPPORT_INCLUDED