#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void swap(int *a, int *b);
void print_arr(int *arr, int len);
void rand_arr(int *arr, int len);
void selection_sort(int *arr, int len);
void bubble_sort(int *arr, int len);
void insertion_sort(int *arr, int len);

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void print_arr(int *arr, int len)
{
  for(int i = 0; i < len; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

void rand_arr(int *arr, int len) 
{
  srand(time(NULL));
  for(int i = 0; i < len; ++i)
    arr[i] = rand() % 100;
}

void selection_sort(int *arr, int len)
{
  int i,j,min_idx;
  for(i = 0; i < len - 1; ++i) {
    min_idx = i;
    for(j = i+1; j < len; ++j)
      if(arr[j] < arr[min_idx])
        min_idx = j;
    if(min_idx != i)
      swap(&arr[min_idx], &arr[i]);
  }
}

void bubble_sort(int *arr, int len)
{
  for(int i = 0; i < len-1; ++i)
    for(int j = 0; j < len - i - 1; ++j)
      if(arr[j] > arr[j+1])
        swap(&arr[j], &arr[j+1]);
}

void insertion_sort(int *arr, int len)
{
  int i,j,key;
  for(i = 1; i < len; ++i) {
    key = arr[i];
    j = i - 1;
    while(j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j = j - 1;
    }
    arr[j+1] = key;
  }
}
