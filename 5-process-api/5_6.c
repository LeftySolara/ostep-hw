/*
Write a slight modification of the previous program, this time us-
ing waitpid() instead of wait(). When would waitpid() be
useful?
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
        waitpid(rc, &chstatus, WUNTRACED);
        printf("Child status: %d\n", chstatus);
    }
    else {
        printf("PARENT PROCESS. Waiting...\n");
        int wstatus;
        waitpid(rc, &wstatus, WUNTRACED);
        printf("Patent status: %d\n", wstatus);
    }

    return 0;
}
