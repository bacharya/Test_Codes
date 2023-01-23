#include "stdio.h"
#include "stdlib.h"

int dp[100];

int
max(int a, int b){

    return a>b?a:b;
}

int
maxSubArrayRec(int *a, int n){

    if(n == 0){
        return max(0, a[0]);
    }
    if (dp[n])
        return dp[n];

    dp[n] = max(maxSubArrayRec(a, n-1)+a[n], dp[n-1]);

    return dp[n];
}

int
maxSubArraySum(int *a, int n) {

    int i, j, maxVal= 0;
    for(i=0;i<n;i++){
        maxVal = 0;
        for(j=0;j<i;j++) {
            if(a[j]+dp[i-1] > maxVal){
                maxVal = a[j]+dp[j];
            }
        }
    }

    for(i=0;i<n;i++){
        if(dp[i] > maxVal)
            maxVal = dp[i];
    }

    return maxVal;
}

int
main() {

    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n, res, i, maxVal;
    n = sizeof(a)/sizeof(int);
    printf("\nArray is:\n");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);

    for(i=0;i<n;i++)
        dp[i] = 0;

    //res = maxSubArraySum(a, n);
    res = maxSubArrayRec(a, n-1);

    printf("\nDp array is:\n");
    for(i=0;i<n;i++)
        printf("%d ", dp[i]);

    for(i=0;i<n;i++){
        if(dp[i] > maxVal)
            maxVal = dp[i];
    }
    printf("\nMaximum sum is:%d\n", maxVal);

}
