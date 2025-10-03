#include <stdio.h>

int main() {
    int year;
    printf("Inserisci un anno: ");
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("L'anno %d è bisestile.\n", year);
    } else {
        printf("L'anno %d non è bisestile.\n", year);
    }
    return 0;
}