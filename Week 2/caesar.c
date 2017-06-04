#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) {
    if ( argc != 2) {
        printf("Error!\n");
        return 1;
    }

    int key = atoi((argv[1]));

    printf("plaintext: ");
    char plaintext[80];
    fgets(plaintext, sizeof plaintext, stdin);

    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++) {
       if (islower(plaintext[i])) {
           printf("%c", (plaintext[i] + key - 97) % 26 + 97);
       } else if (isupper(plaintext[i])){
           printf("%c", (plaintext[i] + key - 65) % 26 + 65);
       } else {
            printf("%c", plaintext[i]);
       }

    }
    printf("\n");
    return 0;

}

/* Implement a program that encrypts messages using Caesar’s cipher, per the below.

*$ ./caesar 13
*plaintext:  HELLO
*ciphertext: URYYB
*/
