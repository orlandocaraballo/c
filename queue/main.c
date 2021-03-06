#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "queue.h"
#include "../error.h"

int main(int argument_count, char **argument_values) {
  Queue *queue = initialize_queue();

  // use the current time as the seed
  //  for random function used below
  srand(time(NULL));

  // kick the user out if the argument was not passed in
  if(argument_count < 2) {
    print_error_and_exit(
      "You must pass in a number of items to enqueue into the queue",
    1);
  }

  for(int i = 0; i < atoi(argument_values[1]); ++i) {
    // enqueue a random value between 1 and the 100
    enqueue(queue, rand() % 100 + 1);
  }

  for(int i = 0; i < 3 ; ++i) {
    printf("The value we are dequeueing is: %d\n", dequeue(queue));
  }

  for(int i = 0; i < queue->count; i++) {
    printf("The current element on index [%d] is: %d\n", i, queue->values[i]);
  }

  printf("The front of the queue is: %d\n", front(queue));
  printf("The rear of the queue is: %d\n", rear(queue));
}