#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include <inttypes.h>

typedef struct Node_ {
    uint32_t data;
    struct Node_ *next;
} Node;

typedef Node * node;

