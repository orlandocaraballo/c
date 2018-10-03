#include <stdio.h>
#include "linked_list.h"

int main(int argument_count, char **argument_values) {
  LinkedList *list = initialize_linked_list();

  add(list, 5);
  add(list, 6);
  add(list, 10);
  add(list, 200);

  // list->head->next = initialize_node(6);

  // printf("%d", list->head->next->value);
  display(list);

  return 0;
}