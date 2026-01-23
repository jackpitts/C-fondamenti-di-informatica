#define MAXA 100
#define MAXB 10
#include <stdio.h>

float A[MAXA], B[MAXB];
// lastA/lastB indicano l’ultima posizione utile in un vettore (se A contiene 10 elementi lastA vale 9;
// all’inizio i due vettori sono vuoti.
int lastA = -1, lastB = -1;

int INS(float A[MAXA], float B[MAXB], int *lastA, int lastB)
{

    int ElA = *lastA + 1;
    int ElB = lastB + 1;
    int i;
    //  in A non c’è spazio per B
    if ((ElA + ElB) > MAXA)
    {
        printf("Non esiste spazio\n");
        return 0;
    }
    // se B è vuoto A contiene già il risultato
    if (ElB == 0)
        return 1;
    // Creo spazio in A, spostando metà elementi di A in avanti x far posto a B
    for (i = *lastA; i >= ElA / 2; i--)
        A[i + ElB] = A[i];
    // inserisco B versione 1
    for (i = 0; i <= lastB; i++)
        A[ElA / 2 + i] = B[i];
    // inserisco B versione 2
    for (i = ElA / 2; i < ElA / 2 + ElB; i++)
        A[i] = B[i - ElA / 2];
    // ricalcolo lastA
    *lastA = *lastA + lastB + 1;
    return 1;
}

int main () {

    // Esempio di test
    lastA = 5;
    A[0] = 1.1; A[1] = 2.2; A[2] = 3.3; A[3] = 4.4; A[4] = 5.5; A[5] = 6.6;
    lastB = 2;
    B[0] = 9.9; B[1] = 8.8; B[2] = 7.7;

    if (INS(A, B, &lastA, lastB)) {
        printf("Vettore A dopo l'inserimento:\n");
        for (int i = 0; i <= lastA; i++) {
            printf("%.1f ", A[i]);
        }
        printf("\n");
    } else {
        printf("Inserimento non riuscito.\n");
    }

    return 0;

}