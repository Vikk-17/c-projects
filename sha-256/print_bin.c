#include<stdio.h>

int main(int argc, char *argv[]) {
    if(argc <= 1) printf("Invalid usage\n\n");
    char *c = argv[1];
    // char *itoa(int value, char *str, int base);
    printf("%s", *c);
    return 0;
}
