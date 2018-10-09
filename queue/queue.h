#ifndef _queue_included_
#define _queue_included_

// declare our queue struct
typedef struct Queue {
  int *values;
  int count;
  int size;
} Queue;

// declare our queue helper function prototypes
Queue* initialize_queue();
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
int rear(Queue *queue);
int front(Queue *queue);

#endif