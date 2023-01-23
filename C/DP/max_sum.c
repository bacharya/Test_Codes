#include "stdio.h"
#include "stdlib.h"
#include "math.h"
static int dp[100] = {0};

int
max(int a, int b){
    return a>b?a:b;
}

int maxThree(int a, int b, int c){

    return a>b?(a>c?a:c):(b>c?b:c);
}

int
max_value(int *a, int m){

    int i=0, j=0, maxVal=0;

    if(a[i] >= 0)
        dp[0] = a[i];
    for (i=1;i<m;i++){
        if((a[i]+dp[i-1] > 0)){
            dp[i] = a[i]+dp[i-1];
        } else {
            dp[i] = 0;
        }
    }

    maxVal = dp[0];
    printf("%d ", maxVal);
    for(j=1;j<m;j++){
        printf("%d ", dp[j]);
        if(dp[j] > maxVal){
            maxVal = dp[j];
        }
    }

    return maxVal;
}

int
max_value_2(int *a, int m){

    int i=0, j=0, maxVal=0;

    if(a[0] >= 0)
        dp[0] = a[0];
    if(a[1] > a[0]){
        dp[1] = a[1];
    } else {
        dp[1] = a[0];
    }
    for (i=2;i<m;i++){
        if(max(a[i]+dp[i-2], dp[i-1]) > 0) {
            dp[i] = max(a[i]+dp[i-2], dp[i-1]);
        } else {
            dp[i] = 0;
        }
    }

    maxVal = dp[0];
    printf("%d ", maxVal);
    for(j=1;j<m;j++){
        printf("%d ", dp[j]);
        if(dp[j] > maxVal){
            maxVal = dp[j];
        }
    }

    return maxVal;
}

int
max_value_3(int *a, int m){

    int i=0, j=0, maxVal=0;

    dp[0] = max(a[0], 0);
    dp[1] = max(a[1], a[0]);
    dp[2] = maxThree(a[2], a[1], a[0]);

    for (i=3;i<m;i++){
        if(maxThree(a[i]+dp[i-3], dp[i-2], dp[i-1]) > 0) {
            dp[i] = maxThree(a[i]+dp[i-3], dp[i-2], dp[i-1]);
        } else {
            dp[i] = 0;
        }
    }

    maxVal = dp[0];
    printf("%d ", maxVal);
    for(j=1;j<m;j++){
        printf("%d ", dp[j]);
        if(dp[j] > maxVal){
            maxVal = dp[j];
        }
    }

    return maxVal;
}

int main(){

    int arr[7] = {2, 11, -3, -4, 13, -5, 2};
    int i, size=7, res;
    printf("\nEntered Array is:\n");
    for(i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\nDP Array is:\n");
    res = max_value(arr, size);
    printf("\nMaximum subsum is:%d\n", res);
    res = max_value_2(arr, size);
    printf("\nMaximum subsum(2 non-contiguous) is:%d\n", res);
    res = max_value_3(arr, size);
    printf("\nMaximum subsum(3 non-contiguous) is:%d\n", res);
    return 0;
}
