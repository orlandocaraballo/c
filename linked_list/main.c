#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
#include "../error.h"

int main(int argument_count, char **argument_values) {
  LinkedList *list = initialize_linked_list();

  // use the current time as the seed
  //  for random function used below
  srand(time(NULL));

  if(argument_count < 2) {
    print_error_and_exit("You must provide an argument.", 1);
  }

  for(int i = 0; i < atoi(argument_values[1]); ++i) {
    // generate a random number to add to the linked list
    add_to_tail(list, rand() % 100 + 1);
  }

  display(list);

  return 0;
}