
typedef struct dnode {
    int data;
    struct dnode *next;
    struct dnode *prev;
} dnode_t;

typedef struct dlist {
    dnode_t *head;
    dnode_t *tail;          
    int size;
} dlist_t;

dlist_t* create_dlist();
int insert(dlist_t* list, dnode_t* before,int data);
int rmv_node(dlist_t* list, dnode_t* node);
void del_node(dlist_t* list);
void del_list(dlist_t* list);
void print_list(dlist_t* list);
