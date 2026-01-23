#include <stdio.h>
#include <stdlib.h>

struct el
{
    int n;
    struct el *precedente;
    struct el *successivo;
};
struct el *primo = NULL, *ultimo = NULL;

int inserisci(struct el **primo, struct el **ultimo, int v, struct el *sep)
{

    struct el *nuovo = (struct el *)malloc(sizeof(struct el));
    nuovo->n = v;


    // controllo correttezza sep
    int trovato = 0;
    int countFirstHalf = 0;
    int countSecondHalf = 0;
    struct el *curr = *primo;
    while (curr != NULL)
    {
        if (curr == sep)
        {
            trovato = 1;
            curr = curr->successivo; // <-- AGGIUNGI QUESTA RIGA
            break;
        }
        curr = curr->successivo;
        countFirstHalf++;
    }

    if (!trovato && sep != NULL)
    {
        free(nuovo);
        return 0;
    }

    // Inserimento
    while (curr != NULL)
    {
        curr = curr->successivo;
        countSecondHalf++;
    }
    if (countFirstHalf > countSecondHalf)
    {
        nuovo->successivo = *primo;
        (*primo)->precedente = nuovo;
        *primo = nuovo;
        nuovo->precedente = NULL;
    }
    else if (countFirstHalf < countSecondHalf)
    {
        nuovo->precedente = *ultimo;
        (*ultimo)->successivo = nuovo;
        *ultimo = nuovo;
        nuovo->successivo = NULL;
    }
    else
    {
        free(nuovo);
        return 1;
    }

    return 1;
}