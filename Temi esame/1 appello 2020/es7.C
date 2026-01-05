#include <stdio.h>

void EVAL(char nomefile[20], int *numCaratteri, float *numCaratteriTotali, int *numRighe, int *numCaratteriNonBlank, int *maxRiga, float *media)
{
    FILE *fp = fopen(nomefile, "r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file\n");
        *numCaratteri = -1;
        *numRighe = -1;
        return;
    }

    char res;
    int max = 0;
    *numCaratteri = 0;

    while (fscanf(fp, "%c", &res) == 1) {
        if (res == '\n') {
            if (*numCaratteri > max)
                max = *numCaratteri;
            *numCaratteri = 0;
        } else {
            (*numCaratteri)++;
        }
    }

    if (*numCaratteri > max)
        max = *numCaratteri;

    *maxRiga = max;   // ← QUESTO è il risultato


    char res4;
    *numCaratteriTotali = 0;
    rewind(fp); // Torna all'inizio del file per contare i caratteri totali
    while (fscanf(fp, "%c", &res4) == 1)
    {
        (*numCaratteriTotali)++;
    }
    

    rewind(fp); // Torna all'inizio del file per contare le righe
    char res2;
    *numRighe = 1; // Inizializza a 1 per contare l'ultima riga anche se non termina con '\n'
    while (fscanf(fp, "%c", &res2) == 1)
    {
        if (res2 == '\n')
        {
            (*numRighe)++;
        }
    }

    rewind(fp);
    char res3;
    *numCaratteriNonBlank = 0;
    while (fscanf(fp, "%c", &res3) == 1)
    {
        if (res3 != ' ' && res3 != '\n' && res3 != '\t')
        {
            (*numCaratteriNonBlank)++;
        }
    }

    char res5;
    *media = 0;
    if (*numCaratteriTotali > 0){
        *media = *numCaratteriTotali / (float)(*numRighe);
    }

    fclose(fp);
}

int main()
{
    char nomefile[20] = "eval.txt";
    int caratteri, righe, numCaratteriNonBlank, maxRiga;
    float caratteriTotali, media;

    EVAL(nomefile, &caratteri, &caratteriTotali, &righe, &numCaratteriNonBlank, &maxRiga, &media);

    if (caratteri != -1)
    {
        printf("Numero di caratteri: %.0f\n", caratteriTotali);
        printf("Caratteri massimi in una riga: %d\n", maxRiga);
        printf("Media caratteri per riga: %.2f\n", media);
        printf("Numero di righe: %d\n", righe);
        printf("Caratteri non blank: %d\n", numCaratteriNonBlank);
    }
    return 0;
}
