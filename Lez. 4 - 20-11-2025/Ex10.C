#define NMAX 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int vett[NMAX];
    int vettTot[10] = {0};

    for(int i = 0; i < NMAX; i++) {
        vett[i] = rand() % NMAX;
    }

    printf("Vettore generato:\n\n");
    for (int i = 0; i < NMAX; i++) {
        printf("%d\t", vett[i]);
    }
    printf("\n\n");
    printf("--------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < NMAX; i++) {
        if (vett[i] >= 0 && vett[i] <= 9){
            vettTot[0]++;
        }
        else if (vett[i] >= 10 && vett[i] <= 19){
            vettTot[1]++;
        }
        else if (vett[i] >= 20 && vett[i] <= 29){
            vettTot[2]++;
        }
        else if (vett[i] >= 30 && vett[i] <= 39){
            vettTot[3]++;
        }
        else if (vett[i] >= 40 && vett[i] <= 49){
            vettTot[4]++;
        }
        else if (vett[i] >= 50 && vett[i] <= 59){
            vettTot[5]++;
        }
        else if (vett[i] >= 60 && vett[i] <= 69){
            vettTot[6]++;
        }
        else if (vett[i] >= 70 && vett[i] <= 79){
            vettTot[7]++;
        }
        else if (vett[i] >= 80 && vett[i] <= 89){
            vettTot[8]++;
        }
        else if (vett[i] >= 90 && vett[i] <= 99){
            vettTot[9]++;
        }
    }

    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("Numeri compresi tra %d e %d: %d\n", i*10, i*10+9, vettTot[i]);
    }
    printf("\n");
    return 0;
}