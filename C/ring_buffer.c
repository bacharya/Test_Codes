#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "inttypes.h"
#include "stdbool.h"
#include "pthread.h"
#include "unistd.h"

#define BUF_SIZE               100
#define BUF_BEGIN(buffer)      (uint64_t)buffer->buff
#define BUF_END(buffer)        (uint64_t)buffer->buff+buffer->size


static uint32_t r_count=0;
static uint32_t w_count=0;
static uint32_t rw_count=0;

typedef struct r_buf_ {
    uint8_t *buff;
    uint64_t w_head;
    uint64_t r_head;
    uint32_t size;
    bool is_recycle;
    struct r_buf_ *next;
} r_buf_t;

static int32_t mtx = 1;

void
mutex_lock() {
    while(mtx == 0);
    mtx -=1;
}

void
mutex_unlock() {
    mtx +=1;
}

int32_t
rbuf_init(r_buf_t *buffer, uint32_t size) {
    buffer->buff = (uint8_t *)calloc(size, sizeof(uint8_t));
    buffer->w_head = BUF_BEGIN(buffer);
    buffer->r_head = BUF_END(buffer);
    buffer->size = size;
    buffer->is_recycle = false;
    return 0;
}

int32_t 
rbuf_write(r_buf_t *buffer, uint8_t *data, uint32_t len){


    uint32_t free = 0;
    rw_count++;

    if(!(buffer->is_recycle) && (buffer->w_head < buffer->r_head)) {
        printf("Write failed\n");
        return -1;
    }

    free = (BUF_END(buffer)-buffer->w_head)+(buffer->r_head-BUF_BEGIN(buffer)-1);
    if (len > free){
        printf("data size is higher\n");
        return -1;
    }
    /* Splitting data and buffer to write*/
    if (!(buffer->is_recycle) && (len > (BUF_END(buffer)-buffer->w_head))) {
        memcpy((uint8_t *)buffer->w_head, data, (BUF_END(buffer)-buffer->w_head));
        len -= ((uint32_t)(BUF_END(buffer)-buffer->w_head));
        data = data+(BUF_END(buffer)-buffer->w_head);
        buffer->w_head = BUF_BEGIN(buffer);
        buffer->is_recycle = true;
    }

    memcpy((uint8_t *)buffer->w_head, data, len);
    buffer->w_head +=len;

    /*reset re-cycle flag*/
    if(buffer->is_recycle && (buffer->w_head > buffer->r_head)){
        buffer->is_recycle = false;
    }
    w_count++;
    return len;
}

int32_t 
rbuf_read(r_buf_t *buffer, uint32_t len, uint8_t *data){

    uint32_t used = 0;
    rw_count++;

    /*Check to see reading more data than the written buffer-data*/
    if (!(buffer->is_recycle) && (len > (buffer->w_head-buffer->r_head))){
        printf("data read is higher\n");
        return -1;
    }
    /*Check to see reading more data than the written buffer-data*/
    used = (BUF_END(buffer)-buffer->r_head) + (buffer->w_head-BUF_BEGIN(buffer));
    if((buffer->is_recycle) && (len > used)) {
        printf("data read is higher\n");
        return -2;
    }
    /* Splitting data and buffer to read*/
    if ((buffer->is_recycle) && (len > (BUF_END(buffer)-buffer->r_head))) {
        memcpy(data, (uint8_t *)buffer->r_head, (BUF_END(buffer)-buffer->r_head));
        len -= ((uint32_t)(BUF_END(buffer)-buffer->r_head));
        data = data+(BUF_END(buffer)-buffer->r_head);
        buffer->r_head = BUF_BEGIN(buffer);
    }
    memcpy(data, (uint8_t *)buffer->r_head, len);
    buffer->r_head +=len;

    r_count++;
    return len;
}

void *
rbuf_write_thread(void *buf) {
    
    r_buf_t *buffer = (r_buf_t *)buf;
    uint32_t n, w_size;
    char *test_data = "Writing test data in w-thread";
    w_size = strlen(test_data);

    mutex_lock();
    n = rbuf_write(buffer, (uint8_t *)test_data, w_size);
    mutex_unlock();
    printf("WRITE_T: Written  data size: %d\n", n);
    printf("WRITE_T: Write-counter: %d\n", w_count);
    printf("WRITE_T: rw-counter: %d\n", rw_count);
    printf("WRITE_T: Write-head: %lu \n", buffer->w_head);
    return NULL;

}
void *
rbuf_read_thread(void *buf) {
    
    r_buf_t *buffer = (r_buf_t *)buf;
    uint8_t data[1024] = {0};
    uint32_t n, r_size=29;

    mutex_lock();
    n = rbuf_read(buffer, r_size, data);
    mutex_unlock();
    printf("\nREAD_T: Read data size: %d and data :%s\n", n, data);
    printf("READ_T: Read-counter: %d \n", r_count);
    printf("READ_T: rw-counter: %d\n", rw_count);
    printf("READ_T: Read-head: %lu \n", buffer->r_head);
    return NULL;
}

int
main() {

    pthread_t w_thread_id, r_thread_id;
    r_buf_t buffer = {0};
    uint32_t ch;
    rbuf_init(&buffer, BUF_SIZE);
    do {
#if 0
        printf("\nEnter 1 if you want to write data again:\n");
        scanf("%d", &ch);
#endif
        pthread_create(&w_thread_id, NULL, rbuf_write_thread, (void *)&buffer);
        pthread_create(&r_thread_id, NULL, rbuf_read_thread, (void *)&buffer);
        pthread_join(w_thread_id, NULL);
        pthread_join(r_thread_id, NULL);
        ch = 1;
        sleep(1);
    } while(ch);
    return 0;
}
