#include <stdio.h>
#include <board.h>

int * create_board(void) {
  static int board[NUM_ELEMENTS];
  return board;
}

int get_index_from_coords(int x, int y) {
  return (x - 1) * SIDE_LENGTH + (y - 1);
}

void get_coords_from_index(int index, int *x, int *y) {
  *x = (index / SIDE_LENGTH) + 1;
  *y = (index % SIDE_LENGTH) + 1;
}

void clear_board(int *board) {
  for (int i = 0; i < NUM_ELEMENTS; i++) {
    board[i] = 0;
  }
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
  for (int i = 0; i < NUM_ELEMENTS; i++) {
    if ((i / SIDE_LENGTH) == ((i + 1) / SIDE_LENGTH)) {
      if (board[i] != board[i+1] || board[i] == 0) {
        winner_found = 0;
      }
    } else {
      if (winner_found == 1) {
        return board[i];
      } else {
        winner_found = 1;
      }
    }
  }

  winner_found = 1;
  for (int i = 0; i < NUM_ELEMENTS;) {
    if ((i / SIDE_LENGTH) < ((NUM_ELEMENTS / SIDE_LENGTH) - 1)) {
      if (board[i] != board[i+SIDE_LENGTH] || board[i] == 0) {
        winner_found = 0;
      }
    } else {
      if (winner_found == 1) {
        return board[i];
      } else {
        winner_found = 1;
      }
    }

    if (i < 15 && ((i + SIDE_LENGTH) / SIDE_LENGTH) == (NUM_ELEMENTS / SIDE_LENGTH)) {
      i = i - NUM_ELEMENTS + 1;
    }
    i = i + SIDE_LENGTH;
  }

  winner_found = 1;
  for (int i = 0; i < (NUM_ELEMENTS - 1); i = i + SIDE_LENGTH + 1) {
    if (board[i] != board[i+SIDE_LENGTH+1] || board[i] == 0) {
      winner_found = 0;
    }
  }
  if (winner_found == 1) {
    return board[0];
  }

  winner_found = 1;
  for (int i = SIDE_LENGTH - 1; i < (NUM_ELEMENTS - SIDE_LENGTH); i = i + SIDE_LENGTH - 1) {
    if (board[i] != board[i+SIDE_LENGTH-1] || board[i] == 0) {
      winner_found = 0;
    }
  }
  if (winner_found == 1) {
    return board[SIDE_LENGTH-1];
  }


  return 0;
}


