#include "hash.h"

void
hash_decode_lnode(hlnode node, char *decode){

    if(!node){
        sprintf(decode, "NULL");
        return;
    }
    sprintf(decode, "%d:%d", *(uint32_t *)node->key, *(uint32_t *)node->data);
    return;
}

uint32_t
hash(uint8_t *key, uint32_t len, uint32_t size) {

    int i;
    uint64_t tmp = 19;
    for(i=0;i<len; i++){
        tmp += (uint64_t)key[i]+tmp;
    }
    return tmp%size;
}

hlnode
hash_get_list_node(){
    hlnode lnode = NULL;
    lnode = (hlnode)malloc(sizeof(hashListNode));
    return lnode;
}

htable
hash_create_table(uint32_t size) {

    htable table = NULL;
    htnode node = NULL;
    int i = 0, new_size;

    new_size = nearest_prime(size); 

    table = (htable) malloc(sizeof(hashTable));
    if (!table) {
        printf("\nHash Table creation failed\n");
        return NULL;
    }
    table->size = new_size;
    node = (htnode) malloc(sizeof(hashTableNode)*new_size);
    if(!node) {
        printf("\nHash Table creation failed\n");
        free(table);
        return NULL;
    }
    table->table = node;

    for(i=0;i<size;i++){
        node[i].index = i;
        node[i].count = 0;
        node[i].next = NULL;
    }

    return table;
}

hash_ret
hash_insert(htable table, uint8_t *key, uint32_t key_len, uint8_t *data, uint32_t data_len) {

    int32_t index;
    hlnode lnode = NULL, tmp = NULL;
    if (!key || !data || !table || !table->table){
        printf("\nNULL check failed during insertion\n");
        return HASH_ERROR;
    }

    index = hash(key, key_len, table->size);

    if(index < 0){
        printf("\nHashing failed\n");
        return HASH_ERROR;
    }

    lnode = hash_get_list_node();
    lnode->key = (uint8_t *)calloc(key_len, sizeof(uint8_t)); 
    lnode->data = (uint8_t *)calloc(data_len, sizeof(uint8_t));
    memcpy(lnode->key, key, key_len);
    memcpy(lnode->data, data, data_len);
   
    if(!table->table[index].next){
        table->table[index].next = lnode;
    }
    else {
        tmp = table->table[index].next;
        while(NULL != tmp->next){
            tmp = tmp->next;
        }
        tmp->next = lnode;
    }
    table->table[index].count++;

   return HASH_SUCCESS;
}

void
hash_print_table(htable table){

    htnode hnode = NULL;
    hlnode lnode = NULL;
    int i;
    char decode[100] = {0};
    if(!table){
        printf("\nTable doesn't exist\n");
        return;
    }

    hnode = table->table;
    printf("\n|");
    for(i = 0; i<table->size;i++){
       lnode = hnode[i].next;
       printf("%d|", hnode[i].count);
       while(lnode){
           hash_decode_lnode(lnode, decode);
           printf("->[%s]",decode);
           lnode = lnode->next;
       }
       printf("->NULL");
       printf("\n|");
    }
    return;
}

int main(){

    int i, key, data, n;
    htable table = NULL;
    FILE *fp = NULL;

    printf("\nEnter the hash-table size :");
    scanf("%d", &n);
    table = hash_create_table(n);
    printf("\nHash table contents are:\n");
    hash_print_table(table);

    printf("\nEnter the number of elements to be added to hash-table :");
    scanf("%d", &n);

    fp = fopen("tc.txt", "r");
    if(!fp){
        printf("\nFailed to open file:\n");
        return 0;
    }
    printf("\nEnter %d elements(key, data):\n", n);
    for(i=0;i<n;i++){
        fscanf(fp, "%d %d", &key, &data);
        hash_insert(table, (uint8_t *)&key, sizeof(key), (uint8_t *)&data, sizeof(data));
    }
    fclose(fp);

    printf("\nHash table contents are:\n");
    hash_print_table(table);
}
