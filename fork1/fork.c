/* see http://stackoverflow.com/questions/9994530/warning-implicit-declaration-of-function-kill */
#define _POSIX_SOURCE
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

/* see http://stackoverflow.com/questions/6501522/how-to-kill-a-child-process-by-the-parent-process */

int var_glb;

int main() {
  pid_t pid;

  pid = fork();

  printf("The process pid = %d\n", pid);

  if (pid < 0) {
    fprintf(stderr, "Fork failed\n");
    return 1;
  } else if (pid == 0) {
    printf("The Child Process\n");
    printf("The process pid = %d\n", getpid());
    printf("The parent process pid = %d\n", getppid());
  } else {
    // wait(NULL);
    kill(pid, SIGTERM);
    printf("Child complete\n");
    printf("The Parent process\n");
    printf("The process pid = %d\n", getpid());
    printf("The parent process pid = %d\n", getppid());
  }

  return 0;
}
