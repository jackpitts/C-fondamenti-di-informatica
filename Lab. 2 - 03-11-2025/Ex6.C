#include <iostream>

int main () {

    int n = 1, min, max, sum = 0, count = 0;

    while (n != 0) {

        printf("Inserisci un numero intero: ");
        scanf("%d", &n);

        if (n == 0) break;

        if (count == 0) {
            min = max = n;
        }

        sum += n;
        count++;

        if (n < min) {
            min = n;
        }

        if (n > max) {
            max = n;
        }
    }

    if (count == 0){
        printf("Nessun calcolo da eseguire.\n");
        return 0;
    } else {
        printf("Minimo: %d\n", min);
        printf("Massimo: %d\n", max);
        printf("Somma: %d\n", sum);
        printf("%d numeri inseriti.\n", count);
    }

    return 0;
}