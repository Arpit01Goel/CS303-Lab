#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// unistd provides unix like system apis like read, write, close, fork, exec functions

void printOneFile(char * filename) {
    int fd = open(filename, O_RDONLY);
    if (fd<0) {
        //error case 
        printf("error in opening");
        return;
    }
    char buf[1024];
    ssize_t bytes;
    while ((bytes= read(fd, buf, sizeof(buf))) > 0) {
        write(STDOUT_FILENO, buf, bytes);
    }
    close(fd);
    
}

int main(int argc, char* argv[], char* envp[]) {

    for (int i=1;i<argc;i++) {
        printOneFile(argv[i]);
    }
    return 0;
}