#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

  int pid;
  int status;

  pid = fork();
  if (pid > 0)
  {
    printf("parent \n");
    pid = wait(&status);
    printf("%d \n", status);
    printf("parnet end \n");
  }

  else
  {
    printf("child \n");
    execlp("no_command", "casdifh", "fork-01.c", NULL);

    //child code 
    printf("here \n");
    exit(2);
  }
}
