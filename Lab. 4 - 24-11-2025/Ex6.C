#include <stdio.h>
#define C_LEN 10
#include <time.h>
#include <stdlib.h>

int enqueue(int coda[], int *n, int elem){

    if (*n < C_LEN){
        coda[*n] = elem;
        (*n) += 1;
        return 1;
    } else {
        return -1;
    }

}

int dequeue(int coda[], int *n){

    if (*n > 0){
        for (int i = 0; i < *n; i++){
            coda[i] = coda[i+1];
        }
        (*n) -= 1;
        return 1;
    } else {
        return -1;
    }

}

void stampa_coda(int coda[], int n){

    printf("Coda: ");
    for (int i = 0; i < n; i++){
        printf("%d ", coda[i]);
    }
    if (n == 0){
        printf("<vuota>");
    } else if (n == C_LEN){
        printf("<piena>");
    }
    printf("\n");
}

int main () {

    srand(time(NULL));
    int coda[C_LEN];
    int n = 0; // numero di elementi nella coda
    int P_MAX = 100;
    int x = 0;

    while (x < P_MAX){
        int r = rand() % 2; // genera 0 o 1
        printf("Operazione %d di %d.", x+1, P_MAX);
        if(r==1){
            printf("Ingresso -> ");
            int e = rand() % 10;
            enqueue(coda, &n, e);
            stampa_coda(coda, n);
        } else if (r==0){
            printf("Uscita -> ");
            dequeue(coda, &n);
            stampa_coda(coda, n);
        }
        x++;
    }

    printf("\n");
    return 0;

}