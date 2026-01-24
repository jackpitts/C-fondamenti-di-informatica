#define N 4
#include <math.h>
#include <stdio.h>
typedef unsigned int riga[N];
riga M[N] = {
    {4,10,5,1},
    {0,2,6,0},
    {7,4,12,8},
    {0,7,8,0}
};

double geodist (int s1, int s2){
    return abs(s2 - s1);
}

int main (){

    if (N == 1){
        printf("Diagonale perde");
        return 0;
    }
    // Lunghezza diagonale
    int diag_len = 0;
    for (int i = 0; i < N; i++){
        diag_len += M[i][i];
    }

    // Lunghezza orizzontale
    int horiz_len = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            horiz_len += M[i][j];
        }
        if (horiz_len > diag_len){
            printf("Diagonale perde");
            return 0;
        }
    }

    // Lunghezza verticale
    int vert_len = 0;
    for (int j = 0; j < N; j++){
        for (int i = 0; i < N; i++){
            vert_len += M[i][j];
        }
        if (vert_len > diag_len){
            printf("Diagonale perde");
            return 0;
        }
    }
    printf("Diagonale vince");
    return 0;
}