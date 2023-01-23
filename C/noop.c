#include "stdio.h"

#define noop (void)0

int main(){

    int x = 10;
    printf("\nTest program for No-Op\n");
    noop;
    //x = noop;
    printf("\nPost No-Op : %d\n",x);
    return 0;
}
