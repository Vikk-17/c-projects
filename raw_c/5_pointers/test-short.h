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

