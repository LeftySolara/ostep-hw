/*
Write a program that creates two children, and connects the stan-
dard output of one to the standard input of the other, using the
pipe() system call.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int fd[2];
    int nbytes;
    pid_t childpid;

    char string[] = "Hello world\n";
    char readbuffer[80];

    pipe(fd);

    if ((childpid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    if (childpid == 0) {
        /* Child closes input side of pipe */
        close(fd[0]);

        /* Send "string" through the output side of the pipe */
        write(fd[1], string, (strlen(string)+1));
        exit(0);
    }
    else {
        /* Parent closes output side of pipe */
        close(fd[1]);

        /* Read in a string from the pipe */
        nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
        printf("Received string: %s", readbuffer);
    }

    return 0;
}
