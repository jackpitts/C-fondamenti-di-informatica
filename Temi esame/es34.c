#include <stdio.h>
#define n 6
int mat [n][n] = {
    {1, 2, 3, 4, 5, 6},
    {7, 8, 32, 4, 3, 2},
    {5, 6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15, 16},
    {9, 10, 11, 44, 6, 5},
    {13, 10, 9, 1, 2, 3}
};

int peak (int mat[n][n], int *posx, int *posy, int*val){

    *posx = -1;
    *posy = -1;
    *val = 0;
    for (int i = 1; i < n - 1; i++){
        for (int j = 1; j < n - 1; j++){
            if (mat[i][j] > mat[i-1][j] && mat[i][j] > mat[i-1][j-1] && mat[i][j] > mat[i][j-1] && mat[i][j] > mat[i-1][j+1] && mat[i][j] > mat[i][j+1] && mat[i][j] > mat[i+1][j+1] && mat[i][j] > mat[i+1][j] && mat[i][j] > mat[i+1][j-1]){
                if (mat[i][j] > *val){
                    *posx = i;
                    *posy = j;
                    *val = mat[i][j];
                }
            }
        }
    }

    return 0;
}

int main (){
    int posx, posy, val;
    if (peak(mat, &posx, &posy, &val)){
        printf ("Peak trovata in posizione [%d][%d] con valore %d\n", posx + 1, posy + 1, val);
        return 0;
    } else {
        printf ("Nessuna peak trovata [%d][%d]\n", posx, posy);
        return 0;
    }
    return 0;
}
