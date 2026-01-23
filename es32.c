#include <stdio.h>
#include <stdlib.h>

struct prod {
    int codice;
    int quantita;
    struct prod *link;
};
struct prod *LP = NULL;
int codice, quantita;

struct prod *ins (struct prod *LP, int codice, int quantita){
    struct prod *nuovo = (struct prod *) malloc (sizeof(struct prod));
    nuovo->codice = codice;
    nuovo->quantita = quantita;

    struct prod *curr = LP;
    while (curr->link != NULL){
        if (curr->link->codice == codice){
            nuovo->link = curr->link;
            curr->link = nuovo;
        } else {
            curr->link = nuovo;
            nuovo->link = NULL;
        }
        curr = curr->link;
    }


    return LP;
}