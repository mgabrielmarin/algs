void Bubble_Sort(int arr[], int len) {
  for(int i = 0; i < len; ++i)
    for(int j = 0; j < len - i - 1; ++j)
      if(arr[j] > arr[j+1])
        Swap(&(arr[j]), &(arr[j+1]));
}

void Insertion_Sort(int arr[], int len) {
  for(int i = 1; i < len; ++i) {
    int key = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j = j - 1;
    }
    arr[j+1] = key;
  }
}
