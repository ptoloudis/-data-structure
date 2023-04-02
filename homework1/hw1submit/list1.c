// global library
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// my library
#include "dlist.h"

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

void maxLen(dlist_t*  list, int *start, int *size) 
{ 
    // Initialize result 
    int i, j, curr_sum; 
    dnode_t* stoixio = list->head;
    dnode_t* prt = list->head;

    // Pick a starting point 
    for (i = 0 ; i < list->size; stoixio = stoixio->next, i++) { 
  
        // Initialize currr_sum for every starting point 
        curr_sum = 0; 

        // try all subarrays starting with 'i' 
        for (j = i, prt = stoixio; j < list->size; prt = prt->next , j++) { 
            curr_sum +=  prt->data ; 
  
            // If curr_sum becomes 0, then update max_len if required 
            if (curr_sum == 0){ 
                if (*size < max( *size, j - i + 1)){
                    *size = max( *size , j - i + 1);
                    *start = i + 1;
                } 
            }
        } 
    } 
} 

int main (int argc, char* argv[]){
    int i,start,size,j;
    char str[5];
    struct dlist*  list;
    dnode_t* print;

    list = create_dlist();
    while (1){
        scanf("%s",str);
        if(str[0] == '0'){
            break;
        }
        insert(list,list->tail,atoi(str));
    }
    

    start=-1;
    size=-1;

    maxLen(list, &start, &size);
    if (size == -1){
        printf("NO sub-sequences sum = 0 \n");
        return 0;
    }    

    printf("start: %d, stop: %d, size: %d\n", start - 1, start + size -2 , size);
    
    print = list->head; 
    for ( i = 0; i < start -1; i++){   
        print = print->next;
    }
    for ( i = 0; i < size; i++){
        printf("%d",print->data);
        if (i < size -1){
            printf(" ");
            print = print->next;
            continue;
        }
        printf(" \n");
    }    
    del_list(list);
    return 1;
}