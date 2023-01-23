#include "stdio.h"
#include "stdlib.h"


static int dp[100] = {0};
/*
 * [10,9,2,5,3,7,101,18]
 */

int max(int a, int b) {
    return a>b?a:b;
}

/*
 *   max(n) = { max(m[n-1], )
 *
 */

int
longest_inc_seq(int *a, int n){

    int i, j, high;
    if(n<0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    for(j=0;j<n;j++) {
        dp[j] = 1;
    }
    for(i=0;i<n;i++)
        printf("%d ", dp[i]);
    printf("\n");
    for(i=1;i<n;i++) {
        for(j=0;j<i;j++) {
            if(a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    high = dp[0];
    for(i=1;i<n;i++){
        if(dp[i] > high){
            high = dp[i];
        }
    }

    for(i=0;i<n;i++)
        printf("%d ", dp[i]);
    printf("\n");
    return high;
}

int main(){

    int arr[] = {10,9,2,5,3,7,101,18},n,i,res;
    n = sizeof(arr)/sizeof(int);
    printf("\nGiven array is:\n");
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\nDP array is:\n");
    for(i=0;i<n;i++)
        printf("%d ", dp[i]);
    printf("\n");
    res = longest_inc_seq(arr,n);
    printf("Longest increasing sequence is of length:%d\n", res);

    return 0;
}
