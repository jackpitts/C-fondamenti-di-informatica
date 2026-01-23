#include <stdio.h>
int nq, nd;

int check(int mat[nq][nd])
{
    for (int i = 0; i < nq; i++)
    {
        for (int j = 0; j < nd; j++)
        {
            if (j < 3 && (mat[i][j] < 0 || mat[i][j] > 9))
            {
                return -1;
            }
            else if (j >= 3 && (mat[i][j] < 0 || mat[i][j] > 5))
            {
                return -1;
            }
        }
    }
    return 1;
}

int avgQ(int num, float *media, int mat[nq][nd])
{
    *media = 0.0;
    if (num < 0 || num >= nq)
        return -1;

    if (check(mat) != 1)
        return -1;

    int sum = 0;

    for (int j = 0; j < nd; j++)
    {
        sum += mat[num][j];
    }

    *media = (float)sum / nd;
    return 1;
}

int maxAvg(float *maxMedia, int mat[nq][nd])
{
    *maxMedia = -1.0;
    for (int i = 0; i < nq; i++)
    {
        float media = 0.0;
        if (avgQ(i, &media, mat) == -1)
        {
            return -1;
        }
        if (i == 0 || media > *maxMedia)
        {
            *maxMedia = media;
        }
    }
    return 1;
}

int main()
{
    int mat[nq][nd];
    float media;
    do
    {
        printf("Inserire il numero di questionari [0,1000]");
        scanf("%d", &nq);
    } while (nq < 0 || nq > 1000);

    if (nq != 0)
    {
        do
        {
            printf("Inserire il numero di domande [0,100]");
            scanf("%d", &nd);
        } while ((nd < 1 || nd > 20));
    }

    for (int i = 0; i < nq; i++){
        avgQ(i, &media, mat);
        printf("Media: %.2f\n", media);
    }
    return 0;
}
