#include "stdio.h"
#include "stdlib.h"

int main(){

    int v = 100, u = 200;
    int const *a = &v;

    *a = u;
    //name[1] = 'H';
    printf("\a *a = %d\n", *a);
    return 0;

}
