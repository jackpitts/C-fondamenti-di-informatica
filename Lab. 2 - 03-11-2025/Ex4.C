#include <stdio.h>

int main () {

    int n, risultato = 1, resto;
    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Errore: il numero deve essere positivo.\n");
        return 1;
    }

    while (risultato != 0) {
        risultato = n / 2;
        resto = n % 2;
        printf("%d\n", resto);
        n = risultato;
    }
    
    printf("Rappresentazione binaria dal basso verso l'alto.\n\n");
    return 0;

}