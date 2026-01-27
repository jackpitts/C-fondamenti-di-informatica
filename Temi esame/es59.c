#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct campo{
    char nomecampo[40];
    char tipocampo[50];
    struct campo *nextCampo;
};

struct tabella{
    char nometabella[100];
    struct tabella *nextTabella;
    struct campo *nextCampo;
};
struct tabella *lista = NULL;


int query(struct tabella *lista, char *nometabella, char *stringa[100]){
    if(lista == NULL){
        return 0;
    }
    struct tabella *curr = lista;
    while(curr != NULL){
        if (strcmp(curr->nometabella, nometabella) == 0){
            struct campo *currCampo = curr->nextCampo;
            int i = 0;
            if(currCampo != NULL){
                *stringa = "Create table nometabella (nomecampo1 tipocampo1, nomecampo2 tipocampo2, ...);";
                return 1;
            }
        }
        curr = curr->nextTabella;
    }
    return 0;
}

int main (){
    // Esempio di utilizzo della funzione query
    char *result[100];
    if(query(lista, "mia_tabella", result)){
        printf("%s\n", *result);
    } else {
        printf("Tabella non trovata.\n");
    }
    return 0;
}