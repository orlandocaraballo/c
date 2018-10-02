#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
  int i;

  // create the stack
  Stack *stack = initialize_stack();

  // pushes elements onto the top of the stack
  push(stack, 90);
  push(stack, -1);
  push(stack, -33);
  push(stack, 4);
  push(stack, -13);
  push(stack, 11);
  push(stack, -9);
  push(stack, 100);

  
  // printf("The number popped from the stack is: %d\n", pop(stack));
  
  // pop some items from the top of the stack
  pop(stack);
  pop(stack);

  for(i = 0; i < stack->size; i++) {
    printf("The current element on index [%d] is: %d\n", i, stack->values[i]);
  }

  printf("The number at the top of the stack is: %d\n", peek(stack));

  return 0;
}