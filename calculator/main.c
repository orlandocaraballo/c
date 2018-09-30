#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
#include "messages.h"

int main(int argument_count, char **argument_values) {
  // kick the user out if there aren't enough params passed in
  if(argument_count == 1) {
    printf("%s\n", MISSING_OPERAND1_MESSAGE);
    return 0;
  } else if(argument_count == 2) {
    printf("%s\n", MISSING_OPERAND1_MESSAGE);
    return 0;
  } else if(argument_count == 3) {
    printf("%s\n", MISSING_OPERATOR_MESSAGE);
    return 0;
  }

  char *operation = argument_values[3];
  int arg1 = atoi(argument_values[1]),
    arg2 = atoi(argument_values[2]);
  
  printf("The values are %d, %d and %s\n", arg1, arg2, operation);

  // grab the appropriate operation
  Operation chosen_operation = choose_operation(operation);

  printf("Chosen operation is: %d\n", chosen_operation(arg1, arg2));

  return 0;
}