/* RSA (Rivest-Shamir-Adleman)
 * Algorithm:
 * 1. Key generation
 * 2. Key distribution
 * 3. Publid-key operation (used for encryption/verifying a signature)
 * 4. Private-key operation (used for decryption/signing a message)
 * */

#include<stdio.h>
#include <stdlib.h>
#include "random.h"

int main(int argc, char *argv[]) {
    // if(argc != 2) {
    //     printf("Invalid usage\n\n");
    //     return 1;
    // }
    // printf("%s\n", argv[1]);
    printf("%d\n\n", generate_random(RAND_MAX));
    return 0;
}
