#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {

    int mat[2][2];
    int det;
    int sum;

} Risultato;

Risultato genera_matrice(int mat[2][2]);

int main(){

    int mat[2][2];
    Risultato r = genera_matrice(mat);
    printf("Il determinante è %d\n", r.det);
    printf("La somma degli elementi è %d\n", r.sum);
    printf("La matrice generata è:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\t", r.mat[i][j]);
        }
        printf("\n");
    }

}

Risultato genera_matrice(int mat[2][2]){
    srand(time(NULL));

    Risultato r;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            r.mat[i][j] = rand() % 10;
        }
    }

    int det;
    r.det = r.mat[0][0] * r.mat[1][1] - r.mat[0][1] * r.mat[1][0];
    
    int sum;
    r.sum = r.mat[0][0] + r.mat[0][1] + r.mat[1][0] + r.mat[1][1];
    
    return r;
}
