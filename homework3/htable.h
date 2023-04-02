/* if value  
    is  0x1 is tomb
    or  NULL is empty
    or  pointer is full */
struct htable{
    int size;
    int delete;
    int max; 
    int **hash;
};
 
int Insert(int *value, struct htable* node, int rehash);
int Find(int value, struct htable* node);
int Delete(int value, struct htable* node, int rehash);
void Print(struct htable* node);
struct htable* rehash_fuc(struct htable* node);