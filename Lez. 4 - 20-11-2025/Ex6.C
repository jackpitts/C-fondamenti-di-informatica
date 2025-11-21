#include <stdio.h>
#define MAX 10
#include <time.h>
#include <stdlib.h>

int main () {

    srand(time(NULL));

    int n;
    int vett1[MAX];
    int vett2[MAX];
    int vett3[MAX];

    do {
        printf("Inserisci un numero 1 <= n <= %d: ", MAX);
        scanf("%d", &n);
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++){
        vett1[i] = rand() % MAX;
        vett2[i] = rand() % MAX;
    }

    int j = n - 1;
    for (int i = 0; i < n; i++){
        vett3[i] = vett1[i] + vett2[j];
        j--;
    }

    for (int i = 0; i < n; i++){
        printf("%d\t", vett1[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++){
        printf("%d\t", vett2[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++){
        printf("%d\t", vett3[i]);
    }

    return 0;

}