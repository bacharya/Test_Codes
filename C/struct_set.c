#include "stdio.h"
#include "stdlib.h"

typedef struct st_ {
int a;
int b;
int c;
} st;

int main() {

    st s = {0};

    printf("Strcut contents: %d %d %d\n", s.a, s.b, s.c);

    s.a = 10;
    s.b = 20;
    s.c = 30;

    printf("Strcut contents: %d %d %d\n", s.a, s.b, s.c);

    s = {0};
    
    printf("Strcut contents: %d %d %d\n", s.a, s.b, s.c);
 return 0;
}
