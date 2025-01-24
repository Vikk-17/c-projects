#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
// #define _XOPEN_SOURCE
#include<crypt.h>

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Usage: %s <plaintext password> <salt>\n", argv[0]);
        exit(1);
    }
    printf("Password \"%s\" with salt \"%s\"\n", argv[1], argv[2]);
    printf("hashes to ==> %s \n", crypt(argv[1], argv[2]));

    return 0;
}
