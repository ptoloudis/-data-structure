#include <stdio.h>
#include <stdlib.h>
#include "tree.h"



int main(int argc, char* argv[]) {
	int i=0;
	int pianka[50] = { 0 };
	char str[4];
    tree_t* tree;
    node_t* root;

    while (1) {
        scanf("%s", str);
        if (str[0] == '-') {
            break;
        }
        pinaka[i] = atoi(str);
    }

    tree = bt_create();
    root = create_root(pinaka[0]);
    tree->root = root;
    tree->size = 1;
    stoixio = list->head->next;
    for (j = 1; j <= i; j++) {
        bst_insert(root, pinaka[j]);
        tree->size++;
    }


}