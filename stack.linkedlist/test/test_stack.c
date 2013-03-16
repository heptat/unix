#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stack.h>

static void test_new_stack_head_points_to_null(void) {
  Stack *stack = create_stack();

  assert (NULL == stack->head && "stack should point to NULL");
  destroy_stack(stack);
}

static void test_new_stack_next_points_to_null(void) {
  Stack *stack = create_stack();

  assert (NULL == stack->next && "stack should point to NULL");
  destroy_stack(stack);
}

static void test_new_stack_is_empty_returns_true(void) {
  Stack *stack = create_stack();

  assert (TRUE == is_empty(stack) && "stack is_empty should return TRUE");
  destroy_stack(stack);
}

static void test_new_stack_size_is_zero(void) {
  Stack *stack = create_stack();

  assert (0 == size(stack) && "stack size should be 0");
  destroy_stack(stack);
}

static void test_push_onto_empty_stack_creates_node_with_value(void) {
  Stack *stack = create_stack();
  push(stack, 8);

  assert (8 == stack->head->value && "stack->head->value should be 8");
  destroy_stack(stack);
}

static void test_push_onto_empty_stack_size_is_one(void) {
  Stack *stack = create_stack();
  push(stack, 8);

  assert (1 == size(stack) && "stack size after push should be 1");
  destroy_stack(stack);
}

static void test_push_onto_non_empty_stack_size_is_correct(void) {
  Stack *stack = create_stack();
  push(stack, 8);
  push(stack, 7);

  assert (2 == size(stack) && "stack size after pushes should be 2");
  destroy_stack(stack);
}

static void test_non_empty_stack_is_empty_returns_false(void) {
  Stack *stack = create_stack();
  push(stack, 8);

  assert (FALSE == is_empty(stack) && "stack is_empty should return FALSE");
  destroy_stack(stack);
}

static void test_pop_from_non_empty_stack_size_is_correct(void) {
  Stack *stack = create_stack();
  push(stack, 8);
  push(stack, 7);
  int value;
  pop(stack, &value);

  assert (1 == size(stack) && "stack size after pop should be 1");
  destroy_stack(stack);
}

static void test_pop_from_non_empty_stack_value_is_correct(void) {
  Stack *stack = create_stack();
  push(stack, 8);
  push(stack, 7);
  int value;
  pop(stack, &value);

  assert (7 == value && "popped value should be 7");
  destroy_stack(stack);
}

static void test_pop_from_stack_with_one_node_size_is_correct(void) {
  Stack *stack = create_stack();
  push(stack, 8);
  int value;
  pop(stack, &value);

  assert (0 == size(stack) && "stack size after pop should be 0");
  destroy_stack(stack);
}

static void test_pop_from_stack_with_one_node_value_is_correct(void) {
  Stack *stack = create_stack();
  push(stack, 8);
  int value;
  pop(stack, &value);

  assert (8 == value && "popped value should be 8");
  destroy_stack(stack);
}

static void test_pop_from_empty_stack_size_is_zero(void) {
  Stack *stack = create_stack();
  int value;
  pop(stack, &value);

  assert (0 == size(stack) && "stack size should be 0");
  destroy_stack(stack);
}

int main (void) {
  test_new_stack_head_points_to_null();
  test_new_stack_next_points_to_null();
  test_new_stack_is_empty_returns_true();
  test_new_stack_size_is_zero();
  test_push_onto_empty_stack_creates_node_with_value();
  test_push_onto_empty_stack_size_is_one();
  test_push_onto_non_empty_stack_size_is_correct();
  test_non_empty_stack_is_empty_returns_false();
  test_pop_from_non_empty_stack_size_is_correct();
  test_pop_from_non_empty_stack_value_is_correct();
  test_pop_from_stack_with_one_node_size_is_correct();
  test_pop_from_stack_with_one_node_value_is_correct();
  test_pop_from_empty_stack_size_is_zero();
}

