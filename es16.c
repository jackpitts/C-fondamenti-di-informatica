#define N 5
#include <stdio.h>
#include <stdlib.h>

struct elem
{
    int c;
    struct elem *next;
};

typedef struct elem *lista;
lista L1, L2;
int vet[N] = {1, 0, 1, 0, 1};

int sel(lista L1, lista *L2, int vet[N])
{
    struct elem *p = L1;
    struct elem *q = *L2;
    int i = 0;

    while (p != NULL && i < N)
    {
        if (vet[i] == 1)
        {
            struct elem *nuovo_elem = (struct elem *)malloc(sizeof(struct elem));
            nuovo_elem->c = p->c;
            nuovo_elem->next = NULL;

            if (q == NULL)
            {
                *L2 = nuovo_elem;
                q = *L2;
            }
            else
            {
                q->next = nuovo_elem;
                q = q->next;
            }
        }
        p = p->next;
        i++;
    }
    return 1;
}

int main() {
    // Creo L1
    L1 = (struct elem *)malloc(sizeof(struct elem));
    L1->c = 10;
    L1->next = (struct elem *)malloc(sizeof(struct elem));
    L1->next->c = 20;
    L1->next->next = (struct elem *)malloc(sizeof(struct elem));
    L1->next->next->c = 30;
    L1->next->next->next = (struct elem *)malloc(sizeof(struct elem));
    L1->next->next->next->c = 40;
    L1->next->next->next->next = (struct elem *)malloc(sizeof(struct elem));
    L1->next->next->next->next->c = 50;
    L1->next->next->next->next->next = NULL;

    L2 = NULL;

    // stampo L1
    struct elem *tmp = L1;
    while (tmp != NULL) {
        printf("%d\t", tmp->c);
        tmp = tmp->next;
    }
    printf("\n");

    // stampo vet
    for (int i = 0; i < N; i++)
        printf("%d\t", vet[i]);
    printf("\n");

    // seleziono elementi in L2
    sel(L1, &L2, vet);

    // stampo L2
    tmp = L2;
    while (tmp != NULL) {
        printf("%d\t", tmp->c);
        tmp = tmp->next;
    }
    printf("\n");

    // libero memoria L1
    tmp = L1;
    while (tmp != NULL) {
        struct elem *next = tmp->next;
        free(tmp);
        tmp = next;
    }

    // libero memoria L2
    tmp = L2;
    while (tmp != NULL) {
        struct elem *next = tmp->next;
        free(tmp);
        tmp = next;
    }

    return 0;
}