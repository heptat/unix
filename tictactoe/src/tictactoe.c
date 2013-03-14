#include <stdio.h>
#include <board.h>

int main() {
  int *board = create_board();

  check_winner(board);

  return 0;
}
