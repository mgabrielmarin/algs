#include <stdio.h>
#include <stdlib.h>

void swap(int *i, int *j) {
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

void bubble_sort(int *arr, int len) {
    for(int i = 0; i < len; ++i) {
        for(int j = 0; j < len - i - 1; ++j) {
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void insertion_sort(int *arr, int len) {
    for(int i = 1; i < len; ++i) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selection_sort(int *arr, int len) {
    for(int i = 0; i < len - 1; ++i) {
        int minidx = i;
        for(int j = i+1; j < len; ++j)
            if(arr[j] < arr[minidx])
                minidx =  j;
        if(arr[minidx] != arr[i])
            swap(&arr[minidx], &arr[i]);
    }
}

/* Helper function used for merge sort */
void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int llen = m - l + 1;
    int rlen = r - m;
    int larr[llen], rarr[rlen];

    for(i = 0; i < llen; ++i)
        larr[i] = arr[l+i];
    for(j = 0; j < rlen; ++j)
        rarr[j] = arr[m+1+j];

    i = j = 0;
    k = l;
    while(i < llen && j < rlen) {
        if(larr[i] < rarr[j]) {
            arr[k] = larr[i];
            i++; k++;
        } else {
            arr[k] = rarr[j];
            j++; k++;
        }
    }
    while(i < llen) {
        arr[k] = larr[i];
        i++; k++;
    }
    while(j < rlen) {
        arr[k] = rarr[j];
        j++; k++;
    }
}

void merge_sort(int *arr, int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low;
    for(int j = low; j < high; ++j) {
        if(arr[j] < pivot) {
            swap(&arr[j], &arr[i]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);

    return i;
}

void quick_sort(int *arr, int l, int h) {
    if(l < h) {
        int p = partition(arr, l, h);
        quick_sort(arr, l, p-1);
        quick_sort(arr, p, h);
    }
}

struct tree {
    int val;
    struct tree *left;
    struct tree *right;
};

struct tree *init_tree(int val) {
    struct tree* t = malloc(sizeof(struct tree));
    t->val = val;
    t->left = t->right = NULL;
    return t;
}

struct tree *add_tree(struct tree *t, int val) {
    if(t == NULL)
        return init_tree(val);
    if(val < t->val)
        t->left = add_tree(t->left, val);
    else
        t->right = add_tree(t->right, val);
    return t;
}

void in_order(int *arr, int *i, struct tree *t) {
  if(t != NULL) {
        in_order(arr, i,  t->left);
        arr[*i] = t->val; (*i)++;
        in_order(arr, i, t->right);
    }
}

void tree_sort(int *arr, int len) {
    struct tree *root = NULL;
    int i;
    for(i = 0; i < len; ++i) {
        root = add_tree(root, arr[i]);
    }
    i = 0;
    in_order(arr, &i, root);
}

void print_arr(int *arr, int len) {
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int *copy_arr(int *arr, int len) {
    int *narr = malloc(sizeof(int)*len);
    for(int i = 0; i < len; ++i)
        narr[i] = arr[i];
    return narr;
}

int main(void) {
    int root[5] = {3, 10, 2, 5, 7};
    int len = sizeof(root) / sizeof(int);

    printf("Bubble sort:\n");
    int *arr = copy_arr(root, len);
    print_arr(arr, len);
    bubble_sort(arr, len);
    print_arr(arr, len);
    free(arr);

    printf("Insertion sort:\n");
    arr = copy_arr(root, len);
    print_arr(arr, len);
    insertion_sort(arr, len);
    print_arr(arr, len);
    free(arr);

    printf("Selection sort:\n");
    arr = copy_arr(root, len);
    print_arr(arr, len);
    selection_sort(arr, len);
    print_arr(arr, len);
    free(arr);

    printf("Merge sort:\n");
    arr = copy_arr(root, len);
    print_arr(arr, len);
    merge_sort(arr, 0, len-1);
    print_arr(arr, len);
    free(arr);

    printf("Quick sort:\n");
    arr = copy_arr(root, len);
    print_arr(arr, len);
    quick_sort(arr, 0, len-1);
    print_arr(arr, len);
    free(arr);

    printf("Tree sort:\n");
    arr = copy_arr(root, len);
    print_arr(arr, len);
    tree_sort(arr, len);
    print_arr(arr, len);
    free(arr);

    return 0;
}
