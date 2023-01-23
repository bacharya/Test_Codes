#include "stdio.h"

int data[100] = {0};
int res[100] = {0};
int
remove_duplicate(int *a, int n){
    int i, tmp, j, k;
    //int *data = (int *)calloc(n, sizeof(int));
    i = 0;
    j = 0;
    k = n-1;
    while(i<n){
        if(data[a[i]] == 0){
            data[a[i]] = 1;
            res[j] = a[i];
            j++;
        } else {
            res[k] = a[i];
            k--;
        }
        i++;
    }
}

int main() {

    int n, i;
    int a[100];
    printf("\nEnter the array size:\n");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    remove_duplicate(a, n);
    printf("\nAfter removing duplicate elements:\n");
    for(i=0;i<n;i++){
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
