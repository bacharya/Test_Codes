#include "stdio.h"
#include "stdlib.h"

int find(int *a, int l , int h){
    int m;
    int v = -1;
    if(l<h && (h-l >= 2)){
    //if(l<h){
        m = (l+h)/2;
        printf("mean: --%d--\n", (a[l]+a[h])/2);
        printf("mid:  --%d--\n", a[m]);
        printf("l:    --%d--\n", l);
        printf("h:    --%d--\n", h);
        printf("m:    --%d--\n", m);
        printf("----------\n\n");
        if(a[m] != (a[l]+a[h])/2)
            return (a[l]+a[h])/2;
        v = find(a, l, m);
        if(v >= 0)
            return v;
        v = find(a, m, h);
        return v;
    }
    return -1;
}

int main(){

    int arr[100] = {0};
    int n, i;
    int l = 0, r = 7, res = -1;
    printf("\nEnter the size:\n");
    scanf("%d", &n);
    printf("\nEnter %d elements:\n",n);
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    res = find(arr, l, n-1);
    if (res < 0){
        printf("\nMissing number is not found\n");
        return 0;
    }
    printf("\nMissing number is %d\n", res);
    return 0;
}
