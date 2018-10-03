#include <stdbool.h>

// define our queue struct
typedef struct Queue {
  int *values;
  int count;
  int size;
} Queue;

// define our queue helper function prototypes
Queue* initialize_queue();
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
int rear(Queue *queue);
int front(Queue *queue);

// make static to scope function to definition file
static int calculate_new_size(Queue *queue);
static bool is_empty(Queue *queue);
static void grow(Queue *queue);