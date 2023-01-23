#include "linked_list.h"

typedef enum ll_ret_ {
    LL_SUCCESS = 0,
    LL_ERROR
} ll_ret;

ll_ret
ll_insert(node *head, uint32_t data) {

    node new_node = (node) malloc(sizeof(Node));
    new_node->data = data;
    if (*head == NULL) {
        *head = new_node;
        return LL_SUCCESS;
    }
    new_node->next = *head;
    *head = new_node;
    return LL_SUCCESS;
}


ll_ret
ll_delete(node *head, uint32_t data) {

    node tmp, prev;
    if (*head == NULL) {
        return LL_ERROR;
    }

    tmp = *head;
    if (tmp->data == data) {
        *head = tmp->next;
        free(tmp);
        return LL_SUCCESS;
    }
    while(NULL != tmp) {
        if(tmp->data == data) {
            prev->next = tmp->next;
            free(tmp);
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }

    return LL_SUCCESS;
}

void
ll_print (node head) {
    node tmp = head;

    while(tmp) {
        printf("%d->", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
    return;
}

void
ll_reverse(node *head) {

    node cur, tmp = NULL, prev = NULL;
    if (*head == NULL) {
        return;
    }
    cur = *head;
    while(NULL != cur) {
        tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    *head = prev;
}

int
main() {

    node HEAD = NULL;
    uint8_t ch;
    uint32_t data[100], n;
    printf("\nEnter 1 to add node to tree and 0 to exit:\n");
    scanf("%" SCNu8 "", &ch);
    if(ch) {
        printf("\nEnter data size:\n");
        scanf("%" SCNu32 "", &n);
        for(int i = 0; i< n; i++) {
            scanf("%" SCNu32 "", &data[i]);
            ll_insert(&HEAD, data[i]);
        }
    }
    ll_print(HEAD);
    printf("\nEnter data to be deleted:\n");
    scanf("%" SCNu32 "", &n);
    ll_delete(&HEAD, n);
    ll_print(HEAD);
    ll_reverse(&HEAD);
    ll_print(HEAD);
    return 0;
}
