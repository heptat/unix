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

static void test_check_winner(void) {
  int *new_board = create_board();

  make_move(new_board, 'x', 1, 1);
  make_move(new_board, 'x', 1, 2);
  make_move(new_board, 'x', 1, 3);
  make_move(new_board, 'x', 1, 4);

  int winner = check_winner(new_board);
  assert ('x' == winner && "'x' should be the winner");
}

int main (void) {
  test_create_board();
  test_make_move();
  test_check_winner();
}

