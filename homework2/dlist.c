// global library
#include <stdio.h>
#include <stdlib.h>

// my library
#include "dlist.h"


dlist_t* create_dlist() {
    dlist_t* list = (dlist_t*) malloc(sizeof(dlist_t));
    if(!list)
        exit(-1);
    list->head = list->tail = NULL;
    list->size = 0;
    return list;
}

int insert(dlist_t* list, dnode_t* before,int data) {  // oxi allagi head
    dnode_t* new_node;
    new_node = (dnode_t*)malloc(sizeof(dnode_t)); // desmesi thesi
    if( !new_node ){
        exit(-1);
    }
    if (list->head == NULL){
        list->head = new_node;
        list->tail =new_node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
        list->size++;
        return 1;
    }
    
    // input in list 
    new_node->data = data;
    new_node->prev = before;
    new_node->next = before->next;
    
    if(before->next == NULL){//if the next in list is null
        list->tail = new_node;   
    }
    else{//set the next in list 
        before->next->prev = new_node;    
    }
    before->next = new_node;
    list->size++;

    return 1;
}

int rmv_node(dlist_t* list, dnode_t* node) {
    int data = node->data;
    
    if(node==list->head) {
        list->head = node->next;
        node->next->prev = node->prev;
    }
    else if(node==list->tail) {
        list->tail = node->prev;
        node->prev->next = node->next;
    }
    else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    free(node);
    list->size--;
    return data;
}

void del_node(dlist_t* list){
    dnode_t* data = list->head;
    dnode_t* del;

    while (data->next != NULL)
    {   
        del = data;
        data = data->next;
        free (del);
    }

    free (data);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void del_list(dlist_t* list){
    del_node(list);
    free(list);
}

void print_list(dlist_t* list){
    dnode_t *p;
    int i;

    p = list->head;
    for ( i = 0; i < list->size; i++){
        printf("%d",p->data);
        p = p->next;
    }
}