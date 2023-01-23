#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stack.h"
#include <inttypes.h>

stack_ret
stack_push(node *head, uint8_t *data, uint32_t len) {

    node new_node = (node) malloc(sizeof(Node));
    new_node->data = (uint8_t *)malloc(len*sizeof(uint8_t));
    if(!new_node->data){
        free(new_node);
        return STACK_ERROR;
    }
    memcpy(new_node->data, data, len);
    if (*head == NULL) {
        *head = new_node;
        return STACK_SUCCESS;
    }
    new_node->next = *head;
    *head = new_node;
    return STACK_SUCCESS;
}


stack_ret
stack_pop(node *head) {

    node tmp;
    if (*head == NULL) {
        return STACK_SUCCESS;
    }
    tmp = *head;
    *head = tmp->next;
    free(tmp);

    return STACK_SUCCESS;
}

void
stack_print (node head) {
    node tmp = head;

    while(tmp) {
        printf("%f->", *(float *)tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
    return;
}

int
main() {

    node HEAD = NULL;
    uint8_t ch;
    float data[100];
    uint32_t n;
    printf("\nEnter 1 to add node to tree and 0 to exit:\n");
    scanf("%" SCNu8 "", &ch);
    if(ch) {
        printf("\nEnter data size:\n");
        scanf("%" SCNu32 "", &n);
        for(int i = 0; i< n; i++) {
            //scanf("%" SCNu32 "", &data[i]);
            scanf("%f", &data[i]);
            stack_push(&HEAD, (uint8_t *)&data[i], sizeof(data[i]));
        }
    }
    stack_print(HEAD);
    stack_pop(&HEAD);
    stack_print(HEAD);
    return 0;
}
