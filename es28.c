#define max 100
int V[max];
#include <stdio.h>

void InsDel (char filename[20], char CA1, char CA2, char vett[100], int *eliminati, int *accettati){
    FILE *fp = fopen (filename,"r");
    int c;
    *accettati = 0;
    *eliminati = 0;
    while ((c = fgetc(fp)) != EOF){
        if (c >= CA1 && c <= CA2){
            (*accettati)++;
            vett[*accettati -1] = c;
        } else {
            (*eliminati)++;
            printf("carattere %c eliminato\n", c);
        }
        if (*accettati >= max){
            printf ("Vettore pieno\n");
            break;
        }
    }
    printf("File finito\n");
    fclose (fp);
}

int main (){
    char filename[20];
    char CA1, CA2;
    char vett[100];
    int eliminati, accettati;
    printf ("Inserisci il nome del file: ");
    scanf ("%s", filename);
    printf ("Inserisci il carattere iniziale e finale dell'intervallo: ");
    scanf (" %c %c", &CA1, &CA2);
    InsDel (filename, CA1, CA2, vett, &eliminati, &accettati);
    printf ("Caratteri accettati: %d\nCaratteri eliminati: %d\n", accettati, eliminati);
    for (int i = 0; i < accettati; i++){
        printf ("%c ", vett[i]);
    }
    return 0;
}