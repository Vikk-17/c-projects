/*
 * Write a program that converts upper case to lower or lower case to upper, 
 * depending on the name it is invoked with, as found in argv[0].
*/

// ./a.out lower/upper <any thing> 

#include<stdio.h>
#include<ctype.h>
#include<string.h>


int main(int argc, char **argv) {
    // char* str = argv[2];
    int c;
    if(argc < 2) {
        printf("Invalid command!\n");
    }

    if(strcmp(argv[1], "lower") == 0) {
        while((c = getchar()) != EOF) {
            putchar(tolower(c));
        }
    }
    else if(strcmp(argv[1], "upper") == 0) {
        while((c = getchar()) != EOF) {
            putchar(toupper(c));
        }
    }
    return 0;
}
