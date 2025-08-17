#include<unistd.h>
#include<stdio.h>
#include<pthread.h>

typedef char ALIGN[16];
union header {
    struct {
        size_t size;
        unsigned is_free;
        union header *next; // linked list
    } s;

    ALIGN stub; // to get the 16 bytes, the largest member size;
};

// alising
typedef union header header_t;

header_t *head, *tail;

/* To prevent two or more threads from concurrently accessing memory,
 * we will put a basic locking mechanism in place
 * Before every action on memory we have to acquire the lock, and once 
 * we are done we have to release the lock.
 * */
pthread_mutex_t global_malloc_lock;
/* total_size = header_size + size 
 * sbrk(total_size), header is internally managed, and kept private
 * ____________________________
 * |          |               |
 * |  header  | actual memory | --------> link to another block
 * |          |     block     |
 * ----------------------------
 * */

/* malloc: allocates size bytes of memory and returns a pointer to the allocated memory */
void *malloc(size_t size) {
    size_t total_size;
    void *block;
    header_t *header_block;
    if(!size) return NULL;
   
    // mutex lock
    pthread_mutex_lock(&global_malloc_lock);
    header_block = get_free_block(size); 
}

header_t *get_free_block(size_t size) {
    header_t *curr = head;
    while(curr) {
        if(curr->s.is_free && curr->s.size >= size) return curr;
        curr = curr->s.next;
    }
    return NULL;
}
