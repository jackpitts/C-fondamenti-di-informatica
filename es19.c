#include <stdio.h>
#include <stdlib.h>

int read(char filename[20])
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Errore all'apertura del file.\n");
        return 0;
    }

    int most = 0;
    int digit = -1;
    int counter;
    char c;

    for (int i = 0; i < 10; i++)
    {
        counter = 0;
        rewind(fp);

        while ((c = fgetc(fp)) != EOF)
        {
            if (c == '0' + i)
                counter++;
        }

        if (counter > most)
        {
            most = counter;
            digit = i;
        }
    }

    printf("Il numero che compare piu' volte e': %d (%d volte)\n", digit, most);
    fclose(fp);
    return 1;
}

int main()
{
    char filename[20];

    printf("Inserisci il nome del file: ");
    scanf("%s", filename);

    read(filename);

    return 0;
}