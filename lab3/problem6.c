#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>   // for fork()
#include <sys/wait.h> // for wait()
#include <fcntl.h>

int main()
{
    for (int i = 0; i < 10; i++)
    {
        fork();
        
    }
    
    printf("The process with the pid= %d \n", getpid());
    int fd = open("process_management.txt", O_WRONLY | O_CREAT | O_APPEND , 0644);
    
    char buff[5000];
    int len = snprintf(buff, sizeof(buff)+4,"%d \n", getpid());
    //  const char *msg = "Hello from open()!\n";
    write(fd, buff, len);
    close(fd);
    return 0;
}
