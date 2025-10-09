#include <stdio.h>

int main() {
    int year;
    printf("Inserisci un anno: ");
    if(scanf("%d", &year) == 1) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            printf("L'anno %d è bisestile.\n", year);
        } else {
            printf("L'anno %d non è bisestile.\n", year);
        }
    } else {
        printf("Input non valido. Inserisci un numero intero.\n");
    }
    return 0;
}