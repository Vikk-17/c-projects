/*  
 *  strcpy: copy t to s; only the pointers not the content
 */
void strcpy1(char *s, char *t) {
    int i = 0;
    while((s[i] = t[i]) != '\0') i++;
}
void strcpy2(char *s, char *t) {
    int i = 0;
    while((*s = *t) != '\0') {
        s++, t++;
    }
}
void strcpy2v2(char *s, char *t) {
    int i = 0;
    while((*s++ = *t++) != '\0') {
        ;
    }
}
void strcpy2v3(char *s, char *t) {
    while((*s++ = *t++)) {
        ;
    }
}

int strcmp(char *s, char *t) {
    int i;
    for(i = 0; s[i] == t[i]; i++)
        if(s[i] == '\0') return 0;
    return s[i] - t[i];
}
int strcmp1(char *s, char *t) {
    for(; *s == *t; s++, t++)
        if(*s == '\0') return 0;
    return *s - *t;
}
