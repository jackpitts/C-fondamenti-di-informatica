#include <stdio.h>
#include <stdlib.h>
struct s_studente {
    char nome[20];
    int matricola;
    struct s_studente *prev;
    struct s_studente *next;
};
struct s_studente *primo;

//struct s_studente *ricerca(struct s_studente *primo, int matr)

struct s_studente *elimina_studente(struct s_studente *primo){
    int matr;
    struct s_studente *del;
    del = 0;
    // del = ricerca(primo, matr);

    if (del == NULL) {
        printf ("Studente non trovato. \n");
    } else if (del == primo){
        primo = primo->next;
        primo->prev = NULL;
    } else if (del->prev != NULL && del->next != NULL){
        del->prev->next = del->next;
        del->next->prev = del->prev;
    } else if (del->next == NULL){
        del->prev->next = NULL;
    }

    return primo;
}

