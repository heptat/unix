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
  push(stack, 5);

  assert (5 == stack->head->value && "stack->head->value should be 5");
  destroy_stack(stack);
}

static void test_push_onto_empty_stack_size_is_one(void) {
  Stack *stack = create_stack();
  push(stack, 5);

  assert (1 == size(stack) && "stack size after push should be 1");
  destroy_stack(stack);
}

static void test_push_onto_non_empty_stack_size_is_correct(void) {
  Stack *stack = create_stack();
  push(stack, 5);
  push(stack, 4);

  assert (2 == size(stack) && "stack size after pushes should be 2");
  destroy_stack(stack);
}

static void test_non_empty_stack_is_empty_returns_false(void) {
  Stack *stack = create_stack();
  push(stack, 5);

  assert (FALSE == is_empty(stack) && "stack is_empty should return FALSE");
  destroy_stack(stack);
}

static void test_pop_from_non_empty_stack_size_is_correct(void) {
  Stack *stack = create_stack();
  push(stack, 5);
  push(stack, 4);
  Node *node = NULL;
  pop(stack, &node);

  assert (1 == size(stack) && "stack size after pop should be 1");
  free(node);
  destroy_stack(stack);
}

static void test_pop_from_non_empty_stack_value_is_correct(void) {
  Stack *stack = create_stack();
  push(stack, 5);
  push(stack, 4);
  Node *node = NULL;
  pop(stack, &node);

  assert (4 == node->value && "popped value should be 4");
  free(node);
  destroy_stack(stack);
}

static void test_pop_from_stack_with_one_node_size_is_correct(void) {
  Stack *stack = create_stack();
  push(stack, 5);
  Node *node = NULL;
  pop(stack, &node);

  assert (0 == size(stack) && "stack size after pop should be 0");
  free(node);
  destroy_stack(stack);
}

static void test_pop_from_stack_with_one_node_value_is_correct(void) {
  Stack *stack = create_stack();
  push(stack, 5);
  Node *node = NULL;
  pop(stack, &node);

  assert (5 == node->value && "popped value should be 5");
  free(node);
  destroy_stack(stack);
}

static void test_pop_from_empty_stack_node_is_null(void) {
  Stack *stack = create_stack();
  Node *node = NULL;
  pop(stack, &node);

  assert (NULL == node && "popped node should be NULL");
  free(node);
  destroy_stack(stack);
}

static void test_pop_from_empty_stack_size_is_zero(void) {
  Stack *stack = create_stack();
  Node *node = NULL;
  pop(stack, &node);

  assert (0 == size(stack) && "stack size should be 0");
  free(node);
  destroy_stack(stack);
}

static void test_empty_stack_peek(void) {
  Stack *stack = create_stack();

  // Note: You can't tell if a stack is empty by simply peeking, you also have
  // to call "is_empty"
  assert (0 == peek(stack) && "peek at empty stack should show 0");
  destroy_stack(stack);
}

static void test_stack_peek(void) {
  Stack *stack = create_stack();
  push(stack, 5);

  assert (5 == peek(stack) && "peek at stack should show 5");
  destroy_stack(stack);
}

static void test_stack_peek_after_pop(void) {
  Stack *stack = create_stack();
  push(stack, 4);
  push(stack, 5);
  Node *node;
  pop(stack, &node);

  assert (4 == peek(stack) && "peek at stack should show 4");
  free(node);
  destroy_stack(stack);
}

static void test_sort_stack_with_two_nodes_in_order(void) {
  Stack *stack = create_stack();
  push(stack, 1);
  push(stack, 2);

  sort(stack);

  Node *ptr = stack->next;
  assert (1 == ptr->value && "first stack value should be 1");
  ptr = ptr->next;
  assert (2 == ptr->value && "second stack value should be 2");
  destroy_stack(stack);
  ptr = NULL;
}

// static void test_sort_stack(void) {
//   Stack *stack = create_stack();
//   push(stack, 3);
//   push(stack, 2);
//   push(stack, 1);
// 
//   sort(stack);
// 
//   Node *ptr = stack->next;
//   assert (1 == ptr->value && "first stack value should be 1");
//   ptr = ptr->next;
//   assert (2 == ptr->value && "second stack value should be 2");
//   ptr = ptr->next;
//   assert (3 == ptr->value && "third stack value should be 3");
//   ptr = NULL;
//   destroy_stack(stack);
// }

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
  test_pop_from_empty_stack_node_is_null();
  test_pop_from_empty_stack_size_is_zero();
  test_empty_stack_peek();
  test_stack_peek();
  test_stack_peek_after_pop();
  test_sort_stack_with_two_nodes_in_order();
}


