#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "linked_list.h"

bool is_empty(LinkedList *list);

Node* initialize_node(int value) {
  Node *node = (Node *) malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;

  return node;
}

LinkedList* initialize_linked_list() {
  LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));

  list->head = NULL;
  list->count = 0;
  list->size = 0;

  return list;
}

void add(LinkedList *list, int value) {
  // create the head node if list is empty
  if(is_empty(list)) {
    list->head = initialize_node(value);

    return;
  }

  Node *node;

  do {
    node = list->head;
  } while(node->next);


  node->next = initialize_node(value);
}

void display(LinkedList *list) {
  if(is_empty(list)) {
    printf("The linked list is empty");
  }

  int count = 0;

  for(Node *node = list->head; node != NULL; node = node->next, count++) {
    printf("The current node at index [%d] is %d\n", count, node->value);
  }
}

bool is_empty(LinkedList *list) {
  return list->head == NULL;
}