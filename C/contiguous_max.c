#include "stdio.h"
#include "stdlib.h"

int max(int a, int b, int c){

    return a>b?(a>c?a:c):(b>c?b:c);
}

/*
 * 1. check in the 
 *
 * */

int maxVal(int *a, int l, int h) {

    int maxLeftSum = 0, maxRightSum=0, leftSum = 0, rightSum = 0, leftBrSum = 0, rightBrSum=0;
    int m, i;
    if (l == h){
        return a[l];
    }
    m = (l+h)/2;

    leftSum = maxVal(a, l, m);
    rightSum = maxVal(a, m+1,h);

    for(i= m; i>=l;i--){
        leftBrSum += a[i];
        if(leftBrSum > maxLeftSum){
            maxLeftSum = leftBrSum;
        }
    } 
    for(i= m+1; i<=h;i++){
        rightBrSum += a[i];
        if(rightBrSum > maxRightSum){
            maxRightSum = rightBrSum;
        }
    } 

    return max(leftSum, rightSum, maxLeftSum+maxRightSum);

}

int main(){

    int arr[] = {1, 0, 5, -2, 4, 20, 1};
    int a= 30, b= 20, c= 45, i, n=7;

    printf("Max of a:%d, b:%d, c:%d is res:%d", a, b, c, max(a,b,c));
    printf("\nArray contents are:\n");
    for(i = 0;i<n;i++){
        printf("%d \n", arr[i]);
    }
    printf("\nMax sum of subsequence is %d\n", maxVal(arr, 0, n-1));

    return 0;
}
