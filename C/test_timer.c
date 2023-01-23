#include "test_timer.h"

static uint32_t q_index = 0;

uint32_t
timer_callback(time_t exp, uint32_t interval) {

    time_t cur_time;
    cur_time = time(NULL);
    if(cur_time < exp){
        return 0;
    }
    printf(" %d",interval);
    //printf("Start Time : %ld\n", mytime1);
    //sleep(interval);
    printf("Job id:%d, End Time : %ld\n", interval, cur_time);
    //printf("+++++++++++++++++++\n");
    return interval;
}

lnode
get_new_lnode(uint32_t interval, uint32_t (*timer_cb)(time_t exp, uint32_t time)){
    time_t expiry_time;
    uint32_t interval_count = 0;

    interval_count = interval/TIMER_QSIZE;
    expiry_time = time(NULL)+interval;
    lnode new_lnode = (lnode) calloc(1, sizeof(struct ListNode));
    if(!new_lnode){
        assert(0);
    }
    new_lnode->interval = interval;
    new_lnode->count = interval_count;
    new_lnode->exp = expiry_time;
    new_lnode->timer_cb = timer_cb;
    new_lnode->next = NULL;
}

qnode
get_new_qnode() {
    qnode new_qnode = (qnode) calloc(1,sizeof(struct Queuenode));
    return new_qnode;
}

void
free_lnode(lnode head) {
    lnode tmp = head, cur=NULL;
    while(tmp){
    cur = tmp;
    tmp = tmp->next;
    free(cur);
    }
    return;
}

void
free_qnode(qnode n) {
    free_lnode(n->node);
    free(n);
    return;
}


qnode
timer_init() {

    qnode HEAD = NULL;;
    uint32_t i;

    printf("\nInitializing timer\n");
    for(i = 0;i<TIMER_QSIZE;i++){
        HEAD = timer_node_insert(HEAD);
    }
    return HEAD;
}

qnode
timer_node_insert(qnode head) {

    qnode tmp = NULL;
    qnode new_node = NULL;
    if(!head){
        return get_new_qnode();
    }

    new_node = get_new_qnode();
    if(!new_node)
        assert(0);

    tmp = head;
    while(tmp && tmp->idx < q_index){
        tmp = tmp->next;
    }
    if(!tmp)
        assert(0);

    new_node->next = tmp->next;
    tmp->next = new_node;
    q_index++;
    new_node->idx = q_index;
    return head;
}

void
timer_insert_job (qnode head, uint32_t interval) {

    qnode tmp = NULL;
    lnode new_lnode = NULL, cur_lnode = NULL, prev_lnode = NULL;
    uint32_t count = 0;
    uint32_t index = 0;
    uint8_t  flag = 0;

    if(!head)
        assert(0);

    index = interval%TIMER_QSIZE;

    tmp = head;
    while(tmp){
        if(tmp->idx == index)
            break;
        if(count > q_index)
            assert(0);
        count++;
        tmp = tmp->next;
    }

    new_lnode = get_new_lnode(interval, timer_callback);
    if(!tmp->node){
        tmp->node = new_lnode;
        return;
    }
    cur_lnode = tmp->node;
    prev_lnode = tmp->node;
    while(cur_lnode->next){
        if(cur_lnode->count > new_lnode->count){
            prev_lnode->next = new_lnode;
            new_lnode->next = cur_lnode;
            flag = 1;
            break;
        }
        cur_lnode = cur_lnode->next;
    }
    if(!flag){
        cur_lnode->next = new_lnode;
    }

    return;
}

void
timer_print_job(lnode head){

    lnode tmp_lnode = head;
    if(!tmp_lnode){
        printf("->NULL\n");
        return;
    }
    while(tmp_lnode){
        printf("->%d", tmp_lnode->interval);
        tmp_lnode->timer_cb(tmp_lnode->exp, tmp_lnode->interval);
        tmp_lnode = tmp_lnode->next;
    }
    printf("->NULL\n");
    return;
}

void
timer_print_timer(qnode head){
    qnode tmp_qnode = head;
    uint32_t count = 0;
    time_t mytime1, mytime2;

    if(!tmp_qnode){
        printf("\nEmpty timer wheel\n");
        return;
    }
    while(tmp_qnode && count <= q_index){
       mytime1 = time(NULL);
        printf("Start Time : %ld\n", mytime1);
        printf("|%d|", tmp_qnode->idx);
        timer_print_job(tmp_qnode->node);
        mytime2 = time(NULL);
        printf("End Time : %ld\n", mytime2);
        printf("+++++++++++++++++++\n");
        tmp_qnode = tmp_qnode->next;
        count++;
    }
}

int
main() {

    qnode HEAD = NULL;;
    uint8_t ch;
    uint32_t interval;

    printf("\nInitializing timer\n");
    HEAD = timer_init();

    printf("\nEnter 1 to add job to queue and 0 to exit:\n");
    scanf("%" SCNu8 "", &ch);
    while(ch) {
        printf("\nEnter interval:\n");
        scanf("%" SCNu32 "", &interval);

        timer_insert_job(HEAD, interval);
        printf("\nEnter 1 to add qnode to queue and 0 to exit:\n");
        scanf("%" SCNu8 "", &ch);
    }
#if 0
    printf("\nEnter 1 to del qnode from queue and 0 to exit:\n");
    scanf("%" SCNu8 "", &ch);
    while(ch) {
        HEAD = dequeue(HEAD);
        print_queue(HEAD);
        printf("\nEnter 1 to del qnode from queue and 0 to exit:\n");
        scanf("%" SCNu8 "", &ch);
    }
#endif

    printf("\nCurrent status of the timer is:\n");
    timer_print_timer(HEAD);
    return 0;
}
