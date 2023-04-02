#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "hbtree.h"

#define max(a,b) (((a) > (b)) ? (a) : (b))

struct Node* NewNode(int data){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	temp->N = 0;
	temp->height = 1;
	return temp;
}

struct Node* FindMin(struct Node* node){
	while(node->left!=NULL)
		node = node->left;

	return node;
}

int height(struct Node* node){
	if(node==NULL)
		return 0;

 	return node->height;
}

int Balance(struct Node* node){
	int value , hit;
	double N;
	if(node==NULL)
		return 0;

	N = (int) floor(log2(node->N) );
	value = max(1, N);
	hit = height(node->left) - height(node->right);
	if (value >= hit)
		return 0;
 	
	return hit;
}

void preorder(struct Node* root){
	if(root==NULL)
		return;

	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void print(struct Node* root){
    printf("\n");
    preorder( root);
    printf("\n");
}

int Insert(struct Node* root,int data)
{	int balance;

	if(root==NULL){
		root = NewNode(data);
		return 1;
	}
	if(data < root->data)
		Insert(root->left,data);

	else if(data > root->data)
		Insert(root->right,data);

	else
		return 0;

	root->height = max(height(root->left),height(root->right))+1;
	root->N++;

	balance = Balance(root);

	if (balance == 0){
		return 1;
	}
	
	// Left Left Case
	if(balance > 1 && data < root->left->data)
		root = RightRotate(root);

	// Right Right Case
	if(balance < -1 && data > root->right->data)
		root = LeftRotate(root);

	//Left Right Case
	if(balance > 1 && data > root->left->data){
		root->left = LeftRotate(root->left);
		root = RightRotate(root);
	}

	// Right Left Case
	if(balance < -1 && data < root->right->data)
	{
		root->right = RightRotate(root->right);
		root = LeftRotate(root);
	}

	return 1;
}

int Delete(struct Node* root,int data)
{	struct Node* temp;
	int balance;

	if(root==NULL)
		return 0;

	if ( !Find(root,data) ){
		return 0;
	}
	

	if(data < root->data)
		Delete(root->left,data);

	else if(data > root->data)
		Delete(root->right,data);

	else{
		if(root->right==NULL && root->left==NULL){
			free(root);
			return 1;
		}

		else if(root->left!=NULL && root->right==NULL){
			temp = root->left;
			root = root->left;
			free(temp);
		}

		else if(root->right!=NULL && root->left==NULL){
			temp = root->right;
			root = root->right;
			free(temp);
		}

		else{
			temp = FindMin(root->right);
			root->data = temp->data;
			Delete(root->right,temp->data);
		}
	}

	if(root==NULL)
		return 1;

	root->height = 1 + max(height(root->left),height(root->right));
	root->N--;

	balance = Balance(root);
	if (balance == 0){
		return 1;
	}

	//Left Left Case
	if(balance > 1 && Balance(root->left) >=0)
		root = RightRotate(root);

	// Right Right Case
	if(balance < -1 && Balance(root->right) <=0)
		root = LeftRotate(root);

	// Left Right Case
	if(balance > 1 && Balance(root->left) < 0){
		root->left = LeftRotate(root->left);
		root = RightRotate(root);
	}
	
	//Right Left Case
	if(balance < -1 && Balance(root->right) > 0){
		root->right = RightRotate(root->right);
		root = LeftRotate(root);
	}

	return 1;
}

struct Node* LeftRotate(struct Node* z)
{
	struct Node* y = z->right;
	struct Node* t2 = y->left;

	y->left = z;
	z->right = t2;

	z->height = max(height(z->left),height(z->right))+1;
	y->height = max(height(y->left),height(y->right))+1;

	return y;
}

struct Node* RightRotate(struct Node* z)
{
	struct Node* y = z->left;
	struct Node* t3 = y->right;

	y->right = z;
	z->left = t3;

	z->height = max(height(z->left),height(z->right))+1;
	y->height = max(height(y->left),height(y->right))+1;

	return y;
}

int Find( struct Node* root,int key){
    if (root == NULL)
		return 0;
	else if (root->data <key) {
		return Find(root->right,key);
	}else if (root->data >key) {
		return Find(root->left,key);
	}
	return 1;
}

void Destroy(struct Node* root){
	if (root == NULL) {
        return;
    }
	Destroy(root->left);
	Destroy(root->right);
	free(root);
}
