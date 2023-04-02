// global library
#include <stdio.h>
#include <stdlib.h>

// my library
#include "tree.h"

tree_t* bt_create(){
    tree_t* tree;

    tree = (tree_t*)malloc(sizeof(tree_t));
    if(!tree){
        perror("err in tree create\n");
        exit(-1);
    }
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

node_t* create_root(int e){
    node_t *new;

    new = (node_t*)malloc(sizeof(node_t));
	if (new == NULL) {
		perror("out of space");
	}
	new->parent= NULL;
	new->value = e;
	new->left = new->right = NULL;
	return new;
}

void bst_insert(node_t *bst, int e){   
    node_t *new;

	if (bst->value == e) {
		return;
	} else if (bst->value < e) {
		if (bst->right != NULL) {
			bst_insert(bst->right, e);
		} else {
			new = create_root(e);
			new->parent = bst; 
			bst->right = new;
		}
	} else {
		if (bst->left != NULL) {
			bst_insert(bst->left, e);
		} else {
			new = create_root(e);
			new->parent = bst;
			bst->left = new;
		}
	}
}

int bst_find(node_t* bst, int e){
	if (bst == NULL)
		return -1;
	else if (bst->value < e) {
		return bst_find(bst->right, e) + 1;
	} else if (bst->value > e) {
		return bst_find(bst->left, e ) + 1;
	}
	return 1;
}

node_t* bst_delete(node_t* bst, int e){   
    node_t*  ptr;

	if (bst == NULL) {
		perror("element not found");
		return bst;
	} else if (bst->value > e) {
		bst->left = bst_delete(bst->left, e);
	} else if (bst->value < e) {
		bst->right = bst_delete(bst->right, e);
	} else {
		if (bst->left == NULL && bst->right == NULL) {
			free(bst);
			return NULL;
		} else if (bst->left == NULL || bst->right == NULL) {
			ptr = bst->left == NULL ? bst->right : bst->left;
			free(bst);
			return ptr;
		}
		bst->right = bst_delete(bst->right, bst->value);
	}
	return bst;
}

void bt_destroy(node_t *bst){
	if (bst == NULL) {
        return;
    }
	bt_destroy(bst->left);
	bt_destroy(bst->right);
	free(bst);
}