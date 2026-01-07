#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000

int lettura_al_contrario(char filename[20]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Errore apertura file.\n");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long pos = ftell(fp);
    char line[MAX_LINE];
    int idx = 0;

    for (long i = pos - 1; i >= 0; i--) {
        fseek(fp, i, SEEK_SET);
        int c = fgetc(fp);

        if (c == '\n') {
            if (idx > 0) {  // stampo la riga trovata
                line[idx] = '\0';
                // stampo la riga invertita perché l'abbiamo letta all'indietro
                for (int j = idx - 1; j >= 0; j--)
                    putchar(line[j]);
                putchar('\n');
                idx = 0;
            }
        } else {
            line[idx++] = c;
        }
    }

    // stampo l'ultima riga (all'inizio del file)
    if (idx > 0) {
        line[idx] = '\0';
        for (int j = idx - 1; j >= 0; j--)
            putchar(line[j]);
        putchar('\n');
    }

    fclose(fp);
    return 1;
}

int main() {
    char filename[20];
    printf("Inserisci il nome del file: ");
    scanf("%s", filename);
    lettura_al_contrario(filename);
    return 0;
}