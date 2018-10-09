#ifndef _linked_list_included_
#define _linked_list_included_

typedef struct Node {
  struct Node *next;
  int value;
} Node;

typedef struct LinkedList {
  Node *head;
  Node *tail;
} LinkedList;

// setup our list function prototypes
LinkedList* initialize_linked_list();
Node* initialize_node(int value);
void add_to_tail(LinkedList *list, int value);
void add_to_tail_thru_head(LinkedList *list, int value);
void add_to_head(LinkedList *list, int value);
void display(LinkedList *list);

#endif