// global library
#include <stdio.h>
#include  <stdlib.h>

// my library
#include "fifo.h"

struct fifo* create_fifo(){
    Fifo *new;
    new = (Fifo*)malloc(sizeof(Fifo));
    new->rear = NULL;
    new->size = 0;
    return new;
}

void enqueue(Fifo *list, int NUM){
    Queue *new;

    new = (Queue*)malloc(sizeof(Queue));
    new->num = NUM;
    new->next = list->rear; 
    list->rear = new;
    list->size = list->size + 1;
}

int dequeue(Fifo *list){
    int i = 0;
    Queue *del;
    Queue *data = list->rear;

    for ( i = 0; i < list->size - 1; i++)
    {
        data = data->next;
    }

    del = data->next;
    i = del->num;
    data->next = NULL;
    free(del);
    list->size = list->size - 1;
    return i;
}

void  del_fifo(Fifo *list){
    int i = 0;
    Queue *del;
    Queue *data = list->rear;
    
    for ( i = 0; i < list->size; i++)
    {   
        del = data;
        data = data->next;
        free(del);
    }
    
    free(data);
    free(list);
}