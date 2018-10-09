#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack_as_array.h"
#include "../error.h"

// make static to scope function to definition file
static int calculate_new_size(Stack *stack);
static bool is_empty(Stack *stack);
static void grow(Stack *stack);

// creates the Stack
Stack* initialize_stack() {
  Stack *stack = (Stack *) malloc(sizeof(Stack));
  
  // set our default values
  stack->values = NULL;
  stack->count = 0;
  stack->size = 0;

  return stack;
}

// push items into the stack
void push(Stack *stack, int value) {
  // grow the stack if the inner array is full
  //  for data
  if(stack->count == stack->size) {
    grow(stack);
  }

  // add the value to the end of the inner array
  stack->values[stack->count] = value;
  stack->count++;
}

// returns the element at the top of the stack
int peek(Stack *stack) {
  // let the user know they can't peek with no data
  if(is_empty(stack)) {
    print_error_and_exit(
      "You cannot peek with no data stored in the stack",
    1);
  }

  return stack->values[stack->count - 1];
}

// removes the element at the top of the stack
//  and returns the element from the function
int pop(Stack *stack) {
  // let the user know they can't pop with no data
  if(is_empty(stack)) {
    print_error_and_exit(
      "You cannot pop with no data stored in the stack",
    1);
  }

  int current_index = stack->count - 1;
  
  // store the popped value so we can return it from the function
  int popped_value = stack->values[current_index];

  // set the current last element to 0
  stack->values[current_index] = 0;

  // reduce the stack count by 1
  stack->count--;

  // return the last element of the inner array
  return popped_value;
}

// calculates new inner array size
static int calculate_new_size(Stack *stack) {
  int new_size;

  if(is_empty(stack)) {
    // if the stack is empty then set the size to 1
    new_size = 1;
  } else {
    // otherwise the size should be set to double the prior size
    new_size = 2 * stack->size;
  }

  return new_size;
}

// checks to see if the stack is empty
static bool is_empty(Stack *stack) {
  return stack->size == 0;
}

// increases the size of the inner array
static void grow(Stack *stack) {
  // get the new size of the inner array
  int larger_size = calculate_new_size(stack);

  // on the first pass, the first argument is NULL therefore it will
  //  behave very much like a malloc
  // every other pass after this will try to reallocate the amount of
  //  already set for stack->values to a larger size
  stack->values = (int *) realloc(stack->values, larger_size * sizeof(int));

  // set the new size of the array to the larger size
  stack->size = larger_size;
}