#include "stdio.h"
#include "queue.h"

int main() {

    qnode HEAD = NULL;
    uint8_t ch;
    uint32_t data;
    printf("\nEnter 1 to add qnode to queue and 0 to exit:\n");
    scanf("%" SCNu8 "", &ch);
    while(ch) {
        printf("\nEnter data:\n");
        scanf("%" SCNu32 "", &data);
        HEAD = enqueue(HEAD, &data, 1);
        print_queue(HEAD);
        printf("\nEnter 1 to add qnode to queue and 0 to exit:\n");
        scanf("%" SCNu8 "", &ch);
    }
    printf("\nEnter 1 to del qnode from queue and 0 to exit:\n");
    scanf("%" SCNu8 "", &ch);
    while(ch) {
        HEAD = dequeue(HEAD);
        print_queue(HEAD);
        printf("\nEnter 1 to del qnode from queue and 0 to exit:\n");
        scanf("%" SCNu8 "", &ch);
    }
    return 0;
}
