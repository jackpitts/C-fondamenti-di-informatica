#include <stdio.h>
#include <string.h>
#define MAXLEN 50

void estrazione(char orig[MAXLEN], char carat, char risult[MAXLEN]);

int main() {
    char orig[MAXLEN];
    char carat;
    char risult[MAXLEN];

    estrazione(orig, carat, risult);

    printf("Risultato: %s\n", risult);
    return 0;
}

void estrazione(char orig[MAXLEN], char carat, char risult[MAXLEN]) {
    printf("Inserire una stringa: ");
    fgets(orig, MAXLEN, stdin);
    orig[strcspn(orig, "\n")] = '\0'; // rimuove il newline finale

    printf("Inserire un carattere da cercare: ");
    scanf(" %c", &carat);

    int j = 0;
    int inizio = -1; // posizione della prima occorrenza
    int seconda_trovata = 0;

    for (int i = 0; orig[i] != '\0'; i++) {
        if (orig[i] == carat) {
            if (inizio == -1) {
                // prima occorrenza trovata
                inizio = i;
            } else {
                // seconda occorrenza trovata, includila e fermati
                risult[j++] = orig[i];
                seconda_trovata = 1;
                break;
            }
        }

        // se abbiamo trovato la prima occorrenza, copiamo il carattere
        if (inizio != -1 && !seconda_trovata) {
            risult[j++] = orig[i];
        }
    }

    risult[j] = '\0'; // chiude la stringa
}