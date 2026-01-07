#include <stdio.h>

#define N 4

int main() {
    int M[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Inserisci l'elemento [%d][%d]: ", i, j);
            scanf("%d", &M[i][j]);
        }
    }

    int trovato = 0;

    for (int i = 0; i < N - 1 && !trovato; i++) {
        for (int j = 0; j < N && !trovato; j++) {

            int magincol = 1;

            for (int x = i + 1; x < N; x++) {
                if (M[i][j] <= M[x][j]) {
                    magincol = 0;
                    break;
                }
            }

            if (magincol) {
                printf("Le coordinate del maggiore in colonna sono: [%d][%d]\n", i, j);
                trovato = 1;
            }
        }
    }

    if (!trovato) {
        printf("Maggiore non trovato\n");
    }

    return 0;
}