#include "stdio.h"
#include "stdlib.h"

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    returnSize = (int *) malloc(2*sizeof(int));
    int tmp, found,i, j;
    for(i=0;i<numsSize-1;i++){
        tmp = target-nums[i];
        found = 0;
        for(j=i+1;j<numsSize;j++){
            
            if(nums[j] == tmp){
                returnSize[0] = i;
                returnSize[1] = j;
                return returnSize;              
            }
        }
    }
    return returnSize;
}

int main() {

    int nums[4] = {2,7,11,15};
    int target = 9;
    int *returnSize = NULL;

    returnSize = twoSum(nums, 4, target, returnSize);

    printf("%d %d", returnSize[0], returnSize[1]);

    return 0;


}
