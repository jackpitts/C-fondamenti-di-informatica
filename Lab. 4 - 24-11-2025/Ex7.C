#include <stdio.h>
#define EN_MAX 5
#define DIM_MARE 5
#define N_NAVI 5
#include <time.h>
#include <stdlib.h>

typedef struct
{
    int r;       // da 0 a DIM_MARE-1
    int c;       // da 0 a DIM_MARE-1
    int energia; // da 0 a EN_MAX
} s_nave;

int turni = 0;

void setup(int mare[DIM_MARE][DIM_MARE], s_nave flotta[N_NAVI])
{
    srand(time(NULL));

    // inizializzo mare vuoto
    for (int i = 0; i < DIM_MARE; i++)
    {
        for (int j = 0; j < DIM_MARE; j++)
        {
            mare[i][j] = -1;
        }
    }

    // piazzo le navi
    for (int i = 0; i < N_NAVI; i++)
    {
        int r, c;
        do
        {
            r = rand() % DIM_MARE;
            c = rand() % DIM_MARE;
        } while (mare[r][c] != -1); // ripeti finché la cella non è vuota

        mare[r][c] = i;
        flotta[i].r = r;
        flotta[i].c = c;
        flotta[i].energia = EN_MAX; // tutte le navi partono con energia massima
    }
}

void stampa_mare(int mare[DIM_MARE][DIM_MARE])
{
    for (int i = 0; i < DIM_MARE; i++)
    {
        for (int j = 0; j < DIM_MARE; j++)
        {
            if (mare[i][j] == -1)
                printf("-1\t");
            else
                printf("%d\t", mare[i][j]);
        }
        printf("\n");
    }
}

void stampa_flotta(s_nave flotta[N_NAVI])
{
    for (int i = 0; i < N_NAVI; i++)
    {
        printf("Nave %d in (%d,%d). Energia = %d\n", i, flotta[i].r, flotta[i].c, flotta[i].energia);
    }
}

void fuoco(int mare[DIM_MARE][DIM_MARE], s_nave flotta[N_NAVI])
{

    int r = rand() % DIM_MARE;
    int c = rand() % DIM_MARE;
    printf("Fuoco coordinate (%d, %d)\n", r, c);

    if (mare[r][c] == -1)
    {
        printf("Acqua!\n");
    }
    else
    {
        int id_nave = mare[r][c];
        if (flotta[id_nave].energia > 1)
        {
            flotta[id_nave].energia--;
            printf("Nave %d colpita! Energia rimanente = %d\n", id_nave, flotta[id_nave].energia);
        }
        else
        {
            flotta[id_nave].energia = 0;
            mare[flotta[id_nave].r][flotta[id_nave].c] = -1;
            printf("Nave %d affondata!\n", id_nave);
        }
    }
    turni++;
}

int gameover(int mare[DIM_MARE][DIM_MARE])
{
    for (int i = 0; i < DIM_MARE; i++)
    {
        for (int j = 0; j < DIM_MARE; j++)
        {
            if (mare[i][j] != -1)
            {
                return 0; // almeno una nave è ancora viva
            }
        }
    }
    printf("Tutte le navi sono state affondate dopo %d tiri!\n", turni);
    return 1; // tutte le navi affondate
}

int main()
{

    int mare[DIM_MARE][DIM_MARE];
    s_nave flotta[N_NAVI];
    srand(time(NULL));

    setup(mare, flotta);
    stampa_mare(mare);
    stampa_flotta(flotta);

    while (!gameover(mare))
    {

        fuoco(mare, flotta);
        stampa_mare(mare);
        stampa_flotta(flotta);
    }
}