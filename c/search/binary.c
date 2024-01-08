// Binary search, that finds tval index inside arr.
// If tval is not found, returns -1 val.
int binarysearch(int arr[], int len, int tval) {
    int low = 0;
    int high = len - 1;
    int mid = 0;
    while(low <= high) {
        mid = ((high-low)/2) + low;
        int val = arr[mid];
        if(val == tval) {
            return mid; 
        }
        if(val > tval) {
            high = mid - 1;
            continue;
        }
        if(val < tval) {
            low = mid + 1;
            continue;
        }
    }
    return -1;
}
