#include <stdio.h>
#include <stdlib.h>

struct el {
    int n;
    struct el *next;
};
struct el *lista = NULL;

struct el *cancella (struct el **lista){

    struct el *curr = *lista;
    int i = 0;
    while (curr != NULL){
        if (i % 2 == 0){
            if (curr == *lista){
                // Cancellazione in testa
                *lista = curr->next;
            } else {
                // Cancellazione in mezzo o in coda
                struct el *temp = *lista;
                while (temp->next != curr){
                    temp = temp->next;
                }
                temp->next = curr->next;
            }
        }
        i++;
        curr = curr->next;
    }

    return *lista;

}

int main (){

    struct el *n1 = (struct el *) malloc (sizeof (struct el));
    struct el *n2 = (struct el *) malloc (sizeof (struct el));
    struct el *n3 = (struct el *) malloc (sizeof (struct el));
    struct el *n4 = (struct el *) malloc (sizeof (struct el));
    struct el *n5 = (struct el *) malloc (sizeof (struct el));
    struct el *n6 = (struct el *) malloc (sizeof (struct el));
    struct el *n7 = (struct el *) malloc (sizeof (struct el));
    struct el *n8 = (struct el *) malloc (sizeof (struct el));
    struct el *n9 = (struct el *) malloc (sizeof (struct el));
    struct el *n10 = (struct el *) malloc (sizeof (struct el));

    n1->n = 1;
    n2->n = 2;
    n3->n = 3;
    n4->n = 4;
    n5->n = 5;
    n6->n = 6;
    n7->n = 7;
    n8->n = 8;
    n9->n = 9;
    n10->n = 10;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;
    n10->next = NULL;

    lista = n1;

    lista = cancella (&lista);

    struct el *curr = lista;
    while (curr != NULL){
        printf ("%d ", curr->n);
        curr = curr->next;
    }
    printf ("\n");

    // Liberazione memoria
    while (lista != NULL){
        struct el *temp = lista;
        lista = lista->next;
        free (temp);
    }

    return 0;
}