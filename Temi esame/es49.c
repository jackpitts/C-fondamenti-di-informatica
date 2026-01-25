#include <stdio.h>
#include <stdlib.h>

struct el {
    int val;
    struct el *next;
};
struct el *L = NULL;
struct el *L2 = NULL;

struct el *traduci(int v[1000], int dim, struct el **L, int *codice){
    // Controlla che la lista sia vuota
    if (*L != NULL){
        *codice = 0;
        return NULL;
    }

    // Controllo che l'array non sia vuoto
    if (v == NULL || dim <= 0){
        *codice = 1;
        return *L;
    }

    // Inserimento
    int count = 1;
    int maxCount = 1;
    for (int i = 0; i < dim; i++){
        if (i == 0 && v[i] == 9){
                struct el *nuovo = (struct el *)malloc(sizeof(struct el));
                nuovo->val = 0;
                nuovo->next = NULL;
                *L = nuovo;
            }
        if (v[i] == v[i+1]){
            count++;
        } else {
            struct el *nuovo = (struct el *)malloc(sizeof(struct el));
            // Assegno i valori per i diversi casi
            nuovo->val = count;
            
            // Inserisco il nuovo elemento per i vari casi
            if (*L == NULL){
                nuovo->next = NULL;
                *L = nuovo;
            } else {
                struct el *curr = *L;
                while (curr->next != NULL){
                    curr = curr->next;
                }
                curr->next = nuovo;
                nuovo->next = NULL;
            }

            // Assegno il counter massimo
            if (count > maxCount){
                maxCount = count;
            }
            count = 1;
        }
    }
    printf("Max count: %d\n", maxCount);
    *codice = 1;
    return *L;
}

int main(){

    int v[22] = {9,9,9,1,1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,9,1,1};
    int dim = 22;
    printf("Vettore originale: ");
    for (int i = 0; i < dim; i++){
        printf("%d ", v[i]);
    }
    printf("- ");
    int codice;
    traduci(v, dim, &L, &codice);
    printf ("Vettore tradotto: ");

    struct el *curr = L;
    while (curr != NULL){
        printf("%d ", curr->val);
        if (curr->next != NULL){
            printf("-> ");
        }
        curr = curr->next;
    }

    printf("\n\n");

    int v2[23] = {1,1,1,1,1,1,1,9,9,9,1,1,9,9,9,9,1,1,1,1,1,1,9};
    int dim2 = 23;
    printf("Vettore originale: ");
    for (int i = 0; i < dim2; i++){
        printf("%d ", v2[i]);
    }
    printf("- ");
    traduci(v2, dim2, &L2, &codice);
    printf ("Vettore tradotto: ");

    struct el *curr2 = L2;
    while (curr2 != NULL){
        printf("%d ", curr2->val);
        if (curr2->next != NULL){
            printf("-> ");
        }
        curr2 = curr2->next;
    }

    printf("\n");
    return 0;
}