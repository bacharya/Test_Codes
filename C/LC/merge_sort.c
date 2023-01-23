#include "stdio.h"
#include "stdlib.h"

void merge(int *arr, int l, int m, int r) {
    int  n1, n2, i, j, k;
    n1 = m-l+1;
    n2 = r-m;

    int L[n1], R[n2];

    for(i = 0; i< n1; i++)
        L[i] = arr[l+i];
    for(j=0;j< n2; j++)
        R[j] = arr[m+1+j];

    i = j = 0;
    k = l;

    while(i < n1 && j < n2) {

        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort( int *arr, int l, int r) {
    if ( l< r) {
        int m = l + (r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {

    int nums[] = {-1,0,3,5,9,12}, target = 12, idx, size = 6;
    merge_sort(nums, 0, size-1);

    printf("\nSort result :\n");

    for(int i = 0;i<size;i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
