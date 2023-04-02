#include <stdio.h>
#include <stdlib.h>
#include "htable.h"

int Insert(int *value, struct htable* node, int rehash){
    int key, startPosition;
    int tombStone = 1, tombStoPos;
    struct htable* temp;

    if ( Find(*value,node) != -1){
        return 0;
    }
    
    if (rehash == 1){
        temp = rehash_fuc(node);
        if (temp != NULL){
            node = temp;
        }
    }

    key = *value % node->max;
    tombStoPos = key;
    startPosition = node->max;

    do{
      if (*node->hash[key] == 0x1 ){
        tombStoPos = key;
        tombStone = 0;
      }
      if (node->hash[key] == NULL){
        if (tombStone)
            node->hash[key] = value;

        else{
            node->hash[tombStoPos] = value;
            node->delete--;
        }
        node->size++;
        return 1;
      }
      key = (key + 1) % node->max;
    } while (key != startPosition);
    
    return -1;
}

int Find(int value, struct htable* node){
    int i ,start;

    i = start = value % node->max;
    do{
        if(node->hash[i] == NULL)
            return -1;
    
        if(*node->hash[i] != 0x1 && *node->hash[i] == value)
            return i;
        else
            i = (i + 1)% node->max; 
    } while (i != start);
    return -1;
}

int Delete(int value, struct htable* node, int rehash){
    int i;
    struct htable* temp;

    i = Find( value, node);
    if (i == -1){
        return 0;
    }

    *node->hash[i] = 0x1;
    node->size--;
    node->delete++;

    if (rehash == 1){
        temp = rehash_fuc(node);
        if (temp != NULL){
            node = temp;
        }
    }

    return 1;
}

void Print(struct htable* node){
    int i=0 , *print;

    printf("SIZE: %d, INSERTED: %d, DELETED: %d\n", node->max, node->size, node->delete);
    // print thesi
    for (i = 0; i < node->max -1; i++){
        printf("3.%d ",i);
    }
    printf("3.%d\n", i);

    // print value
    for (i = 0; i < node->max -1; i++){
        if (node->hash[i] == NULL){
            printf("  * ");
        }
        else if (*node->hash[i] == 0x1){
            printf("  # ");
        }
        else{
            print = node->hash[i];
            printf("3.%d ", *print);
        }
    }
    if (node->hash[node->max -1] == NULL){
        printf("  * ");
    }
    else if (*node->hash[node->max -1] == 0x1){
        printf("  # ");
    }
    else{
        print = node->hash[node->max -1];
        printf("3.%d ", *print);
    }

}

struct htable* rehash_fuc(struct htable* node){
    int i, *table;
    double loadFactor;
    struct htable *temp;

    loadFactor = (1.0 * node->size) / node->max;

    if (loadFactor < 0.5 && loadFactor > 0.125){
        return node;
    }

    if (loadFactor >= 0.5){
        table = (int *) malloc( (node->max *2)*sizeof( int* ));
        if (table == NULL){
            return node;
        }
        *temp->hash = table;
        temp->delete=0;
        temp->max = node->max *2;
        temp->size=0;
        
        for (i = 0; i < temp->max; i++){
            temp->hash[i] = NULL;
        }
        for (i = 0; i < node->max ; i++){
            Insert( node->hash[i] , temp, 0);
        }
    }

    if (loadFactor <= 0.125 ) {
        if (node->max == 2){
            return node;
        }

        table = (int*)malloc((node->max / 2) * sizeof(int*));
        if (table == NULL) {
            return node;
        }
        *temp->hash = table;
        temp->delete=0;
        temp->max = node->max /2;
        temp->size=0;
        
        for (i = 0; i < temp->max; i++){
            temp->hash[i] = NULL;
        }
        for (i = 0; i < node->max ; i++){
            Insert( node->hash[i] , temp, 0);
        }
    }
     
    free(node);     
    return temp;
}
