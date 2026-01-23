#include <stdio.h>

int main() {
    int num1, num2, num3, num4;

    do {
        printf("Inserisci il 1° numero: ");
        scanf("%d", &num1);
        printf("Inserisci il 2° numero: ");
        scanf("%d", &num2);
        printf("Inserisci il 3° numero: ");
        scanf("%d", &num3);
        printf("Inserisci il 4° numero: ");
        scanf("%d", &num4);
    } while (!(num2 > num1 && num4 > num3 && num3 > num2));

    printf("Inserisci il nome del file.txt: ");
    char filename[50];
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    char s[10000];
    long long vetres[1000];
    int j = 0;

    fscanf(fp, "%s", s);
    fclose(fp);

    int pos = 0;
    while (s[pos] != '\0') {
        int N = s[pos] - '0';
        pos++;

        long long x = 0;
        for (int i = 0; i < N; i++) {
            x = x * 10 + (s[pos] - '0');
            pos++;
        }

        if ((x >= num1 && x <= num2) || (x > num3 && x < num4)) {
            vetres[j++] = x;
        } else {
            printf("Numero non valido: %lld\n", x);
        }
    }

    printf("Numeri validi:\n");
    for (int i = 0; i < j; i++) {
        printf("%lld\n", vetres[i]);
    }

    return 0;
}