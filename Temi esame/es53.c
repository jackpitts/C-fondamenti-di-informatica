#include <stdio.h>
#include <stdlib.h>

struct el {
    int val;
    struct el *next;
};

struct el* leggi(char filename[20], int *codice, struct el **L){
    if (*L != NULL){
        *codice = 0;
        return NULL;
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Errore nell'apertura del file\n");
        *codice = 0;
        return NULL;
    }

    char c;
    int num = 0;
    int inNumero = 0;  // Flag per sapere se stiamo leggendo un numero
    
    while ((c = fgetc(fp)) != EOF){
        if (c >= '0' && c <= '9'){
            // È una cifra
            num = num * 10 + (c - '0');
            inNumero = 1;
        } else if (inNumero){
            // Abbiamo finito di leggere un numero (trovato spazio, newline, ecc.)
            struct el *nuovo = (struct el *) malloc(sizeof(struct el));
            if (nuovo == NULL){
                printf("Errore allocazione memoria\n");
                fclose(fp);
                *codice = 0;
                return NULL;
            }
            
            nuovo->val = num;

            if (*L == NULL){
                // Inserimento in lista vuota
                nuovo->next = NULL;
                *L = nuovo;
            } else if (num % 2 == 0){
                // Inserimento in testa (numeri pari)
                nuovo->next = *L;
                *L = nuovo;
            } else {
                // Inserimento in seconda posizione (numeri dispari)
                nuovo->next = (*L)->next;
                (*L)->next = nuovo;
            }

            num = 0;
            inNumero = 0;
        }
    }
    
    // Gestione ultimo numero se il file non termina con spazio
    if (inNumero){
        struct el *nuovo = (struct el *) malloc(sizeof(struct el));
        if (nuovo == NULL){
            printf("Errore allocazione memoria\n");
            fclose(fp);
            *codice = 0;
            return NULL;
        }
        
        nuovo->val = num;

        if (*L == NULL){
            nuovo->next = NULL;
            *L = nuovo;
        } else if (num % 2 == 0){
            nuovo->next = *L;
            *L = nuovo;
        } else {
            nuovo->next = (*L)->next;
            (*L)->next = nuovo;
        }
    }
    
    fclose(fp);
    *codice = 1;
    return *L;
}

int main(){
    struct el* L = NULL;
    int codice;
    char filename[20] = "test7.txt";
    
    L = leggi(filename, &codice, &L);
    if (codice == 0){
        printf("Operazione fallita\n");
        return 0;
    }

    printf("Lista: ");
    struct el *curr = L;
    while (curr != NULL){
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");

    // Liberazione memoria
    while (L != NULL){
        struct el *temp = L;
        L = L->next;
        free(temp);
    }

    return 0;
}
