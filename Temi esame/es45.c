#include <stdio.h>
#define N 3
int mat [N][N] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

int main (){
    int soglia;
    int count = 0;
    do {
        printf("Inserisci la soglia (intero positivo): ");
        scanf("%d", &soglia);
    } while (soglia <= 0);

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            count += mat[i][j];
            if (count > soglia){
                printf("Superata la soglia %d alla posizione [%d][%d] con somma %d\n", soglia, i+1, j+1, count);
                return 0;
            }
        }
    }
    printf("Soglia %d non superata, somma totale %d [-1][-1]\n",soglia, count);
}