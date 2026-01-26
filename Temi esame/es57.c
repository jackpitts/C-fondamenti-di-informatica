#include <stdio.h>

int eval(char filename[20], int *numRighe, int *numCharNonBlank, int *maxLineChar, int *avgLineChar) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    char c;
    *numRighe = 0;
    *numCharNonBlank = 0;
    *maxLineChar = 0;
    int currentLineChar = 0;
    int totalChar = 0;

    while ((c = fgetc(fp)) != EOF) {
        totalChar++;
        
        // Conto i caratteri non blank
        if (c != ' ' && c != '\n' && c != '\t') {
            (*numCharNonBlank)++;
        }

        // Conto i caratteri della riga corrente
        if (c == '\n') {
            (*numRighe)++;
            if (currentLineChar > *maxLineChar) {
                *maxLineChar = currentLineChar;
            }
            currentLineChar = 0;
        } else {
            currentLineChar++;
        }
    }

    // Gestisco l'ultima riga se il file non termina con \n
    if (currentLineChar > 0) {
        (*numRighe)++;
        if (currentLineChar > *maxLineChar) {
            *maxLineChar = currentLineChar;
        }
    }

    // Calcolo la media dei caratteri per riga
    if (*numRighe > 0) {
        *avgLineChar = totalChar / *numRighe;
    } else {
        *avgLineChar = 0;
    }

    fclose(fp);
    return 1;
}
