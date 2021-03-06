/*
Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to some-
thing (e.g., 100). What value is the variable in the child process?
What happens to the variable when both the child and parent change
the value of x?
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int x = 100;
    printf("x before forking: %d\n", x);

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Error forking");
        exit(1);
    }
    else if (rc == 0) {  // child process
        x = 50;
        printf("x in the child process: %d\n", x);
    }
    else {  // parent process
        x = 2;
        printf("x in the parent process: %d\n", x);
    }
    return 0;
}
