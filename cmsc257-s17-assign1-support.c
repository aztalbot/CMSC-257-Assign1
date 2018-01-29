
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
    char binary_str[sizeof(int) * 8];
    char *bin_str_ptr = &binary_str[0];
    int len = 0;
    int *len_ptr = &len;
    binaryString(bin_str_ptr, len_ptr, number);
    int i, counter;
    counter = 0;
    for (i = 0; i < (int) sizeof(int) * 8; i++) {
        if (binary_str[i] == '1') { counter++; }
    }
    return counter;
}

int most_values(int values[], int num_elements, int max_value){
    return 1; // TO DO -- IMPLEMENT
}

unsigned short reverseBits(int number) {
    char binary_str[sizeof(int) * 8];
    char *bin_str_ptr = &binary_str[0];
    int len = 0;
    int *len_ptr = &len;
    binaryString(bin_str_ptr, len_ptr, number);
    int i;
    unsigned short reverse_int = 0;
    for (i = 0; i < (int) sizeof(int) * 8; i++) {
        int current_int = (int) binary_str[i];
        reverse_int += current_int * (2^i);
    }
    return reverse_int;
}

void binaryString(char *ptr, int *len, int num) {
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

void swap(int *ptr, int a, int b) {
	int temp = ptr[a];
	ptr[a] = ptr[b];
	ptr[b] = temp;
}

int partition(int *ptr, int lo, int hi) {
 int pivot = ptr[hi];
 int i = lo - 1;    
 int j;
 for (j = lo; j < hi; j++) {
 	if (ptr[j] < pivot) {
      swap(ptr, ++i, j);
   }
 }
 if (ptr[hi] < ptr[i + 1]) {
   	swap(ptr, i + 1, hi);
 }
 return i + 1;
}

void integerQuickSort(int *numbers, int left, int right) {
	if(left < right) {
		int p = partition(numbers, left, right);
		integerQuickSort(numbers, left, p - 1);
		integerQuickSort(numbers, p + 1, right);
	}
}
        

// END FUNCTION IMPLEMENTATIONS
