#include <stdio.h>
#include <stack.h> 

#define STACK_SIZE 10

int main() {
  int stack[STACK_SIZE];

  printf("A stack of maximum %lu elements\n", sizeof(stack)/sizeof(int));

  return 0;
}
