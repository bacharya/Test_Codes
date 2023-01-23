#include "stdio.h"
#include "stdlib.h"

void
swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int
partition(int *a, int low, int high) {
    int left, right, p = a[low];
    left = low;
    right = high;

    while(left < right){
        while(a[left] <= p)
            left++;
        while(a[right] > p)
            right--;
        if(left < right)
            swap(&a[left], &a[right]);
    }
    a[low]  = a[right];
    a[right] = p;
    return right;
}

void
quick_sort(int *a, int l, int r) {
    int p;
    if(l<r){
        p = partition(a, l, r);
        quick_sort(a, l, p-1);
        quick_sort(a, p+1, r);
    }
    return;
}

void main(){
    int a[10] = {2, 6, 9, 3, 5, 25, 94, 22, 33, 1};
    int b[10], j, i;
    printf("\nBefore sorting:\n");
    for(j = 0; j < 10; j++)
        printf(" %d", a[j]);
    quick_sort(a, 0, 9);
    printf("\nAfter sorting:\n");
    for(i =0;i < 10; i++)
        printf(" %d", a[i]);
    printf("\n");
}
