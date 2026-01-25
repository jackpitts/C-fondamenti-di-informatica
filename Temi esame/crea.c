#include <stdio.h>
#include <string.h>

struct Tfornitore {
    int id;
    char nome[20];
    char via[20];
};

struct Tric {
    int id;
    long pos;  // posizione in byte nel file principale
};

int main() {
    FILE *f1 = fopen("File2", "wb");
    FILE *f2 = fopen("File2RIC", "wb");

    if (!f1 || !f2) {
        printf("Errore apertura file!\n");
        return 1;
    }

    struct Tfornitore fornitori[60];
    struct Tric ric[60];

    // --- Popoliamo i fornitori con dati di esempio ---
    for (int i = 0; i < 60; i++) {
        fornitori[i].id = i + 1;
        snprintf(fornitori[i].nome, sizeof(fornitori[i].nome), "Nome%d", i+1);
        snprintf(fornitori[i].via, sizeof(fornitori[i].via), "Via %d", i+1);
    }

    // --- Scriviamo File2: fornitori non ordinati ---
    // Mescoliamo leggermente per non essere ordinati
    for (int i = 0; i < 60; i++) {
        int j = (i * 7) % 60;  // semplice "shuffle" fittizio
        fwrite(&fornitori[j], sizeof(struct Tfornitore), 1, f1);
        // Salviamo anche l'indice di posizione per il file RIC
        ric[j].id = fornitori[j].id;
        ric[j].pos = i * sizeof(struct Tfornitore);  // posizione in byte nel file
    }

    // --- Scriviamo File2RIC: ordinato per id ---
    for (int i = 0; i < 60; i++) {
        fwrite(&ric[i], sizeof(struct Tric), 1, f2);
    }

    fclose(f1);
    fclose(f2);

    printf("File2 e File2RIC creati con successo con 60 record ciascuno!\n");
    return 0;
}