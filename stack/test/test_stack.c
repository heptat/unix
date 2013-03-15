#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stack.h>

static void test_new_stack_has_correct_length(void) {
  Stack *stack = create_stack(3);

  assert (3 == stack->length && "stack length should be 3");
  free(stack);
}

static void test_new_stack_head_is_negative(void) {
  Stack *stack = create_stack(3);

  assert (0 > stack->head && "stack head should be -1");
  free(stack);
}

static void test_new_stack_is_empty_is_true(void) {
  Stack *stack = create_stack(3);

  assert (TRUE == is_empty(stack) && "is_empty should return TRUE");
  free(stack);
}

static void test_non_empty_stack_is_empty_is_false(void) {
  Stack *stack = create_stack(3);
  push(stack, 8);

  assert (FALSE == is_empty(stack) && "is_empty should return FALSE");
  free(stack);
}

static void test_push_onto_empty_stack_sets_head_to_first_element(void) {
  Stack *stack = create_stack(3);
  push(stack, 8);

  assert (0 == stack->head && "stack head should be 0");
  free(stack);
}

static void test_push_onto_non_full_stack_succeeds(void) {
  Stack *stack = create_stack(3);
  BOOL pushed = push(stack, 8);

  assert (TRUE == pushed && "push should succeed");
  free(stack);
}

static void test_push_onto_non_full_stack_stores_value(void) {
  Stack *stack = create_stack(3);
  push(stack, 8);

  assert (8 == stack->values[stack->head] && "pushed value should be 8");
  free(stack);
}

static void test_push_onto_full_stack_fails(void) {
  Stack *stack = create_stack(3);
  push(stack, 8);
  push(stack, 7);
  push(stack, 6);
  BOOL pushed = push(stack, 5);

  assert (FALSE == pushed && "push should fail");
  free(stack);
}

static void test_pop_from_empty_stack_fails(void) {
  Stack *stack = create_stack(3);
  BOOL success;
  pop(stack, &success);

  assert (FALSE == success && "pop should fail");
  free(stack);
}

static void test_pop_from_non_empty_stack_succeeds(void) {
  Stack *stack = create_stack(3);
  push(stack, 8);
  BOOL success;
  pop(stack, &success);

  assert (TRUE == success && "pop should succeed");
  free(stack);
}

static void test_pop_from_stack_with_one_element_sets_head_to_negative(void) {
  Stack *stack = create_stack(3);
  push(stack, 8);
  BOOL success;
  pop(stack, &success);

  assert (0 > stack->head && "pop should set head to negative");
  free(stack);
}

static void test_pop_from_non_empty_stack_returns_correct_value(void) {
  Stack *stack = create_stack(3);
  push(stack, 8);
  BOOL success;
  int value = pop(stack, &success);

  assert (8 == value && "popped value should be 8");
  free(stack);
}

static void test_empty_stack_peek_shows_zero(void) {
  Stack *stack = create_stack(3);
  int value = peek(stack);

  assert (0 == value && "peeked value should be 0");
  free(stack);
}

static void test_non_empty_stack_peek_shows_correct_value(void) {
  Stack *stack = create_stack(3);
  push(stack, 8);
  int value = peek(stack);

  assert (8 == value && "peeked value should be 8");
  free(stack);
}

static void test_push_and_pop_to_and_from_stack(void) {
  Stack *stack = create_stack(3);

  push(stack, 8);
  assert (8 == peek(stack) && "stack value should be 8");
  assert (0 == stack->head && "stack head should be 0");

  push(stack, 7);
  assert (7 == peek(stack) && "stack value should be 7");
  assert (1 == stack->head && "stack head should be 1");

  push(stack, 6);
  assert (6 == peek(stack) && "stack value should be 6");
  assert (2 == stack->head && "stack head should be 2");

  push(stack, 5);
  assert (6 == peek(stack) && "stack value should be 6");
  assert (2 == stack->head && "stack head should be 2");

  BOOL success;
  int value = pop(stack, &success);
  assert (6 == value && "stack value should be 6");
  assert (1 == stack->head && "stack head should be 1");

  value = pop(stack, &success);
  assert (7 == value && "stack value should be 7");
  assert (0 == stack->head && "stack head should be 0");

  value = pop(stack, &success);
  assert (8 == value && "stack value should be 8");
  assert (0 > stack->head && "stack head should be 0");

  value = pop(stack, &success);
  assert (0 > stack->head && "stack head should be 0");
  free(stack);
}

int main (void) {
  test_new_stack_has_correct_length();
  test_new_stack_head_is_negative();
  test_new_stack_is_empty_is_true();
  test_non_empty_stack_is_empty_is_false();
  test_push_onto_empty_stack_sets_head_to_first_element();
  test_push_onto_non_full_stack_succeeds();
  test_push_onto_non_full_stack_stores_value();
  test_push_onto_full_stack_fails();
  test_pop_from_empty_stack_fails();
  test_pop_from_non_empty_stack_succeeds();
  test_pop_from_stack_with_one_element_sets_head_to_negative();
  test_pop_from_non_empty_stack_returns_correct_value();
  test_empty_stack_peek_shows_zero();
  test_non_empty_stack_peek_shows_correct_value();
  test_push_and_pop_to_and_from_stack();
}

