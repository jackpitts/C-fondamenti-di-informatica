#include <stdio.h>
#include <stdlib.h>
struct s_giocatore {
    char nome[20];
    int punteggio;
    struct s_giocatore *next;
};
struct s_giocatore *primo;

// struct s_giocatore crea (char nome[20], int punteggio)

struct s_giocatore *insincoda (struct s_giocatore *primo){

    struct s_giocatore *nuovo = (struct s_giocatore *) malloc (sizeof (struct s_giocatore));
    printf ("Inserisci il nome del giocatore: ");
    scanf("%s", nuovo->nome);
    printf ("Inserisci il punteggio del giocatore: ");
    scanf ("%d", &nuovo->punteggio);

    if (primo == NULL){
        primo = nuovo;
        primo->next = NULL;
    } else if (nuovo->punteggio > primo->punteggio){
        struct s_giocatore *curr = primo;
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = nuovo;
        nuovo->next = NULL;
    } else {
        free (nuovo);
    }
    return primo;
}