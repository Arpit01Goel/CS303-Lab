#include  <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include  <sys/types.h>
#include <unistd.h>   // for fork()
#include <sys/wait.h> // for wait()

void printAddress(int *x) {
    printf("address: %p \n", (void*)&x);
}
int main() {
    int a=0;
    printAddress(&a);
    int pid = fork();
    while (1) {
        if (pid>0) {

            printf("parent process:: address: %p and val: %d \n", (void*)&a, ++a );

        }
        else {
 printf("child process:: address: %p and val: %d \n", (void*)&a, ++a );
           
        }
    }

}

//use ./a.out & ./a.out & ./a.out in terminal for part A