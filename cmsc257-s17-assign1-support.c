
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


// Function     : float_display_array
// Description  : This function prints out the array of floating point values
// Inputs       : values - pointer reference to array of floats
//                arrLength - integer length of array
// Outputs      : 0 if successful test, -1 if failure
int float_display_array(float *values, int arrLength) {
    // iterate over array and print out floats
    for (int i = 0; i < arrLength; i++)
        printf("%6.2f%s", values[i], (i == arrLength - 1) ? "" : ", ");
    printf("\n");
    return 0;
}


// Function     : integer_display_array
// Description  : This function prints out the array of integer values
// Inputs       : values - pointer reference to array of integers
//                arrLength - integer length of array
// Outputs      : 0 if successful test, -1 if failure
int integer_display_array(int *values, int arrLength) {
    // iterate over array and print out integers
    for (int i = 0; i < arrLength; i++)
        printf("%3d%s", values[i], (i == arrLength - 1) ? "" : ", ");
    printf("\n");
    return 0;
}


// Function     : float_evens
// Description  : Return the number of even numbers in the array (float version)
// Inputs       : numbers - pointer reference to array of floats
//                arrLength - integer length of array
// Outputs      : integer number of even numbers in the array
int float_evens(float *numbers, int arrLength) {
    // iterate through array and count each even number
    int i, numEvens;
    numEvens = 0;
    for(i = 0; i < arrLength; i++) {
        if(((int) numbers[i] & 1) == 0) // mod bitwise
            numEvens++;
    }
    return numEvens;
}


// Function     : integer_evens
// Description  : Return the number of even numbers in the array (int version)
// Inputs       : numbers - pointer reference to array of integers
//                arrLength - integer length of array
// Outputs      : integer number of even numbers in the array
int integer_evens(int *numbers, int arrLength) {
    // iterate through array and count each even number
    int i, numEvens;
    numEvens = 0;
    for(i = 0; i < arrLength; i++) {
        if((numbers[i] & 1) == 0) // mod bitwise
            numEvens++;
    }
    return numEvens;
}


// Function     : countBits
// Description  : Count the number of '1' bits in the binary representation
// Inputs       : number - integer to count bits from
// Outputs      : integer number of nonzero bits in the number
int countBits(int number) {
    // COUNTS 1 BITS IN BINARY STRING
    int i, len, counter;
    len = 33; // int (4 bytes) plus null terminator
    char binaryStr[sizeof(int) * len];
    // fill binaryStr with binary representation of number
    binaryString((char*) &binaryStr, len, number);
    counter = 0;
    for(i = 0; i < (int) sizeof(int) * len; i++) {
        if(binaryStr[i] == '1')
            counter++; // increment counter for each '1'
    }
    return counter;
} // end countBits


// Function     : float_display_array
// Description  : Print out the values with the most occurences in array
// Inputs       : values - pointer reference to integer array
//                numElements - the number of elements in the array
//                maxValue - the maximum possible value
// Outputs      : integer 1 indicating success -- prints value(s) occuring most often
int most_values(int *values, int numElements, int maxValue){
    // Assumes sorted array, iterates through and counts freq of values
    // need to allocate an array in case no distinct mode
    int *mostValues = malloc(sizeof(int) * numElements);
    int i, mostFreq, currentVal, numModes, lastIndex, seenMax; // we keep track of these -- initially 0
    for(i = 1, lastIndex = mostFreq = numModes = seenMax = 0;
            (i <= numElements && !seenMax); i++) {
        currentVal = values[i - 1]; // set the currentValue for the next comparison
        int isMax = currentVal == maxValue; // if maxValue is only the last index, we don't care
        // loop until we reach the maxValue - because we know that's last
        if(values[i] != currentVal || isMax) { // we reached the next value
            int freq = (isMax) ? (numElements - (i - 1)) : i - lastIndex; // freq of the last value we saw
            freq = (freq == 0) ? 1 : freq;
            lastIndex = i; // where that last value is
            if(freq - mostFreq >= 1) { // did it occur more than the current mode?
                mostFreq = freq; // replace the current mode
                numModes = 1; // pretend array has one item
                mostValues[numModes - 1] = currentVal;
            } else if(freq - mostFreq == 0) { // same freq as current mode?
                numModes++; // add it to the array
                mostValues[numModes - 1] = currentVal;
            }
            seenMax = (isMax) ? 1 : 0;
        }
    }
    for(i = 0; i < numModes; i++)
      printf("%d%s", mostValues[i], ((i == numModes - 1) ? "" : ", "));
    free(mostValues);
    return 1;
} // end most_values


// Function     : reverseBits
// Description  : Reverse the binary bit string
// Inputs       : number - the unsigned short int number to reverse
// Outputs      : the number, as an unsigned short int, 
//                represented by the reverse of the input's bits
unsigned short int reverseBits(unsigned short int number) {
    // interpret the binary string backwards
    int i, j, len;
    unsigned short int reverseInt = 0;
    len = 17; // short (2 bytes) plus null terminator
    char binaryStr[sizeof(int) * len];
    // generate binary string of number
    binaryString((char*) &binaryStr, len, number);
    for(i = 0, j = 1; i < len - 1; i++, j <<= 1) // multiply j by 2 bitwise each iter
        reverseInt += (binaryStr[i] & 1) * j;
    return reverseInt;
} // end reverseBits


// Function     : binaryString
// Description  : Print the binary equivalent of the number passed
// Inputs       : strPointer - pointer reference to string
//                length - the length of the string
//                number - integer number to convert to binary
// Outputs      : None. Side-effect -- fills string with binary
//                binary represenation of the number.
void binaryString(char *ptr, int len, int num) {
  // CONVERTS ANY INT TO BINARY STRING
  int start, numBits, i;
  ptr[len - 1] = '\0'; // terminate string at end of array
  if (num == 0) {
    for(i = len - 2; i >= 0; i--) {
      ptr[i] = 0 + '0'; // if 0 return all 0s
    }
  } else {
    // get number of bits required to express the given number
    numBits = (int) ceil(log2(num + 1)); // e.g. 8 requires 4 bits
    start = (numBits >= len - 1) ? 0 : numBits - 1;
    for(i = 0; i < start; i++)
      ptr[i] = '0';  // pad with 0's to left of start
    // loop from end to start assigning remainder and dividing num by 2
    for(i = len - 2; i >= start ; i--) {
      char remainder = (num & 1) + '0'; // mod bitwise
      ptr[i] = remainder;
      num >>= 1; // div by 2 btwise
    }
  }
} // end binaryString

// ###### QUICKSORT #########
// QUICKSORT HELPER FUNCTIONS
// --------------------------

// Function     : swap
// Description  : Swap the values of two different array integers
// Inputs       : a - pointer to the value to swap with b
//                b - pointer to the value to swap with a
// Outputs      : None. Side-effect -- swaps the values at a and b
void swap(int *a, int *b) {
    // swap values using bitwise operators
    if(a != b) { // must be different
  	  *a ^= *b;
  	  *b ^= *a;
      *a ^= *b;
    }
} // end swap

// Function     : partition
// Description  : Parition an array for quicksort
// Inputs       : ptr - pointer to the array or partition
//                lo - integer lowest index of the partition
//                hi - integer highest index of the partition
// Outputs      : The integer index of the new pivot
int partition(int *ptr, int lo, int hi) {
  // algorithm from wikipedia as instructed
  int pivot, i, j;
  pivot = ptr[hi];
  i = lo - 1;    
  for (j = lo; j < hi; j++) {
   if (ptr[j] < pivot) {
      swap(&ptr[++i], &ptr[j]);
   }
  }
  if (ptr[hi] < ptr[i + 1]) {
   	swap(&ptr[i + 1], &ptr[hi]);
  }
  return i + 1;
} // end partition
// END QUICKSORT HELPER FUNCTIONS
// ------------------------------

// Function     : integerQuickSort
// Description  : Sort the integer array using QuickSort algorithm
// Inputs       : number - pointer reference to integer array to sort
//                left - integer left index
//                right - integer right index
// Outputs      : None. Side-effect -- sorts the values in the array
//                from lowest to highest.
void integerQuickSort(int *numbers, int left, int right) {
	if(left < right) {
		int p = partition(numbers, left, right);
		integerQuickSort(numbers, left, p - 1);
		integerQuickSort(numbers, p + 1, right);
	}
} // end integerQuickSort

// ###### END QUICKSORT ######

// END FUNCTION IMPLEMENTATIONS
