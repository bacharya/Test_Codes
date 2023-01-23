#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

typedef enum fsm_state_ {
    STATE_A = 0,
    STATE_B,
    STATE_C
} fsm_state;

typedef struct simple_fsm_
{
    /* data */
    void (*cur_state)();
    fsm_state state;
    //void (*next_state)(int);

} simple_fsm;

static int value = 0;

void
fsm_state_a() {
    printf("\nIn function fsm_state_A\n");
    value = value+2;
    sleep(1);
    printf("Value is %d\n", value);
}

void
fsm_state_b() {
    printf("\nIn function fsm_state_B\n");
    value = value+3;
    sleep(2);
    printf("Value is %d\n", value);
}

void
fsm_state_c() {
    printf("\nIn function fsm_state_C\n");
    value = value+1;
    sleep(3);
    printf("Value is %d\n", value);    
}

simple_fsm fsm[3] = {
        { &fsm_state_a },
        { &fsm_state_b },
        { &fsm_state_c }
};

int main() {
    printf("\nFSM started:\n");
    while (1)
    {
        /* code */
        if(value % 3 == 0) {
            (fsm[2].cur_state)();
        } else if (value % 2 == 0)
        {
            /* code */
            (fsm[1].cur_state)();
        } else {
            (fsm[0].cur_state)();
        }
        if (value > 10) {
            break;
        }
    }
    printf("\nFSM ended:\n");
    return 0;
}


