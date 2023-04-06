# Process API - Homework (Code)

In this homework, you'll gain some familiarity with the process management APIs about which you just read.

## Questions

### Question 1

**Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable (e.g., `x`) and set its value to something (e.g., `100`). What value is the variable in the child process? What happens to the variable when both the child and parent change the value of `x`?**

The value of `x` in the child process is initially the same as in the parent process. Because each process has its own copy of the variable, each copy will (separately) have whatever new value is assigned to it if both the parent and child processes modify it.

[Code](./1.c)

### Question 2

**Write a program that opens a file (with the `open()` system call) and then calls `fork()` to create a new process. Can both the child and parent access the file discriptor returned by `open()`? What happens when they are writing to the file concurrently?**

Both the parent and child processes can access the file descriptor. When writing to the file concurrently, the child is blocked from writing until the parent is finished.

[Code](./2.c)

### Question 3

**Write another program using `fork()`. The child process should print "hello"; the parent process should print "goodbye". You should try to ensure that the child process always prints first; can you do this _without_ calling `wait()` in the parent?**

[Code](./3.c)

### Question 4

**Write a program that calls `fork()` and then calls some form of `exec()` to run the program `/bin/ls`. See if you can try all of the variants of `exec()`, including `execl()`, `execle()`, `execlp`, `execv`, `execvp`, and `execvpe()`. Why do you think there are so many variants of the same basic call?**

There are many versions of `exec()` so that it's flexible depending on what information you have. For example, some of the variants take an `envion` argument to set the program environment while others do not. This is useful when the user doesn't care about a specific environment setup.

[Code](./4.c)

### Question 5

**Now write a program that uses `wait()` to wait for the child process to finish in the parent. What does `wait()` return? What happpens if you use `wait()` in the child?**

The `wait()` function returns the PID of the child whose status changed. If `wait()` is used in the child process, then it waits for the parent process to complete before continuing.

[Code](./5.c)

### Question 6

**Write a slight modification of the previous program, this time using `waitpid()` instead of `wait()`. When would `waitpid()` be useful?**

`waitpid()` would be useful when we want to wait for a specific child and get extra information back about how its status changed.

[Code](./6.c)

### Question 7

**Write a program that creates a child process, and then in the child closes standard output (`STDOUT_FILENO`). What happens if the child calls `printf()` to print some output after closing the descriptor?**

If the child calls `printf()` after closing the descriptor, then the writing doesn't work and no output is displayed.

[Code](./7.c)

### Question 8

**Write a program that creates two children, and connects the standard output of one to the standard input of the other, using the `pipe()` system call.**

[Code](./8.c)
