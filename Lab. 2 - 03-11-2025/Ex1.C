#include <stdio.h>

int main () {

    char stagione;
    int temperatura;

    printf("Stagione? (e = estate, i = inverno): ");
    scanf(" %c", &stagione);

    printf("Temperatura? ");
    scanf("%d", &temperatura);

    if (stagione == 'e'){

        if (temperatura >= 27.5 && temperatura <= 32.5){

            printf("Temperatura estiva nella media\n");

        }

        else {

            printf("Temperatura estiva non nella media\n");

        }

    }

    if (stagione == 'i'){

        if (temperatura >= 2.5 && temperatura <= 7.5){

            printf("Temperatura invernale nella media\n");

        }

        else {

            printf("Temperatura invernale non nella media\n");

        }

    }

    return 0;

}