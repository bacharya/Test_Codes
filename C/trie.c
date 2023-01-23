#include "stdio.h"
#include "stdlib.h"
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>

typedef struct node_ {
    char ch;
    struct node_ *next[26];
    bool endOfWord;
} node_t;

typedef node_t * node;

node
trie_get_node() {
    node new = (node) malloc(sizeof(node_t));
    return new;
}


void
trie_insert(node *root, char *str) {

    node tmp = NULL;
    node new = NULL;
    if(NULL == *root && NULL == tmp) {
        new = trie_get_node();
        *root = new;
    }

    tmp = *root;

    char ch;
    int i = 0;
    int idx = 0;
    int len = strlen(str);
    for (i = 0; i< len; i++) {
        ch = str[i];
        idx = 0;
        new = trie_get_node();
        new->ch = ch;

        if(i == len-1)
            new->endOfWord = true;

        /*calculate idx*/
        idx = ch-'a';
        tmp->next[idx] = new;
        tmp = new;
    }
}

int
trie_search(node root, char *str) {

    node tmp = NULL;
    if(NULL == root) {
        return 0;
    }

    tmp = root;

    char ch;
    int i = 0;
    int idx = 0;
    int len = strlen(str);
    for (i = 0; i< len; i++) {
        ch = str[i];
        idx = 0;

        /*calculate idx*/
        idx = ch-'a';
        if(NULL == tmp->next[idx]) {
            return 0;
        }
        tmp = tmp->next[idx];
    }
    return 1;
}

int main() {
    node HEAD = NULL;
    int res;
    uint8_t ch;
    char data[100], n;
    printf("\nEnter 1 to add node to tree and 0 to exit:\n");
    scanf("%" SCNu8 "", &ch);
    while(ch) {
        printf("\nEnter the string:\n");
        scanf("%s", data);
        trie_insert(&HEAD, data);
        printf("\nEnter 1 to add node to tree and 0 to exit:\n");
        scanf("%" SCNu8 "", &ch);
    }

    printf("\nEnter the string:\n");
    scanf("%s", data);
    res = trie_search(HEAD, data);

    if(res){
        printf("\nString found\n");
    } else {
        printf("\nString not found\n");
    }
    return 0;
}
