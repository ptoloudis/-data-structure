
typedef struct queue{
    int num;
    struct queue* next;
} Queue;

typedef struct fifo{
    struct queue *rear;
    int size;
}Fifo;

struct fifo* create_fifo(); 
void enqueue(Fifo *list, int new);
int dequeue(Fifo *list);
void  del_fifo(Fifo *list);




