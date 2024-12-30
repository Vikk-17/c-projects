# Socekt

### File descriptor
- When we open a file, the os creates an **entry** to represent that file and store the informationabout the opened file.
- So if there are 100 files opened in our os, there will be 100 entries in os (somewhere in kernel). These entries are represented by integers like ..., 100, 101, ...
- These entry number is file descriptor. So, it's an integer number that uniquely represents an opened file in the process. If our process opens 10 files then our process table will have 10 entries for file descriptors.
