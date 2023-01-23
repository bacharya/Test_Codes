#include "stdio.h"
#include "stdlib.h"
#define COUNT 10

typedef struct node_ {

    int data;
    struct node_ *left, *right;
} node_t;

typedef node_t * node;

int
max(int a, int b){
    return a>b?a:b;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(node root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    print2DUtil(root->left, space);
}


int
inorder(node root, int *count, int pos){
    
    int res = -1;
    if(!root)
        return res;
    res = inorder(root->left, count, pos);
    //printf("%d ", root->data);
    if (res != -1)
        return res;
    if(++(*count) == pos){
        //printf("%d ", root->data);
        return root->data;
    }
    res = inorder(root->right, count, pos);
    return res;
}

node
buildBST(node root, int a[], int low, int high){

    int mid;

    if(low<high){
        mid = (low+high)/2;
        if(!root){
            root = (node) calloc(1, sizeof(node_t));
        }
        root->data = a[mid];
        root->left = buildBST(root->left, a, low, mid);
        root->right = buildBST(root->right, a, mid+1, high);
    }

    return root;

}

int partition(int *a, int low, int high) {

    int pivot, i, j, tmp;
    pivot = a[low];
    i = low;
    j = high;
    while(i < j){
        while(a[i] <= pivot)
            i++;
        while(a[j] > pivot)
            j--;
        if(i < j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    a[low] = a[j];
    a[j] = pivot;
    return j;
}

void
q_sort(int *a, int low, int high){
    int p;
    if(low < high) {
        p = partition(a, low, high);
        q_sort(a, low, p-1);
        q_sort(a, p+1, high);
    }
    return;
}


int
max_path_sum(node root){
    int leftSum, rightSum;
    if(!root)
        return 0;
    leftSum = max_path_sum(root->left);
    rightSum = max_path_sum(root->right);
    return max(leftSum, rightSum)+root->data;
}

int main() {

    node root = NULL;
    int arr[] = {100, 2, 6, 26, 4, 82, 88, 67, 99, 98, 101};
    int n, i, max, max2, res, count = 0, pos=7;
    n = sizeof(arr)/sizeof(int);

    printf("\nArray elements are:\n");
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);

    printf("\n");

    //q_sort(arr, 0, n-1);
    printf("\nAfter sorting: Array elements are:\n");
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);

    printf("\n");

    root = buildBST(root, arr, 0, n-1);
    printf("Tree:\n");
    print2DUtil(root, 2);

    printf("\n%dth smallest element is:\n", pos);
    res = inorder(root, &count, pos);
    printf("Result is : %d\n", res);
    printf("Max path sum of BST : %d\n", max_path_sum(root));

    return 0;
}
