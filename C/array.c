#include "stdio.h"
#include "stdlib.h"


void
print_array_val(char arr[3][5], int m, int n){
    int i, j;
    char *ptr = NULL;
    for(i=0;i<m;i++)
    {
        //ptr = *arr[i];
        for(j=0;j<n;j++) {
            printf("%c",arr[i][j]);
            if(' ' == arr[i][j]){
                arr[i][j] = '0';
            }
        }
        printf("\n");
    }

    return;
}

void
print_array_ref(char (*arr)[5], int m, int n){
    int i, j;
    char *ptr = NULL;
    for(i=0;i<m;i++)
    {
        //ptr = *arr[i];
        for(j=0;j<n;j++) {
            printf("%c",arr[i][j]);
            if('0' == arr[i][j]){
                arr[i][j] = '_';
            }
        }
        printf("\n");
    }

    return;
}

void
print_sd_array(int *arr, int n){
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return;
}

void
pass_by_ref(int *a, int n){

    a[0] = 0;
    return;
}

int
compare(void *a, void *b){

    int x, y;
    x = *(int *)a;
    y = *(int *)b;

    if(x == y)
        return 0;

    return x<y?-1:1;
}

int main() {
    char arr[3][5]  = { ' ', ' ','1', ' ', ' ',
        ' ','1',' ' ,'1',' ',
        '1', ' ', ' ', ' ','1'};

    int n;

    int ar[5] = {5,4,3,2,1};

    n = sizeof(ar)/sizeof(int);

    print_array_val(arr, 3, 5);
    printf("--------------------------------------\n");
    print_array_ref(arr, 3, 5);
    printf("--------------------------------------\n");
    print_array_val(arr, 3, 5);
    printf("--------------------------------------\n");
    print_sd_array(ar, n);
    pass_by_ref(ar, n);
    print_sd_array(ar, n);
    printf("--------------------------------------\n");
    qsort(ar, n, sizeof(int), compare);
    print_sd_array(ar, n);
    printf("--------------------------------------\n");

    return 0;
}
