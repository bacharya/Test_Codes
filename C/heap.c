#include "stdio.h"
#include "stdlib.h"

#define MAX_HEAP 0
#define MIN_HEAP 1

#define COUNT    2

typedef struct heap_ {
    int *arr;
    int count;
    int capacity;
    int type;
} heap;


heap* create_heap(int capacity, int type) {

    heap *h = (heap *) malloc(sizeof(heap));

    h->capacity = capacity;
    h->count = 0;
    h->type = type;
    h->arr = (int *) malloc(capacity*sizeof(int));

    return h;
}

int parent(heap *h, int i) {

    if ((i<0) || i>= h->count){
        return -1;
    }

    return (i-1)/2;
}

int left_child(heap *h, int i) {

    int l = 2*i+1;
    if ((i<0) || i>= h->count){
        return -1;
    }
    if(l >= h->count) {
     return -1;
    }

    return l;
}

int right_child(heap *h, int i) {

    int r = 2*i+2;
    if ((i<0) || i>= h->count){
        return -1;
    }
    if(r >= h->count) {
     return -1;
    }

    return r;
}

int get_max(heap *h) {

    if(0 <= h->count) {
        return -1;
    }

    return h->arr[0];

}

void heapify(heap *h, int i) {

    int max, tmp;
    int l = left_child(h, i);
    int r = right_child(h, i);

    if( l < 0 && r < 0)
        return;

    max = i;

    if( l >= 0 && h->arr[i] < h->arr[l])
        max = l;
    if (r >= 0 && h->arr[r] > h->arr[max])
        max = r;

    if (i != max) {
        tmp = h->arr[i];
        h->arr[i] = h->arr[max];
        h->arr[max] = tmp;
    } else {
        return;
    }

    heapify(h, max);
}

void
insert(heap *h, int data) {

    int i, tmp;

    if(h->capacity == h->count) {
        printf("\nHeap full\n");
        return;
    }

    h->count++;
    i = h->count-1;

    while(i > 0 && data > h->arr[(i-1)/2]) {
        tmp = h->arr[(i-1)/2];
        h->arr[(i-1)/2] = h->arr[i];
        h->arr[i] = tmp;
        i = (i-1)/2;
    }

    h->arr[i] = data;

}

void
delete(heap *h) {

    int data;
    if(h->count <= 0) {
        printf("\nEmpty heap\n");
        return;
    }

    data = h->arr[0];

    h->arr[0] = h->arr[h->count-1];
    h->arr[h->count-1] = 0;
    h->count--;
    heapify(h, 0);
}

void print(heap *h) {

    int i;

    if(h->count <= 0) {
        printf("\nEmpty heap\n");
        return;
    }

    for(i= 0; i< h->count; i++) {
        printf(" %d", h->arr[i]);
    }
    printf("\n");

    return;
}

// It does reverse inorder traversal
void print2DUtil(heap *h, int idx, int space)
{
    int right, left;
    // Base case
    if (idx >= h->count)
        return;

    // Increase distance between levels
    space += COUNT;
    
    right = right_child(h, idx);
    if (right < 0)
        return;

    // Process right child first
    print2DUtil(h, right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", h->arr[idx]);

    left = left_child(h, idx);
    if (left < 0)
        return;
    // Process left child
    print2DUtil(h, left, space);
}


void print_heap(heap *h) {
    print2DUtil(h, 0, 0);
}

int
delete_index(heap *h, int idx) {
    int key;
    if(idx > h->count && idx < 0){
        printf("\nIncorrect index\n");
        return -1;
    }
    key = h->arr[idx];
    h->arr[idx] = h->arr[h->count-1];
    h->count--;
    heapify(h, idx);
    return key;
}

void
print_val_greater(heap *h, int idx, int data){

    int left, right;
    if(idx >= h->count){
        return;
    }

    if (h->arr[idx] < data){
        return;
    }
    printf(" %d", h->arr[idx]);
    left = left_child(h, idx);
    if (left >= 0)
        print_val_greater(h, left, data);
    right = right_child(h, idx);
    if (right >= 0)
        print_val_greater(h, right, data);

}


int main() {

    int a[100];
    int i, idx, data;
    int n;
    printf("\nEnter the size of the HEAP:");
    scanf("%d",&n);
    printf("\nEnter %d elements:\n", n);
    for(i =0;i< n; i++)
        scanf("%d", &a[i]);
    printf("\nCreated heap for the same is:\n");

    heap *h = create_heap(n, MAX_HEAP);

    for(i=0; i<n;i++) {
        insert(h, a[i]);
    }

    print(h);
    printf("\n++++++++++++++++++++++++++++++++++++++++\n");
    print_heap(h);
    printf("\n++++++++++++++++++++++++++++++++++++++++\n");
    printf("\nDelete Max\n");
    delete(h);
    print(h);
    printf("\nEnter the index of the element to be deleted:");
    scanf("%d",&idx);
    printf("\nDeleted element at index: %d\n", delete_index(h, idx));
    print(h);
    printf("\nEnter the value for which the greater elements should be searched for:");
    scanf("%d",&data);
    print_val_greater(h, 0, data);

}
