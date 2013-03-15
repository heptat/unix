#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

int main() {
  Stack *stack = create_stack(3);
  printf("stack head = %d\n", stack->head);
  printf("stack value at head = %d\n", stack->values[stack->head]);

  BOOL empty = FALSE;
  empty = is_empty(stack);
  printf("empty = %d\n", empty);

  push(stack, 22);
  printf("stack head = %d\n", stack->head);
  printf("stack value at head = %d\n", stack->values[stack->head]);

  empty = is_empty(stack);
  printf("empty = %d\n", empty);

  free(stack);

  Stack *new_stack = create_stack(100);

  push(new_stack, 88);
  printf("new_stack head = %d\n", new_stack->head);
  printf("new_stack value at head = %d\n", new_stack->values[new_stack->head]);

  return 0;
}
