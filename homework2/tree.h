typedef struct bt_node {
    int value;
    struct bt_node* parent;
    struct bt_node* left;
    struct bt_node* right;
} node_t;

typedef struct btree {
    node_t* root;
    int size;
} tree_t;

tree_t* bt_create();
node_t* create_root(int e);
void bst_insert(node_t *bst, int e);
int bst_find(node_t* bst, int e);
node_t* bst_delete(node_t* bst, int e);
void bt_destroy(node_t *bst);