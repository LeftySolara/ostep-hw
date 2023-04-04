/**
 * OSTEP Chapter 5 - Question 1
 *
 * Write a program that calls `fork()`. Before calling `fork()`,
 * have the main process access a variable (e.g., `x`) and set
 * its value to something (e.g., `100`). What value is the variable
 * in the child process? What happens to the variable when both the
 * child and parent change the value of `x`?
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    int pid = fork();

    if (pid == -1) {
        printf("Error forking.\n");
        exit(1);
    }

    x = 50;
    if (pid == 0) { /* Child process */
        printf("Child process: value of x is %d.\n", x);
    }
    else {
        printf("Parent process: value of x is %d.\n", x);
    }

    return 0;
}
