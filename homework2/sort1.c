#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
//#include "dlist.h"

int main (int argc, char* argv[]){
    int x,y;
    char str[6];
    struct dlist* list;

    x = atoi(argv[1]);
    y = atoi(argv[2]);

    if (x>6 || x<1){
        printf ("Invalid argument\n");
        return 0;
    }
    if (x== 6 || x==5){
        if (y!=1 ||y!=2 ||y!=4 ||y!=8 ||y!=16 )
        {
            printf ("Invalid argument\n");
            return 0;
        }   
    }
    


    list = create_dlist();
    while (1){
        scanf("%s",str);
        if(str[0] == '-'){
            break;
        }
        insert(list,list->tail,atoi(str));
    }

    print_list(list);

    switch( x ){
        case 1:insertion_sort(list);
                break;
        case 2:selection_sort(list);
                break;
        case 3:list->head = quick_sort(list->head,list->size,0);
                break;
        case 4:list->head = mergeSort(list->head,0);
            break;
        case 5: 
            break;
        case 6: 
            break;
        default: return 0;
            break;
    }

    print_list(list);
    del_list(list);
    return 1;
}