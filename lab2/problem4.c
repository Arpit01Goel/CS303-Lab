#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[], char* envp) {
    if (argc<2) {
        printf("invalid number of arguments \n");
        return 1;
    }
    // open the file 
    int fd = open(argv[1], O_RDWR);
    // check if properly opened
    if (fd<0) {
        perror("open");
        return 1;
    }

    // store the size of file 
    off_t file_size = lseek(fd,0, SEEK_END);
    // iterate to del every 5th byte
    off_t i = 0, j=0;
    char c;
    while (j<file_size) {
        if (j+1 %5 == 0) {j++ ;continue;}
        lseek(fd, j, SEEK_SET);
        if (read(fd, &c, 1) !=1) break;
        lseek(fd, &c, SEEK_SET);
        write(fd, &c, 1);
        i++;j++;
    }
    ftruncate(fd,i);
    
    close(fd);
    return 0;
}