#include <stdbool.h>

// define our stack signature
typedef struct _stack {
  int *values;
  int count;
  int size;
  int multiplier;
} Stack;

// define our stack helper function signatures
Stack* initialize_stack();
void push(Stack *, int);
int peek(Stack *);
int pop(Stack *);

// make static to scope function to definition file
static int calculate_new_size(Stack *);
static bool is_empty(Stack *);
static void on_first_push(Stack *);
static void grow(Stack *);