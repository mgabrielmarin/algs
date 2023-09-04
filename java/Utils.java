import java.util.Random;

public class Utils {
    public static void printArr(int[] arr, int len) {
        for(int i = 0; i < len; i++) {
            System.out.printf("%d ", arr[i]);
        }
        System.out.println();
    }
    public static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    public static int[] randArr(int len) {
        Random rd = new Random();
        int[] arr = new int[len];
        for(int i = 0; i < len; i++) {
            arr[i] = rd.nextInt(100);
        }
        return arr;
    }
}
