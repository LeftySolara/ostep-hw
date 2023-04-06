/**
 * OSTEP Chapter 5 - Question 7
 *
 * Write a program that creates a child process, and then
 * in the child closes standard output (`STDOUT_FILENO`).
 * What happens if the child calls `printf()` to print some
 * output after closing the descriptor?
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error forking.\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(STDOUT_FILENO);
        printf("Printing to standard output...\n");
    }
    else {
        wait(&pid);
        printf("Parent process.\n");
    }

    return 0;
}

