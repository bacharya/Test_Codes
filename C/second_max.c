#include "stdio.h"
#include "limits.h"

int main(){

    int arr[] = {100, 2, 6, 4, 82, 67, 99, 98, 101};
    int n, i, max, max2;
    n = sizeof(arr)/sizeof(int);

    printf("\nArray elements are:\n");
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);

    printf("\n");

    max = arr[0];
    max2 = INT_MIN;
    for(i=1;i<n;i++){
        if(arr[i] > max){
            max2 = max;
            max = arr[i];
        }
        if(arr[i] > max2 && arr[i] < max){
            max2 = arr[i];
        }
    }

    printf("\nMaximum element is:%d 2nd maximum is:%d\n", max, max2);

}
