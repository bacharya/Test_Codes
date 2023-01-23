#include "stdio.h"
#include "stdlib.h"
#define INT_MAX 9999
#if 0
int search(int* nums, int numsSize, int target){
    if (target == nums[numsSize-1]) {
        return numsSize;
    } else if( target > nums[((numsSize-1)/2)]) {
        return search(nums+((numsSize-1)/2), numsSize, target);
    } else{
        return search(nums, (numsSize-1)/2, target);
    }
    return -1;
}

int search(int* nums, int numsSize, int target){
    int low=0, high = numsSize-1, i;
    i = (high-low)/2;
    while(i < high  && i > low) {
        if (target == nums[i]) {
            return i;
        } else if (target > nums[i]) {
            low =  i;
            i = i+((high-low)/2);
        } else{
            high = i;
            i = low+((high-low)/2);
        }
    }
    return -1;
}
#endif

int bin_search(int *nums, int l, int r, int target) {
    int mid = (r+l)/2;
    if(nums[mid] == target) {
        return mid;
    } 
    if(nums[mid] > target) {
        return bin_search(nums, l, mid, target);
    } else{
        return bin_search(nums, mid, r, target);
    }
    return -1;
}

int search(int* nums, int numsSize, int target){
    int low=0, high = numsSize;
    return bin_search(nums, low, high, target);

}

int minval(int a, int b){
    return a<b?a:b;
}

int minSubArrayLen(int target, int* nums, int numsSize){
int sums[numsSize];
    sums[0] = nums[0];
    int i, j, min= INT_MAX;
    for(i =1; i< numsSize; i++){
        sums[i] = nums[i]+sums[i-1];
    }
    for(i = 0; i< numsSize; i++) {
        if(sums[i] < target) {
            continue;
        }
        printf("%d ",i);
#if 0
        for(j = 0; j < i; j++){
            if (sums[i]-sums[j] >= target) {
                min = minval(min, (i-j));
            }
        }
#endif
        min = (min, search(sums, i, target));
    }
    if (min == INT_MAX)
        return 0;
    return min;
}

int main() {

    int nums[] = {2,3,1,2,4,3}, target = 7, idx, size = 6;
    //idx = search(nums, size, target);
    idx = minSubArrayLen(target, nums, size);

    printf("\nSearch result at index :%d\n", idx);
    return 0;

}
