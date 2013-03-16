#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

int main() {
  Stack *stack = create_stack();
  push(stack, 20);
  printf("stack head value = %d\n", stack->head->value);
  print_stack(stack);

  push(stack, 21);
  printf("stack head value = %d\n", stack->head->value);
  print_stack(stack);

  int value;
  pop(stack, &value);
  printf("popped value = %d\n", value);
  printf("stack head value = %d\n", stack->head->value);
  print_stack(stack);

  push(stack, 22);
  printf("stack head value = %d\n", stack->head->value);
  print_stack(stack);

  destroy_stack(stack);

  return 0;
}
