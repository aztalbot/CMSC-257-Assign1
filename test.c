#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binaryString(char *str_pointer, int length, int number) {
    int quotient = number / 2;
    if (quotient > 0) {
        binaryString(str_pointer + 1, length - 1, quotient);
    }
    str_pointer = number % 2;
    *str_pointer += length;
    str_pointer = '\0';
}

int main(int argc, char *argv[]) {
  int number = 12;  // 1100 in binary
  char binary_str[sizeof(int) * 8];
  char *ptr = binary_str;
  binaryString(ptr, sizeof(int) * 8, number);
  printf("%s", binary_str);
  return 0;
}