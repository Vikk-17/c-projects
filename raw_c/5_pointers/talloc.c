#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

// returns pointer or 0 in case of error
char *alloc(int n) {
    if(allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else  {
        return 0;
    }
}

void afree(char *p) {
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
