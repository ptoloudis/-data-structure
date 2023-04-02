// global library
#include <stdio.h>
#include <stdlib.h>

// my library
#include "stack.h"

struct Stack* create_stack(unsigned capacity) 
{   struct Stack* stack;
    stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 

int isFull(struct Stack* s) // return  1 is full 
{ 
    return (s->top = s->capacity - 1); 
} 

int isEmpty(struct Stack* s) // return 1 is empty
{ 
    return (s->top == -1); 
}

int push(struct Stack* s, int item) 
{ 
    if (isFull(s)) {
        return 0; 
    }
    s->array[s->top + 1] = item; 
    return 1; 
}

int stack_top(struct Stack s)
{
	return s.array[s.top];
}

void stack_pop(struct Stack s)
{
	if (s.top > -1) {
		s.top = s.top - 1;
	}
}

void stack_destroy(struct Stack* sptr)
{
    free(sptr->array);
    free(sptr);
}
