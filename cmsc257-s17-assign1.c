////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmsc257-s17-assign1.c
//  Description    : This is the main source code for for the first assignment
//                   of CMSC257.  See the related
//                   assignment page for details.
//
//   Author        : Andrew Talbot
//   Last Modified : 1/17/2018
//

// Include Files
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Project Includes
#include "cmsc257-s17-assign1-support.h"

//
// Functions

////////////////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : The main function for the CMSC257 assignment #1
//
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Outputs      : 0 if successful test, -1 if failure

#define MAX_FLOATS 20
#define MAX_INTS 25

int main(int argc, char *argv[]) {

	// Local variables
	float f_array[MAX_FLOATS];
    int i, even_floats, even_ints, m_array[MAX_INTS];
    char binary_str[sizeof(int) * 8];

	// Step #1 - read in the float numbers to process
	for (i = 0; i < MAX_FLOATS; i++) {
		scanf("%f", &f_array[i]);
	}

    // Step #2 - convert the floating point values to integers
    for (i = 0; i < MAX_FLOATS; i++) {
        m_array[i] = (int) f_array[i];
    }

    // Step #3 - print out the integer and floating point arrays
    float_display_array(f_array, MAX_FLOATS);
    integer_display_array(m_array, MAX_INTS);
    
    // Step #4 - print out the number of '1's in each integer
    for (i = 0; i < MAX_INTS; i++) {
        printf("The integer %d has %d '1' bits in its binary representation",
            m_array[i], countBits(m_array[i]));
    }

    // Step #5 - Sort the integer array using QuickSort and print the sorted array
    // TO DO -- IMPLEMENT !!!

    // Step #6 - figure out number of evens in each array (float and sorted integer arrays)
    even_floats = float_evens(f_array, MAX_FLOATS);
    even_ints = integer_evens(m_array, MAX_INTS);

    // Step #7 - print the most frequent values from the sorted integer array
    most_values(m_array, MAX_INTS, m_array[MAX_INTS - 1]); 

    // Step #8 - print the integers corresponding to the reverse bit string from integer array
    for (i = 0; i < MAX_INTS; i++) {
        printf("The integer corresponding to the reverse bit string of %d is %d",
            m_array[i], reverseBits(m_array[i]));
    }

	// Return successfully
	return(0);
}
