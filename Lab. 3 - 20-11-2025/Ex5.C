#include <stdio.h>
#include <string.h>

int main () {

    int count = 0;
    char nome[10];

    printf("Inserisci il tuo nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Ciao %s", nome);

    for (int i = 0; i < sizeof(nome); i++) {

        if (nome[i] != '\0'){
            count++;
        }
        else {
            break;
        }

    }

    printf("La lunghezza del nome calcolato manualmente è: %d\n", count);
    printf("La lunghezza del nome calcolato con strlen è: %lu\n", strlen(nome));

}