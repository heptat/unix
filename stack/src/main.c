#include <stdio.h>
#include <stack.h>
// #include "../include/stack.h"

int main() {
  BOOL empty = FALSE;
  empty = is_empty();
  printf("empty = %d\n", empty);

  size_t stack_size;
  int *stack = create_stack(&stack_size);

  printf("stack size = %zu\n", stack_size);
  printf("A stack of maximum %lu elements\n", (int)stack_size/sizeof(stack[0]));

  return 0;
}
