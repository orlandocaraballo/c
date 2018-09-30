const char *MISSING_OPERAND1_MESSAGE = "You are missing operand 1";
const char *MISSING_OPERAND2_MESSAGE = "You are missing operand 2";
const char *MISSING_OPERATOR_MESSAGE = "You are missing the operator";

void display_message_based_on_argument_count(int argument_count, const char *message) {
  printf("%s\n", message);
  exit(-argument_count);
}