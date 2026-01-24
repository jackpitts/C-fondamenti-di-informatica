#include <stdio.h>

void pari (int vet[1000], int dim, int *countMax, int *pos){
    *pos = -1;
    int count = 0;
    *countMax = 0;
    for (int i = 0; i < dim; i++){
        if (vet[i] % 2 == 0){
            count++;
        }
        if (vet[i] % 2 != 0 && count > *countMax){
            *countMax = count;
            *pos = i - count;
            count = 0;
        }
    }
}

int main (){
    int vet[1000] = {2, 4, 6, 1, 8, 10, 12, 14, 3, 16};
    int dim = 10;
    int countMax, pos;
    pari(vet, dim, &countMax, &pos);
    if (pos != -1){
        printf("La sequenza di numeri pari piu' lunga inizia alla posizione %d e ha lunghezza %d\n", pos + 1, countMax);
    } else {
        printf("Non ci sono numeri pari nel vettore.\n");
    }
}