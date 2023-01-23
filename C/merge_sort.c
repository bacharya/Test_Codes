#include "stdio.h"
#include "stdlib.h"

void merge(int *a, int *tmp, int l, int m, int r) {

    int left_end, i, j,k, size;
    left_end = m-1;
    size = r-l+1;
    i = l;
    j = m;
    k = l;

    while(i<=left_end && j<=r) {
        if(a[i] < a[j]){
            tmp[k] = a[i];
            i++;
        } else {
            tmp[k] = a[j];
            j++;
        }
        k++;
    }
    while(j<=r){
        tmp[k] = a[j];
        j++;
        k++;
    }
    while(i<=left_end){
        tmp[k] = a[i];
        i++;
        k++;
    }

    for(i=0;i<size;i++){
        a[r] = tmp[r];
        r--;
    }

}
#if 0
void merge(int *a, int *tmp, int l, int m, int r){

    int left_end, i, size, k;
    left_end = m-1;
    size = r-l+1;
    k = l;
    
    while((l <= left_end) && (m <= r)) {
        if(a[l] < a[m]){
            tmp[k] = a[l];
            l++;
        } else {
            tmp[k] = a[m];
            m++;
        }
        k++;
    }
    while(l <= left_end){
        tmp[k] = a[l];
        l++;
        k++;
    }
    while(m <= r){
        tmp[k] = a[m];
        m++;
        k++;
    }
    for(i=0;i<=size;i++){
        a[r] = tmp[r];
        r--;
    }
    return;
}
#endif
void merge_sort(int *a, int *tmp, int l, int r){
    int m;
    if(l<r){
        m = (l+r)/2;
        merge_sort(a, tmp, l, m);
        merge_sort(a, tmp, m+1,r);
        //merge(a, tmp, l, m+1, r);
        merge(a, tmp, l, m+1, r);
    }
}

void main(){
    int a[10] = {2, 6, 9, 3, 5, 25, 94, 22, 33, 1};
    int b[10], i;
    printf("\nBefore sorting:\n");
    for(i =0;i < 10; i++)
        printf(" %d", a[i]);
    merge_sort(a, b, 0, 9);
    printf("\nAfter sorting:\n");
    for(i =0;i < 10; i++)
        printf(" %d", a[i]);
    printf("\n");
}
