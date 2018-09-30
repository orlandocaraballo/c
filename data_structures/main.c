#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
  int i;
  Stack *stack = (Stack *) malloc(sizeof(Stack));

  initialize(stack);
  grow(stack);
  push(stack, 90);
  push(stack, -1);
  push(stack, -33);
  push(stack, 4);


  for(i = 0; i < stack->size; i++) {
    printf("The current element on index [%d] is: %d\n", i, stack->values[i]);
  }

  return 0;
}