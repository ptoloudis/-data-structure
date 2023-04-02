struct Node{
	int data;
	int height;
	double N;
	struct Node* left;
	struct Node* right;
};

int Insert(struct Node* root,int data);
int Delete(struct Node* root,int data);
int Find( struct Node* root,int key);
void Destroy(struct Node* root);

struct Node* NewNode(int data);
struct Node* FindMin(struct Node* node);
int height(struct Node* node);
int Balance(struct Node* node);
void preorder(struct Node* root);
void print(struct Node* root);
struct Node* LeftRotate(struct Node* z);
struct Node* RightRotate(struct Node* z);
