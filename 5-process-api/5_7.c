/*
Write a program that creates a child process, and then in the child
closes standard output (STDOUT FILENO). What happens if the child
calls printf() to print some output after closing the descriptor?
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
        printf("CHILD PROCESS\n");
        close(STDOUT_FILENO);
        printf("Printing to stdout after closing...\n");
    }
    else {
        printf("PARENT PROCESS\n");
        int wstatus;
        waitpid(rc, &wstatus, WUNTRACED);
        printf("Child process terminated.\n");
    }

    return 0;
}
