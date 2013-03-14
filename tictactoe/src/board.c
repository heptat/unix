#include <board.h>

int * create_board(void) {
  static int board[NUM_ELEMENTS];
  return board;
}

int make_move(int *board, int move, int row, int col) {

  int element = (row - 1) * SIDE_LENGTH + (col - 1);

  if (element >= NUM_ELEMENTS) {
    return 0;
  }

  if (board[element] == 0) {
    board[element] = move;
  } else {
    return 0;
  }
  return 1;
}

int check_winner(int *board) {

  int winner_found = 1;
  int winner;
  for (int i = 0; i < NUM_ELEMENTS; i++) {
    if ((i / SIDE_LENGTH) == ((i + 1) / SIDE_LENGTH)) {
      if (board[i] != board[i+1]) {
        return 0;
      }
    }
  }

  if (winner_found == 1) {
    winner = board[0];
    return winner;
  }
  return 0;
}
