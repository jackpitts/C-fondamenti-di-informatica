#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    int vet[1000];
    int count = 0;
    int L1, L2, L3, L4;
    
    do {
        printf("Inserisci il primo numero: ");
        scanf("%d", &L1);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &L2);
    } while (L1 >= L2);

    do {
        printf("Inserisci il terzo numero: ");
        scanf("%d", &L3);
        printf("Inserisci il quarto numero: ");
        scanf("%d", &L4);
    } while (L3 >= L4);

    char filename[256];
    printf("Inserisci il nome del file: ");
    
    while (getchar() != '\n');
    
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';
    
    printf("Tentativo di apertura file: '%s'\n", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Errore nell'apertura del file!\n");
        printf("Errore: %s\n", strerror(errno));
        return -1;
    }
    
    printf("File aperto con successo!\n");

    char c;
    while ((c = fgetc(fp)) != EOF) {
        // Salta caratteri non numerici
        if (c < '0' || c > '9') {
            continue;
        }
        
        int lunghezza = c - '0';
        
        if (lunghezza == 0) {
            continue;
        }
        
        // Leggi 'lunghezza' cifre per formare il numero
        int num = 0;
        int cifre_lette = 0;
        
        for (int i = 0; i < lunghezza; i++) {
            c = fgetc(fp);
            
            // Se incontriamo EOF o carattere non numerico
            if (c == EOF) {
                printf("Avviso: File terminato prematuramente (attese %d cifre, lette %d)\n", 
                       lunghezza, cifre_lette);
                fclose(fp);
                printf("\nNumeri salvati nell'array: %d\n", count);
                return 0;
            }
            
            if (c < '0' || c > '9') {
                printf("Avviso: Carattere non numerico '%c' (ASCII %d) trovato, cifre attese: %d, lette: %d\n", 
                       c, c, lunghezza, cifre_lette);
                // Salta questo numero e continua
                break;
            }
            
            num = num * 10 + (c - '0');
            cifre_lette++;
        }
        
        // Processa il numero solo se abbiamo letto tutte le cifre attese
        if (cifre_lette != lunghezza) {
            continue;
        }
        
        if (num >= L1 && num <= L2) {
            printf("Numero nel primo intervallo: [%d,%d] -> %d\n", L1, L2, num);
            vet[count] = num;
            count++;
        } else if (num > L3 && num < L4) {
            printf("Numero nel secondo intervallo: (%d,%d) -> %d\n", L3, L4, num);
            vet[count] = num;
            count++;
        } else {
            printf("Numero fuori intervalli: %d\n", num);
        }
        
        if (count >= 1000) {
            printf("Array pieno!\n");
            break;
        }
    }
    
    fclose(fp);
    
    printf("\nNumeri salvati nell'array: %d\n", count);
    return 0;
}
