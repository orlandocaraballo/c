#include "hello.h"

int main(int argument_count, char* argument_values[]) {
  int numbers[] = { 1,25,3,4,5,6,7,8,9,10 };
  int *current_element = &numbers;

  // char *names[] = { 
  //   "orlando",
  //   "patrisha",
  //   "denisse" 
  // };

  int i;
  // if(argument_count < 2) {
  //   printf("Missing argument! :(\n");
  // } else {
  //   printf("Thank you!\n");
  //   printf("Here is your argument: %s\n", argument_values[1]);
  // }

  // for(current_element = &numbers; current_element; current_element) {
  //   printf("The current element is: %d\n", numbers[i]);
  // }

  printf("The output value is: %b\n", current_element[10] == NULL);

  return 0;
}