#include "stdio.h"
#include "time.h"
#include "stdint.h"
#include "stdlib.h"
#include <inttypes.h>
#include "assert.h"
#include "string.h"
#include "unistd.h"

#define TIMER_QSIZE 10

struct ListNode {
    uint32_t interval;
    uint32_t count;
    time_t exp;
    uint32_t (*timer_cb)(time_t exp, uint32_t time);
    struct ListNode *next;
};

typedef struct ListNode * lnode;

struct Queuenode {
 uint32_t idx;
 uint32_t count;
 lnode node;
 struct Queuenode *next;
};
typedef struct Queuenode * qnode;
qnode get_new_qnode();
void free_qnode(qnode n);

qnode timer_init();

qnode timer_node_insert(qnode head);
