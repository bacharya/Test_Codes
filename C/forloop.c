#include "stdio.h"

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int i;
    for(i=0;i<8;i++) {
     printf(" %d", arr[i]);
     i = i+1;
    }
    printf("\n");
    return 0;

}
