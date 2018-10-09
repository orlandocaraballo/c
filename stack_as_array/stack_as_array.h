#ifndef _stack_as_array_included_
#define _stack_as_array_included_

// define our stack struct
typedef struct Stack {
  int *values;
  int count;
  int size;
} Stack;

// define our stack helper function prototypes
Stack* initialize_stack();
void push(Stack *stack, int value);
int peek(Stack *stack);
int pop(Stack *stack);

#endif