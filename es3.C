#include <stdio.h>
#include <math.h>

typedef struct tnodo {
    int x;
    int y;
    struct tnodo *next;
} vertice;
vertice *spezzata1 = NULL;

vertice s1[] = {
    {0, 0, &spezzata1[1]},
    {1, 2, &spezzata1[2]},
    {3, 3, &spezzata1[3]},
};

int nodistance (vertice* lista, vertice** risultato){

    vertice* curr = lista;

    while(curr && curr->next){
        int dx = curr->next->x - curr->x;
        int dy = curr->next->y - curr->y;
        if (sqrt(dx*dx + dy*dy) <= 0){
            *risultato = curr;
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

void cleandist(vertice* lista, vertice** risultato){
    while (nodistance(lista, risultato)){
        vertice* da_eliminare = (*risultato)->next; // nodo da rimuovere
        if (da_eliminare->next == NULL){
            (*risultato)->next = NULL;
        } else {
            (*risultato)->next = da_eliminare->next;
        }
        free(da_eliminare); // libero la memoria
    }
}

int ripasso(vertice* lista, vertice** risultato){
    if (!lista || !lista->next) return 0;

    vertice* prec = lista;
    vertice* curr = lista->next;

    while (curr){
        vertice* scan = lista;
        while (scan != prec){
            if (scan->x == curr->x && scan->y == curr->y){
                *risultato = prec;  // Vi-1
                return 1;
            }
            scan = scan->next;
        }
        prec = curr;
        curr = curr->next;
    }

    return 0;
}
