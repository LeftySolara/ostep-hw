/*
Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process. Can both the child
and parent access the file descriptor returned by open()? What
happens when they are writing to the file concurrently, i.e., at the
same time?
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int fd = open("/tmp/testFile.txt", O_CREAT | O_WRONLY | O_TRUNC);
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Error forking\n");
        exit(1);
    }
    else if (rc == 0) {
        const char *text = "This is the child process\n";
        write(fd, text, strlen(text));
    }
    else {
        const char *text = "This is the parent process\n";
        write(fd, text, strlen(text));
    }

    return 0;
}
