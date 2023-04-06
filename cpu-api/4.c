
/**
 * OSTEP Chapter 5 - Question 4
 *
 * Write a program that calls `fork()` and then calls some form
 * of `exec()` to run the program `/bin/ls`. See if you can try
 * all of the variants of `exec()`, including `execl()`,
 * `execle()`, `execlp`, `execv`, `execvp`, and `execvpe()`.
 * Why do you think there are so many variants of the same basic call?
 *
 */
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static const char *ls = "/bin/ls";

char **environ;

void call_execl()
{
    execl(ls, "ls", "-l", "-h", (char *)NULL);
}

void call_execle()
{
    execle(ls, "ls", "-l", "-h", (char *)NULL, environ);
}

void call_execlp()
{
    execlp(ls, "ls", "-l", "-h", (char *)NULL);
}

void call_execv()
{
    char *args[] = {"ls", "-l", "-h", NULL};
    execv(ls, args);
}

void call_execvp()
{
    char *args[] = {"ls", "-l", "-h", NULL};
    execvp(ls, args);
}

void call_execvpe()
{
    char *const args[] = {"ls", "-l", "-h", NULL};
    char *const envp[] = {NULL};
    execvpe(ls, args, envp);
}

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error forking.\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { /* Child process */
        call_execvpe();
    }
    else { /* Parent process */
        wait(&pid);
    }
}
