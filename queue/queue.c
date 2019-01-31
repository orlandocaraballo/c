#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include "../error.h"

// make static to scope function to definition file
static int calculate_new_size(Queue *queue);
static bool is_empty(Queue *queue);
static void grow(Queue *queue);

// create our queue
Queue* initialize_queue() {
  // allocate enough space for a queue struct
  Queue *queue = (Queue *) malloc(sizeof(Queue));

  // set our initial values
  queue->values = NULL;
  queue->count = 0;
  queue->size = 0; 

  return queue;
}

// add a new value to the rear of the queue
void enqueue(Queue *queue, int value) {
  // grow the queue if the inner array is full
  //  of data
  if(queue->count == queue->size) {
    grow(queue);
  }

  // add the value to the end of the inner array
  queue->values[queue->count] = value;
  queue->count++;
}

// removes the element at the front of the queue
//  and returns the element from the function
int dequeue(Queue *queue) {
  // let the user know they can't dequeue with no data
  if(is_empty(queue)) {
    printf("You cannot dequeue with no data stored in the queue\n");
    exit(1);
  }

  int current_index = queue->count - 1;
  
  // store the popped value so we can return it from the function
  int dequeued_value = queue->values[current_index];

  // set the current last element to 0
  queue->values[current_index] = 0;

  // reduce the queue count by 1
  queue->count--;

  // return the last element of the inner array
  return dequeued_value;
}

// find the rear of the queue
int rear(Queue *queue) {
  if(is_empty(queue)) {
    print_error_and_exit(
      "You cannot find the front of a queue with no items",
    1);
  }

  return queue->values[0];
}

// find the front of the queue
int front(Queue *queue) {
  // kick the user out if there are no items in the queue
  if(is_empty(queue)) {
    print_error_and_exit(
      "You cannot find the front of a queue with no items",
    1);
  }

  return queue->values[queue->count - 1];
}

// checks to see if the queue is empty
static bool is_empty(Queue *queue) {
  return queue->count == 0;
}

// calculates new inner array size
static int calculate_new_size(Queue *queue) {
  // if the queue is empty then set the size to 1
  if(is_empty(queue)) {
    return 1;
  } 
  
  // otherwise the size should be set to double the prior size
  return 2 * queue->size;
}

// increases the size of the inner array
static void grow(Queue *queue) {
  // get the new size of the inner array
  int larger_size = calculate_new_size(queue);

  // on the first pass, the first argument is NULL therefore it will
  //  behave very much like a malloc
  // every other pass after this will try to reallocate the amount of
  //  already set for queue->values to a larger size
  queue->values = (int *) realloc(queue->values, larger_size * sizeof(int));

  // set the new size of the array to the larger size
  queue->size = larger_size;
}