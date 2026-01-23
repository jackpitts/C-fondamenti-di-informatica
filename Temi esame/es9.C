#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char str[36];  // obbligatorio
str vet[50];           // array globale di stringhe
int posizione = -1;    // indice dell'ultimo elemento caricato

// funzione che controlla se le vocali in una stringa sono in ordine crescente
int vowelsOrdered(str s) {
    char prev = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            if (prev > c) return 0; // vocale fuori ordine
            prev = c;
        }
    }
    return 1; // tutte le vocali in ordine
}

int main() {
    // popoliamo il vettore globale e aggiorniamo posizione
    strcpy(vet[0], "ciao");
    strcpy(vet[1], "matteo");
    strcpy(vet[2], "aiuto");
    strcpy(vet[3], "pippo");
    strcpy(vet[4], "ouai");
    posizione = 4; // ultimo indice caricato

    printf("Stringhe con vocali in ordine:\n");
    for (int i = 0; i <= posizione; i++) {
        if (vowelsOrdered(vet[i])) {
            printf("%s\n", vet[i]);
        }
    }

    return 0;
}