// operations
int sum(int arg1, int arg2) { 
  return arg1 + arg2; 
}

int difference(int arg1, int arg2) { 
  return arg1 - arg2; 
}

int product(int arg1, int arg2) { 
  return arg1 * arg2; 
}

int quotient(int arg1, int arg2) { 
  return arg1 / arg2; 
}

// typedef for operations
typedef int (*Operation)(int, int);