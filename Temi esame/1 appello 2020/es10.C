#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef unsigned int riga[N];
riga M[N] = {
    {4, 10, 5, 1},
    {0, 3, 6, 0},
    {7, 4, 4, 8},
    {0, 70, 80, 3}
};

int geodist(int s1, int s2)
{
    return abs(s2 - s1);
}

int main()
{
    int minDistanzaRiga = -1, minRiga = -1;
    int minDistanzaColonna = -1, minColonna = -1;
    int distanzaDiagonale = 0;

    // Calcolo distanza totale della diagonale
    for (int i = 1; i < N; i++){
        for (int j = 1; j < N; j++){
            if (i == j){
                distanzaDiagonale += geodist(M[i][j], M[i-1][j-1]);
            }
        }
    }

    // Calcolo distanza totale per ogni riga
    for (int i = 0; i < N; i++) {
        int distRiga = 0;
        for (int j = 1; j < N; j++) {
            distRiga += geodist(M[i][j], M[i][j-1]);
        }
        if (minDistanzaRiga == -1 || distRiga < minDistanzaRiga) {
            minDistanzaRiga = distRiga;
            minRiga = i;
        }
    }

    // Calcolo distanza totale per ogni colonna
    for (int j = 0; j < N; j++) {
        int distColonna = 0;
        for (int i = 1; i < N; i++) {
            distColonna += geodist(M[i][j], M[i-1][j]);
        }
        if (minDistanzaColonna == -1 || distColonna < minDistanzaColonna) {
            minDistanzaColonna = distColonna;
            minColonna = j;
        }
    }

    printf("Riga con distanza minore: %d (distanza = %d)\n", minRiga, minDistanzaRiga);
    printf("Colonna con distanza minore: %d (distanza = %d)\n", minColonna, minDistanzaColonna);
    printf("Distanza totale della diagonale: %d\n", distanzaDiagonale);

    if (minDistanzaRiga < distanzaDiagonale || minDistanzaColonna < distanzaDiagonale){
        printf("Diagonale perde");
    } else if (distanzaDiagonale < minDistanzaRiga && distanzaDiagonale < minDistanzaColonna){
        printf("Diagonale vince");
    }

    return 0;
}