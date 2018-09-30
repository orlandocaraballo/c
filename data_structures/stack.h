#include <stdlib.h>

typedef struct _stack {
  int *values;
  int count;
  int size;
  int multiplier;
  // int (* peek)();
  // void (* push)(int value);
  // int (* pop)();
} Stack;

void initialize(Stack *stack) {
  int array[] = { 9, 11, 13 };
  stack->values = (int *) malloc(sizeof(int[3]));

  stack->count = 3;
  stack->size = 3;
  stack->multiplier = 2;
  stack->values[0] = 9;
  stack->values[1] = 11;
  stack->values[2] = 13;
}

void grow(Stack *stack) {
  int larger_size = stack->multiplier * stack->size;
  int *larger_array = (int *) malloc(sizeof(int[larger_size]));
  int i;

  for(i = 0; i < stack->size; i++) {
    larger_array[i] = stack->values[i];
  }

  stack->values = larger_array;
  stack->size = larger_size;
}

void push(Stack *stack, int value) {
  if(stack->count == stack->size) {
    grow(stack);
  }

  stack->values[stack->count] = value;
  stack->count++;
}