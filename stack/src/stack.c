#include <stdio.h>
#include <stdlib.h>
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

Stack * create_stack(int length) {
  Stack *stack = (Stack *) malloc(sizeof(Stack));
  stack->values = malloc(length * sizeof(int));
  stack->length = length;
  stack->head = -1;

  return stack;
}

BOOL is_empty(Stack *stack) {
  if (stack->head < 0) {
    return TRUE;
  } else {
    return FALSE;
  }
}
BOOL push(Stack *stack, int value) {
  if (stack->head == (stack->length - 1)) {
    return FALSE;
  }
  stack->head++;
  stack->values[stack->head] = value;

  return TRUE;
}

int pop(Stack *stack, BOOL *success) {
  if (stack->head < 0) {
    *success = FALSE;
    return FALSE;
  }
  *success = TRUE;
  int value = stack->values[stack->head];
  stack->head--;

  return value;
}

int peek(Stack *stack) {
  if (stack->head < 0) {
    return 0;
  }
  return stack->values[stack->head];
}

