#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "dlist.h"

void printlevel(node_t *root, int desired, int current){
    if (root){
        if (desired == current)
            printf("%d ", root->value);

        else if (current > desired){
            return ;
        }
        else          
        {
            printlevel(root->left, desired, current + 1);
            printlevel(root->right, desired, current + 1);
        }
    }

} 

int main (int argc, char* argv[]){
    int j,x,P;
    char str[6];
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
    
    //create a tree
    tree = bt_create();
    root = create_root(list->head->data);
    tree->root = root;
    tree->size = 1;
    stoixio = list->head->next;
    for ( j = list->size -1  ; j > 0 ; j--){
        bst_insert(root, stoixio->data);
        tree->size++;
        stoixio = stoixio->next;
    }
    del_list(list);   

    printf("Enter integer: \n");
    scanf("%d", &x);
    P = bst_find(tree->root,x);
    if(P == -1){
        printf("%d not found!\n",x);
        return 0;
    }
    printf("Integers in level %d are: ",P-1);
    printlevel(root,P-1,0);
    printf("\n");

    bt_destroy(root);
    free(tree);
    return 1;
}