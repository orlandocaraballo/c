typedef struct Node {
  struct Node *next;
  int value;
} Node;

typedef struct LinkedList {
  Node *head;
  int count;
  int size;
} LinkedList;

// setup our list function prototypes
LinkedList* initialize_linked_list();
Node* initialize_node(int value);
void add(LinkedList *list, int value);
void display(LinkedList *list);