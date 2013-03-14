#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stack.h>

static void test_stack_create(void) {
  int *new_stack = create_stack();
  int size = sizeof(new_stack)/sizeof(int);
  printf("stack size = %d\n", size);
  assert (10 == size && "stack size should be 10");
}

int main (void) {
  test_stack_create();
}

