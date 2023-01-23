#include "stdio.h"
#include "stdlib.h"

#define THRESH 0.1

int main() {

    int a = 0;
    int b = 10;
    
    int c;

    c = b*THRESH;
    printf("\nc=%d\n", c);

    if( a >= b*THRESH){
        printf("Test passed\n");
    }else
        printf("Test failed\n");

    return 0;
}

