#include<assert.h>
#include <stdlib.h>

/* Returns the integer in the range [0, n) */
int generate_random(long n) {
    if((n-1) == RAND_MAX) return rand(); 
    else {
        /*
         * Supporting larger values for n would reuires an even more elaborate
         * implemenation that combines muliple calls to rand()
         * */
        assert(n <= RAND_MAX);
        // chop off all of the values that would cause skew...
        int end = RAND_MAX / n; // truncate skew
        assert(end > 0);
        end *=n;
        /*
         * and ignore results from rand() that fall above the limit.
         * (worst case the loop condition should succed %50 of the time,
         * so we can except to bail out of this loop pretty quickly.)
         * */
        int r;
        while((r = rand()) >= end);
        return r%n;
    }
}

// int main() {
//     // int x = 7;
//     // x = 9;
//     // assert(x==7);
//     long x = randint(RAND_MAX);
//     printf("%ld\n", x);
//     return 0;
// }
