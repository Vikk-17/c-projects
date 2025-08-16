#include<unistd.h>
#include<stdio.h>

/* malloc: allocates size bytes of memory and returns a pointer to the allocated memory */
void *malloc(size_t size) {
    void *block;
    block = sbrk(size);
    if(block == (void*) -1) return NULL;
    return block;
}
