/**
 * OSTEP Chapter 5 - Question 6
 *
 * Write a slight modification of the previous program,
 * this time using `waitpid()` instead of `wait()`.
 * When would `waitpid()` be useful?
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int *wstatus = NULL;
    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error forking.\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        waitpid(pid, wstatus, WUNTRACED);
        printf("Child process\n");
    }
    else {
        printf("Parent process\n");
    }

    return 0;
}
