#include "tree.h"

node avl_insert(node root, node parent, int data);

int avl_isAVL(node root);

int avl_count_nodes_in_range(node root, int a, int b);

node avl_find_close_key(node root, int data);

double avl_median(node root);


