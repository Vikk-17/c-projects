#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define _XOPEN_SOURCE


// Barf message in case of erro
void barf(char *message, char *extra){
    printf(message, extra);
    exit(1);
}

// Dictionary attack
int main(int argc, char *argv[]){

    FILE *wordlist;
    char *hash, word[30], salt[3];

    if(argc < 2)
        barf("Usage: %s <password file> <salt>\n", argv[0]);

    // Extract the salt first 2 bytes of the hash value provided into command argc
    strncpy(salt, argv[2], 2);
    salt[2] = '\0'; // terminate the string
    printf("Salt is: %s\n", salt);


    if((wordlist = fopen(argv[1], "r")) == NULL) // Open the wordlist
        barf("Error: cannot open this file %s\n", argv[1]);

    // Read each word
    while(fgets(word, 30, wordlist) != NULL){
        word[strlen(word)-1] = '\0'; // Removes '\n' at the end
        hash = crypt(word, salt); // hash the word using salt
        printf("Trying word: %-15s ==> %30s\n", word, hash);
        if (strcmp(hash, argv[2]) == 0){
            printf("The hash \"%s\" is from the plaintext password \"%s\"\n", argv[2], word);
            fclose(wordlist);
            exit(0);
        }
    }

    printf("Could not find the plaintext password in the wordlist.\n");
    fclose(wordlist);

    return 0;
}
