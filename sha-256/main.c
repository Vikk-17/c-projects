#include<stdio.h>

int main() {
    char input[] = "hello world";
    int size = sizeof(input) / sizeof(input[0]);
    printf("%d\n", size);
    // convert it to binary and store it
    for(int i = 0; i<size; i++) {
        printf("%b\n", input[i]);
    }
    printf("\n\n");
    return 0;
}
