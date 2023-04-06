/**
 * OSTEP Chapter 5 - Question 8
 *
 * Write a program that creates two children,
 * and connects the standard output of one to the
 * standard input of the other, using the `pipe()` system call.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pipefd[2];
    char buf;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t child1 = fork();
    if (child1 == -1) {
        fprintf(stderr, "Error forking.\n");
        exit(EXIT_FAILURE);
    }

    if (child1 == 0) {
        close(pipefd[1]);

        while (read(pipefd[0], &buf, 1) > 0) {
            write(STDIN_FILENO, &buf, 1);
        }
        write(STDIN_FILENO, "\n", 1);

        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    }
    else {
        pid_t child2 = fork();

        if (child2 == -1) {
            fprintf(stderr, "Error forking.\n");
        }

        if (child2 == 0) {
            const char *text = "Writing from child 2";
            close(pipefd[0]);
            write(pipefd[1], text, strlen(text));
            close(pipefd[1]);
            exit(EXIT_SUCCESS);
        }
        else {
            wait(NULL);
        }
    }

    return 0;
}
