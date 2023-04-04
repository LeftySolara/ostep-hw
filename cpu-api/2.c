/**
 * OSTEP Chapter 5 - Question 2
 *
 * Write a program that opens a file (with the `open()` system call)
 * and then calls `fork()` to create a new process. Can both the child
 * and parent access the file discriptor returned by `open()`?
 * What happens when they are writing to the file concurrently?
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = open("testfile.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);

    int pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error forking.\n");
        exit(EXIT_FAILURE);
    }

    char *line;
    int bytes_written;
    if (pid == 0) { /* Child process */
        line = "This is the child process\n";
        bytes_written = write(fd, line, strlen(line) + 1);
    }
    else { /* Parent process. */
        line = "This is the parent process\n";
        bytes_written = write(fd, line, strlen(line) + 1);
    }

    if (bytes_written == -1) {
        fprintf(stderr, "Error writing the following line: %s", line);
    }

    close(fd);

    return 0;
}
