#define N 4
#include <stdio.h>

typedef unsigned int riga[N];
riga M[N];

int valuta (riga M[N]){

    // Sostituzione riga
    int r;
    do {
        printf("Inserisci il numero di una riga: (1-%d) ", N);
        scanf("%d", &r);
    } while (r < 1 || r > N);

    int vett[N];
    for (int i = 0; i < N; i++){
        printf("Inserire il numero %d da sostituire per la riga %d: ",i+1, r);
        scanf("%d", &vett[i]);
        M[r-1][i] = vett[i];
    }

    printf("\nMatrice aggiornata:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }

    // Verifica somme sx e dx della diagonale principale

    int sum_sx = 0;
    int sum_dx = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (j < i){
                sum_sx += M[i][j];
            } else if (j > i){
                sum_dx += M[i][j];
            }
        }
    }

    if (sum_sx > sum_dx){
        printf("\nLa somma a sinistra della diagonale principale (%d) è maggiore di quella a destra (%d)\n\n", sum_sx, sum_dx);
        return 1;
    } else {
        printf("\nLa somma a sinistra della diagonale principale (%d) non è maggiore di quella a destra (%d)\n\n", sum_sx, sum_dx);
        return 0;
    }
}

int main() {

    printf("Inserisci i valori della matrice %dx%d:\n", N, N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%d", &M[i][j]);
        }
    }

    valuta(M);
    return 0;
}