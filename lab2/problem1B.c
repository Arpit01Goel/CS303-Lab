#include <stdio.h>

int main(int argc, char* argv[], char* envp[]) {
    if (argc < 3 ) return -1;
    if (rename(argv[1], argv[2])!=0) {
        perror("mv");
        return 1;
    }
    return 0;
}