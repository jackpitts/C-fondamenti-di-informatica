#include <stdio.h>

int main()
{

    int vet[1000];
    int inf, sup;
    char filename[20];
    char c;
    int i = 0;

    printf("Inserisci il nome di un file: ");
    scanf("%s", filename);
    printf("Inserisci il numero inferiore: ");
    scanf("%d", &inf);
    printf("Inserisci il numero superiore: ");
    scanf("%d", &sup);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file.\n");
        return -1;
    }

    int x = 0;

    while ((c = fgetc(fp)) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            x = x * 10 + (c - '0');
        }
        else
        {
            if (x > inf && x < sup)
            {
                vet[i++] = x;
            }
            x = 0;
        }
    }

    /* ultimo numero */
    if (x > inf && x < sup)
    {
        vet[i++] = x;
    }

    fclose(fp);

    for (int j = 0; j < i; j++)
    {
        printf("%d ", vet[j]);
    }

    printf("\n");

    return 1;
}