#include  <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include  <sys/types.h>
#include <unistd.h>   // for fork()
#include <sys/wait.h> // for wait()

int main() {
    int pid = fork();
    fork();
    printf("%d %d \n", getpid(), getppid());
}