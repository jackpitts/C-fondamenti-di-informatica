#define N 3
#include <stdio.h>

int mat[N][N] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

int main (){

    int soglia;
    printf("Inserire la soglia: ");
    scanf("%d", &soglia);

    int tot = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            tot += mat[i][j];
            if (tot > soglia){
                printf("La somma ha superato la soglia dopo l'elemento in posizione [%d][%d] con valore %d\n", i, j, tot);
                return 1;
            }
        }
    }
    printf("La soglia non è stata superata. [-1][-1]\n");
    return 0;
}