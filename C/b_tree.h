#include "tree.h"
#pragma once

struct Node {
 uint32_t data;
 struct Node *left;
 struct Node *right;
 uint32_t height;
 uint32_t count;
};
typedef struct Node * node;

typedef enum tree_type_ {
    TREE_BST = 0,
    TREE_AVL,
    TREE_BAL,
    TREE_RADIX,
    TREE_MAX
} tree_type;

node get_new_node();
void insert_node(struct Node **root, uint32_t data, tree_type type);
void delete_node(struct Node *root, uint32_t data, tree_type type);
//node delete_node(node root, uint32_t data);
void print_tree(node root);
void inorder(node root);
void levelorder(node root, node left, node right);
uint32_t tree_height(node root);
void print2DUtil(node root, int space);
int max(int a, int b);
bool is_valid_bst(node root);
int leaf_count(node root);
int max_path_sum(node root);
