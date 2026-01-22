#include <stdio.h>

#define maxv 10
#define maxmr 10
#define maxmc 10
#define N 9
int vet[maxv];

int mat[maxmr][maxmc] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}};

int main()
{
    for (int i = 0; i < maxv; i++) {
    printf("Inserisci il numero %d: ", i + 1);
    scanf("%d", &vet[i]);
}

    int freq[maxv] = {0};

    for (int i = 0; i < maxv; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < maxmc; k++)
            {
                if (mat[j][k] == vet[i])
                {
                    freq[i]++;
                }
            }
        }
    }

    printf("Scansione terminata.\n");

    // Stampa risultati al contrario
    for (int i = maxv - 1; i >= 0; i--)
    {
        printf("Il numero %d compare %d volte\n", vet[i], freq[i]);
    }
    return 0;
}
