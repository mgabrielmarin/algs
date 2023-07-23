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

void Merge(int arr[], int l, int m, int r)
{
  int i, j, k;
  int L_Len = m - l + 1;
  int R_Len = r - m;

  int L[L_Len], R[R_Len];

  for(i = 0; i < L_Len; ++i)
    L[i] = arr[l + i]; 
  for(j = 0; j < R_Len; ++j)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while(i < L_Len && j < R_Len) {
    if(L[i] <= R[j]) {
      arr[k] = L[i];
      ++i;
      ++k;
    } else {
      arr[k] = R[j];
      ++j;
      ++k;
    }
  }

  while(i < L_Len) {
    arr[k] = L[i];
    ++i;
    ++k;
  }
  while(j < R_Len) {
    arr[k] = R[j];
    ++j;
    ++k;
  }
}
