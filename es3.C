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

int valida (vertice* lista, vertice** risultato){

    int codiceErrore = 0;
    vertice* p = lista;
    
    if (p->next != NULL){
        codiceErrore = 1;
        return 0;
    } else if (nodistance(lista, risultato) && ripasso(lista, risultato)){
        codiceErrore = 4;
        return 0;
    } else if (nodistance(lista, risultato)){
        codiceErrore = 2;
        return 0;
    } else if (ripasso(lista, risultato)){
        codiceErrore = 3;
        return 0;
    }

    return 1;
}

int lunghezzza (vertice* lista){
    int lunghezza = 0;
    vertice* curr = lista;

    while(curr && curr->next != NULL){
        int dx = curr->next->x - curr->x;
        int dy = curr->next->y - curr->y;
        lunghezza += sqrt(dx*dx + dy*dy);
        curr = curr->next;
    }
    return lunghezza;
}
