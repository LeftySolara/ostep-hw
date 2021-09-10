/*
Write another program using fork(). The child process should
print “hello”; the parent process should print “goodbye”. You should
try to ensure that the child process always prints first; can you do
this without calling wait() in the parent?
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Error forking\n");
    }
    else if (rc == 0) {    /* child process */
        printf("hello\n");
    }
    else {    /* parent process */
        int wstatus;
        do {
            waitpid(rc, &wstatus, WUNTRACED);
        } while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
        printf("goodbye\n");
    }
    return 0;
}
