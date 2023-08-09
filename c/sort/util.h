#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tree {
    int          val;
    struct tree* left;
    struct tree* right;
} tree;

void Swap(int* x, int* y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void Print_Arr(int arr[], int len) {
  for(int i = 0; i < len; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

int *Rand_Arr(int len)
{
  srand(time(NULL));
  int *arr = calloc(len, sizeof(int));
  for(int i = 0; i < len; ++i)
    arr[i] = rand() % 100;
  return arr;
}

void Merge(int arr[], int l, int m, int r)
{
  int i, j, k;
  int L_Len = m - l + 1;
  int R_Len = r - m;

  int L[L_Len], R[R_Len];

  for(i = 0; i < L_Len; ++i)
    L[i] = arr[l + i]; 
  for(j = 0; j < R_Len; ++j)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while(i < L_Len && j < R_Len) {
    if(L[i] <= R[j]) {
      arr[k] = L[i];
      ++i;
      ++k;
    } else {
      arr[k] = R[j];
      ++j;
      ++k;
    }
  }

  while(i < L_Len) {
    arr[k] = L[i];
    ++i;
    ++k;
  }
  while(j < R_Len) {
    arr[k] = R[j];
    ++j;
    ++k;
  }
}

tree* newtree(int val) {
    tree* tmp = malloc(sizeof(tree));
    tmp->val = val;
    tmp->left = tmp->right = NULL;
    return tmp;
}

tree* add(tree* t, int val) {
    if (t == NULL) {
        return newtree(val);
    }
    if (val < t->val) {
        t->left = add(t->left, val);
    } else {
        t->right = add(t->right, val);
    }
    return t;
}

void printInOrder(int arr[], tree* t) {
    if (t != NULL) {
        printInOrder(arr, t->left);
        printf("%d ", t->val);
        printInOrder(arr, t->right);
    }
}

