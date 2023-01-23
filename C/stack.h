#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include <inttypes.h>

typedef enum stack_ret_ {
    STACK_SUCCESS = 0,
    STACK_ERROR
} stack_ret;

typedef struct Node_ {
    uint8_t *data;
    struct Node_ *next;
} Node;

typedef Node * node;

stack_ret
stack_push(node *head, uint8_t *data, uint32_t len);

stack_ret
stack_pop(node *head);
