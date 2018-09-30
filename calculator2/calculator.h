#include <string.h>
#include <stdio.h>
#include "operations.h"

// calculator
int calculator(int arg1, int arg2, Operation callback) {
  return callback(arg1,arg2);
}

// choose operation based on 
Operation choose_operation(char *operation_argument) {
  Operation output;
  
  printf("Operation argument = %s\n", operation_argument);

  if(strcmp(operation_argument, "sum") == 0) {
    output = sum;
  } else if(strcmp(operation_argument, "difference") == 0) {
    output = difference;
  } else if(strcmp(operation_argument, "product") == 0) {
    output = product;
  } else if(strcmp(operation_argument, "quotient") == 0) {
    output = quotient;
  } 

  return output;
}