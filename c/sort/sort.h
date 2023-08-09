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

void Selection_Sort(int arr[], int len) {
  for(int i = 0; i < len - 1; ++i) {
    int min_idx = i;
    for(int j = i + 1; j < len; ++j)
      if(arr[j] < arr[min_idx])
        min_idx = j;
    if(min_idx != i)
      Swap(&(arr[min_idx]), &(arr[i]));
  }
}

void MergeSort(int arr[], int l, int r) {
  if(l < r) {
    int m = l + (r - l) / 2;
    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, r);
    Merge(arr, l, m, r);
  }
}

void TreeSort(int arr[], int len) {
    tree* root = NULL;
    for (int i = 0; i < len; i++) {
        root = add(root, arr[i]);
    }
    printInOrder(arr, root);
}
