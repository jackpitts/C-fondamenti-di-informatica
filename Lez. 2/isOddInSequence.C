
#include <stdio.h>

int main () {
    int contiene_dispari = 0;
    while(1) {
        int num;
        printf("Inserisci un numero intero (0 per terminare): ");
        scanf("%d", &num);
        if(num == 0)
            break;
        if(num % 2 != 0)
            contiene_dispari = 1;
    }
    if (contiene_dispari)
        printf("La sequenza contiene almeno un numero dispari.\n");
    else
        printf("La sequenza non contiene numeri dispari.\n");
    return 0;
}