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

int * create_stack(size_t *size) {
  static int stack[STACK_SIZE];
  *size = sizeof(stack);
  return stack;
}

BOOL is_empty(void) {
  return TRUE;
}

