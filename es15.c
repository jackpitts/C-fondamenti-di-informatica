#include <stdio.h>
#include <ctype.h>

int read_file(char filename[50], int n)
{
    char vett[40];
    char c;
    int i = 0;
    int counter = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file %s\n", filename);
        return 0;
    }

    while ((c = fgetc(fp)) != EOF)
    {
        i = 0;

        if (c == EOF)
            break;

        // leggo la parola
        while (c != ' ' && c != '\n' && c != EOF) {
            if (i < 39) {
                if (i == 0) {
                    vett[i++] = toupper(c);  // prima lettera maiuscola
                    counter++;
                } else if (!(c >= 'A' && c <= 'Z')){
                    vett[i++] = c; // resto della parola invariato
                    counter++;
                }
            }
            c = fgetc(fp);
        }
        vett[i] = '\0';
        if (counter < n){
            printf("%s\n", vett);
            return 1;
        }
        counter = 0;
    }

    fclose(fp);
    return 0;
}

int main()
{
    char filename[50];
    int n;

    printf("Inserisci il nome del file da leggere: ");
    scanf("%s", filename);

    printf("Inserisci il numero di elementi da leggere: ");
    scanf("%d", &n);

    read_file(filename, n);

    return 0;
}