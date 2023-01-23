#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "prime.h"
#include <inttypes.h>

typedef enum hash_ret_ {
    HASH_SUCCESS = 0,
    HASH_ERROR
} hash_ret;

typedef struct hashListNode_ {
    uint8_t *key;
    uint8_t *data;
    struct hashListNode_ *next;
} hashListNode;

typedef hashListNode * hlnode;

typedef struct hashTableNode_ {
    uint8_t count;
    uint32_t index;
    hlnode next;
} hashTableNode;

typedef hashTableNode * htnode;

typedef struct hashTable_ {
    uint32_t size;
    hashTableNode *table;
} hashTable;

typedef hashTable * htable;

uint32_t
hash(uint8_t *key, uint32_t len, uint32_t size);

htable
hash_create_table(uint32_t size);

hash_ret
hash_insert(htable table, uint8_t *key, uint32_t key_len, uint8_t *data, uint32_t data_len);

hash_ret
hash_delete(htable table);

hash_ret
hash_search(htable table);

extern int nearest_prime(int n);
