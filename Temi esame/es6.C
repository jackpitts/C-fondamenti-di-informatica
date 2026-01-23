#include <stdio.h>
#include <stdlib.h>

struct list_t
{
    int valore;
    struct list_t *next;
};

struct list_t* alternato(struct list_t *lista1, struct list_t *lista2)
{
    struct list_t *lista3 = NULL;
    struct list_t *tail = NULL;
    
    struct list_t *curr1 = lista1;
    struct list_t *curr2 = lista2;
    
    while (curr1 != NULL && curr2 != NULL){

    struct list_t *nuovo = (struct list_t *)malloc(sizeof(struct list_t));
    nuovo->valore = curr1->valore;
    nuovo->next = NULL;

    if (lista3 == NULL){
        lista3 = nuovo;
        tail = nuovo;
    } else {
        tail->next = nuovo;
        tail = nuovo;
    }
    curr1 = curr1->next;

    struct list_t *nuovo2 = (struct list_t *)malloc(sizeof(struct list_t));
    nuovo2->valore = curr2->valore;
    nuovo2->next = NULL;

    tail->next = nuovo2;
    tail = nuovo2;
    
    curr2 = curr2->next;
}

while (curr1 != NULL){
    struct list_t *nuovo = (struct list_t*)malloc(sizeof(struct list_t));
    nuovo->valore = curr1->valore;
    nuovo->next = NULL;
    tail->next = nuovo;
    tail = nuovo;
    curr1 = curr1->next;
}

while (curr2 != NULL){
    struct list_t *nuovo = (struct list_t*)malloc(sizeof(struct list_t));
    nuovo->valore = curr2->valore;
    nuovo->next = NULL;
    tail->next = nuovo;
    tail = nuovo;
    curr2 = curr2->next;
}

return lista3;
}