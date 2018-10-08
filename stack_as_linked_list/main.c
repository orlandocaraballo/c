#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "stack_as_linked_list.h"
#include "../error.h"

// defined towards the bottom
void push_random_value_onto_stack(StackAsLinkedList *stack);
void push_random_values_onto_stack(StackAsLinkedList *stack, int amount_of_values);
char ask_for_input();

int main(int argument_count, char **argument_values) {
  // create the stack
  StackAsLinkedList *stack = initialize_stack_as_linked_list();

  // if argument was passed in then push random values onto the stack
  //  based on argument passed in
  if(argument_count > 1) {
    // push random values onto the stack
    push_random_values_onto_stack(stack, atoi(argument_values[1]));

    // display top of the stack
    printf("The top of the stack is: %d\n", peek(stack));
    display(stack->linked_list);

    return 0;
  }

  // if no argument was passed in then ask user if
  //  they would like to let the program forever and add random values
  //  onto the stack until it recieves a TERM signal

  // set our response var
  char response = ask_for_input();

  // if user enters yes then proceed to grow stack by 1000
  //  every x amount of seconds
  if(response == 'y') {
    while(true) {
      // push 1000 items onto the stack until the program is closed
      push_random_values_onto_stack(stack, 1);

      // display the items within the linked list currently
      display(stack->linked_list);

      // wait for 5 seconds
      sleep(2);
    }
  } else if(response == 'n') {
    // kick the user out if they do not want to randomly add items
    //  onto the stack
    print_error_and_exit(
      "There is nothing else to do then :(",
    1);
  } else {
    print_error_and_exit(
      "Command not understood. Exiting...",
    2);
  }

  return 0;
}

// pushes a set of random values onto the stack based on amount_of_values
void push_random_values_onto_stack(StackAsLinkedList *stack, int amount_of_values) {
  for(int i = 0; i < amount_of_values; i++) {
    push_random_value_onto_stack(stack);
  }
}

// push a random value between 1 and 100 onto stack
void push_random_value_onto_stack(StackAsLinkedList *stack) {
  push(stack, rand() % 100);
}

// ask user for input on whether they want to proceed as a psuedo-daemon
//  or not
char ask_for_input() {
  char response;

  printf("Would you like to run this as a psuedo-daemon? (Enter 'y' or 'n')\n");
  scanf("%c", &response);

  return response;
}