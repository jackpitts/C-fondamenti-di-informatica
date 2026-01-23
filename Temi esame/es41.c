#include <stdio.h>
#define m 6
#define n 6
int M[m][n];

int main (){
    int VV;
    printf("Inserisci un numero da 1 a 10: ");
    scanf("%d", &VV);
    if (VV < 1 || VV > 10){
        printf("Numero non valido\n");
        return -1;
    }

    for (int i = 0, j = m-1; i <= j; i++, j--){
        for (int k = 0; k < n; k++){
            M[i][k] = VV;
            M[j][k] = VV;
        }
        VV = VV + 1;
    }

    // Stampa matrice
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}