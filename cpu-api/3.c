/**
 * OSTEP Chapter 5 - Question 3
 *
 * Write another program using `fork()`. The child process should
 * print "hello"; the parent process should print "goodbye".
 * You should try to ensure that the child process always prints first;
 * can you do this _without_ calling `wait()` in the parent?
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void sig_handler(int signum)
{
    printf("goodbye\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    int parent_pid = getpid();
    int child_pid = fork();
    if (child_pid == -1) {
        fprintf(stderr, "Error forking.\n");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) { /* child process */
        printf("hello\n");
        kill(parent_pid, SIGCONT);
        exit(0);
    }
    else { /* parent process */
        signal(SIGCONT, sig_handler);
        pause();
    }

    return 0;
}
