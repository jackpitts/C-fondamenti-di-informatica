#include <stdio.h>

int main () {

    int x, y;
    char op;
    int risultato;
    int cont = 0;

    do {
    printf("Inserisci il primo numero: ");
    scanf("%d", &x);
    printf("Inserisci l'operazione (+, -, *, /, m, M): ");
    scanf(" %c", &op);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &y);

    printf("Operazione scelta: %d %c %d\n", x, op, y);

    switch (op) {

        case '+':
            risultato = x + y;
            break;
        
        case '-':
            risultato = x - y;
            break;

        case '*':
            risultato = x * y;
            break;

        case '/':
            if (y != 0) {
                risultato = x / y;
            } else {
                printf("Errore: divisione per zero non consentita.\n");
                return 1;
            }
            break;
        
        case 'M':
            if (x > y) {
                risultato = x;
            } else {
                risultato = y;
            }
            break;

        case 'm':
            if (x < y) {
                risultato = x;
            } else {
                risultato = y;
            }
            break;

        default:
            printf("Operazione non valida.\n");
            break;

        }

    printf("Risultato: %d\n", risultato);
    printf("Vuoi continuare? (0 per no, 1 per si): ");
    scanf("%d", &cont);

    } while (cont == 1);

}