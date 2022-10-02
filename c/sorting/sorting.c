#include "sorting.h"

int main(int argc, char **argv)
{
  int len;
  printf("Please enter array len: ");
  scanf("%d", &len);
  int array[len];  

  rand_arr(array, len);
  printf("Selection Sort:\n");
  print_arr(array, len);
  selection_sort(array, len);
  print_arr(array, len);
  printf("------------------------------\n");

  rand_arr(array, len);
  printf("Bubble Sort:\n");
  print_arr(array, len);
  bubble_sort(array, len);
  print_arr(array, len);
  printf("------------------------------\n");

  rand_arr(array, len);
  printf("Insertion Sort:\n");
  print_arr(array, len);
  insertion_sort(array, len);
  print_arr(array, len);
  printf("------------------------------\n");

  return 0;
}
