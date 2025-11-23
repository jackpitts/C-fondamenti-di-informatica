#include <stdio.h>

int main () {

    int altezza;
    printf("Inserisci l' altezza della piramide: ");
    scanf("%d", &altezza);

    for (int i = 0; i < altezza; i ++) {

        printf("%d", i+1);

    }

    printf("\n");

    for (int i = 0; i < altezza; i++) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

}