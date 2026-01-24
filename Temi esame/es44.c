#include <stdio.h>
#include <stdlib.h>

int mostFrequent(int num){
    char stringa[20];
    sprintf(stringa, "%d", num);
    
    int freq[10] = {0};
    for (int i = 0; stringa[i] != '\0'; i++){
        int cifra = stringa[i] - '0';
        freq[cifra]++;
    }

    int maxFreq = 0;
    int cifraPiuFrequente = 0;  // Memorizza la cifra, non solo la frequenza
    for (int i = 0; i < 10; i++){
        if (freq[i] > maxFreq){
            maxFreq = freq[i];
            cifraPiuFrequente = i;  // Salva quale cifra ha questa frequenza
        }
    }   
    return cifraPiuFrequente;  // Restituisci la cifra
}


int read(char filename[20]){
    FILE *fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Errore nell'apertura del file!\n");
        return -1;
    }

    int num;
    while (fscanf(fp, "%d", &num) == 1){  // Leggi direttamente gli interi
        printf("%d - ", num);
        printf("%d\n", mostFrequent(num));
    }

    fclose(fp);
    return 1;
}

int main(){
    char filename[20];
    printf("Inserisci il nome del file: ");
    scanf("%s", filename);

    read(filename);
    return 0;
}
