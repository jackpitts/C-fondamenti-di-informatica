#define max 100
#include <stdio.h>

int vet[max];

void scan (int vet[max], int *n){

    int numIns = 0;
    int inserimento;

    if (n != 0){
        for (int i = 0; i < *n; i++){
            vet[i] = 0;
        }
    }

    do {
        printf("Quanti numeri vuoi iserire nel vettore? (max %d): ", max);
        scanf ("%d", &numIns);
    } while (numIns <= 0 || numIns > max);

    *n = numIns;

    for (int i = 0; i < numIns; i++){
        printf("Inserisci il numero %d: ", i+1);
        scanf ("%d", &inserimento);
        if (i == 0 && inserimento > 0){
            vet[i] = inserimento;
        }
        else if(inserimento > 0 && inserimento >= vet[i-1] && i != 0){
            vet[i] = inserimento;
        } 
    }

}

int main (){

    int n = 0;
    scan(vet, &n);

    for (int i = 0; i < n; i++){
        printf ("%d ", vet[i]);
    }

    return 0;

}
