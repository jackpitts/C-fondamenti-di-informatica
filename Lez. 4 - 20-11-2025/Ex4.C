#define DIM_M 3
#include <stdio.h>

int main() {

    int matrix[DIM_M][DIM_M];

    for(int i = 0; i < DIM_M; i++) {
        for (int j = 0; j < DIM_M; j++) {
            printf("Inserisci l'elemento in posizione [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }

    printf("Matrice originale:\n");
    for(int k = 0; k < DIM_M; k++) {
        for (int l = 0; l < DIM_M; l++) {
            printf("%d\t", matrix[k][l]);
        }
        printf("\n");
    }

    printf("\nMatrice raddoppiata:\n");
    for(int k = 0; k < DIM_M; k++) {
        for (int l = 0; l < DIM_M; l++) {
            printf("%d\t", (2 * matrix[k][l]));
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}