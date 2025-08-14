#include<stdio.h>

int tstrlen(char *s) {
    char *p = s;
    while(*p != '\0') p++;
    return p-s;
}

int main() {
    char arr[] = "carmack";

    int len = tstrlen(arr);

    printf("%d\n", len);
    return 0;
}
