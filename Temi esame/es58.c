#include <stdio.h>

int uno[10] = {5,4,9,8,3,0,1,9,3,4};
int due[10] = {9,3,4,5,4,9,8,3,0,1};

int confronta(int uno[], int due[]){
    for(int i=0; i<10; i++){
        if(uno[i] != due[i]){
            return 0;
        }
    }
    return 1;
}

int eqs(){
    int count = 0;
    while (confronta(uno, due) == 0){
        int temp = due[9];  // Salva l'ultimo elemento PRIMA del ciclo
        
        for (int i = 9; i > 0; i--){  // Parte da 9 e va verso 0
            due[i] = due[i-1];  // Sposta a destra
        }
        
        due[0] = temp;  // Mette l'ultimo elemento salvato all'inizio
        count++;
        
        // Sicurezza contro loop infinito
        if(count > 10){
            printf("Nessuna rotazione trovata\n");
            return -1;
        }
    }

    printf("Ruotazioni effettuate: %d\n", count);
    return 0;
}

int main() {
    eqs();
    return 0;
}
