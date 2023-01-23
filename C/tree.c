#include "tree.h"

int main() {

    node HEAD = NULL, element = NULL;
    uint8_t ch;
    uint8_t tree_type = TREE_BST;
    uint32_t data[100], n, retVal;
    uint32_t a, b, diff;
    printf("\nEnter tree type: \n");
    printf(" BST: 0\n");
    printf(" AVL: 1\n");
    printf(" BAL: 2\n");
    printf(" RADIX: 3\n");
    scanf("%" SCNu8 "", &tree_type);
    if(tree_type >= TREE_MAX ){
        printf("\n Wrong tree type");
        return 0;
    }
    printf("\nEnter 1 to add node to tree and 0 to exit:\n");
    scanf("%" SCNu8 "", &ch);
    while(ch) {
        printf("\nEnter data size:\n");
        scanf("%" SCNu32 "", &n);
        for(int i = 0; i< n; i++) {
            scanf("%" SCNu32 "", &data[i]);
            insert_node(&HEAD, data[i], tree_type);
        }
        printf("\nEnter 1 to add node to tree and 0 to exit:\n");
        scanf("%" SCNu8 "", &ch);
    }
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    print_tree(HEAD);
    printf("\nTree inorder traversal:\n");
    inorder(HEAD);
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\nTree height: %d\n", tree_height(HEAD));
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\nEnter 1 to delete node to tree and 0 to exit:\n");
    scanf("%" SCNu8 "", &ch);
    while(ch) {
        printf("\nEnter data:\n");
        scanf("%" SCNu32 "", &n);
        delete_node(HEAD, n, TREE_BST);
        printf("\nEnter 1 to delete node to tree and 0 to exit:\n");
        scanf("%" SCNu8 "", &ch);
    }
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    print_tree(HEAD);
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    if(tree_type == TREE_AVL) {
        printf("\nEnter 1 to check is AVL tree 0 to exit:\n");
        scanf("%" SCNu8 "", &ch);
        if (ch) {
            retVal = avl_isAVL(HEAD);
            if(retVal > 0) {
                printf("\nEntered Tree is AVL");
             } else {
                printf("\nEntered Tree is NOT AVL");
             }
        }
        printf("\nEnter 1 to check is number of nodes in range 0 to exit:\n");
        scanf("%" SCNu8 "", &ch);
        if (ch) {
            printf("\nEnter a and b:\n");
            scanf("%" SCNu32 "%" SCNu32 "", &a, &b);
            retVal = avl_count_nodes_in_range(HEAD, a, b);
            if(retVal > 0) {
                printf("\nNumber of nodes in range is :%d", retVal);
             } else {
                printf("\nNo nodes found within the range");
             }
        }
        printf("\nEnter 1 to check is closest node to find; 0 to exit:\n");
        scanf("%" SCNu8 "", &ch);
        if (ch) {
            printf("\nEnter a :\n");
            scanf("%" SCNu32 "", &a);
            element = avl_find_close_key(HEAD, a);
            if(!element) {
                printf("\nClosest node is :%d", element->data);
             } else {
                printf("\nNo nodes found within the range");
             }
        }
        printf("\nMedian value in the AVL tree:");
        printf(":%lf\n", avl_median(HEAD));

    }
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    if(is_valid_bst(HEAD)) {
        printf("\nEntered Tree is a BST\n");
    } else{
        printf("\nEntered Tree is not a BST\n");
    }
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\nTree inorder traversal:\n");
    inorder(HEAD);
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\nLeaf count: %d\n", leaf_count(HEAD));
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\nTree height: %d\n", tree_height(HEAD));
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    //printf("\nTree levelorder traversal:\n");
    //levelorder(HEAD, HEAD->left, HEAD->right);
    //printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\nTree height: %d\n", tree_height(HEAD));
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\nTree Max path sum: %d\n", max_path_sum(HEAD));
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    return 0;
    
}
