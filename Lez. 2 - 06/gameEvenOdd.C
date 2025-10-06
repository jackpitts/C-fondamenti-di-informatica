
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int n_utente;
    int n_bot;
    int count_pari = 0;
    int count_dispari = 0;

    srand(time(NULL)); // inizializza il generatore di numeri casuali

    for (int i = 0; i < 10; i++) {
        printf("Inserisci un numero: ");
        scanf("%d", &n_utente);
        n_bot = rand() % 100 + 1; // numero random tra 1 e 100
        int somma = n_utente + n_bot;
        printf("Il bot ha scelto: %d, somma: %d\n", n_bot, somma);
        if (somma % 2 == 0) {
            count_pari++;
            count_dispari = 0;
            printf("PARI VINCE IL ROUND!\n");
        } else {
            count_dispari++;
            count_pari = 0;
            printf("DISPARI VINCE IL ROUND!\n");
        }
        if (count_pari == 2) {
            printf("PARI VINCE LA PARTITA!\n");
            return 0;
        } else if (count_dispari == 2) {
            printf("DISPARI VINCE LA PARTITA!\n");
            return 0;
        }
    }
    printf("Raggiunti i 10 tentativi, la partita finisce\n");
    return 0;
}