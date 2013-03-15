#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <board.h>

static void test_create_board(void) {
  int *new_board = create_board();
  assert (0 == new_board[0] && "board value at 1,1 should be 0");
  assert (0 == new_board[15] && "board value at 4,4 should be 0");
}

static void test_get_index(void) {
  int index = get_index_from_coords(1, 1);
  assert (0 == index && "index at 1,1 should be 0");
  index = get_index_from_coords(4, 4);
  assert (15 == index && "index at 4,4 should be 15");
}

static void test_get_coords(void) {
  int x, y;
  get_coords_from_index(0, &x, &y);
  assert (1 == x && "x coord at index 0 should be 1");
  assert (1 == y && "y coord at index 0 should be 1");
  get_coords_from_index(15, &x, &y);
  assert (4 == x && "x coord at index 0 should be 4");
  assert (4 == y && "y coord at index 0 should be 4");
}

static void test_clear_board(void) {
  int *new_board = create_board();
  make_move(new_board, 'x', 1, 1);
  clear_board(new_board);

  for (int i = 0; i < NUM_ELEMENTS; i++) {
    assert (0 == new_board[i] && "board value should be 0");
  }
}

static void test_make_move(void) {
  int *new_board = create_board();

  int valid = make_move(new_board, 'x', 1, 1);
  assert (1 == valid && "move should be valid");
  assert ('x' == new_board[0] && "board value at 1,1 should be 'x'");

  valid = make_move(new_board, 'o', 1, 1);
  assert (0 == valid && "move should be invalid");
  assert ('x' == new_board[0] && "board value at 1,1 should be 'x'");

  valid = make_move(new_board, 'o', 4, 4);
  assert (1 == valid && "move should be valid");
  assert ('o' == new_board[15] && "board value at 4,4 should be 'o'");

  valid = make_move(new_board, 'o', 5, 5);
  assert (0 == valid && "move should be invalid");
}

static void test_check_winner_on_row(void) {
  int *new_board = create_board();

  clear_board(new_board);
  make_move(new_board, 'x', 1, 1);
  make_move(new_board, 'x', 1, 2);
  make_move(new_board, 'x', 1, 3);
  make_move(new_board, 'x', 1, 4);

  int winner = check_winner(new_board);
  assert ('x' == winner && "'x' should be the winner");

  clear_board(new_board);
  make_move(new_board, 'o', 4, 1);
  make_move(new_board, 'o', 4, 2);
  make_move(new_board, 'o', 4, 3);
  make_move(new_board, 'o', 4, 4);

  winner = check_winner(new_board);
  assert ('o' == winner && "'o' should be the winner");
}

static void test_check_winner_on_col(void) {
  int *new_board = create_board();

  clear_board(new_board);
  make_move(new_board, 'x', 1, 1);
  make_move(new_board, 'x', 2, 1);
  make_move(new_board, 'x', 3, 1);
  make_move(new_board, 'x', 4, 1);

  int winner = check_winner(new_board);
  assert ('x' == winner && "'x' should be the winner");

  clear_board(new_board);
  make_move(new_board, 'o', 1, 4);
  make_move(new_board, 'o', 2, 4);
  make_move(new_board, 'o', 3, 4);
  make_move(new_board, 'o', 4, 4);

  winner = check_winner(new_board);
  assert ('o' == winner && "'o' should be the winner");
}

static void test_check_winner_on_diag(void) {
  int *new_board = create_board();

  clear_board(new_board);
  make_move(new_board, 'x', 1, 1);
  make_move(new_board, 'x', 2, 2);
  make_move(new_board, 'x', 3, 3);
  make_move(new_board, 'x', 4, 4);

  int winner = check_winner(new_board);
  assert ('x' == winner && "'x' should be the winner");

  clear_board(new_board);
  make_move(new_board, 'o', 1, 4);
  make_move(new_board, 'o', 2, 3);
  make_move(new_board, 'o', 3, 2);
  make_move(new_board, 'o', 4, 1);

  winner = check_winner(new_board);
  assert ('o' == winner && "'o' should be the winner");
}

int main (void) {
  test_create_board();
  test_get_index();
  test_get_coords();
  test_clear_board();
  test_make_move();
  test_check_winner_on_row();
  test_check_winner_on_col();
  test_check_winner_on_diag();
}

