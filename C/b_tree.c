#include "tree.h"
#define COUNT 10

node get_new_node();
void free_node(node n);

int
max(int a, int b) {
    return a>b?a:b;
}

node get_new_node() {
    node new_node = (node) calloc(1,sizeof(struct Node));
    return new_node;
}

void free_node(node n) {
    free(n);
    return;
}

void * find_max_bst(node root) {

    if(NULL == root)
        return NULL;
    if(NULL == root->right)
        return root;
    return find_max_bst(root->right);
}

void insert_node_bst(node root, node new_node) {
    node tmp = root;
    while(tmp) {
        if(new_node->data < tmp->data) {
            if( NULL == tmp->left) {
                tmp->left = new_node;
                return;
            }
            tmp = tmp->left;
        } else {
            if( NULL == tmp->right) {
                tmp->right = new_node;
                return;
            }
            tmp = tmp->right;
        }
    }
}

node delete_node_bst_rec(node root, int data) {

    node tmp;

    if (NULL == root) {
        printf("\nNo elements in the tree\n");
    }
    else if(data < root->data) {
        root->left = delete_node_bst_rec(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node_bst_rec(root->right, data);
    } else {
        if(root->left && root->right) {
            tmp = find_max_bst(root->left);
            root->data = tmp->data;
            //printf("++++++++++++++++++++\n");
            //print2DUtil(tmp, 2);
            //printf("++++++++++++++++++++\n");
            root->left = delete_node_bst_rec(root->left, root->data);
        } else {
            tmp = root;
            if(NULL == root->left) {
                root = root->right;
            }
            else if (NULL == root->right) {
                root = root->left;
            }
            free(tmp);
        }
    }
    return root;
}

void delete_node_bst(node root, int data) {
    node tmp = root;
    node cur = NULL;
    int tmp_data = data;
    while(tmp) {
        if(tmp_data < tmp->data) {
            tmp = tmp->left;
        } else if (tmp_data > tmp->data) {
            tmp = tmp->right;
        } else {
            if(tmp->left && tmp->right) {
                cur = find_max_bst(tmp->left);
                tmp->data = cur->data;
                tmp_data = cur->data;
                tmp = tmp->left;
            } else {
                cur = tmp;
                if(NULL == tmp->left) {
                    tmp = tmp->right;
                }
                if (NULL == tmp->right) {
                    tmp = tmp->left;
                }
                free(cur);
            }
        }
    }
}

void
insert_node_radix(node root, uint32_t data) {
    node tmp = root, new_node1, new_node2;
    uint32_t max = 0xFFFFFFFF;
    uint32_t net,host1, host2, var, mask, len, left, right;

    if(!root){
        new_node1 = get_new_node();
        new_node1->data = data;
        new_node1->left = NULL;
        new_node1->right = NULL;
        root = new_node1;
        return;
    }

    var = (tmp->data ^ data);
    len = (int)(log2(var));

    net = tmp->data & (max<<(len+1));
    host1 = (tmp->data^net);
    host2 = data^net;
    left = host1 < host2?host1:host2;
    right = host2 < host1?host2:host1;

    if(net < tmp->data) {
        if( NULL == tmp->left){
            new_node1 = get_new_node();
            new_node1->data = data;
            new_node1->left = NULL;
            new_node1->right = NULL;
            tmp->left = new_node1;
        } else {
            insert_node_radix(tmp->left, left);
            insert_node_radix(tmp->left, right);
        }
    } else if (net > tmp->data) {
        if( NULL == tmp->right){
            new_node1 = get_new_node();
            new_node1->data = data;
            new_node1->left = NULL;
            new_node1->right = NULL;
            tmp->left = new_node1;
        } else {
            insert_node_radix(tmp->right, left);
            insert_node_radix(tmp->right, right);
        }
    } else {
        return;
    }
}

void insert_node(struct Node **root, uint32_t data, tree_type type) {
    node tmp;
    if(NULL == root) {
        return;
    }
    switch(type) {
        case TREE_BST:
            tmp = get_new_node();
            tmp->data = data;
            tmp->left = NULL;
            tmp->right = NULL;

            if(NULL == *root) {
                *root = tmp;
                return;
            }
            insert_node_bst(*root, tmp);
            return;
        case TREE_AVL:
            *root = avl_insert(*root, *root, data);
            return;
        case TREE_RADIX:
            if(NULL == *root) {
                tmp = get_new_node();
                tmp->data = data;
                tmp->left = NULL;
                tmp->right = NULL;
                *root = tmp;
                return;
            }
            insert_node_radix(*root, data);
            return;
        default:
            printf("\nUnsupported tree-type\n");
    }
    return;
}

void delete_node(node root, uint32_t data, tree_type type) {

    if(NULL == root) {
        return;
    }
    switch(type) {
        case TREE_BST:
            //delete_node_bst(root, data);
            delete_node_bst_rec(root, data);
            return;
        default:
            printf("\nUnsupported tree-type\n");
    }
    return;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(node root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    // Process left child
    print2DUtil(root->left, space);
}
 

void print_tree(node root) {
    node tmp = NULL;
    print2DUtil(root, 0);
}

void inorder(node root) {
    node tmp = root;
    if (tmp) {
        inorder(tmp->left);
        printf("%d ", tmp->data);
        inorder(tmp->right);
    }
    return;
}

void levelorder(node root, node left, node right) {
    node tmp = root;

    if (tmp){
        printf(" %d", tmp->data);
    } else{
        return;
    }
    levelorder(tmp->left, left->left, right->right);
    levelorder(tmp->right, left->left, right->right);
    return;

}

uint32_t tree_height(node root) {

    if (NULL == root) {
        return 0;
    }
    if(NULL != root && NULL == root->left && NULL == root->right) {
        return 1;
    }

    return tree_height(root->left) > tree_height(root->right)? tree_height(root->left)+1: tree_height(root->right)+1;
}


bool is_valid_bst(node root){
    bool res;
    if(!root)
        return true;
    if(NULL != root->left){
        if(root->data < root->left->data)
            return false;
    }
    if(NULL != root->right){
        if(root->data > root->right->data)
            return false;
    }
    res = is_valid_bst(root->left);
    if(!res){
        return false;
    }
    res = is_valid_bst(root->right);
    if(!res){
        return false;
    }
    return true;
}

int
leaf_count(node root){
    int a,b;
    if (!root)
        return 0;
    if(!root->left && !root->right)
        return 1;

    a = leaf_count(root->left);
    b = leaf_count(root->right);
    return a+b;
}

int
max_path_sum(node root) {

    int leftSum, rightSum;
    if(!root)
        return 0;
    leftSum = max_path_sum(root->left);
    rightSum = max_path_sum(root->right);

    return max(leftSum, rightSum)+root->data;
}
