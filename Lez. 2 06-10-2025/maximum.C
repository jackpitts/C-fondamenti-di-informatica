#include <stdio.h>

int main() {
    int n1, n2;
    printf("Inserisci un numero intero: ");
    if(scanf ("%d", &n1) != 1) {
        printf("Input non valido. Inserisci un numero intero.\n");
        return 0;
    }
    printf("Inserisci un altro numero intero: ");
    if(scanf("%d", &n2) != 1) {
        printf("Input non valido. Inserisci un numero intero.\n");
        return 0;
    }
    if (n1 > n2) {
        printf("%d è maggiore di %d\n", n1, n2);
    } else if (n1 < n2) {
        printf("%d è maggiore di %d\n", n2, n1);
    } else {
        printf("I numeri sono uguali.\n");
    }
    return 0;
}