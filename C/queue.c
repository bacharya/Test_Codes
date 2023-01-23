#include "queue.h"


qnode
get_new_qnode() {
    qnode new_qnode = (qnode) calloc(1,sizeof(struct Queuenode));
    return new_qnode;
}

void
free_qnode(qnode n) {
    free(n);
    return;
}

qnode
enqueue(qnode head, void *data, int isInt) {

    int val = 0;

    qnode tmp = NULL;
    if (head == NULL) {
        head = get_new_qnode();
        if (isInt) {
            head->data = *(uint32_t *)data;
        } else {
            head->dataPtr = data;
        }
        return head;
    }

    tmp = get_new_qnode();
    if (isInt) {
        tmp->data = *(uint32_t *)data;
    } else {
        tmp->dataPtr = data;
    }
    tmp->next = head;
    head = tmp;
    return head;
}

qnode
dequeue(qnode head) {
    qnode tmp = NULL,
         prev = NULL;
    if (head == NULL) {
        return head;
    }

    tmp = head;
    prev = head;
    while(NULL != tmp->next) {
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = NULL;
    free_qnode(tmp);
    if(head == tmp) {
        return NULL;
    }
    return head;
}

void
print_queue(qnode head) {

    qnode tmp = NULL;
    if(NULL == head)
        printf("\nEmpty queue\n");

    tmp = head;
    while(NULL != tmp) {
        printf("%d->",tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

#if 0
int main() {

    qnode HEAD = NULL;
    uint8_t ch;
    uint32_t data;
    printf("\nEnter 1 to add qnode to queue and 0 to exit:\n");
    scanf("%" SCNu8 "", &ch);
    while(ch) {
        printf("\nEnter data:\n");
        scanf("%" SCNu32 "", &data);
        HEAD = enqueue(HEAD, data);
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
#endif
