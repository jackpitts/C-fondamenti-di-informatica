#define DIM1 5
#define DIM2 4
#include <stdio.h>

int main() {

    int vett1[DIM1];
    int vett2[DIM2];
    int vettInt[DIM2];

    for (int i = 0; i < DIM1; i++){
        printf("Inserisci il %d numero per il vettore 1: ", i+1);
        scanf("%d", &vett1[i]);
    }

    printf("\n");

    for (int j = 0; j < DIM2; j++){
        printf("Inserisci il %d numero per il vettore 2: ", j+1);
        scanf("%d", &vett2[j]);
    }

    for (int i = 0; i < DIM1; i++){
            for (int j = 0; j < DIM2; j++){
                    if (vett2[j] == vett1[i]) {
                        vettInt[j] = vett2[j];
                    }
            }
    }

    for (int k = 0; k < DIM2; k++) {
        printf("%d ", vettInt[k]);
    }

    return 0;
}