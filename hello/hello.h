#include <stdio.h>

// prototypes
void output_to_screen(int number) {
  printf("You are outputting the number %d\n", number);
}

void display_array(int numbers[]) {
  int *pointer;
  
  for(pointer = numbers; pointer != 0; pointer++) {
    printf("The current value being looped is: %p", pointer);
  }
}