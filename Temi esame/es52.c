#include <stdio.h>
#include <stdlib.h>
#define C 5
#define R 4
int M[R][C] = {
    {11,21,24,31,13},
    {12,5,10,6,35},
    {12,21,8,7,4},
    {33,20,13,5,14}
};

int maxAnello (int M[R][C], int i, int j, int *imax, int *jmax)
{
    int codice = 0;
    int max = M[i][j];

    /* alto-sinistra */
    if (i-1 >= 0 && j-1 >= 0 &&
        M[i-1][j-1] > max) {
        max = M[i-1][j-1];
        *imax = i-1; *jmax = j-1;
        codice = 1;
    }

    /* alto */
    if (i-1 >= 0 &&
        M[i-1][j] > max) {
        max = M[i-1][j];
        *imax = i-1; *jmax = j;
        codice = 1;
    }

    /* alto-destra */
    if (i-1 >= 0 && j+1 < C &&
        M[i-1][j+1] > max) {
        max = M[i-1][j+1];
        *imax = i-1; *jmax = j+1;
        codice = 1;
    }

    /* sinistra */
    if (j-1 >= 0 &&
        M[i][j-1] > max) {
        max = M[i][j-1];
        *imax = i; *jmax = j-1;
        codice = 1;
    }

    /* destra */
    if (j+1 < C &&
        M[i][j+1] > max) {
        max = M[i][j+1];
        *imax = i; *jmax = j+1;
        codice = 1;
    }

    /* basso-sinistra */
    if (i+1 < R && j-1 >= 0 &&
        M[i+1][j-1] > max) {
        max = M[i+1][j-1];
        *imax = i+1; *jmax = j-1;
        codice = 1;
    }

    /* basso */
    if (i+1 < R &&
        M[i+1][j] > max) {
        max = M[i+1][j];
        *imax = i+1; *jmax = j;
        codice = 1;
    }

    /* basso-destra */
    if (i+1 < R && j+1 < C &&
        M[i+1][j+1] > max) {
        max = M[i+1][j+1];
        *imax = i+1; *jmax = j+1;
        codice = 1;
    }

    if (codice)
        printf("Max attorno a [%d][%d] è: %d\n", i, j, max);
    else
        printf("Nessun max attorno a %d in posizione [%d][%d]\n",max, i, j);

    return codice;
}

void grande (int M[R][C], int i, int j){
    int imax, jmax, res;
    while ((res = maxAnello(M, i, j, &imax, &jmax)) == 1){
        i = imax;
        j = jmax;
    }
}

int main(int argc, char *argv[]){
    if (argc < 3){
        return 0;
    }
    int i = atoi(argv[1]), j = atoi(argv[2]);
    int imax, jmax;
    int res = maxAnello(M, i, j, &imax, &jmax);
    printf("\n");
    grande(M, i, j);
    return 0;
}