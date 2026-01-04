#include <stdio.h>

struct list_t
{
    int valore;
    struct list_t *next;
};

struct list_t *lista = NULL;

int conta(struct list_t *lista, int n)
{

    int conto = 0;
    int pos = 1;
    struct list_t *curr = lista;
    while (curr != NULL)
    {
        if (curr->valore == n && pos != 3 && curr->next != NULL)
        {
            conto++;
        }
        curr = curr->next;
        pos++;
    }
    return conto;
}

int cancella (struct list_t **lista, int valore, int limit){
    int count = 0;
    struct list_t *curr = lista;
    struct list_t *prev = NULL;
    struct list_t *ultimo = NULL;
    struct list_t *prev_ultimo = NULL;
    
    while (curr != NULL){
        if (curr->valore == valore){
            count++;
            ultimo = curr;
            prev_ultimo = prev;
        }
        prev = curr;
        curr = curr->next;
    }

    if (count > 0 && count < limit){
        if (prev_ultimo == NULL){
            *lista = ultimo->next;
            return 1;
        }
        else {
            prev_ultimo->next = ultimo->next;
            return 1;
        }
    }

    free(ultimo);
    return 0;
}

struct list_t* delel(struct list_t** lista, struct list_t* prec, struct list_t* curr){

    if (prec == NULL){
        *lista = curr->next;
        return lista;
        free (curr);
    } else if (curr !=NULL && prec != NULL){
        prec->next = curr->next;
        return lista;
        free (curr);
    }

}