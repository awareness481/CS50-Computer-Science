#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    char name[80];
    fgets(name, sizeof name, stdin);


    if (name[0] != ' ' && name[0] != '\0') {
        printf("%c", toupper(name[0]));
    }

    for (int i = 0, n = strlen(name); i < n; i++ ) {
        if (name[i] == ' ') {
            if (name[i + 1] != ' ' && name[i + 1] != '\0') {
                printf("%c", toupper(name[i + 1]));
                i++;
            }
        }
    }
    printf("\n");
}
