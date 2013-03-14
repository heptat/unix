#include <stdio.h>
#include <stack.h>
// #include "../include/stack.h"

int main() {
  int * stack;
  BOOL empty = FALSE;
  int test[10];

  empty = is_empty();

  stack = create_stack();
  // pop(stack);
  stack[0] = 11;
  stack[9] = 18;
  stack[10] = 22;

  for (int i = 0; i < STACK_SIZE; i++) {
    printf("Element %i has the value %d\n", i, stack[i]);
  }

  printf("The sizeof stack is %lu\n", sizeof(stack));
  printf("A stack of maximum %lu elements\n", sizeof(stack)/sizeof(stack[0]));
  printf("A test array of maximum %lu elements\n", sizeof(test)/sizeof(test[0]));
  printf("empty = %d\n", empty);

  return 0;
}
