#include<stdio.h>

int get_line(char *line, int maxline) {
    int i, c;
    for(i = 0; i<maxline && (c=getchar() != EOF) && c != '\n'; ++i)
        line[i] = c;
    if(c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

int main() {
    char line[] = "";
    int maxline = 20;
    // int len = get_line(line, maxline);
    // printf("%d\n\n", len);
    return 0;
}
