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

Stack * create_stack(void) {
  Stack *stack = (Stack *) malloc(sizeof(Stack));
  stack->head = NULL;
  stack->next = NULL;

  return stack;
}

BOOL is_empty(Stack *stack) {
  if (size(stack) > 0) {
    return FALSE;
  }
  return TRUE;
}

int size(Stack *stack) {
  int count = 0;
  Node *ptr = stack->next;
  while (ptr != NULL) {
    ptr = ptr->next;
    count++;
  }
  return count;
}

void push(Stack *stack, int value) {
  Node *node = (Node *) malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;

  if (stack->head == NULL) {
    stack->next = node;
  } else {
    stack->head->next = node;
  }
  stack->head = node;
}

void pop(Stack *stack, int *value) {
  if (1 == size(stack)) {
    *value = stack->head->value;
    stack->next = NULL;
    free(stack->head);
  } else if (stack->next != NULL) {
    *value = stack->head->value;

    Node *ptr = stack->next;
    while (ptr->next->next != NULL) {
      ptr = ptr->next;
    }
    stack->head = ptr;
    ptr = stack->head->next;
    stack->head->next = NULL;
    free(ptr);
  }
}

void print_stack(Stack *stack) {
  Node *ptr = stack->next;
  for (int i = 0; i < size(stack); i++) {
    printf("%d", ptr->value);
    if (i < (size(stack) - 1)) {
      printf(", ");
    }
    ptr = ptr->next;
  }
  printf("\n");

}

void destroy_stack(Stack *stack) {
  Node *ptr = stack->next;

  while (ptr != NULL) {
    stack->next = ptr->next;
    free(ptr);
    ptr = stack->next;
  }

  free(stack);
}
