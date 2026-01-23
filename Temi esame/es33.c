#include <stdio.h>
#include <stdbool.h>
#define N 100
int V[N];
int ultimo = -1;

void inversione(int V[N], int ultimo)
{

    bool isPari = (ultimo + 1) % 2 == 0;
    if (isPari)
    {
        printf("Vettore di lunghezza pari\n");
    }
    else
    {
        printf("Vettore di lunghezza dispari\n");
    }
    int i = 0, j = ultimo;
    while (i < j)
    {
        int temp = V[i];
        V[i] = V[j];
        V[j] = temp;
        i++;
        j--;
    }
}

void cerca(int V[N], int ultimo, int *val, int *pos, int tre[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= ultimo; j++)
        {
            if (V[j] == tre[i])
            {
                *val = tre[i];
                *pos = i;
                return;
            }
        }
    }
    *val = -1;
    *pos = -1;
}

int main()
{
    int V[N] = {1, 2, 3, 4, 5, 6};
    int ultimo = 5;
    int tre[3] = {3, 6, 1};
    int val, pos;
    printf("Vettore originale:\n");
    for (int i = 0; i <= ultimo; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n\n");
    printf("Vettore invertito:\n");
    inversione(V, ultimo);
    for (int i = 0; i <= ultimo; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n\n");
    printf("Valori da cercare:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", tre[i]);
    }
    cerca(V, ultimo, &val, &pos, tre);
    printf("\nValore trovato: %d in posizione %d\n", val, pos + 1);
    printf("\n");
    return 0;
}