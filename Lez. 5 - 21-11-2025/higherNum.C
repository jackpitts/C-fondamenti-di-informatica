#include <stdio.h>
int a, b, c;

int *maggiore(int *x, int *y, int *z){

    int *max = x;
    if (*y > *max) max = y;
    if (*z > *max) max = z;
    return max;

}

int main () {

    printf("Inserisci tre numeri interi: ");
    scanf("%d %d %d", &a, &b, &c);

    int *max = maggiore(&a, &b, &c);
    printf("Il numero maggiore è: %d\n", *max);

}