class BubbleSort {

    static void bubbleSort(int[] arr, int len) {
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len-1-i; j++) {
                if(arr[j] > arr[j+1]) {
                    Utils.swap(arr, j, j+1);
                }
            }
        }
    }

    public static void main(String[] args) {
        int size = 10;
        int[] arr = Utils.randArr(size);
        Utils.printArr(arr, size);
        bubbleSort(arr, size);
        Utils.printArr(arr, size);
    }

}
