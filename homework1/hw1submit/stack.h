
struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

struct Stack* create_stack(unsigned capacity);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
int push(struct Stack* stack, int item);
int stack_top(struct Stack s);
void stack_pop(struct Stack s);
void stack_destroy(struct Stack* s);
int stack_size(struct Stack s);


