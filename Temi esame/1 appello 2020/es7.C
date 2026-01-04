#include <stdio.h>

void EVAL(char nomefile[20], int *numCaratteri, int *numRighe){
    FILE *fp = fopen(nomefile, "r");
    if (fp == NULL){
        printf("Errore nell'apertura del file\n");
        *numCaratteri = -1;
        *numRighe = -1;
        return;
    }

    char res;
    *numCaratteri = 0;
    
    while (fscanf(fp, "%c", &res) == 1 && res != '\n') {
        (*numCaratteri)++;
    }

    char res2;
    *numRighe = 0;
    while(fscanf(fp, "%c", &res2) == 1){
        if (res2 == '\n'){
            (*numRighe)++;
        }
    }
    
    fclose(fp);
}

int main(){
    char nomefile[20] = "eval.txt";
    int caratteri, righe;
    
    EVAL(nomefile, &caratteri, &righe);
    
    if (caratteri != -1){
        printf("Caratteri prima riga: %d\n", caratteri);
        printf("Numero di righe: %d\n", righe + 1);
    }
    return 0;
}
