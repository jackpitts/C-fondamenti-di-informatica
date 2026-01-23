#include <stdio.h>
#include <stdlib.h>

struct el
{
    char valore;
    struct el *successivo;
};
struct el *lista = NULL;

struct el *insdel(struct el *lista, char ca, char filename[20])
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file.\n");
        return lista;
    }

    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        struct el *nuovo = (struct el *)malloc(sizeof(struct el));
        nuovo->valore = c;
        nuovo->successivo = NULL;

        if (lista == NULL)
        {
            // Lista vuota -> nuovo diventa primo
            lista = nuovo;
        }
        else if (nuovo->valore <= lista->valore)
        {
            // Inserimento in testa
            nuovo->successivo = lista;
            lista = nuovo;
        }
        else
        {
            // Inserimento in coda
            struct el *curr = lista;
            while (curr->successivo != NULL)
            {
                curr = curr->successivo;
            }
            curr->successivo = nuovo;
            nuovo->successivo = NULL;
        }
    }

    fclose(fp);

    printf("Inserire un carattere: ");
    scanf(" %c", &ca);

    struct el *curr = lista;
    struct el *prev = NULL;

    while (curr != NULL)
    {
        if (curr->valore == ca)
        {
            struct el *da_cancellare = curr;

            if (prev == NULL)
            {
                // Nodo da eliminare è il primo
                lista = curr->successivo;
            }
            else
            {
                prev->successivo = curr->successivo;
            }

            curr = curr->successivo;
            free(da_cancellare);
        }
        else
        {
            prev = curr;
            curr = curr->successivo;
        }
    }

    return lista;
}

// Funzione di stampa per test
void stampa_lista(struct el *lista)
{
    while (lista != NULL)
    {
        printf("%c -> ", lista->valore);
        lista = lista->successivo;
    }
    printf("NULL\n");
}

int main()
{
    lista = insdel(lista, 'A', "test2.txt"); // sostituire con il nome del file
    stampa_lista(lista);
    return 0;
}