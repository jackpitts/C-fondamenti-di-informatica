#include <stdio.h>
#define DIMV 5

int main() {

    int n = 0;
    int vett[DIMV];

    for (int i = 0; i < DIMV; i++){
        printf("Inserisci il %d numero: ", i+1);
        scanf("%d", &vett[i]);
        n = DIMV - (i + 1);
        printf("Numero di elementi liberi nel vettore: %d\n", n);
        if (vett[i] == 0){
            break;
        }
    }
    
    for (int j = 0; j < DIMV; j++){
        printf("%d ", vett[j]);
    }

    return 0;
}