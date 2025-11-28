#include <stdio.h>
#define DIM 3

typedef float t_matrice[DIM][DIM];

int dentro (int r, int c){
    if (r >= 0 && r < DIM && c >= 0 && c < DIM){
        return 1;
    } else {
        return 0;
    }
}

float media(int matr_orig[DIM][DIM], int i, int j){
    float somma = 0;
    int count = 0;

    for (int r = i-1; r <= i+1; r++){
        for (int c = j-1; c <= j+1; c++){
            // escludo la cella stessa
            if ((r != i || c != j) && dentro(r, c)){
                somma += matr_orig[r][c];
                count++;
            }
        }
    }

    return (count > 0) ? somma / count : 0;
}

void calcola (t_matrice matr_media, int matr_orig[DIM][DIM]) {

    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++){
            matr_media[i][j] = media(matr_orig, i, j);
        }
    }
}

int main(){

    int matr_orig[DIM][DIM];
    t_matrice matr_media;

    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++){
            printf("Inserire il valore [%d][%d]: ", i, j);
            scanf("%d", &matr_orig[i][j]);
        }
    }

    printf("Matrice originale: \n");
    for(int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++){
            printf("%d\t", matr_orig[i][j]);
        }
        printf("\n");
    }

    printf("Matrice media: \n");

    calcola(matr_media, matr_orig);

    for(int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++){
            printf("%.2f\t", matr_media[i][j]);
        }
        printf("\n");
    }

    return 0;
}