#include <stdio.h>

int main(){
    int num, min, max;
    printf("Inserisci un numero: ");
    scanf("%d", &num);
    printf("Inserisci un massimo: ");
    scanf("%d", &max);
    printf("Inserisci un minimo: ");
    scanf("%d", &min);
    if ((num % 2 != 0) || (num > min && num < max)) {
        printf("OK");
    } else {
        printf("notOK");
    }
    return 0;
}