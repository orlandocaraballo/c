#include <stdio.h>
#include "error.h"

// display the error message and exit program
void print_error_and_exit(char * message, int code) {
  printf("%s\n", message);
  exit(code);
}