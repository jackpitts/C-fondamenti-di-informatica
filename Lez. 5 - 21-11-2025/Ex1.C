#include <stdio.h>

int main () {

    int a, b;
    float media = 0, sum = 0, n = 0;

    printf("Inserisci il primo numero: ");
    scanf("%d", &a);

    do {

        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);

    } while (b <= a);

    for (int i = a; i <= b; i++) {

        n++;
        sum += i;

    }

    media = sum / n;

    printf("L' intervallo è [%d, %d]\n", a, b);
    printf("La somma dei numeri compresi tra %d e %d è: %.0f\n", a, b, sum);
    printf("La media dei numeri compresi tra %d e %d è: %.1f\n", a, b, media);

}