#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h> 

int main() {
    char fn[10]; 
    char *buff;
    int fd, n;

    printf("Enter the filename: ");
    scanf("%s", fn);

    getchar();

    printf("\nEnter text: \n");
    buff = (char *)malloc(100); 
    fgets(buff, 100, stdin);

    fd = open(fn, O_CREAT | O_WRONLY, 0644); 

    

    n = write(fd, buff, strlen(buff));
    close(fd);
    free(buff); 

    return 0;
}

