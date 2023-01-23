#include "stdio.h"

int i = 0;

int test_rec(int *count){
    int arr[8000] = {0};
    printf("\nCount : %d", ++*count);
    return test_rec(count);
    return 1;
}

int main(){
    int c = 0;
    test_rec(&c);
    return 0;
}
