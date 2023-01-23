#include "stdio.h"
#include "stdlib.h"

int binary_search(int *a, int len, int target){
    int left, right, mid;

    left = 0;
    right = len-1;
    while(left <= right){
        mid = (left+right)/2;
        if (a[mid] == target){
            return mid;
        }
        if (a[mid] < target) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return -1;
}

int main(){

    int arr[7] = {1,3, 5, 6, 8, 9, 23};
    int target = 9, i;

    printf("\nGiven array is:\n");
    for(i=0;i<7;i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTarget:%d, size of array: %lu", target, sizeof(arr));
    printf("\nTarget is at:%d\n", binary_search(arr, 7, target));

    return 0;
}
