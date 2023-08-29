class BubbleSort {

    static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    static void printArr(int[] arr, int len) {
        for(int i = 0; i < len; i++) {
            System.out.printf("%d ", arr[i]);
        }
        System.out.println();
    }

    static void bubbleSort(int[] arr, int len) {
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len-1-i; j++) {
                if(arr[j] > arr[j+1]) {
                    swap(arr, j, j+1);
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = { 3, 5, 9, 2, 7, 8 };
        int size = arr.length;
        bubbleSort(arr, size);
        printArr(arr, size);
    }

}
