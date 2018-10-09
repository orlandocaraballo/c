#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "stack_as_linked_list.h"
#include "../error.h"

// define the expression recieved from the command line
typedef struct Expression {
  char *command;
  int value;
} Expression;

// forward declarations
char ** tokenize(char *command_string);
Expression* convert_tokens_to_expression(char **tokens);
void execute_command(StackAsLinkedList *stack, Expression *expression);
void execute_push_command(StackAsLinkedList *stack, int value);
void execute_peek_command(StackAsLinkedList *stack);
void execute_pop_command(StackAsLinkedList *stack);


int main() {
  StackAsLinkedList *stack = initialize_stack_as_linked_list();
  Expression *expression;
  const int MAX_SIZE = 20;

  // set response length to 20 for now
  char response[MAX_SIZE];

  printf("Welcome to interactive stack as linked list.\n");
  printf("Enter a command:\n\n");

  while(true) {
    printf("isall> ");
    fgets(response, MAX_SIZE, stdin);

    // tokenize input and create expression
    expression = convert_tokens_to_expression(tokenize(response));

    // if the first token found is NULL then jump to the next iteration
    if(expression->command == NULL) {
      printf("Sorry your input was incorrect, please try again.\n");
      continue;
    } else if(strcmp(expression->command, "q") == 0 || strcmp(expression->command, "quit") == 0) {
      // if person enters q or quit then exit the program
      print_error_and_exit("Exiting...", 2);
    }

    // runs the command
    execute_command(stack, expression);
  }

  return 0;
}

// TODO: need to clean up this method, it seems inefficient
// tokenize command string based on some rules defined in the function
char** tokenize(char *command_string) {
  // only look for spaces and newline
  const char *DELIMITER = " \n";

  // only go up until 2 tokens have been found then stop
  const char MAX_TOKEN_AMOUNT = 2;
  
  // store only 2 tokens
  char **tokens= (char **) calloc(MAX_TOKEN_AMOUNT, sizeof(char *));

  // get the first token and store it within the tokens string array
  char *token = strtok(command_string, DELIMITER);
  tokens[0] = token;

  for(int i = 1; (token != NULL) || (i < MAX_TOKEN_AMOUNT); i++) {
    token = strtok(NULL, DELIMITER);
    tokens[i] = token;
  }

  return tokens;
}

// converts tokens array to an expression
//  expression->value is set to -1 if no second token is found
Expression* convert_tokens_to_expression(char** tokens) {
  Expression *expression = (Expression *) malloc(sizeof(Expression));

  expression->command = tokens[0];

  // only set expression value to something
  //  if it exists
  if(tokens[1] != NULL) {
    // use sscanf to convert string buffer to int
    sscanf(tokens[1], "%d", &expression->value);
  } else {
    expression->value = 0;
  }

  return expression;
}

// run command defined by the expression
void execute_command(StackAsLinkedList *stack, Expression *expression) {
  if(strcmp(expression->command, "push") == 0) {
    execute_push_command(stack, expression->value);
  } else if(strcmp(expression->command, "peek") == 0){
    execute_peek_command(stack);
  } else if(strcmp(expression->command, "pop") == 0){
    execute_pop_command(stack);
  } else {
    printf("Unrecognized command.\n");
  }
}

// runs the push command
void execute_push_command(StackAsLinkedList *stack, int value) {  
  push(stack, value);
  printf("The value [ %d ] is pushed on top of the stack\n", value);
}

// runs the peek command
//  displays a message to stderr if stack is empty
void execute_peek_command(StackAsLinkedList *stack) {
  int command_return_value = peek(stack);

  // if the peek returns -1 then there must be nothing in the stack
  if(command_return_value == -1) {
    print_error("You cannot peek with no data stored in the stack");
    return;
  }

  printf("The value on top of the stack is [ %d ]\n", command_return_value);
}

// runs the pop command
//  displays a message to stderr if stack is empty
void execute_pop_command(StackAsLinkedList *stack) {
  int command_return_value = pop(stack);

  // if the pop returns -1 then there must be nothing in the stack
  if(command_return_value == -1) {
    print_error("You cannot pop with no data stored in the stack");
    return;
  }

  printf("The value retrived from the top of the stack is [ %d ]\n", command_return_value);
}