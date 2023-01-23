#include "tree.h"

uint32_t g_count = 0;
node
avl_single_rotate_left(node root) {
    node tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    tmp->height = max(tree_height(tmp->left), tree_height(tmp->right))+1;
    root->height = max(tree_height(root->left), root->height)+1;
    return tmp;
}

node
avl_single_rotate_right(node root) {
    node tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    tmp->height = max(tree_height(tmp->left), tree_height(tmp->right))+1;
    root->height = max(tree_height(root->left), root->height)+1;
    return tmp;
}

node
avl_double_rotate_left(node Z) {
    Z->left = avl_single_rotate_right(Z->left);
    return avl_single_rotate_left(Z);
}

node
avl_double_rotate_right(node Z) {
    Z->right = avl_single_rotate_left(Z->right);
    return avl_single_rotate_right(Z);
}

node
avl_insert(node root, node parent, int data) {
    if(!root) {
        root = get_new_node();
        if(!root){
            printf("\nMalloc Error");
        } else {
            root->data = data;
            root->height = 0;
            root->count = g_count++;
            root->left = root->right = NULL;
        }
    }
    if (data < root->data) {
        root->left = avl_insert(root->left, root, data);
        if(tree_height(root->left) - tree_height(root->right) > 1) {
            if (root->left->data > data) {
                root = avl_single_rotate_left(root);
            } else {
                root = avl_double_rotate_left(root);
            }
        }
    } else if (data > root->data) {
        root->right = avl_insert(root->right, root, data);
        if(tree_height(root->right) - tree_height(root->left) > 1) {
            if (root->right->data < data) {
                root = avl_single_rotate_right(root);
            } else {
                root = avl_double_rotate_right(root);
            }
        }
    }

    root->height = max(tree_height(root->left), tree_height(root->right))+1;
    return root;
}

node
avl_delete(node root, node parent, int data){

    node tmp=NULL;

    if(!root){
        return NULL;
    }
    if(data < root->data){
        return avl_delete(root->left, root, data);
    } else if( data > root->data) {
        return avl_delete(root->right, root, data);
    } else {
        tmp = root;
        if(tmp->left == NULL || tmp->right == NULL){
            
            if(parent->data > tmp->data) {
                parent->left = NULL;
            }

            tree_height(root->left);
            
        }
    }
}

int
avl_isAVL(node root) {

    int left = 0;
    int right = 0;
    if(!root){
        return 0;
    }
    left = avl_isAVL(root->left);
    if(left < 0) {
        return -1;
    }
    right = avl_isAVL(root->right);
    if(right < 0) {
        return -1;
    }

    if(abs(left-right) > 1)
        return -1;

    return max(left, right) +1 ;

}

int
avl_count_nodes_in_range(node root, int a, int b) {

    if(!root)
        return 0;

    if(b > root->data) {
        return avl_count_nodes_in_range(root->left, a, b);
    } else if (a < root->data) {
        return avl_count_nodes_in_range(root->right, a, b);
    } else if ( root->data >= a && root->data <= b) {
        return avl_count_nodes_in_range(root->left, a, b) + avl_count_nodes_in_range(root->right, a, b) + 1;
    }
}

node
avl_find_close_key(node root, int data) {

    node tmp;
    if(!root)
        return root;

    if(root->data == data){
        return root;
    }

    if(data < root->data) {
        if(!root->left)
            return root;
        tmp = avl_find_close_key(root->left, data);
        return abs(root->data-data) < abs(tmp->data-data)?root:tmp;
    } else {
        if(!root->right)
            return root;
        tmp = avl_find_close_key(root->right, data);
        return abs(root->data-data) < abs(tmp->data-data)?root:tmp;
    }

    return NULL;
}

int avl_max_val(node root){
    if(!root)
        return -1;
    if(!root->right)
        return root->data;
    return avl_max_val(root->right);
}

int avl_min_val(node root){
    if(!root)
        return -1;
    if(!root->left)
        return root->data;
    return avl_min_val(root->left);
}

double
avl_median(node root){
    uint32_t tmp;
    double res;

    if(!root)
        return -1;
    if(g_count %2 == 0){
        tmp = avl_min_val(root->right)+root->data;
        res = tmp/2;
    } else {
        res = (double)root->data;
    }
}
