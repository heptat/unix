#include <stdio.h>

int main() {
  int c = 0;
  // this works but it's not really acceptable behaviour and you can't use
  // fileno with c99
  // if (isatty(fileno(stdin)) != 1) {
  while ((c = fgetc(stdin)) != EOF) {
    fputc(c, stdout);
  }
  // }
}
