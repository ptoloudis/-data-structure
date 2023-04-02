/*#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "dlist.h"

tree_t* Insert(list,tree){
    int mn;
    
}
void printPreorder(node_t* node) 
{ 
     if (node == NULL) 
          return; 
  
     // first print data of node 
     printf("%d ", node->value);   
  
     // then recur on left sutree 
     printPreorder(node->left);   
  
     // now recur on right subtree 
     printPreorder(node->right); 
}     

int main (int argc, char* argv[]){
    int j,x,P;
    char str[6];
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
    tree = Insert(list,tree);

    printPreorder(tree);
    printf("\n");
}*/