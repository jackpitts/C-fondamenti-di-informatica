#include <stdio.h>
#include <stdlib.h>

struct el {
    int val;
    struct el *next;
};
struct el *L = NULL;

int crea(struct el **L, int num){
    if (*L != NULL){
        return -1;
    }

    char stringa[20];
    sprintf(stringa, "%d", num);

    int strlen = 0;
    for (int i = 0; stringa[i] != '\0'; i++){
        strlen++;
    }

    for (int i = strlen - 1; i >= 0; i--){
        int cifra = stringa[i] - '0';
        
        for (int j = 0; j < cifra; j++){
            struct el *nuovo = (struct el *) malloc(sizeof(struct el));  // ← SPOSTATO QUI!
            nuovo->val = cifra;
            nuovo->next = NULL;
            
            if (*L == NULL){
                *L = nuovo;
            } else {
                struct el *temp = *L;
                while (temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = nuovo;
            }
        }
    }
    return 1;
}

int main (){
    int num;
    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &num);

    if (crea(&L, num) == -1){
        printf("La lista e' gia' stata creata!\n");
        return -1;
    }

    printf("Lista creata con successo! I valori sono:\n");
    struct el *temp = L;
    while (temp != NULL){
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");

    // Libera la memoria allocata
    temp = L;
    while (temp != NULL){
        struct el *toFree = temp;
        temp = temp->next;
        free(toFree);
    }

    return 0;
}