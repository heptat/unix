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

void pop(Stack *stack, Node **node) {
  *node = stack->head;
  if (1 == size(stack)) {
    stack->next = NULL;
    stack->head = NULL;
  } else if (stack->next != NULL) {
    Node *ptr = stack->next;
    while (ptr->next->next != NULL) {
      ptr = ptr->next;
    }
    stack->head = ptr;
    stack->head->next = NULL;
  }
}

int peek(Stack *stack) {
  if (0 < size(stack)) {
    return stack->head->value;
  }
  return 0;
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

void sort(Stack *stack) {
  // Obviously you only have to sort if the stack size is greater than 1
  if (1 < size(stack)) {

    Stack *tmp_stack = (Stack *) malloc(sizeof(Stack));

    while (0 < size(stack)) {
      Node *tmp_node = NULL;
      pop(stack, &tmp_node);

      // compare
      if (tmp_node->value <= peek(stack)) {
        push(tmp_stack, tmp_node->value);
        free(tmp_node);
      } else {
        Node *tmp_node2 = NULL;
        pop(stack, &tmp_node2);
        push(tmp_stack, tmp_node2->value);
        push(tmp_stack, tmp_node->value);
        free(tmp_node2);
        free(tmp_node);
      }
    }
    stack = tmp_stack;
    destroy_stack(stack);
  }
}

