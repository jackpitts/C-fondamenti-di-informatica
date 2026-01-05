#include <stdio.h>
#define N 10
int vett1[N] = {5, 4, 9, 8, 3, 0, 1, 9, 3, 4};
int vett2[N] = {9, 3, 4, 5, 4, 9, 8, 3, 4, 1};

int checker (int vett1[N], int vett2[N]){

    for (int i = 0; i < N; i++){
        if (vett1[i] != vett2[i]){
            return 0;
        }
    }

    return 1;

}

int EQS() {
    int counter = 0;
    int maxRotazioni = N; // non più di N rotazioni, altrimenti cicliamo all’infinito

    while (!checker(vett1, vett2) && counter < maxRotazioni) {
        int last = vett2[N-1];
        for (int i = N-1; i > 0; i--) {
            vett2[i] = vett2[i-1];
        }
        vett2[0] = last;
        counter++;
    }

    // Se abbiamo fatto tutte le rotazioni possibili e i vettori non sono uguali
    if (!checker(vett1, vett2)) {
        printf("I vettori sono diversi dopo tutte le rotazioni possibili.\n\n");
    }

    return counter;
}

int main() {
    printf("Vettore 1: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", vett1[i]);
    }
    printf("\nVettore 2: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", vett2[i]);
    }
    printf("\n");
    int rotazioni = EQS();
    printf("Numero di rotazioni: %d\n", rotazioni);

    printf("Vettore 1: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", vett1[i]);
    }
    printf("\nVettore 2: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", vett2[i]);
    }

    printf("\n");
    return 0;
}