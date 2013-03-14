#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stack.h>

static void test_stack_create(void) {
  size_t stack_size;
  int *new_stack = create_stack(&stack_size);
  assert (10 == (int)stack_size/sizeof(new_stack[0]) && "stack size should be 10");
}

int main (void) {
  test_stack_create();
}

