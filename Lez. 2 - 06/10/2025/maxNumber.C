
#include <stdio.h>

int main() {
    int num, max, count = 0;
    double somma = 0;
    int primo = 1;

    printf("Inserisci numeri interi (0 per terminare):\n");

    while (1) {
        scanf("%d", &num);
        if (num == 0) break;
        if (primo) { max = num; primo = 0; }
        else if (num > max) max = num;
        somma += num;
        count++;
    }

    if (count > 0) {
        printf("Il maggiore è: %d\n", max);
        printf("La media è: %.2f\n", somma / count);
    } else {
        printf("Nessun numero inserito.\n");
    }
    return 0;
}
