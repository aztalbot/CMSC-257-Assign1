
////////////////////////////////////////////////////////////////////////////////
//
//  File          : cmsc257-s17-assign1-support.c
//  Description   : This provides the implementations for the functional proto-
//                  types in cmsc257-s17-assign1-support.h.
//
//   Author        : Andrew Talbot
//   Last Modified : 1/17/2018
//

// Include Files
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Functional Prototype Include
#include <cmsc257-s17-assign1-support.h>

//
// Function Implementations

int float_display_array(float values[], int arr_length) {
    for (int i = 0; i < arr_length; i++) {
        printf("%.2f\n", values[i]);
    }
    return 0;
}

int integer_display_array(int values[], int arr_length) {
    for (int i = 0; i < arr_length; i++) {
        printf("%d\n", values[i]);
    }
    return 0;
}

int float_evens(float numbers[], int arr_length) {
    int num_evens = 0;
    for (int i = 0; i < arr_length; i++) {
        if ((int) numbers[i] % 2 == 0) {
            num_evens++;
        }    
    }
    return num_evens;
}

int integer_evens(int numbers[], int arr_length) {
    int num_evens = 0;
    for (int i = 0; i < arr_length; i++) {
        if (numbers[i] % 2 == 0) {
            num_evens++;
        }
    }
    return num_evens;
}

int countBits(int number) {
    return 1; // TO DO -- IMPLEMENT
}

int most_values(int values[], int num_elements, int max_value){
    return 1; // TO DO -- IMPLEMENT
}

unsigned short reverseBits(int number) {
    return 1; // TO DO -- IMPLEMENT
}

void binaryString(char *ptr, int len, int num) {
  // ** CONVERTS ANY INT TO BINARY STRING **
    /// position determines index from end of string
  int position = len[0];
    /// we keep dividing by two until we reach 0
	int quotient = num / 2;
	if (quotient > 0) {
	    //// increment position from end of string
	  len[0]++;
		binaryString(ptr, len, quotient); // recursive call
	}
	  /// when we reach 0 we know the length
	else {
		ptr[len[0] + 1] = '\0'; // null terminate string
	}
	
	char bit = (num % 2) + '0'; // remainder as char
	ptr[len[0] - position] = bit; // place char at correct index
}

void integerQuickSort(int numbers[], int left, int right);
        // Sort the integer array using QuickSort algorithm
        // algorithm quicksort(A, lo, hi) is
        //     if lo < hi then
        //         p := partition(A, lo, hi)
        //         quicksort(A, lo, p - 1 )
        //         quicksort(A, p + 1, hi)

        // algorithm partition(A, lo, hi) is
        //     pivot := A[hi]
        //     i := lo - 1    
        //     for j := lo to hi - 1 do
        //         if A[j] < pivot then
        //             i := i + 1
        //             swap A[i] with A[j]
        //     if A[hi] < A[i + 1] then
        //         swap A[i + 1] with A[hi]
        //     return i + 1
        

// END FUNCTION IMPLEMENTATIONS
