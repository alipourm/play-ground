#include "stdio.h"

void print_array(int* A, size_t size) {
  int i;
  for(i = 1; i < size; i++)
    printf("%d ", A[i]);

}
