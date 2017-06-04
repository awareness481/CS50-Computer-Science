#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) {
    if ( argc != 2) {
        printf("Error!");
        return 1;
    }

    const char *key = argv[1];

    for (int j = 0, l = strlen(key); j < l; j++) {
        if (!isalpha(key[j])) {
            printf("Error!, no numbers allowed\n");
            return 1;
        }
    }



    char plaintext[80];

    printf("plaintext: ");
    fgets(plaintext, sizeof plaintext, stdin);
    printf("\nciphertext: ");
    for (int i = 0, k = 0, n = strlen(plaintext); i < n; i++, k++) {
        if (k >= strlen(key)) {
            k = 0;
        }
       int keyVal = key[k];


       if (keyVal >= 'a' && keyVal <= 'z') {
           keyVal = keyVal - 'a';
       }

       if (keyVal >= 'A' && keyVal <= 'Z') {
           keyVal = keyVal - 'A';
       }



       if (islower(plaintext[i])) {
           printf("%c", (plaintext[i] + keyVal - 97) % 26 + 97);
       } else if (isupper(plaintext[i])){
           printf("%c", (plaintext[i] + keyVal - 65) % 26 + 65);
       } else {
            printf("%c", plaintext[i]);
       }

       if(!isalpha(plaintext[i])) {
           k--;
       }

    }
    printf("\n");
    return 0;

}
