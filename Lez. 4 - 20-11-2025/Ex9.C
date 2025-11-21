#include <stdio.h>
#include <string.h>
#include <limits.h>

#define NAMELEN 20
#define NANAGR 5

typedef struct {
    char name[NAMELEN];
    char genere[2];
    int eta;
} s_anagr;

int main () {
    s_anagr v_finale[NANAGR];
    s_anagr v_anagr[NANAGR] = {
        {"Topolino", "M", 47},
        {"Minni",   "F", 37},
        {"Pluto",   "M", 17},
        {"Paperino","M", 25},
        {"Paperina","F", 22}
    };

    // Inizializzo v_finale (eta alto per min-search, stringhe vuote)
    for (int i = 0; i < NANAGR; i++) {
        v_finale[i].name[0] = '\0';
        v_finale[i].genere[0] = '\0';
        v_finale[i].eta = 0;
    }
    v_finale[0].eta = INT_MAX; // posto per il maschio più giovane
    v_finale[1].eta = INT_MAX; // posto per la femmina più giovane

    // Trovo il maschio e la femmina più giovani
    for (int i = 0; i < NANAGR; i++) {
        if (v_anagr[i].genere[0] == 'M') {
            if (v_anagr[i].eta < v_finale[0].eta) {
                v_finale[0] = v_anagr[i];
            }
        } else if (v_anagr[i].genere[0] == 'F') {
            if (v_anagr[i].eta < v_finale[1].eta) {
                v_finale[1] = v_anagr[i];
            }
        }
    }

    // Inserisco i maschi con eta > 25 a partire da indice 2, senza uscire dai limiti
    int idx = 2;
    for (int i = 0; i < NANAGR && idx < NANAGR; i++) {
        if (v_anagr[i].genere[0] == 'M' && v_anagr[i].eta > 25) {
            v_finale[idx++] = v_anagr[i];
        }
    }

    // Stampo l'array di partenza
    printf("Array originale:\n");
    for (int i = 0; i < NANAGR; i++) {
        printf("Nome: %s, Genere: %s, Eta': %d\n",
               v_anagr[i].name, v_anagr[i].genere, v_anagr[i].eta);
    }

    // Stampo solo gli elementi effettivamente riempiti di v_finale
    printf("\nVettore finale (riempiti %d elementi):\n", idx);
    for (int i = 0; i < idx; i++) {
        printf("Nome: %s, Genere: %s, Eta': %d\n",
               v_finale[i].name, v_finale[i].genere, v_finale[i].eta);
    }

    return 0;
}