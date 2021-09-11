/*
Write a program that calls fork() and then calls some form of
exec() to run the program /bin/ls. See if you can try all of the
variants of exec(), including (on Linux) execl(), execle(),
execlp(), execv(), execvp(), and execvpe(). Why do
you think there are so many variants of the same basic call?
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
        printf("CHILD PROCESS\n");
        char *env_list[] = {
            "SHELL=/bin/zsh",
            "EDITOR=vim",
            NULL
        };

        char *const args[] = {
            "/bin/ls",
            "-l",
            "-a",
            "--color=auto",
            (char *) NULL
        };

        /* int exec_rc = execl("/bin/ls", "/bin/ls", "-l", "-a", "--color=auto", (char *) NULL); */
        /* int exec_rc = execle("/bin/ls", "/bin/ls", "-l", "-a", "--color=auto", (char *) NULL, env_list); */
        /* int exec_rc = execlp("ls", "ls", "-l", "-a", "--color=auto", (char *) NULL); */
        /* int exec_rc = execv("/bin/ls", args); */
        /* int exec_rc = execvp("ls", args); */
        int exec_rc = execvpe("ls", args, env_list);

        if (exec_rc == -1) {
            fprintf(stderr, "Error executing program. Aborting...\n");
        }
    }
    else {
        int wstatus;
        do {
            waitpid(rc, &wstatus, WUNTRACED);
        } while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
        printf("PARENT PROCESS\n");

    }
    return 0;
}
