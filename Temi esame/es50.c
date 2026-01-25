#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Tfornitore
{
    int id;
    char nome[20];
    char via[20];
};
struct Tfornitore fornitore;

struct Tric
{
    int id;
    long pos;
};
struct Tric ric;

int main(int argc, char *argv[])
{

    if (argc < 4)
        return 1;

    char filename[20];
    char filename2[20];
    char aux[] = "RIC";

    strcpy(filename2, argv[1]);
    strcat(filename2, aux);

    strcpy(filename, argv[1]);

    int min = atoi(argv[2]);
    int max = atoi(argv[3]);

    struct Tfornitore vet[50];

    FILE *file1 = fopen(filename, "r");
    if (file1 == NULL)
    {
        perror("Error opening first file");
        return 1;
    }
    FILE *file2 = fopen(filename2, "r");
    if (file2 == NULL)
    {
        perror("Error opening second file");
        return 1;
    }

    int i = 0;
    int trovato = 0;
    while (fread(&ric, sizeof(struct Tric), 1, file2) == 1)
    {
        if (ric.id >= min && ric.id <= max)
        {
            trovato = 1;
            fseek(file1, ric.pos, SEEK_SET); // senza moltiplicare per sizeof(Tfornitore)
            fread(&fornitore, sizeof(struct Tfornitore), 1, file1);
            vet[i] = fornitore;
            i++;
            if (i >= 50){
                printf("Array full, stopping at 50.\n");
                break;
            }
        }
    }
    fclose(file1);
    fclose(file2);
    for (int j = 0; j < i; j++)
    {
        printf("ID: %d, Nome: %s, Via: %s\n", vet[j].id, vet[j].nome, vet[j].via);
    }
    if (!trovato) {
        printf("Nessun fornitore trovato nell'intervallo specificato.\n");
    }
    return 0;
}