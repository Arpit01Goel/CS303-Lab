#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BLOCK_SIZE 512

int main(int argc, char* argv[], char* envp[]) {
    if (argc!=2) {
        printf("invalid number of arguments!");
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd<0) {
        perror("Open");
        return 1;
    }
    off_t size_lseek = lseek(fd, 0, SEEK_END);
    close(fd);

    int blocks_lseek = (size_lseek + BLOCK_SIZE -1) / BLOCK_SIZE ;

    struct stat st;
    if (stat(argv[1], &st) < 0) {
        perror("stat");
        return 1;
    }
    

}