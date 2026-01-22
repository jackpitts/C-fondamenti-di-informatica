#include <stdio.h>

void pari(int vet[1000], int tot, int *posMax, int *countMax) {
    int count = 0;
    *countMax = 0;
    *posMax = -1;

    for (int i = 0; i < tot; i++) {
        if (vet[i] % 2 == 0) {
            count++;
            if (count > *countMax) {
                *countMax = count;
                *posMax = i - count + 1;
            }
        } else {
            count = 0;
        }
    }
}

int main() {
    int vet[1000] = {0,1,2,4,6,8,1,2,4,6,8,10,12,14,16,18,20,1,3,5,7,9};
    int tot = 22;

    int posMax, countMax;

    pari(vet, tot, &posMax, &countMax);

    printf("La sequenza piu' lunga di numeri pari inizia in posizione %d e ha lunghezza %d\n",
           posMax + 1, countMax);

    return 0;
}