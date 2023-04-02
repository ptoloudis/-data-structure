// global library
#include <stdio.h>
#include <stdlib.h>

// my library
#include "dlist.h"
#include "tree.h"
#include "stack.h"
#include "fifo.h"

int isBSTUtil(node_t* root, int prev);

node_t* insert_t2(int index, struct dlist* list,int n)
{
    dnode_t *ptr= list->head;
    int i = 0;
    if (index <n)
    {
        for (i = 0; i < index; i++){
            ptr = ptr->next;
        }        
        node_t* temp;
        temp = (node_t*)malloc(sizeof(node_t));
        temp->value = ptr->data;
        temp->left = insert_t2(((2*index)+1),list,n);
        temp->right = insert_t2(((2*index)+2),list,n);
        return temp;
    }
    return NULL;
}

int isBSTUtil(node_t* root, int prev)
{
    // traverse the tree in inorder fashion and
    // keep track of prev node
    if (root) {
        if (!isBSTUtil(root->left, prev))
            return 0;
 
        // Allows only distinct valued nodes
        if (root->value <= prev)
            return 0;
 
        // Initialize prev to current
        prev = root->value;
 
        return isBSTUtil(root->right, prev);
    }
 
    return 1;
}

int main (int argc, char* argv[]){
    char str[5];
    struct dlist* list;
    tree_t* tree;

    list = create_dlist();
    while (1){
        scanf("%s",str);
        if(str[0] == '-'){
            break;
        }
        insert(list,list->tail,atoi(str));
    }

    tree = bt_create();
    tree->root = insert_t2(0,list,list->size);
    del_list(list);
    
    if (isBSTUtil(tree->root,-1))
        printf("Binary Search Tree\n");
    else{
        printf("Binary Tree\n");
    }

    bt_destroy(tree->root);
    free(tree); 
    return 0;
}