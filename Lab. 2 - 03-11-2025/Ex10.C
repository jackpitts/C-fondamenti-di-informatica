#include <stdio.h>

int main () {

    int a, b, x, tent;
    do {

        printf("Inserisci il primo numero (maggiore o uguale a 0): ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero (maggiore del primo): ");
        scanf("%d", &b);

    } while (a < 0 || b <= a);

    do {
        printf("Numero da trovare? (compreso tra [%d e %d]): ", a, b);
        scanf("%d", &x);
    } while (x < a || x > b);

    do {
        printf("Numero massimo di tentativi? (maggiore di 0): ");
        scanf("%d", &tent);
    } while (tent <= 0);

    printf("\n");

    for (int i = 0; i < tent; i++) {

        printf("Tentativo %d/10, Cerco %d tra %d e %d. ", i+1, x, a, b);
        if (x == a){
            printf("Trovato! x = a = %d\n\n", x);
            break;
        } else if (x == b){
            printf("Trovato! x = b = %d\n\n", x);
            break;
        } else {
            printf("Non trovato - ");
        }

        if (x < (a+b)/2){
            printf("Cerco nel range [%d - %d]\n", a, (a+b)/2);
            b = (a+b)/2;
        } else {
            printf("Cerco nel range [%d - %d]\n", (a+b)/2, b);
            a = (a+b)/2;
        }    

    }

    return 0;

}