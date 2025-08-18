#include  <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include  <sys/types.h>
#include <unistd.h>   // for fork()
#include <sys/wait.h> // for wait()

int main() {
    int pid = fork();
    if (pid<0) exit(1);
    if (pid>0) {
        //parent
        int status;
        int completed_pid = wait(&status);
        printf("pid of child: %d \n", completed_pid);
        printf("state in which terminated: %d \n", status);
        printf("state in which terminated: %#x \n", status);

        
    }else {
        int a = 0;
        for (int i=0;i<1000;i++) a++;
        exit(1);
    }
}