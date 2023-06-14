#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void Swap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void Print_Arr(int arr[], int len) {
  for(int i = 0; i < len; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

int *Rand_Arr(int len)
{
  srand(time(NULL));
  int *arr = calloc(len, sizeof(int));
  for(int i = 0; i < len; ++i)
    arr[i] = rand() % 100;
  return arr;
}
