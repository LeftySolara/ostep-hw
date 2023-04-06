
/**
 * OSTEP Chapter 5 - Question 5
 *
 * Now write a program that uses `wait()` to wait for the
 * child process to finish in the parent. What does `wait()`
 * return? What happpens if you use `wait()` in the child?
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
        wait(&pid);
        printf("Child process\n");
    }
    else {
        printf("Parent process\n");
    }

    return 0;
}
