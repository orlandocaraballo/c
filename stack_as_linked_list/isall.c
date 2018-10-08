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
Expression* parse_response(char *response);

int main() {
  StackAsLinkedList *stack = initialize_stack_as_linked_list();
  bool keep_going = true;
  const int MAX_SIZE = 20;

  // set response length to 20 for now
  char response[MAX_SIZE];

  printf("Welcome to interactive stack as linked list.\n");
  printf("Enter a command:\n\n");

  while(keep_going) {
    printf("isall> ");
    fgets(response, MAX_SIZE, stdin);

    parse_response(response);
  }

  return 0;
}

// return an array of strings
Expression* parse_response(char *response) {
  const char *DELIMITER = " \n";
  const char MAX_TOKEN_AMOUNT = 2;
  Expression *expression = (Expression *) malloc(sizeof(Expression));
  char *token = strtok(response, DELIMITER);
  char tokens[MAX_TOKEN_AMOUNT];

  expression->command = token;

  for(int i = 0; (token != NULL) || (i < MAX_TOKEN_AMOUNT - 1); i++) {
    printf("%s\n", token);
    token = strtok(NULL, DELIMITER);
  }

  sscanf(token, "%d", &(expression->value));

  return expression;
}

char** tokenize(char *command_string) {

  for(int i = 0; (token != NULL) || (i < MAX_TOKEN_AMOUNT - 1); i++) {
    printf("%s\n", token);
    token = strtok(NULL, DELIMITER);
  }
}



// Expression* parse_response(char *response) {
//   Expression *expression = NULL;
//   char *token = NULL;
//   const DELIMITER = " ";

//   // get the token and loop until there are
//   //  no more tokens
//   while(token != NULL) {
//     token = strtok(response, DELIMITER);

//   }
  
  
//   return expression;
// }