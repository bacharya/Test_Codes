#include "stdio.h"

int main(){

    short a = 10;
    long int A = 10;
    int B = 0;
    long double F = 0.00;
    long long int D = 100;
    int a1 = 0;
    printf("\nSize of short=%ld, long=%ld int=%ld float=%ld long long int=%ld\n",sizeof(a), sizeof(A), sizeof(B), sizeof(F), sizeof(D));
    printf("\na=%d\n",a);
    printf("\nA=%ld\n",A);
    int b = ++a+a+++a+++a++;
    //int b = 10+a++;
    printf("a=%d, b=%d\n",a,b);
    A++;
    B+=A;
    A++;
    B+=A;
    A++;
    B+=A;
    //++A;
    B+=++A;
    printf("A=%ld, B=%d",A,B);

    a1 = B + (A<100);
    printf("\n%d\n",a1);
    return 0;
}
