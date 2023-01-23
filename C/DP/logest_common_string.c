#include "stdio.h"
#include "stdlib.h"
#include "string.h"
    
static int dp[100][100] = {0};

int max(int a, int b){
    return a>b?a:b;
}


/*
 *           |- 0. if i == m or j==n
 *  lcs(i,j) |- max(lcs(i, j+1), lcs(i+1, j))
 *           |- 1 if X[i] == Y[j]
 */

int lcs_dp(char *X, int m, char *Y, int n) {

    int i, j;

    for(i=m-1; i>=0;i--) {
        for(j=n-1;j>=0;j--){
            if(X[i] == Y[j]) {
                dp[i][j]=max(dp[i][j], dp[i-1][j-1]);
            }
        }
    
    }
    return dp[0][0];
}

int
lcs_dp_res(char *X, int i, int j) {

    if (i < 0 || j < 0){
        return 0;
    }

    if(dp[i][j] == 1){
        //printf("%c", X[i]);
        return 1+lcs_dp_res(X, i-1, j-1);
    }
    else {
        return max(lcs_dp_res(X, i-1, j), lcs_dp_res(X, i, j-1));
    }

}

int lcs(char *X, int i, int m, char *Y, int j, int n) {

    if(i == m || j == n)
        return 0;
    else if(X[i] == Y[j])
        return 1+lcs(X, i+1, m, Y, j+1, n);
    else
        return max(lcs(X, i, m, Y, j+1, n), lcs(X, i+1, m, Y, j, n)); 
}

void
print_dp_array(int m, int n) {

    int i, j;
    printf("\nContents of DP array:\n");
    for(i=0;i<=m;i++) {
        for(j=0;j<=n;j++)
            printf("%d ", dp[i][j]);
        printf("\n");
    }
}

int main(){

    char *a = "ABCBDAB", *b= "BDCABAB";
    int m, n, res, i, j;

    printf("\nEntered strings are:%s & %s\n", a, b);
    m = strlen(a);
    n = strlen(b);
    print_dp_array(m, n);
    printf("length of longest substring is :%d\n", lcs(a, 0, m, b, 0, n));
    //printf("length of longest substring is(DP) :%d\n", lcs_dp(a, m, b, n));
    lcs_dp(a, m, b, n);
    print_dp_array(m, n);
    res = lcs_dp_res(a, m-1,n-1);
    printf("\nResult is %d\n", res);

    return 0;
}
