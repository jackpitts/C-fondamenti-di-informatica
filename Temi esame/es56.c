#include <stdio.h> 
#include <stdlib.h>

struct list_t {
    int n;
    struct list_t* next;
};
struct list_t *L1 = NULL;
struct list_t *L2 = NULL;
struct list_t *L3 = NULL;

struct list_t *merge(struct list_t *L1, struct list_t *L2, struct list_t **L3){
    struct list_t *tail = NULL;  // Tiene traccia dell'ultimo nodo
    int i = 0;
    
    while (L1 != NULL && L2 != NULL){
        struct list_t *nuovo = (struct list_t*) malloc(sizeof(struct list_t));
        
        if (i % 2 == 0){
            nuovo->n = L1->n;
            L1 = L1->next;
        } else {
            nuovo->n = L2->n;
            L2 = L2->next;
        }
        nuovo->next = NULL;
        
        if (*L3 == NULL){
            *L3 = nuovo;
            tail = nuovo;
        } else {
            tail->next = nuovo;
            tail = nuovo;
        }
        i++;
    }
    
    while (L1 != NULL){
        struct list_t *nuovo = (struct list_t*) malloc(sizeof(struct list_t));
        nuovo->n = L1->n;
        nuovo->next = NULL;
        tail->next = nuovo;
        tail = nuovo;
        L1 = L1->next;
    }
    
    while (L2 != NULL){
        struct list_t *nuovo = (struct list_t*) malloc(sizeof(struct list_t));
        nuovo->n = L2->n;
        nuovo->next = NULL;
        tail->next = nuovo;
        tail = nuovo;
        L2 = L2->next;
    }
    
    return *L3;
}

int main (){

    // Creo la prima lista L1: 1 -> 3 -> 5
    struct list_t *n1 = (struct list_t*) malloc(sizeof(struct list_t));
    n1->n = 1;
    struct list_t *n2 = (struct list_t*) malloc(sizeof(struct list_t));
    n2->n = 3;
    struct list_t *n3 = (struct list_t*) malloc(sizeof(struct list_t));
    n3->n = 5;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    L1 = n1;

    // Creo la seconda lista L2: 2 -> 4 -> 6 -> 8
    struct list_t *m1 = (struct list_t*) malloc(sizeof(struct list_t));
    m1->n = 2;
    struct list_t *m2 = (struct list_t*) malloc(sizeof(struct list_t));
    m2->n = 4;
    struct list_t *m3 = (struct list_t*) malloc(sizeof(struct list_t));
    m3->n = 6;
    struct list_t *m4 = (struct list_t*) malloc(sizeof(struct list_t));
    m4->n = 8;
    struct list_t *m5 = (struct list_t*) malloc(sizeof(struct list_t));
    m5->n = 10;
    m1->next = m2;
    m2->next = m3;
    m3->next = m4;
    m4->next = m5;
    m5->next = NULL;
    L2 = m1;

    merge(L1, L2, &L3);
    struct list_t *curr = L3;
    while (curr != NULL){
        printf("%d ", curr->n);
        curr = curr->next;
    }

    return 0;

}