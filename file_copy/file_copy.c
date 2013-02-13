#include <stdio.h>

int main(int argc, char *argv[]) {

  // only one arg allowed for filename
  if (argc != 2) {
    printf("usage: %s filename\n", argv[0]);
  } else {
    FILE *write_fp;
    if ((write_fp = fopen(argv[1], "w"))) {
      int c = 0;
      // grab each character that's passed in via stdin and write it to output
      // file
      while ((c = fgetc(stdin)) != EOF) {
        fprintf(write_fp, "%c", c);
      }
    }
  }
}
