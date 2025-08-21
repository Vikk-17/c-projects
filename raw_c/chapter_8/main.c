// #include "syscall.h"
#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>
/*
 * Copy input to ouput, BUFSIZ = 8192
 * */
void inputToOutput() {
    char buffer[BUFSIZ]; 
    int n;

    while((n = read(0, buffer, BUFSIZ)) > 0) {
        write(1, buffer, n);
    }
}

// unbuffered single character input using getchar
int getchar(void) {
    char c;
    return (read(0, &c, 1) == 1 ? (unsigned char) c : EOF);
}

int bufferedGetchar() {
    static char buf[BUFSIZ];
    static int n = 0;
    static char *bufp = buf;

    if(n == 0) {
        n = read(0, buf, sizeof(buf));
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

int main() {
    
    return 0;
}
