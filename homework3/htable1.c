#include <stdio.h>
#include <stdlib.h>
#include "htable.h"

int main (int argc, char* argv[]){
    char str[5], menu;
    struct htable* root;
    int data ,i,rehash, ret;
    int table[1000];
    int *tab[2];

    i = 0;
    rehash = 1;
    root->size = 0;
    root->delete = 0;
    root->max = 2;
    root->hash = tab;
    root->hash[0] = NULL;  
    root->hash[1] = NULL;

    while (1){
        scanf("%s",str);
        if(str[0] == '-'){
            if(str[1] == 'p'){
                Print(root);
                continue;
            }
            if(str[1] == 'q'){
                free(root->hash);
                break;
            }
            if(str[1] == 'r'){
                rehash = ~rehash;
                break;
            }
            switch (str[1]){
                case 'i': menu = 'i';
                        continue; 
                    break;
                case 'd': menu = 'd';
                        continue; 
                    break;
                case 'f': menu = 'f';
                        continue; 
                    break;
                default: menu = menu;
                    break;
            }
        }

        data = atoi(str);
        switch (menu){
            case 'i':
                table[i] = data; 
                ret = Insert(&table[i] , root, rehash);
                if (ret)
                    printf("INSERTED %d\n",data);
                else
                    printf("NOT INSERTED %d\n",data);
                break;
            case 'd': 
                ret = Delete(data , root, rehash);
                if (ret)
                    printf("DELETED %d\n",data);
                else
                    printf("NOT DELETED %d\n",data);
                break;
            case 'f': 
                ret = Find(data , root);
                if (ret)
                    printf("NOT FOUND %d\n",data);
                else
                    printf("FOUND %d\n",data);
                break;
            default:  continue;
        }
    }

    return 0; 
}