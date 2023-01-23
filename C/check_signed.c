#include "stdio.h"
#include "stdlib.h"

int main(){
    int a = 121;
    int res = 0;
    printf("\na=%d\n", a);
    res = (a & (1 << 31)) == (1 << 31);
    printf("\nres=%d\n", res);
    return 0;

}
