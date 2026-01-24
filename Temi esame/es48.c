#include <stdio.h>
#include <stdlib.h>

struct el {
    int n;
    struct el *next;
    struct el *prev;
};

struct el *ins(struct el **primo, struct el **ultimo, int N, int V[N], int *codice) {
    // Caso 1: lista vuota
    if (*primo == NULL && *ultimo == NULL) {
        *codice = 0;
        return NULL;
    }
    
    // Caso 2: array non valido
    if (V == NULL) {
        *codice = 1;
        return *primo;
    }

    // Inserimento elementi
    for (int i = 0; i < N; i++) {
        int val = V[i];
        
        // Controlla se l'elemento esiste già
        struct el *curr = *primo;
        while (curr != NULL && curr->n != val) {
            curr = curr->next;
        }
        
        // Se non esiste, inseriscilo
        if (curr == NULL) {
            struct el *nuovo = (struct el *)malloc(sizeof(struct el));
            if (nuovo == NULL) {
                *codice = -1; // errore allocazione
                return *primo;
            }
            
            nuovo->n = val;
            nuovo->next = NULL;
            nuovo->prev = NULL;
            
            if (val % 2 != 0) {  // Dispari: inserisci in coda
                nuovo->prev = *ultimo;
                if (*ultimo != NULL) {
                    (*ultimo)->next = nuovo;
                }
                *ultimo = nuovo;
                if (*primo == NULL) {
                    *primo = nuovo;
                }
            } else {  // Pari: inserisci in testa
                nuovo->next = *primo;
                if (*primo != NULL) {
                    (*primo)->prev = nuovo;
                }
                *primo = nuovo;
                if (*ultimo == NULL) {
                    *ultimo = nuovo;
                }
            }
        }
    }
    
    *codice = 1;
    return *primo;
}

