#define N 6
#include <stdio.h>

float peso(int mq[N][N], int *posx, int *posy)
{

    int somma = 0;
    float peso = 0;
    float peso_min = 1000;
    int count = 0;
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int somma = 0;
            int count = 0;

            // Vicino SOPRA
            if (i - 1 >= 0)
            {
                somma += mq[i - 1][j];
                count++;
            }
            // Vicino SOTTO
            if (i + 1 < N)
            {
                somma += mq[i + 1][j];
                count++;
            }
            // Vicino SINISTRA
            if (j - 1 >= 0)
            {
                somma += mq[i][j - 1];
                count++;
            }
            // Vicino DESTRA
            if (j + 1 < N)
            {
                somma += mq[i][j + 1];
                count++;
            }
            // Diagonale ALTO-SINISTRA
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                somma += mq[i - 1][j - 1];
                count++;
            }
            // Diagonale ALTO-DESTRA
            if (i - 1 >= 0 && j + 1 < N)
            {
                somma += mq[i - 1][j + 1];
                count++;
            }
            // Diagonale BASSO-SINISTRA
            if (i + 1 < N && j - 1 >= 0)
            {
                somma += mq[i + 1][j - 1];
                count++;
            }
            // Diagonale BASSO-DESTRA
            if (i + 1 < N && j + 1 < N)
            {
                somma += mq[i + 1][j + 1];
                count++;
            }

            float peso = (float)somma / count;
            if (peso < peso_min)
            {
                peso_min = peso;
                *posx = i;
                *posy = j;
            }

            somma = 0;
            count = 0;
            peso = 0;
        }
    }

    if (peso_min > mq[*posx][*posy])
    {
        printf("L'elemento è una depressione\n");
    }

    return peso_min;
}

int main()
{
    int mq[N][N] = {
        {9, 3, 3, 4, 5, 6},
        {10, 8, 2, 10, 11, 12},
        {2, 1, 6, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}};
    int posx, posy;
    float peso_min = peso(mq, &posx, &posy);
    printf("Peso minimo: %f in posizione [%d][%d]\n", peso_min, posx, posy);
    return 0;
}