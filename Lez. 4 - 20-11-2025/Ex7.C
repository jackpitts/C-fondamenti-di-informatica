#include <stdio.h>
#define DIMR 3
#include <stdlib.h>
#include <time.h>

int main () {

    srand(time(NULL));
 
    int matrice[DIMR][DIMR];
    
    printf("Matrice originale: \n\n");

    for(int i = 0; i < DIMR; i++){

        for(int j = 0; j < DIMR; j++){
            matrice[i][j] = rand() % 10;
        }
    }

    for(int i = 0; i < DIMR; i++){

        for(int j = 0; j < DIMR; j++){
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }

    printf("\nInvertita rispetto all' asse X: \n\n");

    for(int i = DIMR - 1; i >= 0; i--){

        for(int j = 0; j < DIMR; j++){
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }

    printf("\nInvertita rispetto all' asse Y: \n\n");

    for (int i = 0; i < DIMR; i++){
        for (int j = DIMR - 1; j >= 0; j--){
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }

    printf("\nInvertita rispetto all' origine: \n\n");

    for (int i = DIMR - 1; i >= 0; i--){
        for( int j = DIMR - 1; j >= 0; j--){
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    return 0;

}