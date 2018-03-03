////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmsc257-s17-assign1.c
//  Description    : This is the main source code for for the first assignment
//                   of CMSC257.  See the related
//                   assignment page for details.
//
//   Author        : Andrew Talbot
//   Last Modified : 3/01/2018
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

int main(int argc, char *argv[]) {

	// Local variables
	float f_array[MAX_FLOATS];
    int i, m_array[MAX_INTS];

	// Step #1 - read in the float numbers to process
    printf("\n\n## STEP 1 -- ENTER %d FLOATS\n", MAX_FLOATS);
	for (i = 0; i < MAX_FLOATS; i++) {
		scanf("%f", &f_array[i]);
	}

    // Step #2 - convert the floating point values to integers
    for (i = 0; i < MAX_FLOATS; i++) {
        int converted = (int) f_array[i];   // cast to int
        int shifted = converted >> 31;  // step 1 to convert to absolute value (using bitwise)
        int absolute = (shifted ^ converted) - shifted; // step 2 to convert to absolute value
        m_array[i] = absolute & 15; // fit in range between 0 - 15, bitwise mod
    }

    // Step #3 - print out the integer and floating point arrays
    printf("\n\n## STEP 3 -- FLOATS\n");
    float_display_array(f_array, MAX_FLOATS);
    printf("\n\n## STEP 3 -- INTEGERS\n");
    integer_display_array(m_array, MAX_FLOATS);
    
    // Step #4 - print out the number of '1's in each integer
    printf("\n\n## STEP 4 -- '1' BITS\n");
    for (i = 0; i < MAX_FLOATS; i++) {
        printf("The integer %d has %d '1' bits in its binary representation.\n",
            m_array[i], countBits(m_array[i]));
    }

    // Step #5 - Sort the integer array using QuickSort and print the sorted array
    printf("\n\n## STEP 5 -- SORTED INTEGERS\n");
    int *arr_ptr = m_array;
    integerQuickSort(arr_ptr, 0, MAX_FLOATS - 1);
    integer_display_array(m_array, MAX_FLOATS);


    // Step #6 - figure out number of evens in each array (float and sorted integer arrays)
    printf("\n\n## STEP 6 -- EVENS\n");
    printf(
        "There are %d even numbers in the float array.\nAnd there are %d even numbers in the integer array.\n",
        float_evens(f_array, MAX_FLOATS), integer_evens(m_array, MAX_FLOATS)
    );

    // Step #7 - print the most frequent values from the sorted integer array
    printf("\n\n## STEP 7 -- MOST FREQUENT\n");
    most_values(m_array, MAX_FLOATS, m_array[MAX_FLOATS - 1]);

    // Step #8 - print the integers corresponding to the reverse bit string from integer array
    printf("\n\n## STEP 8 -- REVERSE BITS\n");
    for (i = 0; i < MAX_FLOATS; i++) {
        printf("The integer corresponding to the reverse bit string of %d is %d\n",
            m_array[i], reverseBits((unsigned short int) m_array[i]));
    }

	// Return successfully
	return(0);
}
