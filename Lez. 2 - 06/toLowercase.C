
#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    printf("Inserisci un carattere: ");
    scanf(" %c", &c);
    if ((c >= 'A') && (c <= 'Z')){
        printf("%c\n", tolower(c));
    } else {
        printf("Il carattere inserito non è una lettera maiuscola.\n");
    }
    return 0;
}