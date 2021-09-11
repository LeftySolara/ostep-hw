# Questions

*Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to some-
thing (e.g., 100). What value is the variable in the child process?
What happens to the variable when both the child and parent change
the value of x?*

The value of the variable in the child process is the same as in
the parent process. If both the child and parent processes modify
the variable, then its value will be what was set in each process,
as both processes have their own copy.

---

*Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process. Can both the child
and parent access the file descriptor returned by open()? What
happens when they are writing to the file concurrently, i.e., at the
same time?*

The child and parent processes can both access the file descriptor.
When writing concurrently, the process that began writing second waits
for the other process to finish before doing its own write.

---

*Write another program using fork(). The child process should
print “hello”; the parent process should print “goodbye”. You should
try to ensure that the child process always prints first; can you do
this without calling wait() in the parent?*

You can achieve the same result by doing the printing before
calling `fork()`.

---

*Write a program that calls fork() and then calls some form of
exec() to run the program /bin/ls. See if you can try all of the
variants of exec(), including (on Linux) execl(), execle(),
execlp(), execv(), execvp(), and execvpe(). Why do
you think there are so many variants of the same basic call?*

Having the variants is useful for specifying parameters and environment
variables that are different from the defautls of the system.

---

*Now write a program that uses wait() to wait for the child process
to finish in the parent. What does wait() return? What happens if
you use wait() in the child?*

On success, `wait()` returns the PID of the terminated child. On failure,
it returns -1.

---

*Write a slight modification of the previous program, this time us-
ing waitpid() instead of wait(). When would waitpid() be
useful?*

`waitpid()` would be useful when a process has multiple children.

---

*Write a program that creates a child process, and then in the child
closes standard output (STDOUT FILENO). What happens if the child
calls printf() to print some output after closing the descriptor?*

After the child closes standard output, any attempt to write to it with `printf()`
fails and nothing is printed.

---

*Write a program that creates two children, and connects the stan-
dard output of one to the standard input of the other, using the
pipe() system call.*
