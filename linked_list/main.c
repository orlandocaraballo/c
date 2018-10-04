#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "../error.h"

int main(int argument_count, char **argument_values) {
  LinkedList *list = initialize_linked_list();

  if(argument_count < 2) {
    print_error_and_exit("You must provide an argument.", 1);
  }

  for(int i = 0; i < atoi(argument_values[1]); ++i) {
    add(list, rand() % 100 + 1);
  }

  display(list);

  return 0;
}