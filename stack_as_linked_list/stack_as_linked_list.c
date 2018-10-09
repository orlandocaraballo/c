#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack_as_linked_list.h"

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
    return -1;
  }

  return stack->linked_list->head->value;
}

// removes the element at the top of the stack
//  and returns the element from the function
int pop(StackAsLinkedList *stack) {
  // let the user know they can't pop with no data
  if(is_empty(stack)) {
    return -1;
  }

  // store our value to return
  int value = stack->linked_list->head->value;

  // point head to the next node in the linked list
  stack->linked_list->head = stack->linked_list->head->next;

  return value;
}

// checks to see if the stack is empty
static bool is_empty(StackAsLinkedList *stack) {
  return stack->linked_list->head == NULL;
}