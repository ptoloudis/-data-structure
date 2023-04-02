// global library
#include <stdio.h>
#include <stdlib.h>

// my library
#include "dlist.h"
#include "tree.h"
#include "stack.h"
#include "fifo.h"

dlist_t* path1( node_t* root,dlist_t* list,int x);
dlist_t* path2( node_t* root,dlist_t* list,int x);
dlist_t* find_path( node_t* root,dlist_t* list, int a, int b);

// find the all path
dlist_t* find_path( node_t* root,dlist_t* list, int a, int b){
    if (!root){
        return NULL;
    }
    if (root->value >a && root->value >b){
        return find_path(root->left,list,a,b);
    }
    if (root->value <a && root->value <b){
        return find_path(root->right,list,a,b);
    }
    if (root->value >=a && root->value <= b){
        list = path1(root,list,a);
        rmv_node(list, list->tail);
        list = path2(root,list,b);
        return list;
    }
    return list;
}

// find the path of a
dlist_t* path1( node_t* root,dlist_t* list,int x){
    if (root->value == x){
        insert(list,list->tail,root->value);
        return list;
    }
    else if (root->value > x){
        path1(root->left,list,x);
        insert(list,list->tail,root->value);
        return list;
    }
    path1(root->right,list,x);
    insert(list,list->tail,root->value);
    return list;
}

// find the path of b
dlist_t* path2( node_t* root,dlist_t* list,int x){
    if (root->value == x){
        insert(list,list->tail,root->value);
        return list;
    }
    else if (root->value > x){
        insert(list,list->tail,root->value);
        path2(root->left,list,x);
        return list;
    }
    insert(list,list->tail,root->value);
    path2(root->right,list,x);
    return list;
}

int main (int argc, char* argv[]){
    int i,j,x,y;
    char str[5], str2[5];
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

    //read two numbers
    printf("Enter 2 integers: \n");
    scanf("%s",str);
    scanf("%s",str2);
    x = atoi(str);
    y = atoi(str2);

    if ( bst_find(root, x) == NULL)
    {
        printf("%d not found!\n",x);
        return 0;
    }
    
    if ( bst_find(root, y) == NULL)
    {
        printf("%d not found!\n",y);
        return 0;
    }

    //find path
    if (x > y){
        i = x;
        x = y;
        y = i;
        j = -1;
    }
    list = create_dlist();
    list = find_path(root ,list, x, y);

    //print path if in start a>b
    printf("Path is: ");
    if(j == -1){
        stoixio = list->tail;
        for ( i = 0; i < list->size-1; i++){
            printf("%d ",stoixio->data);
            stoixio = stoixio->prev;
        }
        printf("%d\n",stoixio->data);
        del_list(list);
        bt_destroy(root);
        free(tree); 
        return 1;
    }

    //print path if in start  a<b
    stoixio = list->head;
    for ( i = 0; i < list->size-1; i++){
        printf("%d ",stoixio->data);
        stoixio = stoixio->next;
    }
    printf("%d\n",stoixio->data);
    del_list(list);   
    bt_destroy(root);
    free(tree); 
    return 1;
}