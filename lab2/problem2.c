#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[], char* envp[]) {
    if (argc<2) {
        printf("invalid number of arguments! Please give the filename \n");
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    // printf("file pointer is %d \n", fd);
    if (fd<0) {
        perror("open");
        return 1;
    }
    off_t size = lseek(fd, 0, SEEK_END);
    printf("File size in bytes: %ld \n", size);

    struct stat st;
    if (stat(argv[1], &st) < 0) {
        perror("stat");
        close(fd);
        return 1;
    }
    
    long block_size = st.st_blksize/8; // div by 8 to convert bits to bytes
    long num_blocks = (size+ block_size -1) / block_size;  // equivlent to ceil
    printf("block size of this system is: %ld \n", block_size);
    printf("no of blocks assigned: %ld \n", num_blocks);
    close(fd);
    return 0;


}

// To test this file, use ./a.out problem1A.c