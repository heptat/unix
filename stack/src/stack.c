#include <stdio.h>
#include <stack.h>

/**
 * A stack.
 *
 * Pop, push, peek, and maybe is_empty.
 *
 * Resize as necessary (define initial size of stack? yes if it's an
 * array, but no if you're dynamically allocating memory, which is probably
 * what you should do - so a singly linked list).
 */

int * create_stack(void) {
  static int stack[STACK_SIZE];
  printf("inside create_stack size = %lu\n", sizeof(stack)/sizeof(int));
  return stack;
}

BOOL is_empty(void) {
  return TRUE;
}

