#include <stdbool.h>

// define our stack struct
typedef struct Stack {
  int *values;
  int count;
  int size;
} Stack;

// define our stack helper function prototypes
Stack* initialize_stack();
void push(Stack *stack, int value);
int peek(Stack *stack);
int pop(Stack *stack);

// make static to scope function to definition file
static int calculate_new_size(Stack *stack);
static bool is_empty(Stack *stack);
static void grow(Stack *stack);