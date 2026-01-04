#define N 5
#include <stdio.h>

typedef int riga[N];
struct el {
    int val;
    struct el *next;
};

void visibile(riga M[N], int righe[N], int colonne[N])
{

    /* Controllo sulle righe */
    for (int i = 0; i < N; i++)
    {
        int max = M[i][0];
        int num = 1;

        for (int j = 1; j < N; j++)
        {
            if (M[i][j] > max)
            {
                max = M[i][j];
                num++;
            }
        }
        righe[i] = num;
    }

    /* Controllo sulle colonne */
    for (int j = 0; j < N; j++)
    {
        int max = M[0][j];
        int num = 1;

        for (int i = 1; i < N; i++)
        {
            if (M[i][j] > max)
            {
                max = M[i][j];
                num++;
            }
        }
        colonne[j] = num;
    }
}

int caricamat(char nomefile[20], riga M[N])
{

    FILE *fp = fopen(nomefile, "r"); // apertura file in lettura
    int N_1;
    fscanf(fp, "%d", &N_1); // lettura dimensione matrice
    if (N_1 != N)
    {
        printf("Errore: dimensione matrice non valida\n");
        return 0;
    }
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            fscanf(fp, "%d", &M[i][j]);
        }
    }
    fclose(fp);
    return 1;
}

int ricerca(struct el *L1, struct el *L2) {
    struct el *p1 = L1;
    struct el *p2 = L2;
    int maggiore = 0;
    int minore = 0;

    int posizione = 0;  // per stampare la posizione

    while (p1 != NULL && p2 != NULL) {
        if (p1->val > p2->val)
            maggiore ++;
        
        else if (p1->val <= p2->val)
            minore ++;

        p1 = p1->next;  // passo al nodo successivo in L1
        p2 = p2->next;  // passo al nodo successivo in L2
        posizione++;
    }

    if (maggiore > minore){
        return 1;
    } else if (minore >= maggiore){
        return 0;
    }
    
    if (p1 != NULL || p2 != NULL){
        printf("Attenzione: le liste hanno lunghezza diversa!\n");
        return 0;
    }
}

int main()
{
    struct el *L1=NULL, *L2=NULL;
    
    riga Matrice[N];
    int righe[N], colonne[N];

    if (caricamat("matrice.txt", Matrice))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d\t", Matrice[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        visibile(Matrice, righe, colonne);

        // stampa righe
        for (int i = 0; i < N; i++)
            printf("Riga %d: %d\n", i, righe[i]);

        printf("\n");

        // stampa colonne
        for (int j = 0; j < N; j++)
            printf("Colonna %d: %d\n", j, colonne[j]);
    }
    else
    {
        printf("Errore nella lettura della matrice dal file\n");
    }

    return 0;
}
