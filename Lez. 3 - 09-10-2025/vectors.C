#include <stdio.h>
#include <cstring> // Per usare strlen

int main(){
    char nome [30];
       
    printf("come ti chiami?\n");
    scanf("%s", nome); // Non servono & per gli array

    // Controllo della lunghezza del nome per evitare overflow
    if (strlen(nome) >= 30) {
        printf("Nome troppo lungo porco gesú!\n");
        return 1;
    }

    printf("Ciao %s\n", nome);
    return 0;
}