#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack_as_linked_list.h"
#include "../error.h"

// make static to scope function to definition file
// static int calculate_new_size(StackAsLinkedList *stack_as_linked_list);
static bool is_empty(StackAsLinkedList *stack_as_linked_list);
// static void grow(StackAsLinkedList *stack_as_linked_list);

// creates the Stack
StackAsLinkedList* initialize_stack_as_linked_list() {
  StackAsLinkedList *stack = (StackAsLinkedList *) malloc(sizeof(StackAsLinkedList));
  
  // set our default values
  stack->linked_list = (LinkedList *) malloc(sizeof(LinkedList));
  stack->count = 0;
  stack->size = 0;

  return stack;
}

// push items into the stack
void push(StackAsLinkedList *stack, int value) {
  add_to_head(stack->linked_list, value);
  stack->count++;
}

// returns the element at the top of the stack
int peek(StackAsLinkedList *stack) {
  // let the user know they can't peek with no data
  if(is_empty(stack)) {
    print_error_and_exit(
      "You cannot peek with no data stored in the stack",
    1);
  }

  return stack->linked_list->head->value;
}

// removes the element at the top of the stack
//  and returns the element from the function
int pop(StackAsLinkedList *stack) {
  // let the user know they can't pop with no data
  if(is_empty(stack)) {
    print_error_and_exit(
      "You cannot pop with no data stored in the stack",
    1);
  }

  // store our value to return
  int value = stack->linked_list->head->value;

  // point head to the next node in the linked list
  stack->linked_list->head = stack->linked_list->head->next;

  return value;
}

// // calculates new inner array size
// static int calculate_new_size(StackAsLinkedList *stack) {
//   int new_size;

//   if(is_empty(stack)) {
//     // if the stack is empty then set the size to 1
//     new_size = 1;
//   } else {
//     // otherwise the size should be set to double the prior size
//     new_size = 2 * stack->size;
//   }

//   return new_size;
// }

// checks to see if the stack is empty
static bool is_empty(StackAsLinkedList *stack) {
  return stack->linked_list->head == NULL;
}

// // increases the size of the inner array
// static void grow(Stack *stack) {
//   // get the new size of the inner array
//   int larger_size = calculate_new_size(stack);

//   // on the first pass, the first argument is NULL therefore it will
//   //  behave very much like a malloc
//   // every other pass after this will try to reallocate the amount of
//   //  already set for stack->values to a larger size
//   stack->values = (int *) realloc(stack->values, larger_size * sizeof(int));

//   // set the new size of the array to the larger size
//   stack->size = larger_size;
// }