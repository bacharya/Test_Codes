#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include <inttypes.h>

struct Queuenode {
 uint32_t data;
 void     *dataPtr;
 struct Queuenode *next;
};
typedef struct Queuenode * qnode;
qnode get_new_qnode();
void free_qnode(qnode n);
qnode enqueue(qnode head, void *data, int isInt);
qnode dequeue(qnode head);
void print_queue(qnode head);
