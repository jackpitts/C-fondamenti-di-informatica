#include <stdio.h>
#include <stdlib.h>

struct el {
    int v;
    struct el *next;
};

struct el *DEL(struct el *LIS, int *cancellati)
{
    *cancellati = 0;

    struct el *curr = LIS;
    struct el *prev = NULL;

    while (curr != NULL) {

        int somma = 0;
        struct el *tmp = curr->next;

        while (tmp != NULL) {
            somma += tmp->v;
            tmp = tmp->next;
        }

        if (curr->v < somma) {
            struct el *da_eliminare = curr;

            if (prev == NULL) {
                LIS = curr->next;
                curr = LIS;
            } else {
                prev->next = curr->next;
                curr = curr->next;
            }

            free(da_eliminare);
            (*cancellati)++;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return LIS;
}

int main(void)
{

    /* inizializzazione lista */
    struct el *LIS = (struct el *)malloc(sizeof(struct el));
    LIS->v = 30;

    LIS->next = (struct el *)malloc(sizeof(struct el));
    LIS->next->v = 5;

    LIS->next->next = (struct el *)malloc(sizeof(struct el));
    LIS->next->next->v = 2;

    LIS->next->next->next = (struct el *)malloc(sizeof(struct el));
    LIS->next->next->next->v = 10;

    LIS->next->next->next->next = NULL;

    struct el *p = LIS;
    printf("Lista iniziale: ");
    while (p != NULL) {
        printf("%d ", p->v);
        p = p->next;
    }

    /* chiamata DEL */
    int cancellati;
    LIS = DEL(LIS, &cancellati);

    /* stampa lista ritornata */
    printf("\nElementi cancellati: %d\n", cancellati+1); // +1 per l'ultimo elemento sempre cancellato
    printf("Lista finale: ");

    struct el *q = LIS;
    while (q->next != NULL) {
        printf("%d ", q->v);
        q = q->next;
    }
    printf("\n");

    return 0;
}