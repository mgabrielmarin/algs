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

  printf("MergeSort:\n");
  arr = Rand_Arr(len);
  Print_Arr(arr, len); 
  MergeSort(arr, 0, len - 1);
  Print_Arr(arr, len); 
  free(arr);
  printf("\n");

  printf("TreeSort:\n");
  arr = Rand_Arr(len);
  Print_Arr(arr, len); 
  TreeSort(arr, len); // only prints, array stays the same :(
  free(arr);
  printf("\n");

  return 0;
}
