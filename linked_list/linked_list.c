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
  list->tail = NULL;

  return list;
}

// O(n) complexity
void add_to_tail_thru_head(LinkedList *list, int value) {
  // create the head node if list is empty
  if(is_empty(list)) {
    list->head = initialize_node(value);

    return;
  }

  Node *node = list->head;

  while(node->next) {
    node = node->next;
  }

  node->next = initialize_node(value);
}

// O(1) complexity
void add_to_tail(LinkedList *list, int value) {
  // create the head node if list is empty
  if(is_empty(list)) {
    list->head = initialize_node(value);
    list->tail = list->head;

    return;
  }

  Node *new_node = initialize_node(value);
  list->tail->next = new_node;
  list->tail = new_node;
}

// O(1) complexity
void add_to_head(LinkedList *list, int value) {
  if(is_empty(list)) {
    list->head = initialize_node(value);
    list->tail = list->head;

    return;
  }

  Node *old_head_ptr = list->head;
  list->head = initialize_node(value);
  list->head->next = old_head_ptr;
}

// O(n) complexity
void display(LinkedList *list) {
  if(is_empty(list)) {
    printf("The linked list is empty");
  }

  for(Node *node = list->head; node != NULL; node = node->next) {
    printf("%d -> ", node->value);
  }

  printf("NULL\n");
}

bool is_empty(LinkedList *list) {
  return list->head == NULL;
}