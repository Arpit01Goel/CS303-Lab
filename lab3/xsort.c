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
        // Child: launch xterm and run sort1
        execlp("xterm", "xterm", "-hold", "-e", "./sort1", argv[1], (char*)NULL);
        perror("execlp failed"); // Only runs if execlp fails
        exit(1);
    } else {
        // Parent: wait for child
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}
