#include "stdio.h"


int
binary_search(int *a, int low, int high, int target){

    int mid;
    while(low <= high){
    
        mid = (low+high)/2;
        if(target == a[mid])
            return mid;
        if(target < a[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

int
find_rotated_pos(int *a, int low, int high){
    int mid;
    if(high < 1)
        return -1; 
    while(low <= high){
        mid = (low+high)/2;
        if (a[mid] > a[mid+1])
            return mid;
        if(a[mid] > a[low])
            low = mid+1;
        else
            high = mid;
    }
    return -1;
}

int
find(int *a, int n, int target){

    int pos, idx, res;
    pos = find_rotated_pos(a, 0, n);
    if(pos < 0)
        return -1;
    res = binary_search(a, 0, pos, target);
    if(res < 0)
        return binary_search(a, pos, n, target);
    return res;
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int n, j, i, k, tmp1, tmp2, idx, size, target;
    k = 5;
    j = 0;
    size = sizeof(arr)/sizeof(int);

    printf("\nGiven array is:\n");
    for (i = 0;i<size;i++)
        printf("%d ", arr[i]);
    tmp1 = arr[j];
    for (i = 0;i < size; i++) {
        idx = (j+k)%size;
        tmp2 = arr[idx];
        arr[idx] = tmp1;
        tmp1 = tmp2;
        j= idx;
    }
    printf("\nResult array is:\n");
    for (i = 0;i<size;i++)
        printf("%d ", arr[i]);
    printf("\nEnter the element to be searched:\n");
    scanf("%d", &target);
    printf("\nElement found at index: %d", find(arr, size-1, target));
    printf("\n");
}
