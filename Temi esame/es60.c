#include <stdio.h>
#include <stdlib.h>

struct el
{
    char dato;
    struct el *next;
};

struct el *lista = NULL;

typedef struct
{
    int size;
    char *v;
} t_vet;

t_vet vet;

int carica(char filename[10], struct el **lista)
{
    if (*lista != NULL)
    {
        return 0;
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return 0;
    }

    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        struct el *nuovo = (struct el *)malloc(sizeof(struct el));
        nuovo->dato = c;

        // Inserimento in testa
        if (*lista == NULL)
        {
            nuovo->next = NULL;
            *lista = nuovo;
        }
        else
        {
            struct el *curr = *lista;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = nuovo;
            nuovo->next = NULL;
        }
    }
    fclose(fp);
    return 1;
}

int sostituzione(struct el **lista, t_vet **vet, char chg[6], char ch)
{
    int count = 0;
    struct el *curr = *lista;
    while (curr != NULL)
    {
        if (curr->dato == ch)
        {
            curr->dato = chg[0];
            for (int i = 1; i < 6; i++)
            {
                struct el *nuovo = (struct el *)malloc(sizeof(struct el));
                nuovo->dato = chg[i];
                nuovo->next = curr->next;
                curr->next = nuovo;
                curr = nuovo;
            }
            curr = curr->next; // Avanza dopo l'inserimento
        }
        else
        {
            curr = curr->next; // Avanza se non c'è match
        }
    }

    // Conta gli elementi nella lista
    struct el *temp = *lista;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    // Inserimento nel vettore
    (*vet)->size = count;
    (*vet)->v = (char *)malloc(count * sizeof(char));

    temp = *lista;
    int i = 0;
    while (temp != NULL)
    {
        (*vet)->v[i] = temp->dato;
        i++;
        temp = temp->next;
    }

    return 1;
}

