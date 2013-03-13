#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int var_glb;

int main() {
  pid_t pid;
  int var_lcl = 0;

  pid = fork();

  printf("The process pid = %d\n", pid);

  if (pid < 0) {
    fprintf(stderr, "Fork failed\n");
    return 1;
  } else if (pid == 0) {
    // execlp("/bin/ls", "ls", NULL);
    var_lcl++;
    var_glb++;
    printf("\n Child Process :: var_lcl = [%d], var_glb[%d]\n", var_lcl, var_glb);
    printf("The process pid = %d\n", getpid());
    printf("The parent process pid = %d\n", getppid());
  } else {
    wait(NULL);
    printf("Child complete\n");
    var_lcl = 10;
    var_glb = 20;
    printf("\n Parent process :: var_lcl = [%d], var_glb[%d]\n", var_lcl, var_glb);
    printf("The process pid = %d\n", getpid());
    printf("The parent process pid = %d\n", getppid());
  }

  return 0;
}
