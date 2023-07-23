#include "util.h"
#include "sort.h"

int main(int argc, char *argv[])
{
  int len = 10;
  int *arr;

  printf("Bubble_Sort:\n");
  arr = Rand_Arr(len);
  Print_Arr(arr, len); 
  Bubble_Sort(arr, len);
  Print_Arr(arr, len); 
  free(arr);
  printf("\n");

  printf("Insertion_Sort:\n");
  arr = Rand_Arr(len);
  Print_Arr(arr, len); 
  Insertion_Sort(arr, len);
  Print_Arr(arr, len); 
  free(arr);
  printf("\n");

  printf("Selection_Sort:\n");
  arr = Rand_Arr(len);
  Print_Arr(arr, len); 
  Selection_Sort(arr, len);
  Print_Arr(arr, len); 
  free(arr);
  printf("\n");

  printf("Merge_Sort:\n");
  arr = Rand_Arr(len);
  Print_Arr(arr, len); 
  Merge_Sort(arr, 0, len - 1);
  Print_Arr(arr, len); 
  free(arr);
  printf("\n");

  return 0;
}
