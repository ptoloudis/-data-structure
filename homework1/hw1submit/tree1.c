// global library
#include <stdio.h>
#include <stdlib.h>

// my library
#include "dlist.h"
#include "tree.h"
#include "stack.h"
#include "fifo.h"

void printGivenLevel(node_t* root, int level);
int height(node_t* node);

void printLevelOrder(node_t* root){ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i); 
} 

void printGivenLevel(node_t* root, int level){ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->value); 
    else if (level > 1){ 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
} 

int height(node_t* node){ 
    int lheight, rheight;

    if (node==NULL) 
        return 0; 
    else
    { 
        /* compute the height of each subtree */
        lheight = height(node->left); 
        rheight = height(node->right); 
  
        /* use the larger one */
        if (lheight > rheight) 
            return(lheight+1); 
        else return(rheight+1); 
    } 
} 


int main (int argc, char* argv[]){
    int i;
    char str[5];
    struct dlist* list;
    tree_t* tree;
    node_t* root;
    dnode_t* stoixio;

    list = create_dlist();
    while (1){
        scanf("%s",str);
        if(str[0] == '-'){
            break;
        }
        insert(list,list->tail,atoi(str));
    }
    
    tree = bt_create();
    root = create_root(list->tail->data);
    tree->root = root;
    tree->size = 1;
    stoixio = list->tail->prev;

    for ( i = list->size -1  ; i > 0 ; i--){
        bst_insert(root, stoixio->data);
        tree->size++;
        stoixio = stoixio->prev;
    }
    del_list(list);
    printLevelOrder(root);
    printf("\n");
    bt_destroy(root);
    free(tree);    

    return 0;
}