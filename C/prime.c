#include "prime.h"

static uint64_t dp[100] = {0};

uint64_t
factorial(int n){
    int i;
    if (n == 0 || n == 1){
        return 1;
    }
    if(dp[n] != 0){
        return dp[n];
    }
    dp[0] = 1;
    dp[1] = 1;
    for(i=2;i<=n;i++){
        dp[i] = dp[i-1]*i;
    }

    return dp[n];
}

int
is_prime(int n){
    uint64_t res, fact;

    if(n<=0)
        return -1;

    /*Wilson's theorem
     * for a P as prime
     * (P-1)!%p = (P-1)
     */

    fact = factorial(n-1);
    res = fact%n;
    printf("fact:%ld res:%ld\n",fact,res);

    if(res == n-1) {
        return n;
    }

    return -1;
}

int
nearest_prime(int n){

    int i;
    for(i=n;i<(2*n);i++){
        if(is_prime(i) > 0) {
            return i;
        }
    }
    return -1;
}

#if 0
int main(){

    int n, res;
    printf("\nEnter to the number to find nearest prime number:\n");
    scanf("%d", &n);
    res = nearest_prime(n);

    if(res < 0){
        printf("\nNearest prime number not found\n");
        exit(0);
    }
    printf("\nNearest prime number found is: %d\n", res);

    return 0;
}
#endif
