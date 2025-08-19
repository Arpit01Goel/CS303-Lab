// xsort.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        
        execlp("xterm", "xterm", "-hold", "-e", "./sort1", argv[1], (char*)NULL);
        
        exit(1);
    } else {
        
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}
