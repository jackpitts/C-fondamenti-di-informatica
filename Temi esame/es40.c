#include <stdio.h>
struct el {
    int n;
    struct el *precedente;
    struct el *successivo;
};
struct el *primo = NULL, *ultimo = NULL;

int inserisci (struct el *primo, struct el *ultimo,int v, struct el *sep){

}