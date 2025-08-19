#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("invalid number of arguments\n");
        return 1;
    }

    int fd = open(argv[1], O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    off_t file_size = lseek(fd, 0, SEEK_END);
    if (file_size < 0) { perror("lseek"); close(fd); return 1; }

    off_t i = 0, j = 0;
    char c;

    while (j < file_size) {
        if (((j + 1) % 5) == 0) {  // skip every 5th byte
            j++;
            continue;
        }

        if (lseek(fd, j, SEEK_SET) < 0) { perror("lseek-read"); break; }
        if (read(fd, &c, 1) != 1) { perror("read"); break; }

        if (lseek(fd, i, SEEK_SET) < 0) { perror("lseek-write"); break; }
        if (write(fd, &c, 1) != 1) { perror("write"); break; }

        i++;
        j++;
    }

    if (ftruncate(fd, i) < 0) perror("ftruncate");

    close(fd);
    return 0;
}
