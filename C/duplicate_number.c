#include "stdio.h"
#include "stdlib.h"


int main(){
    //int arr[] = {2,3,3,3,4,3,2};
    int arr[100];
    int i, j, n, max = 0, maxid;
    printf("\nEnter the size of array of elements:\n");
    scanf("%d", &n);
    printf("\nENter %d Array elements:\n", n);
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    printf("\nArray elements:\n");
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
    for(i=0;i<n;i++){
        arr[arr[i]%n] += n;
    }
    printf("\nArray elements After:\n");
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\nArray elements After 1:\n");
    for(i=0;i<n;i++){
        if(arr[i]/n > max){
            max = arr[i]/n;
            maxid = i;
        }
        printf("%d ", arr[i]%n);

    }
    printf("\n Index of the element existed max number of time %d\n", maxid);
}
