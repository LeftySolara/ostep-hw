/*
Now write a program that uses wait() to wait for the child process
to finish in the parent. What does wait() return? What happens if
you use wait() in the child?
*/

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Error forking\n");
    }
    else if (rc == 0) {
        printf("CHILD PROCESS. Waiting...\n");
        int chstatus;
        wait(&chstatus);
        printf("Child status: %d\n", chstatus);
    }
    else {
        printf("PARENT PROCESS. Waiting...\n");
        int wstatus;
        wait(&wstatus);
        printf("Patent status: %d\n", wstatus);
    }

    return 0;
}
