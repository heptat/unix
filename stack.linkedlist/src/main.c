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

  // Node *node = (Node *) malloc(sizeof(Node));
  Node *node = NULL;
  pop(stack, &node);
  printf("popped value = %d\n", node->value);
  printf("stack head value = %d\n", stack->head->value);
  print_stack(stack);

  push(stack, 22);
  printf("stack head value = %d\n", stack->head->value);
  print_stack(stack);

  free(node);
  destroy_stack(stack);

  return 0;
}
