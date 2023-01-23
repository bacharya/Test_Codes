#include "stdio.h"

int dp[100] = {1};
int
catalan(int n){

    int i, count;
    if(n == 0){
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    dp[n] = 0;
    for(i=1; i<=n; i++){
        dp[n] += catalan(i-1)*catalan(n-i);
    }

    return dp[n];
}

int main() {

    int n;

    printf("\nEnter the number of vertices:\n");
    scanf("%d", &n);
    printf("\nNumber of possible BSTs for %d vertices are:%d\n", n, catalan(n));

    return 0;
}
