# The Unix System Interface

### File Descriptors
- In the UNIX operating system, all input and output is done by reading or writing files
- All peripheral devices, even keyboard and screen, are files in the file-system.
- That means a single homogenous interface handles all communication between program and peripheral devices.
- The system checks right:
    - Does the file exist?
    - Do we have permission to access it?
- If all goes well, it returns to the program a small non-negative filinteger called a `file descriptor`.
- When the command interpreter (the shell) runs a program, three files are open, with file descriptors 0, 1, 2, called the standard input, standard output, and the standard error.
- Normally, file descriptor 2 remains attached to the screen, so error messages can go there.
- In all the cases file assignments are changed by the shell, not by the program.
- The program does not know where its input comes from nor where its output goes, so long as it uses file 0 for input and 2 for output.


### Low Level I/O - Read and Write

```c 
/*
int fd => file descriptor
char *buf => read/write data from/to
int n => number of bytes to be transferred.
*/
int n_read = read(int fd, char *buf, int n);
int n_writen = write(int fd, char *buf, int n);

// Each call returns a count of the number of bytes transferred.
// Return value 0 means end of file and -1 means error of some sort.
```

