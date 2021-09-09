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
