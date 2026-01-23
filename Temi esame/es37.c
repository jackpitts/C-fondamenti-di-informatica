#include <stdio.h>
#include <stdlib.h>
#define N 14
char stringa[N] = "131,24,912,1,";
char sep = ',';

struct el {
    int valore;
    struct el *next;
};
struct el *lista = NULL;

struct el *cancella (struct el *head){
    struct el *curr;
    while (head != NULL){
        curr = head;
        head = head->next;
        free(curr);
    }
    return head;
}

struct el *trasforma (char stringa[N], char sep, struct el *res){

    cancella(res);
    res = NULL;

    int i = 0;
    int num = 0;
    while (stringa[i] != '\0'){
        if (stringa[i] != sep){
            num = num * 10 + (stringa[i] - '0');
        } else {
            struct el *nuovo = (struct el *) malloc (sizeof(struct el));
            nuovo->valore = num;

            if (res == NULL){
                nuovo->next = NULL;
                res = nuovo;
            } else {
                struct el *curr = res;
                while(curr->next != NULL){
                    curr = curr->next;
                }
                curr->next = nuovo;
                nuovo->next = NULL;
            }
            num = 0;
        }
        i++;
    }
    return res;
}

int main (){
    lista = trasforma(stringa, sep, lista);

    struct el *curr = lista;
    while (curr != NULL){
        printf("%d -> ", curr->valore);
        curr = curr->next;
    }
    printf("NULL\n");

    lista = cancella(lista);
    return 0;
}