#include <stdio.h>
#include <stdlib.h>

struct el {
    int val;
    struct el *next;
};

struct el *L = NULL;
int V[1000]; // vettore globale
int V_size = 0; // numero di elementi significativi in V

int TRADUCI(int v[], int n, struct el **L) {
    if (*L != NULL) return 0; // la lista deve essere vuota

    *L = NULL;
    struct el *p = NULL;

    if (n == 0) return 1; // vettore vuoto → lista rimane vuota

    int i = 0;

    // Caso speciale: vettore inizia con 9
    if (v[0] == 9) {
        // primo nodo = 0
        struct el *first = (struct el*)malloc(sizeof(struct el));
        if (!first) return -1; // errore malloc
        first->val = 0;
        first->next = NULL;
        *L = first;
        p = first;

        // contiamo quanti 9 iniziali ci sono
        int count9 = 0;
        while (i < n && v[i] == 9) {
            count9++;
            i++;
        }

        // secondo nodo = numero di 9 iniziali
        struct el *second = (struct el*)malloc(sizeof(struct el));
        if (!second) return -1;
        second->val = count9;
        second->next = NULL;
        p->next = second;
        p = second;
    }

    // Scorri il resto del vettore
    while (i < n) {
        int current = v[i];
        int count = 0;
        while (i < n && v[i] == current) {
            count++;
            i++;
        }

        struct el *newel = (struct el*)malloc(sizeof(struct el));
        if (!newel) return -1;
        newel->val = count;
        newel->next = NULL;

        if (*L == NULL) { // caso vettore inizia con 1
            *L = newel;
            p = newel;
        } else {
            p->next = newel;
            p = newel;
        }
    }

    return 1; // lista creata correttamente
}

// Funzione di supporto per stampare la lista
void stampa_lista(struct el *L) {
    struct el *p = L;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

// Esempio di main
int main() {
    // Vettore di esempio
    V[0] = 9; V[1] = 9; V[2] = 1; V[3] = 1; V[4] = 1; V_size = 5;

    int cod = TRADUCI(V, V_size, &L);
    if (cod == 0) {
        printf("La lista non era vuota!\n");
        return 1;
    } else if (cod == -1) {
        printf("Errore di memoria\n");
        return 1;
    }

    stampa_lista(L);
    return 0;
}