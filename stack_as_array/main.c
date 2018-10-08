#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "../error.h"

int main(int argument_count, char **argument_values) {
  // create the stack
  Stack *stack = initialize_stack();

  // check to see if an argument was passed in
  if(argument_count > 1) {
    for(int i = 0; i < atoi(argument_values[1]); i++) {
      // push a random value between 1 and 100
      push(stack, rand() % 100);
    }
  } else {
    // kick the user out if the argument was not passed in
    print_error_and_exit(
      "You must pass in a number of items to push into the stack",
    1);
  }

  for(int i = 0; i < stack->count; i++) {
    printf("The current element on index [%d] is: %d\n", i, stack->values[i]);
  }

  printf("The number at the top of the stack is: %d\n", peek(stack));

  return 0;
}