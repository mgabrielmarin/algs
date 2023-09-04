class MergeSort {
    
    static void merge(int[] arr, int l, int m, int r) {
        int lLen = m - l + 1;
        int rLen = r - m;
        int L[] = new int[lLen];
        int R[] = new int[rLen];
        for(int i = 0; i < lLen; i++) {
            L[i] = arr[l + i];
        }
        for(int j = 0; j < rLen; j++) {
            R[j] = arr[m + 1 + j];
        }
        int i = 0, j = 0;
        int k = l;
        while(i < lLen && j < rLen) {
            if(L[i] < R[j]) {
                arr[k] = L[i];
                i += 1;
                k += 1;
            } else {
                arr[k] = R[j];
                j += 1;
                k += 1;
            }
        }
        while(i < lLen) {
            arr[k] = L[i];
            i += 1;
            k += 1;
        }
        while(j < rLen) {
            arr[k] = R[j];
            j += 1;
            k += 1;
        }
    }
    static void mergeSort(int[] arr, int l, int r) {
        if(l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
    public static void main(String[] args) {
        int size = 10;
        int[] arr = Utils.randArr(size);
        Utils.printArr(arr, size);
        mergeSort(arr, 0, size-1);
        Utils.printArr(arr, size);
    }
}
