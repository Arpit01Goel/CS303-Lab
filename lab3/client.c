#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>   // for fork()
#include <sys/wait.h> // for wait()
#include <fcntl.h>

int main()
{
    while (1)
    {
        char opr1[50], opr2[50]; // store numbers as strings
        char opr;

        printf("Enter the input (e.g. 5 + 3): ");
        scanf("%s %c %s", opr1, &opr, opr2);

        int pid = fork();
        if (pid < 0)
            exit(1);

        if (pid > 0)
        {
            int status;
            wait(&status);
            int exit_code = WEXITSTATUS(status);
            printf("Child exited with code: %d\n", exit_code);
        }
        else
        {
            // convert operator to string for execl
            char opr_str[2];
            opr_str[0] = opr;
            opr_str[1] = '\0';

            execl("./server", "server", opr1, opr_str, opr2, NULL);

            // if execl fails:
            perror("execl failed");
            exit(1);
        }
    }
}
