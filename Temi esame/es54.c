#include <stdio.h>
#include <string.h>

int max (char s[], int dim){

    int max = -1;
    int maxFreq = -1;
    int vet[10] = {0};
    for (int i = 0; i < dim; i++){
        vet[s[i] - '0']++;
    }

    for (int i = 0; i < 10; i++){
        if (vet[i] >= maxFreq && i > max){
            maxFreq = vet[i];
            max = i;
        }
    }

    return max;
}

int main (int argc, char *argv[]){

    char filename[20];
    strcpy(filename, argv[1]);

    FILE *fp = fopen (filename, "r");
    if (fp == NULL){
        printf ("Errore nell'apertura del file\n");
        return 0;
    }

    char c;
    int i = 0;
    char s[100];
    while ((c = fgetc(fp)) != '\n'){
        s[i] = c;
        i++;
    }

    int risultato = max (s, i);
    if (risultato == 0){
        printf ("0\n");
        fclose (fp);
        return 0;
    }

    for(int j = 0; j < risultato - 1; j++){
        while ((c = fgetc(fp)) != '\n'){
            // Leggo e scarto la riga
        }
        if (c == EOF){
            fclose (fp);
            return 0;
        }
    }

    int k = 0;
    char f[100];
    while ((c = fgetc(fp)) != '\n' && c != EOF){
        f[k] = c;
        k++;
    }

    int risultato1 = max (f, k);
    printf ("%d\n", risultato1);

    fclose(fp);
    return 0;
}