#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

int main() {
  BOOL empty = FALSE;
  empty = is_empty();
  printf("empty = %d\n", empty);

  Stack *stack = create_stack(3);
  printf("stack current = %d\n", stack->current);
  printf("stack value at current = %d\n", stack->values[stack->current]);

  return 0;
}
