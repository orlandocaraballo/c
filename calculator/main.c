#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
#include "messages.h"

int main(int argument_count, char **argument_values) {
  // rename our target variables a bit
  char *operation = argument_values[3];
  int arg1 = atoi(argument_values[1]),
    arg2 = atoi(argument_values[2]);
  
  // kick the user out if there aren't enough params passed in
  if(argument_count == 1) {
    display_message_based_on_argument_count(argument_count, MISSING_OPERAND1_MESSAGE);
  } else if(argument_count == 2) {
    display_message_based_on_argument_count(argument_count, MISSING_OPERAND2_MESSAGE);
  } else if(argument_count == 3) {
    display_message_based_on_argument_count(argument_count, MISSING_OPERATOR_MESSAGE);
  }
  
  printf("The values are %d, %d and %s\n", arg1, arg2, operation);

  // grab the appropriate operation
  Operation chosen_operation = choose_operation(operation);

  printf("Chosen operation is: %d\n", chosen_operation(arg1, arg2));

  return 0;
}