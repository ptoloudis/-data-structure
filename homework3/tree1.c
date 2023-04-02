#include <stdio.h>
#include <stdlib.h>

#include "hbtree.h"

int main (int argc, char* argv[]){
    char str[5], menu;
    struct Node* root = NULL;
    int data ,i;


    while (1){
        scanf("%s",str);

        if(str[0] == '-'){
            if(str[1] == 'p'){
                print(root);
                continue;
            }
            if(str[1] == 'q'){
                Destroy(root);
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
                i = Insert(root,data);
                if (i)
                    printf("INSERTED %d\n",data);
                else
                   printf("NOT INSERTED %d\n",data);
                break;
            case 'd': 
                i = Delete(root,data);
                if (i)
                    printf("DELETED %d\n",data);
                else
                   printf("NOT DELETED %d\n",data);
                break;
            case 'f': 
                i = Find(root,data);
                if (i)
                    printf("FOUND %d\n",data);
                else
                   printf("NOT FOUND %d\n",data);
                break;
            default:  continue;
        }
    }

    return 0; 
}