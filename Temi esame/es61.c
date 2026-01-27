#include <stdio.h>

#define R 3
#define C 3

int mat[R][C];

int ins(int mat[R][C]){
    int vet[R*C];
    int val;
    int duplicato;
    
    for (int i = 0; i < R*C; i++){
        do {
            duplicato = 0;  // Reset del flag
            printf("Inserisci un valore da inserire nella matrice: ");
            scanf("%d", &val);
            
            // Controllo se il valore è già presente
            for(int j = 0; j < i; j++){  // Nota: j < i, non j < R*C
                if (vet[j] == val){
                    printf("Valore gia' presente nella matrice, inseriscine un altro.\n");
                    duplicato = 1;
                    break;
                }
            }
        } while (duplicato);
        
        vet[i] = val;  // Memorizza il valore nel vettore
    }
    
    // Eventualmente copia i valori dal vettore alla matrice
    int k = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            mat[i][j] = vet[k++];
        }
    }

    // Calcolo somma colonne minore
    int min_somma = 0;
    int min_colonna = 0;
    for(int j = 0; j < C; j++){
        int somma_colonna = 0;
        for(int i = 0; i < R; i++){
            somma_colonna += mat[i][j];
        }
        if (j == 0 || somma_colonna < min_somma){
            min_somma = somma_colonna;
            min_colonna = j;
        }
    }
    
    return min_somma;
}

int main() {
    printf("Somma minima: %d\n", ins(mat));
    return 0;
}
