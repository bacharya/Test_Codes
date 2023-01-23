#include "stdio.h"
#include "limits.h"

int static d[5] = {1, 2, 5, 10, 50};
int static n_d = 5;
int static dp[100] = {0};

int min(int a, int b) {

    return a<b?a:b;
}

int making_change(int n) {

    int i, res;
    if (n < 0){
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (dp[n] != 0) {
        return dp[n];
    }

    res = INT_MAX;
    for(i = 0; i<n_d; i++){
        if(n-d[i] < 0)
            break;
       res = min(res, making_change(n-d[i])+1);
    }

    dp[n] = res;
    return dp[n];
}

int main() {

    int n;
    printf("\nEnter the value:\n");
    scanf("%d", &n);
    printf("\nMinimum change denominations required is:%d\n", making_change(n));

}
