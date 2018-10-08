// define our stack_as_linked_list only if it has not been included
//  already
#ifndef _stack_as_linked_list_included_
#define _stack_as_linked_list_included_

#include "../linked_list/linked_list.h"

// define our stack struct
typedef struct StackAsLinkedList {
  LinkedList *linked_list;
  int count;
  int size;
} StackAsLinkedList;

// define our stack helper function prototypes
StackAsLinkedList* initialize_stack_as_linked_list();
void push(StackAsLinkedList *stack_as_linked_list, int value);
int peek(StackAsLinkedList *stack_as_linked_list);
int pop(StackAsLinkedList *stack_as_linked_list);

#endif