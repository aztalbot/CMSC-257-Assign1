
////////////////////////////////////////////////////////////////////////////////
//
//  File          : cmsc257-s17-assign1-support.c
//  Description   : This provides the implementations for the functional proto-
//                  types in cmsc257-s17-assign1-support.h.
//
//   Author        : Andrew Talbot
//   Last Modified : 1/17/2018
//

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

int countBits(int number);  // what type parameter should I use?
	// Count the number of '1' bits in the binary representation

int most_values(int values[], int num_elements, int max_value);
	// Print out the values with the most occurences in array

unsigned short reverseBits(int number);
        // Reverse the binary bit string

void binaryString(char *str_pointer, int length, int number) {
    int quotient = number / 2;
    if (quotient > 0) {
        binaryString(*str_pointer, length - 1, quotient);
    } else {
        str_pointer = number % 2;
    }
    *str_pointer += length;
    str_pointer = '\0';
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
