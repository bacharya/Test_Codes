#include "stdint.h"
#include "stdio.h"

int main() {
uint32_t a = 10;
double b, c=0.01;

b = (double)a;

b = b-c;
printf("\nA=%d B=%lf\n", a, b);
if(b > a) {
    printf("B is greater\n");
}
return 0;
}
